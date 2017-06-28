#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "passwordcontrol.h"
#include "passwordview.h"
#include "wordsepview.h"
#include "passwordgenerator.h"
#include "entropyview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    QWidget *centralWidget;
    QVBoxLayout *vBox;
    PasswordControl *pwdControl;
    WordSepView *wordSepView;
    PasswordView *pwdView;
    EntropyView *entropyView;
private:
    PasswordGenerator *pwdGen;
};

#endif // MAINWINDOW_H
