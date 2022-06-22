#ifndef BASE_CONTROLLER_MODEL_H__
#define BASE_CONTROLLER_MODEL_H__
#include <QMenuBar>
#include <QWidget>
#include <QSpinBox>
#include <QShortcut>
#include <QButtonGroup>
#include <QRadioButton>

#include "Base/View/view.h"
#include "Base/View/settings.h"
#include "Base/View/audioplayer.h"

class Model : public QWidget {
 Q_OBJECT

 public:
  explicit Model(View* view = nullptr, Settings* settings = nullptr);
  void SetFillColor(int num);

 private:
  void SetMenu();
  void SetAudio();
  void SetUI();
  void SetCenterCircle(QPoint point);
  void SetView();
  void SetSettings();

  AudioPlayer* audio_player_;
  View* view_;
  Settings* settings_;
  QMenuBar* menu_;
  QSpinBox* spin_box_;
  QShortcut* call_paint_message_{};
  QColor color;

  QButtonGroup* buttons_;
  QColor fill_color_{};
};

#endif // BASE_CONTROLLER_MODEL_H__
