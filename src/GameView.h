#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QtWidgets/QAbstractItemView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include <QtCore/QTimer>


class GameView : public QWidget
{
  Q_OBJECT
 
 public:
  GameView(QWidget * parent = 0);
  virtual ~GameView();

  void setModel(QAbstractGameModel * model);

 protected:
  /* Setups */
  void infoTabConfig();
  void chatConfig();
  void bottomConfig();

  /* Layouts */
  QVBoxLayout *m_mainLayout;
  QHBoxLayout *m_centralLayout;
  QHBoxLayout *m_bottomLayout;

  /* Info tab */
  QTabWidget *m_infoTab;
  QTextEdit *m_publicInfoTab;
  QTextEdit *m_privateInfoTab;
  QTextEdit *m_rulesTab;


  /* Chat */
  //need to finish GameChat
  //it needs special features like \
  //managing a lot of buttons (A LOT), adding tabs(?), etc

  /* Window bottom */
  QPushButton *m_state;
  QPushButton *m_privateActions;
  QPushButton *m_publicActions;
  QPushButton *m_alert;
  QPushButton *m_settings;
  QLabel *m_phase;
  QPushButton *m_time; //need a dedicated class ?

  //AbstractGameModel *m_model;

};

#endif //GAMEVIEW_H
