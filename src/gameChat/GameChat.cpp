#include "GameChatModel.h"

GameChatModel::GameChatModel(QWidget * parent)
{
  
  m_serverSocket = new QTcpSocket(this);
  connect(m_serverSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()) );
  connect(m_serverSocket, SIGNAL(connected()), this, SLOT(connected()) );
  connect(m_serverSocket, SIGNAL(disconnected()), this, SLOT(disconnected()) );
  connect(m_serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, socketError(QAbstractSocket::SocketError));

  m_messageSize = 0;
}

void GameChatModel::serverConnection()
{
  
