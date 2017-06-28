#ifndef PASSWORDCONTROL_H
#define PASSWORDCONTROL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include "password.h"

class PasswordControl : public QWidget
{
    Q_OBJECT
public:
    explicit PasswordControl(QWidget *parent = nullptr);
    void setDefault(int length=6, CodeType codeType=wubi);
private:
    QVBoxLayout  *vBox;
    QHBoxLayout  *codeTypeHBox;
    QLabel       *codeTypeLabel;
    QRadioButton *codeWubiButton, *codePinyinButton;
    QButtonGroup *codeTypeButtons;
    QHBoxLayout  *lengthHBox;
    QLabel       *lengthLabel;
    QSlider      *lengthSlider;
    QSpinBox     *lengthSpinBox;
    QPushButton  *genButton;
private slots:
    void changeLength(int length);
    void changeType(int codeType, bool checked=true);
    void request();
signals:
    void lengthChanged(int length);
    void typeChanged(CodeType codeType);
    void requested();
};

#endif // PASSWORDCONTROL_H
