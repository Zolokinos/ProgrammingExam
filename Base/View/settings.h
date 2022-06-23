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
#include <QShortcut>
#include <QMessageBox>
#include <QKeyEvent>

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
  void SetShortCut(QShortcut* call_file_message);
  void SetFileDialog(QFileDialog* file_dialog);
  void SetErrorFileDialog(QMessageBox* error_message);
  void SendFileDialogError();
  void SetCustomBackground(QString filename);

  void SetSpinBox(QSpinBox* spin_box);
  void SetComboBox(QComboBox* combo_box);
  void SetInteraction(QLabel* is_intersection_);
  void SetStyleSheet();
  void SetRedStyle();
  void SetBlueStyle();
  void SetBlackStyle();

  signals:
  void RadioButtonClicked(int num);
  void RadiusChanged(int rad);
  void PenThicknessChanged(QString thickness);
  void PointEditingFinished();
  void CalledDialog();

 private:
  void SetUpWidget();

  QFileDialog* file_dialog_;
  QShortcut* call_file_message_;
  QMessageBox* error_message_;

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

#endif // PROGRAMMINGEXAM_BASE_VIEW_SETTINGS_H__
