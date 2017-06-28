#ifndef ENTROPYVIEW_H
#define ENTROPYVIEW_H

#include <QLabel>
#include "password.h"

class EntropyView : public QLabel
{
    Q_OBJECT
public:
    explicit EntropyView(QWidget *parent = nullptr);
private:
    int length = 0;
signals:

public slots:
    void displayEntInfo(const Password &password);
};

#endif // ENTROPYVIEW_H
