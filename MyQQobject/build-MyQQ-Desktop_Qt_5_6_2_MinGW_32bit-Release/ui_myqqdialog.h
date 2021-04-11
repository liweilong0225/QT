/********************************************************************************
** Form generated from reading UI file 'myqqdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQQDIALOG_H
#define UI_MYQQDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyQQDialog
{
public:
    QPushButton *pb_test;

    void setupUi(QDialog *MyQQDialog)
    {
        if (MyQQDialog->objectName().isEmpty())
            MyQQDialog->setObjectName(QStringLiteral("MyQQDialog"));
        MyQQDialog->resize(400, 300);
        pb_test = new QPushButton(MyQQDialog);
        pb_test->setObjectName(QStringLiteral("pb_test"));
        pb_test->setGeometry(QRect(150, 100, 75, 23));

        retranslateUi(MyQQDialog);

        QMetaObject::connectSlotsByName(MyQQDialog);
    } // setupUi

    void retranslateUi(QDialog *MyQQDialog)
    {
        MyQQDialog->setWindowTitle(QApplication::translate("MyQQDialog", "MyQQDialog", 0));
        pb_test->setText(QApplication::translate("MyQQDialog", "\346\265\213\350\257\225", 0));
    } // retranslateUi

};

namespace Ui {
    class MyQQDialog: public Ui_MyQQDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQQDIALOG_H
