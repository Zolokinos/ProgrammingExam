#ifndef BASE_CONTROLLER_MODEL_H__
#define BASE_CONTROLLER_MODEL_H__
#include <QMenuBar>
#include <QWidget>

#include "Base/View/view.h"
#include "Base/View/audioplayer.h"

class Model : public QWidget {
 Q_OBJECT

 public:
  explicit Model(View* view = nullptr);

 private:
  void SetMenu();
  void SetAudio();

  AudioPlayer* audio_player_;
  View* view_;
  QMenuBar* menu_;
};

#endif // BASE_CONTROLLER_MODEL_H__
