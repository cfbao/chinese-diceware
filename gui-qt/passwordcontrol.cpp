#include "passwordcontrol.h"

PasswordControl::PasswordControl(QWidget *parent) : QWidget(parent)
{
    vBox = new QVBoxLayout(this);
    codeTypeHBox = new QHBoxLayout();
    codeTypeLabel = new QLabel("编码：");
    codeWubiButton = new QRadioButton("五笔");
    codePinyinButton = new QRadioButton("拼音");
    codeTypeButtons = new QButtonGroup(this);
    codeTypeButtons->addButton(codeWubiButton, wubi);
    codeTypeButtons->addButton(codePinyinButton, pinyin);

    lengthHBox = new QHBoxLayout();
    lengthLabel = new QLabel("词语个数：");
    lengthSlider = new QSlider(Qt::Horizontal);
    lengthSlider->setSingleStep(1);
    lengthSlider->setPageStep(1);
    lengthSlider->setMinimum(1);
    lengthSlider->setMaximum(10);
    lengthSlider->setTickInterval(1);
    lengthSlider->setTickPosition(QSlider::TicksBothSides);
    lengthSlider->setMinimumWidth(250);
    lengthSpinBox = new QSpinBox();
    lengthSpinBox->setMinimum(1);
    lengthSpinBox->setMaximum(10);

    genButton = new QPushButton("生成密码");

    codeTypeHBox->addStretch();
    codeTypeHBox->addWidget(codeTypeLabel);
    codeTypeHBox->addWidget(codeWubiButton);
    codeTypeHBox->addWidget(codePinyinButton);
    codeTypeHBox->addStretch();
    lengthHBox->addStretch();
    lengthHBox->addWidget(lengthLabel);
    lengthHBox->addWidget(lengthSlider);
    lengthHBox->addWidget(lengthSpinBox);
    lengthHBox->addStretch();
    vBox->addLayout(codeTypeHBox);
    vBox->addLayout(lengthHBox);
    vBox->addWidget(genButton,0,Qt::AlignCenter);
    vBox->setContentsMargins(0,0,0,0);

    connect(lengthSlider,  &QSlider::valueChanged,
            this, &PasswordControl::changeLength);
    connect(lengthSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &PasswordControl::changeLength);
    connect(codeTypeButtons, static_cast<void(QButtonGroup::*)(int, bool)>(&QButtonGroup::buttonToggled),
            this, &PasswordControl::changeType);
    connect(genButton, &QPushButton::released,
            this, &PasswordControl::request);
}

void PasswordControl::setDefault(int length, CodeType codeType)
{
    changeLength(length);
    changeType(codeType);
}

void PasswordControl::changeLength(int length)
{
    if (lengthSlider->value() == length && lengthSpinBox->value() == length)
        return;
    lengthSlider->setValue(length);
    lengthSpinBox->setValue(length);
    emit lengthChanged(length);
}

void PasswordControl::changeType(int codeType, bool checked)
{
    if (checked) {
        codeTypeButtons->button(codeType)->setChecked(true);
        emit typeChanged(static_cast<CodeType>(codeType));
    }
}
