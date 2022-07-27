#include <QtWidgets/QApplication>
#include "GameChat.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  GameChat chat;
  chat.show();

  return app.exec();
}
