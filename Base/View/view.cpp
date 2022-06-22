#include <QPainter>
#include <iostream>

#include "view.h"
#include "Base/Helpers/helpers.h"

View::View() {
  show();
}

void View::SetMenu(QMenuBar* menu) {
  menu_ = menu;
  setMenuBar(menu_);
  auto exit = menu_->addAction("Exit");
  connect(exit,
          &QAction::triggered,
          this,
          &View::ExitRequested);
}

void View::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(rect(), Qt::AlignCenter, "Qt");;
}
void View::ConnectUI() {
}
