#ifndef SERVERAPPLICATION_H
#define SERVERAPPLICATION_H

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QDir>
#include <QtCore/QtGlobal>
#include <QtCore/QDate>
#include <string>
#include <fstream>
#include "../Client.h"
#include "operationsEnum.h"

#ifdef Q_OS_LINUX
#define LOG_PATH "log/log.txt"
#define CURRENT_OS "GNU/Linux"
#define UNIX_LIKE "true"

#elif Q_OS_MAC
#define LOG_PATH "log/log.txt"
#define CURRENT_OS "Mac OS X"
#define UNIX_LIKE "true"

#elif Q_OS_WIN
#define LOG_PATH "log\\log.txt"
#define CURRENT_OS "MS Windows"
#define UNIX_LIKE "false"

#endif //OS

class ServerApplication : public QObject
{
  Q_OBJECT
 public:
  ServerApplication(QObject * parent = 0);

  void sendPublicMessage(const QString & msg);
  void sendPrivateMessage(const QString & msg, const int ID);
  void sendClanMessage(const QString & msg, const int ID);

 protected:
  void logConfig();

  private slots:
    void newConnection();
    void dataReceived();
    void clientDisconnection();
    void receiveClient(Client * c);

 private:
    QTcpServer *m_server;
    QList<Client *> m_clientsList;
    QList<Client *> m_clientBuffer;
    quint16 m_messageSize;

    bool m_bufferActivity;

    QString const m_serverLog;
};

#endif //SERVERAPPLICATION_H
