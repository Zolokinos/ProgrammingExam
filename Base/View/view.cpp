#include <QPainter>
#include <iostream>

#include "view.h"
#include "Base/Helpers/helpers.h"
#include "Base/Helpers/styles.h"

View::View() {
  setFixedSize(800, 600);
  show();
  setWindowTitle("Paint Zone");
  setStyleSheet(kMainWindowView);
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
  if (is_circle_) {
    QPainter painter(this);
    QPen pen;
    pen.setColor(circle_.color_pen);
    pen.setWidth(circle_.thickness);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(circle_.fill_color);
    brush.setStyle(Qt::BrushStyle::Dense7Pattern);
    painter.setBrush(brush);

    painter.drawEllipse(circle_.central_circle.x() - circle_.radius,
                        circle_.central_circle.y() - circle_.radius,
                        2 * circle_.radius,
                        2 * circle_.radius);
  }

  if (is_line_) {
    QPainter painter(this);
    QPen pen;
    pen.setColor(line_.color_pen);
    pen.setWidth(line_.thickness);
    painter.setPen(pen);
    std::cout << line_.from.x() << line_.from.y() << line_.to.x() << line_.to.y();
    painter.drawLine(line_.from.x(),
                     line_.from.y(),
                     line_.to.x(),
                     line_.to.y());
  }
}

void View::ConnectUI() {
  connect(call_paint_message_,
          &QShortcut::activated,
          this,
          &View::CallDialog);
  connect(dialog_,
          &QColorDialog::colorSelected,
          this,
          &View::ColorDialogColorSelected);
}

void View::mousePressEvent(QMouseEvent* event) {
  emit Clicked(event->pos());
}

void View::SetShortCut(QShortcut* shortcut) {
  call_paint_message_ = shortcut;
}

void View::SendCircle(Circle circle) {
  circle_ = circle;
  is_circle_ = true;

  repaint();
}

void View::SetColorDialog(QColorDialog* dialog) {
  dialog_ = dialog;
}

void View::SendLine(Line line) {
  line_ = line;
  is_line_ = true;

  repaint();
}

