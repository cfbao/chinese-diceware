#include "passwordview.h"
#include <QSizePolicy>
#include <QFontMetrics>
#include <QStringList>

PasswordView::PasswordView(QWidget *parent) : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    setTextInteractionFlags(Qt::TextSelectableByMouse);
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Sunken);
}

void PasswordView::displayPassword(const Password &password)
{
    if (password.size() == 0) {
        setText("libsodium 初始化失败\n"
                "无法生成安全的密码……");
        return;
    }
    QStringList codeList, zhList;
    for (auto iter = password.begin(); iter != password.end(); ++iter) {
        codeList.append(iter->first);
        zhList.append(iter->second);
    }
    setText(codeList.join("") + "\n" +
            codeList.join(" ") + "\n" +
            codeList.join("-") + "\n" +
            zhList.join("-"));
}
