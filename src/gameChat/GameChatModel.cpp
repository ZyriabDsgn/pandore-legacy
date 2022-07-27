#include "GameChatModel.h"

GameChatModel::GameChatModel(QWidget * parent = 0)
{
  m_serverSocket = new QTcpSocket(this);
  connect(m_serverSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()) );
  connect(m_serverSocket, SIGNAL(connected()), this, SLOT(connected()) );
  connect(m_serverSocket, SIGNAL(disconnected()), this, SLOT(disconnected()) );
  connect(m_serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)) );

  m_messageSize = 0;
}

GameChatMdel::~GameChatModel()
{
}

/* SLOTS */
void GameChatModel::serverConnection()
{
  socket->abort();
  socket->connectToHost(//need to finish the 'main' server (with the list of IP in game)
			/* think about making the first tests on a pre-defined IP */
			/* NEED TO CONNECT FROM THE GAME MODEL !! - NOT EXPLICITELY HERE -
