#include <QPainter>
#include <iostream>

#include "view.h"
#include "Base/Helpers/helpers.h"

View::View() {
  setFixedSize(800, 600);
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
}

void View::ConnectUI() {
  connect(call_paint_message_,
          &QShortcut::activated,
          this,
          &View::CallDialog);
}

void View::mousePressEvent(QMouseEvent* event) {
  emit Clicked(event->pos());
}

void View::SetShortCut(QShortcut* shortcut) {
  call_paint_message_ = shortcut;
}

void View::DrawCircle(QPoint point, QColor color, QColor color_pen, int rad) {
  QPainter p(this);
  p.setBrush(color);
  p.setPen(color_pen);
  p.drawEllipse(point.x() - rad, point.y() - rad, rad, rad);
}

