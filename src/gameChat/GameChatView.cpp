#include "GameChatView.h"

GameChatView::GameChatView(QWidget * parent)
  : m_clanEnabled(false), m_anonymousEnabled(false)

{

  if(/*need to write enum*/) //pandora
    {
      QHBoxLayout playersButtonsRow1;
      QHBoxLayout playersButtonsRow2;
      QVBoxLayout 

      int bNum = m_model->getPlayersNumber();
      QVector<QPushButton> dialogueButtons(16);

      for(int i = 0; i < dialogueButtons.size(); ++i)
	{
	  dialogueButtons[i].setText(tr("J") + (QString)i);
	  dialogueButtons[i].setCheckable(true);

	  //need to add to the buttons their features && players
	  
	  if(i <= 7)
	    playersButtonsRow1.addWidget(dialogueButtons[i]);
	  else
	    playersButtonsRow2.addWidget(dialogueButtons[i]);

	}

      //need to add other games

