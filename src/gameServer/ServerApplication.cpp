#include "ServerApplication.h"

using namespace std;

ServerApplication::ServerApplication(QObject * parent)
  : QObject(parent), m_bufferActivity(false)
{
  logConfig();

  m_server = new QTcpServer(this);
  if(!m_server->listen(QHostAddress::Any))
    {
      qDebug() << "Server launch failed." << endl << m_server->errorString() << endl; /* Moving this information to the room window */
    }
  else
    {
      qDebug() << "The server has been launched on port: " << QString::number(m_server->serverPort()) << endl << "Clients can now connect..." << endl;
      connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()) );
    }

  m_messageSize = 0;
}

/* METHODS */
void ServerApplication::sendPublicMessage(const QString & msg)
{
  QByteArray packet;
  QDataStream out(&packet, QIODevice::WriteOnly);

  out << (quint16) 0;
  out << (quint8) BROADCAST_CHAT_MESSAGE;
  out << msg;
  
  out.device()->seek(0);
  out << (quint16) (packet.size() - sizeof(quint16));

  for(int i = 0; i < m_clientsList.size(); ++i)
    m_clientsList[i]->getUser()->write(packet);
}

void ServerApplication::sendPrivateMessage(const QString & msg, const int ID)
{
  if(ID <= 0 || ID > m_clientsList.size())
    return;

  QByteArray packet;
  QDataStream out(&packet, QIODevice::WriteOnly);
  int userID = ID;

  out << (quint16) 0;
  out << (quint8) BROADCAST_PRIVATE_MESSAGE;
  out << msg;

  out.device()->seek(0);
  out << (quint16) (packet.size() - sizeof(quint16));

  for(int i = 0; i < m_clientsList.size(); ++i)
    {
      if(m_clientsList[i]->getID() == userID)
	m_clientsList[i]->getUser()->write(packet);
    }
}

void ServerApplication::sendClanMessage(const QString & msg, const int ID)
{
  if(ID <= 0 || ID > m_clientsList.size())
    return;

  QByteArray packet;
  QDataStream out(&packet, QIODevice::WriteOnly);
  int clanID = ID;

  out << (quint16) 0;
  out << (quint8) BROADCAST_CLAN_MESSAGE;
  out << msg;

  out.device()->seek(0);
  out << (quint16) (packet.size() - sizeof(quint16));

  for(int i = 0; i < m_clientsList.size(); ++i)
    {
	for(int c(0); c < m_clientsList[i]->getClanIDList()->size(); ++c)
	  {
	    if(m_clientsList[i]->getClanIDList()->at(c) == clanID && !m_clientsList[i]->getClanIDList()->isEmpty())
	      {
		m_clientsList[i]->getUser()->write(packet);
	      }
	  }
    }
}

void ServerApplication::logConfig()
{
  QString binPath, logPath;
  binPath = QDir::currentPath();

  if(UNIX_LIKE)
    logPath = (binPath + LOG_PATH);
  else
    logPath = (binPath + LOG_PATH);

  string stdLogPath(logPath.toStdString());

  ofstream logStream(stdLogPath.c_str(), ios::trunc);

  if(logStream)
    {
      logStream << (QDate::currentDate().toString("dd.MM.yyyy")).toStdString() << endl;
      logStream << "OS : " << CURRENT_OS << endl;
    }
}

/* SLOT */
void ServerApplication::newConnection()
{
  Client *newClient = new Client(this);
  newClient->setUser(m_server->nextPendingConnection());
  m_clientsList << newClient;

  connect(newClient->getUser(), SIGNAL(readyRead()), newClient, SLOT(sendClient()) );
  connect(newClient, SIGNAL(getThis(Client)), this, SLOT(receiveClient(Client)) );
  
  //must work on it
  connect(newClient->getUser(), SIGNAL(disconnected()), newClient, SLOT(sendClient()) );
  connect(newClient->getUser(), SIGNAL(disconnected()), this, SLOT(clientDisconnection()) );
}

void ServerApplication::dataReceived()
{
  if(!m_bufferActivity)
    return;
      
  Client *dataClient = m_clientBuffer[0];
  m_clientBuffer.pop_front();
  
  QTcpSocket *clientSocket = dataClient->getUser();
  if(clientSocket == 0)
    return;

  QDataStream in(clientSocket);

  if(m_messageSize == 0)
    {
      if(clientSocket->bytesAvailable() < sizeof(quint16))
	return;
      
      in >> m_messageSize;
    }
  
  if(clientSocket->bytesAvailable() < m_messageSize)
    return;

 
  quint8 header; //headers in the operationsEnum.h file
  in >> header;

  QString message;
  in >> message;

  switch(header)
    {
    case CHAT_MESSAGE:
      sendPublicMessage(message);
      break;
    case PRIVATE_MESSAGE:
      sendPrivateMessage(message, clientSocket->getReceiverID());
      break;
    case CLAN_MESSAGE:
      sendClanMessage(message, clientSocket->getReceiverClanID());
      break;
    }

  m_messageSize = 0;


  else
    return;
}

void ServerApplication::clientDisconnection()
{
  Client *clientSocket = qobject_cast<Client *>(sender());
  if(clientSocker->getUser() == 0)
    return;

  sendPublicMessage(tr("<em> " + clientSocket->getNickname() + " has quit.</em>"));

  m_clientsList.removeOne(clientSocket);

  clientSocket->getUser()->deleteLater();
}


void ServerApplication::receiveClient(Client * c)
{
  m_clientBuffer.push_back(c);

  m_bufferActivity = true;
}
