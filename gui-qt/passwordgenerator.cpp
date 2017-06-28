extern "C" {
    #include "sodium.h"
}
#include "passwordgenerator.h"

PasswordGenerator::PasswordGenerator(QObject *parent) : QObject(parent)
{
    if (sodium_init() < 0) {
        sodiumFailed = true;
    } else {
        sodiumFailed = false;
    }
}

void PasswordGenerator::generatePassword()
{
    if (sodiumFailed && sodium_init()<0) {
        emit passwordChanged(Password());
        return;
    }
    const std::pair<QString,QString> *list;
    if (codeType == wubi) {
        list = wubiWordList;
    } else if (codeType == pinyin) {
        list = pinyinWordList;
    }
    password.resize(length);
    for (auto iter = password.begin(); iter != password.end(); ++iter) {
        *iter = list[randombytes_uniform(8192)];
    }
    emit passwordChanged(password);
}

void PasswordGenerator::setLength(int length)
{
    if (this->length == length)
        return;
    this->length = length;
    generatePassword();
}

void PasswordGenerator::setType(CodeType codeType)
{
    if (this->codeType == codeType)
        return;
    this->codeType = codeType;
    generatePassword();
}
