#include <QPainter>

#include "view.h"
#include "Base/Helpers/helpers.h"

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

void View::ConnectUI() {
  connect(menu_->actions()[static_cast<int>(MenuBarOrder::kExit)],
          &QAction::triggered,
          this,
          &View::ExitRequested);
}
