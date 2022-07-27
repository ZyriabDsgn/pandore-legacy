#include <QtWidgets/QApplication>
#include "GameView.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  GameView game;
  game.show();

  return app.exec();
}



