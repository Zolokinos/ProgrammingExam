#ifndef BASE_HELPERS_H_
#define BASE_HELPERS_H_

#include <QColor>
#include <QPoint>

enum class MenuBarOrder {
  kExit,
};

struct Circle {
  Circle(QColor qfill_color, QColor qcolor_pen,
  int qradius, int qthickness, QPoint qcentral_circle) :
  fill_color(qfill_color),
  color_pen(qcolor_pen),
  radius(qradius),
  thickness(qthickness),
  central_circle(qcentral_circle) {}

  Circle() = default;

  QColor fill_color{QColor(Qt::black)};
  QColor color_pen{QColor(Qt::black)};
  int radius{0};
  int thickness{1};
  QPoint central_circle;
};

struct Line {

};
#endif // BASE_HELPERS_H_
