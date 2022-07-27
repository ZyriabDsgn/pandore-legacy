#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <QtNetwork/QtNetwork>
#include <QWidget>
#include <QtCore/QList>

class TestServer : public QObject
{
  Q_OBJECT

 public:
  TestServer();

  void sendToAll(const QString & message);

  private slots:
    void newConnection();
    void dataReceived();
    void clientDisconnection();

 private:
    QString *m_serverState;

    QTcpServer *m_server;
    QList<QTcpSocket *> m_clients;
    quint16 m_messageSize;
};

#endif //TESTSERVER_H
