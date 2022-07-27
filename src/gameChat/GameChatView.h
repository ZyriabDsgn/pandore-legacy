#ifndef GAMECHATVIEW_H
#define GAMECHATVIEW_H

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include <QtCore/QVector>

#include "GameChatModel.h"

class GameChatView : public QWidget
{
  Q_OBJECT
 public:
  GameChatView(QWidget * parent = 0);
  virtual ~GameChaView();

  void setModel(GameChatModel * model);

  void setClanTabVisible(bool visible);
  void setAnonymousTabVisible(bool visible);

private:
  QTabWidget *m_buttonsTabs;

  QTextEdit *m_privateChat;
  QLineEdit *m_privateChatInput;
  QTextEdit *m_publicChat;
  QLineEdit *m_publicChatInput;

  /* Settings */
  bool m_ClanEnabled;
  bool m_anonymousEnabled;

  GameChatModel *m_model;
};


#endif //GAMECHATVIEW_H
