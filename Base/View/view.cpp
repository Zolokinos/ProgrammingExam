#include <QPainter>

#include "view.h"

View::View() {
  show();
}

void View::SetMenu(QMenuBar* menu) {
  menu_ = menu;
  setMenuBar(menu_);
  menu_->addAction("Exit");
}

void View::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(rect(), Qt::AlignCenter, "Qt");;
}
