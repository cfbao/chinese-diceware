#ifndef PASSWORD_H
#define PASSWORD_H

#include <vector>
#include <utility>
#include <QString>

typedef std::pair<QString, QString> PasswordItem;
typedef std::vector<PasswordItem> Password;
enum CodeType {wubi, pinyin};
extern const PasswordItem wubiWordList[];
extern const PasswordItem pinyinWordList[];

#endif // PASSWORD_H
