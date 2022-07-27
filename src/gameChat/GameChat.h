#ifndef GAMECHAT_H
#define GAMECHAT_H

#include "GameChatView.h"
#include "GameChatModel.h"

/* This class is the link that implements the chat view and its model
 * It is just here to have a cleaner, intuitive and centralized code */

class GameChat
{
  Q_OBJECT
 public:
  GameChat(QWidget * parent = 0);
  virtual ~GameChat();

