#include "TestServer.h"

TestServer::TestServer()
{
  m_server = new QTcpServer(this);
  
  if(!m_server->listen(QHostAddress::Any, 50885))
    {
      qDebug() << "Server launch failed" << endl << m_server->errorString() << endl;
    }
  else
    {
      qDebug() << "The server has been launched on port:" << QString::number(m_server->serverPort()) << endl << "Clients can now connect..." << endl;
      connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()) );
    }

  m_messageSize = 0;
}

/* METHODS */

void TestServer::sendToAll(const QString & message)
{
  QByteArray packet;
  QDataStream out(&packet, QIODevice::WriteOnly);
  
  out << (quint16) 0;
  out << message;

  out.device()->seek(0);
  out << (quint16) (packet.size() - sizeof(quint16));

  for(int i = 0; i < m_clients.size(); ++i)
    m_clients[i]->write(packet);
}

/* SLOTS */
void TestServer::newConnection()
{
  sendToAll(tr("<em>New client connected</em>"));
  QTcpSocket* newClient = m_server->nextPendingConnection();
  m_clients << newClient;

  connect(newClient, SIGNAL(readyRead()), this, SLOT(dataReceived()) );
  connect(newClient, SIGNAL(disconnected()), this, SLOT(clientDisconnection()) );
}

void TestServer::dataReceived()
{
  QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
  if(socket == 0)
    return;

  QDataStream in(socket);

  if(m_messageSize == 0)
    {
      if(socket->bytesAvailable() < (int)sizeof(quint16))
	return;

      in >> m_messageSize;
    }

  if(socket->bytesAvailable() < m_messageSize)
    return;

  QString message;
  in >> message;

  sendToAll(message);

  m_messageSize = 0;
}

void TestServer::clientDisconnection()
{
  sendToAll(tr("<em>A client has quit</em>"));

  QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
  if(socket == 0)
    return;

  m_clients.removeOne(socket);

  socket->deleteLater();
}
