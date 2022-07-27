#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>
#include <QtCore/QString>
#include "gameServer/operationsEnum.h"

/* NEED TO WORK ON THE DESIR / VERTU */


class Client : public QObject
{

  Q_OBJECT
 public:
 Client(QObject * parent = 0);
 Client(const Client & copyClient);

 void setNickname(const QString * nick);
 QString* getNickname() const {return m_nickname;}
 
 void setUser(const QTcpSocket * user);
 QTcpSocket* getUser() const {return m_user;}

 void setID(const int ID);
 int getID() const {return m_ID;}

 void setClanIDList(const QVector<int> ID);
 QVector<int>* getClanIDList() const {return m_clanIDList;}

 void setReceiverID(const int ID);
 int getReceiverID() const {return m_receiverID;}

 void setReceiverClanID(const int ID);
 int getReceiverClanID() const {return m_receiverClanID;}

 

 signals:
 void getThis(Client * c);

 private slots:
   void sendClient() {emit getThis(this);}

 private:
 QString *m_nickname;
 QTcpSocket *m_user;
 quint16 m_messageSize;
 int m_ID;
 QVector<int> *m_clanIDList;
 int m_receiverID;
 int m_receiverClanID;
};

#endif //CLIENT_H

