#ifndef GAMECHATMODEL_H
#define GAMECHATMODEL_H

#include <QtNetwork/QtNetwork>
#include <QtGui/QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>

class GameChatModel : public QWidget
{
  Q_OBJECT

 public:
  GameChatModel(QWidget * parent = 0);

  private slots:
    void serverConnection();
    void on_sendButton_clicked(); //view method?
    void on_message_returnPressed(); //view method?
    void dataReceived();
    void connected();
    void disconnected();
    void socketError(QAbstractSocket::SocketError error);

 private:
    QTcpSocket *m_serverSocket;
    quint16 m_messageSize;
}

#endif //GAMECHATMODEL_H

