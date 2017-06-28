#ifndef WORDSEPVIEW_H
#define WORDSEPVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "password.h"

class WordSepView : public QWidget
{
    Q_OBJECT
public:
    explicit WordSepView(QWidget *parent = nullptr);
public slots:
    void displayPassword(const Password &password);
private:
    QHBoxLayout *hBox;
    QVector<QLabel*> words;
    void clear();
};

#endif // WORDSEPVIEW_H
