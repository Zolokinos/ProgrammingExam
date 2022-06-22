#include <QApplication>
#include "Controller/main_controller.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  MainController controller;
  return QApplication::exec();
}
