#ifndef BASE_VIEW_AUDIOPLAYER_H__
#define BASE_VIEW_AUDIOPLAYER_H__

#include <QAudioOutput>
#include <QScreen>
#include <QMediaPlayer>

class AudioPlayer : public QMediaPlayer {
 Q_OBJECT

 public:
  AudioPlayer();
  void TurnOn();
  void TurnOff();
  void CreateAudioOutput();
  void ChooseStream(const QUrl& url);

 private:
};

#endif // BASE_VIEW_AUDIOPLAYER_H__
