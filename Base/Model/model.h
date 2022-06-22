#ifndef BASE_CONTROLLER_MODEL_H__
#define BASE_CONTROLLER_MODEL_H__
#include <QMenuBar>
#include <QWidget>
#include <QSpinBox>
#include <QShortcut>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QComboBox>
#include <QColorDialog>
#include <QLabel>

#include "Base/View/view.h"
#include "Base/View/settings.h"
#include "Base/View/audioplayer.h"
#include "Base/Helpers/helpers.h"

class Model : public QWidget {
 Q_OBJECT

 public:
  explicit Model(View* view = nullptr, Settings* settings = nullptr);
  void SetFillColor(int num);
  void CreateDialog();
  void DrawCircle(QPoint point);
  void ChangeRadius(int rad);
  void ChangePenThickness(int thickness);
  void SetPenColor(QColor color);
  bool IsSomeEmpty();
  void DrawLine();
  bool EverythingExists() const;
  void FindCrossing();

 private:
  void SetMenu();
  void SetAudio();
  void SetUI();
  void SetView();
  void SetSettings();
  void SetRadioButtons();
  void SetLineEdits();
  void SetSpinBox();
  void SetComboBox();
  void SendResultCrossing(QString string);

  AudioPlayer* audio_player_;
  View* view_;
  Settings* settings_;
  QMenuBar* menu_;
  QShortcut* call_paint_message_{};

  QColor fill_color_{QColor(Qt::black)};
  QColor color_pen_{QColor(Qt::black)};
  int radius_{0};
  int thickness_{1};
  QPoint central_circle_;

  QPoint from_;
  QPoint to_;

  bool is_circle_{false};
  bool is_line_{false};

  QColorDialog* dialog_;

  QButtonGroup* buttons_;
  QLineEdit* from_x_point_;
  QLineEdit* from_y_point_;
  QLineEdit* to_x_point_;
  QLineEdit* to_y_point_;
  QSpinBox* spin_box_;
  QComboBox* combo_box_;
  QLabel* is_intersection_;
};

#endif // BASE_CONTROLLER_MODEL_H__
