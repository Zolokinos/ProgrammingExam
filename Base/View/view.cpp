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

