#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QObject>
#include "password.h"

class PasswordGenerator : public QObject
{
    Q_OBJECT
public:
    explicit PasswordGenerator(QObject *parent = nullptr);
public slots:
    void generatePassword();
    void setLength(int length);
    void setType(CodeType codeType);
signals:
    void passwordChanged(const Password &password);
private:
    int length = 6;             // initialization value not important
    CodeType codeType = wubi;   // initialization value not important
private:
    Password password;
    bool sodiumFailed;

};

#endif // PASSWORDGENERATOR_H
