#include <QApplication>
#include "TestServer.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  TestServer server;

  return app.exec();
}

