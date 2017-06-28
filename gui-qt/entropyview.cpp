#include "entropyview.h"
#include <cmath>

EntropyView::EntropyView(QWidget *parent) : QLabel(parent)
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
}

void EntropyView::displayEntInfo(const Password &password)
{
    if (length == password.size()) return;
    length = password.size();
    if (length == 0) {
        setText("");
        return;
    }
    int entropy = 13 * length;
    setText(QString::fromUtf8("密码强度： %L1 bits").arg(entropy,3));
}
