#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("五笔/拼音 密码生成器");
    centralWidget = new QWidget(this);
    vBox = new QVBoxLayout(centralWidget);

    pwdControl = new PasswordControl();
    pwdGen = new PasswordGenerator(this);
    wordSepView = new WordSepView();
    pwdView = new PasswordView();
    entropyView = new EntropyView();

    connect(pwdControl, &PasswordControl::lengthChanged, pwdGen, &PasswordGenerator::setLength);
    connect(pwdControl, &PasswordControl::typeChanged,   pwdGen, &PasswordGenerator::setType);
    connect(pwdControl, &PasswordControl::request,     pwdGen, &PasswordGenerator::generatePassword);
    connect(pwdGen, &PasswordGenerator::passwordChanged, pwdView, &PasswordView::displayPassword);
    connect(pwdGen, &PasswordGenerator::passwordChanged, wordSepView, &WordSepView::displayPassword);
    connect(pwdGen, &PasswordGenerator::passwordChanged, entropyView, &EntropyView::displayEntInfo);

    vBox->addWidget(pwdControl,0,Qt::AlignCenter);
    vBox->addWidget(wordSepView);
    vBox->addWidget(pwdView);
    vBox->addWidget(entropyView);
    setCentralWidget(centralWidget);

    pwdControl->setDefault();
    pwdGen->generatePassword();
    adjustSize();
    setFixedHeight(height());
}
