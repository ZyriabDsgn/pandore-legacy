#include "Client.h"

Client::Client(QObject * parent = 0)
  : QTcpSocket(parent)
{
  m_nickname = nullptr;
  m_user = nullptr;
  m_ID = 0;
  m_clanID = 0;
  m_messageSize = 0;
}

Client::Client(const Client & copyClient)
{
  m_user = copyClient.getUser();
  m_nickname = copyClient.getNickname();
  m_messageSize = 0;
}

/* METHODS */
void Client::setNickname(const QString * nick)
{
  m_nickname = nick;
}

void Client::setUser(const QTcpSocket * user)
{
  m_user = user;
}

void Client::setID(const int & ID)
{
  m_ID = ID;
}

void Client::setClanIDList(const QVector<int> & IDList)
{
  for(int i(0); i < IDList.size(); ++i)
    m_clanIDList->push_back(new IDList.at(i));
}
