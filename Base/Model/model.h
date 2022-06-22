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

#include "Base/View/view.h"
#include "Base/View/settings.h"
#include "Base/View/audioplayer.h"

class Model : public QWidget {
 Q_OBJECT

 public:
  explicit Model(View* view = nullptr, Settings* settings = nullptr);
  void SetFillColor(int num);
  void CreateDialog();
  void SetCenterCircle(QPoint point);
  void SetFrom(int from);

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

  AudioPlayer* audio_player_;
  View* view_;
  Settings* settings_;
  QMenuBar* menu_;
  QShortcut* call_paint_message_{};
  QColor color_;
  QColor color_pen_;
  int radius_;
  int width_;
  QPoint from_;
  QPoint to_;

  QButtonGroup* buttons_;
  QColor fill_color_{};
  QLineEdit* from_x_point_;
  QLineEdit* from_y_point_;
  QLineEdit* to_x_point_;
  QLineEdit* to_y_point_;
  QSpinBox* spin_box_;
  QComboBox* combo_box_;
};

#endif // BASE_CONTROLLER_MODEL_H__
