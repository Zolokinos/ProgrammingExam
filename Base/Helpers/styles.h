#ifndef PROGRAMMINGEXAM_BASE_HELPERS_STYLES_H_
#define PROGRAMMINGEXAM_BASE_HELPERS_STYLES_H_
#include <QString>

const QString kRadioButton =
    "QRadioButton::indicator {"
    "width: 30px;"
    "height: 30px;}"

    "QRadioButton::indicator::unchecked {"
    "image: url(:/Base/Resources/UncheckedCommon.png);}"

    "QRadioButton::indicator::checked {"
    "image: url(:/Base/Resources/CheckedCommon.png);}"

    "QRadioButton::indicator::unchecked:hover {"
    "image: url(:/Base/Resources/UncheckedHovered.png);}"

    "QRadioButton::indicator::checked:hover {"
    "image: url(:/Base/Resources/CheckedHovered.png);}"

    "QRadioButton::indicator::unchecked:pressed {"
    "image: url(:/Base/Resources/UncheckedPressed.png);}"

    "QRadioButton::indicator::checked:pressed {"
    "image: url(:/Base/Resources/CheckedPressed.png);}";

const QString kLineEditBlack =
    "QLineEdit {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: black;"
    "min-width: 100px}";

const QString kLineEditBlue =
    "QLineEdit {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: blue;"
    "min-width: 100px}";

const QString kLineEditRed =
    "QLineEdit {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: red;"
    "min-width: 100px}";

const QString kSpinBoxBlack =
    "QSpinBox {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: black;}";

const QString kSpinBoxBlue =
    "QSpinBox {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: blue;}";

const QString kSpinBoxRed =
    "QSpinBox {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: red;}";

const QString kComboBoxBlack =
    "QComboBox {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: black;"
    "min-width: 50px}"
    "QComboBox::down-arrow {"
    "image: url(:/Base/Resources/Arrow.png);}"
    "QComboBox::down-arrow:on {" /* shift the arrow when popup is open */
    "top: 1px;"
    "left: 1px;}"
    "QComboBox QAbstractItemView {"
    "border: 2px solid darkgray;"
    "selection-background-color: lightgray;"
    "}";

const QString kComboBoxBlue =
    "QComboBox {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: blue;"
    "min-width: 50px}"
    "QComboBox::down-arrow {"
    "image: url(:/Base/Resources/Arrow.png);}"
    "QComboBox::down-arrow:on {" /* shift the arrow when popup is open */
    "top: 1px;"
    "left: 1px;}"
    "QComboBox QAbstractItemView {"
    "border: 2px solid darkblue;"
    "selection-background-color: lightblue;"
    "}";

const QString kComboBoxRed =
    "QComboBox {"
    "border-width: 2px;"
    "border-style: solid;"
    "border-color: red;"
    "min-width: 50px}"
    "QComboBox::down-arrow {"
    "image: url(:/Base/Resources/Arrow.png);}"
    "QComboBox::down-arrow:on {" /* shift the arrow when popup is open */
    "top: 1px;"
    "left: 1px;}"
    "QComboBox QAbstractItemView {"
    "border: 2px solid red;"
    "selection-background-color: pink;"
    "}";
// font: bold 14px;
const QString kMainWindowSettings =
    "QMainWindow {"
    "image: url(:/Base/Resources/Arrow.png);}";

const QString kMainWindowSettingsPicture =
    "QMainWindow {}";

const QString kMainWindowView =
    "QMainWindow {"
    "background-color: white;}";

const QString kIsIntersectionLabelBlack =
    "QLabel {"
    "border: 2px solid black;"
    "border-radius: 4px;"
    "padding: 2px;"
    "margin-top: 20px;"
    "margin-bottom: 20px;"
    "background-color: white;"
    "font-family: \"Calibri\";"
    "font-size: 20px;"
    "border-style: solid;"
    "border-top-color: darkgray;"
    "border-right-color: darkgray;"
    "border-top-width: 1px;"
    "border-right-width: 1px;}";

const QString kIsIntersectionLabelBlue =
    "QLabel {"
    "border: 2px solid blue;"
    "border-radius: 4px;"
    "padding: 2px;"
    "margin-top: 20px;"
    "margin-bottom: 20px;"
    "background-color: white;"
    "font-family: \"Calibri\";"
    "font-size: 20px;"
    "border-style: solid;"
    "border-top-color: lightblue;"
    "border-right-color: lightblue;"
    "border-top-width: 1px;"
    "border-right-width: 1px;}";

const QString kIsIntersectionLabelRed =
    "QLabel {"
    "border: 2px solid red;"
    "border-radius: 4px;"
    "padding: 2px;"
    "margin-top: 20px;"
    "margin-bottom: 20px;"
    "background-color: white;"
    "font-family: \"Calibri\";"
    "font-size: 20px;"
    "border-style: solid;"
    "border-top-color: pink;"
    "border-right-color: pink;"
    "border-top-width: 1px;"
    "border-right-width: 1px;}";

const QString kMessage =
    "QMessageBox {"
    "background-color: pink;"
    "font-size: 20px;"
    "font-style: italic;}"

    "QMessageBox QPushButton { "
    "color: white;"
    "background-color: green;}";

#endif // PROGRAMMINGEXAM_BASE_HELPERS_STYLES_H_
