#include "wordsepview.h"

WordSepView::WordSepView(QWidget *parent) : QWidget(parent)
{
    hBox = new QHBoxLayout(this);
    hBox->setSpacing(fontMetrics().width("--"));
    hBox->setContentsMargins(0,0,0,0);
    setMinimumHeight(hBox->contentsMargins().top()+hBox->contentsMargins().bottom()+2*fontMetrics().lineSpacing());
    setMaximumHeight(hBox->contentsMargins().top()+hBox->contentsMargins().bottom()+2*fontMetrics().lineSpacing());
}

void WordSepView::displayPassword(const Password &password)
{
    if (password.size() == 0) {
        clear();
        return;
    }
    if (password.size() != words.size()) {
        clear();
        hBox->addStretch();
        for (auto iter = password.begin(); iter != password.end(); ++iter) {
            auto label = new QLabel(iter->first+"\n"+iter->second);
            label->setAlignment(Qt::AlignCenter);
            words.append(label);
            hBox->addWidget(label, 0, Qt::AlignCenter);
        }
        hBox->addStretch();
    } else {
        for (int i = 0; i<password.size(); ++i) {
            words[i]->setText(password[i].first+"\n"+password[i].second);
        }
    }
}

void WordSepView::clear()
{
    while (auto item = hBox->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    words.clear();
}
