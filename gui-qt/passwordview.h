#ifndef PASSWORDVIEW_H
#define PASSWORDVIEW_H
#include <QLabel>
#include "password.h"

class PasswordView : public QLabel
{
    Q_OBJECT
public:
    PasswordView(QWidget* parent=nullptr);
public slots:
    void displayPassword(const Password &password);
};

#endif // PASSWORDVIEW_H
