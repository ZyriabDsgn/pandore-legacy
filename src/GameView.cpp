#include "GameView.h"

GameView::GameView(QWidget * parent)
//  : m_model(nullptr)
{

  m_mainLayout    = new QVBoxLayout;
  m_centralLayout = new QHBoxLayout;
  m_bottomLayout  = new QHBoxLayout;

  infoTabConfig();
  chatConfig();
  bottomConfig();


  m_centralLayout->addWidget(m_infoTab);
  //need to add the chat

  m_mainLayout->addLayout(m_centralLayout);
  m_mainLayout->addLayout(m_bottomLayout);

  this->setLayout(m_mainLayout);

}

GameView::~GameView()
{
}

/*
void GameView::setModel(QAbstractGameModel * model)
{
  m_model = model;
}
*/

/* Setups */
void GameView::infoTabConfig()
{
  m_infoTab        = new QTabWidget;
  m_publicInfoTab  = new QTextEdit;
  m_privateInfoTab = new QTextEdit;
  m_rulesTab       = new QTextEdit;

  m_publicInfoTab->setReadOnly(true);
  m_privateInfoTab->setReadOnly(true);
  m_rulesTab->setReadOnly(true);

  m_infoTab->addTab(m_publicInfoTab, tr("Informations publiques"));
  m_infoTab->addTab(m_privateInfoTab, tr("Informations privées"));
  m_infoTab->addTab(m_rulesTab, tr("Règles"));

  //need to connect public tab model
  //need to connect private tab model
  /* rules: QTextDocument ? */
}


void GameView::chatConfig()
{
  //need to finish GameChat class
}

void GameView::bottomConfig()
{
  m_state          = new QPushButton(tr("État"));
  m_privateActions = new QPushButton(tr("Actions privées"));
  m_publicActions  = new QPushButton(tr("Actions publiques"));
  m_alert          = new QPushButton(tr("!!!"));
  m_phase          = new QLabel(tr("phase")); //will change
  m_time           = new QPushButton("0:00"); //need a timer-button!

  m_bottomLayout->addWidget(m_state);
  m_bottomLayout->addWidget(m_privateActions);
  m_bottomLayout->addWidget(m_publicActions);
  m_bottomLayout->addWidget(m_alert, 10);
  m_bottomLayout->addWidget(m_phase);
  m_bottomLayout->addWidget(m_time);
}


