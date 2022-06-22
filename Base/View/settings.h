#ifndef PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__
#define PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__

#include <QMainWindow>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>

class Settings : public QMainWindow {
 Q_OBJECT

 public:
  Settings();
  void SetRadioButtons(QButtonGroup* buttons);
  void ConnectUI();
  void SetLayout();
  void SetLineEdits(QLineEdit* from_x_point,
                    QLineEdit* from_y_point,
                    QLineEdit* to_x_point,
                    QLineEdit* to_y_point);
  void SetFocusTransition();
  void SetSpinBox(QSpinBox* spin_box);
  void SetComboBox(QComboBox* combo_box);
  void SetInteraction(QLabel* is_intersection_);

  signals:
  void RadioButtonClicked(int num);
  void RadiusChanged(int rad);
  void PenThicknessChanged(QString thickness);

 private:
  void SetUpWidget();

  QButtonGroup* buttons_;
  QLineEdit* from_x_point_;
  QLineEdit* from_y_point_;
  QLineEdit* to_x_point_;
  QLineEdit* to_y_point_;
  QSpinBox* spin_box_;
  QComboBox* combo_box_;
  QLabel* is_intersection_;

  QHBoxLayout* layout_;
  QWidget* central_;
};

#endif //PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__
