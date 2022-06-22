#ifndef PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__
#define PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__

#include <QMainWindow>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>

class Settings : public QMainWindow {
 Q_OBJECT

 public:
  Settings();
  void SetRadioButtons(QButtonGroup* buttons);
  void ConnectUI();
  void SetLayout();

  signals:
  void RadioButtonClicked(int num);

 private:
  void SetUpWidget();

  QButtonGroup* buttons_;
  QHBoxLayout* layout_;
  QWidget* central_;
};

#endif //PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__
