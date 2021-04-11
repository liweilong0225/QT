/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QTabWidget *tw_page;
    QWidget *tab_1;
    QLabel *lb_name;
    QLabel *lb_password;
    QLineEdit *le_name;
    QLineEdit *le_password;
    QPushButton *pb_clear;
    QPushButton *pb_commit;
    QWidget *tab_2;
    QLabel *lb_register_name;
    QLabel *lb_register_password;
    QLineEdit *le_register_password;
    QLineEdit *le_register_name;
    QLabel *lb_register_confirm;
    QLineEdit *le_register_confirm;
    QPushButton *pb_register_commit;
    QPushButton *pb_register_clear;
    QLabel *lb_icon;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(572, 311);
        QFont font;
        font.setPointSize(12);
        loginDialog->setFont(font);
        tw_page = new QTabWidget(loginDialog);
        tw_page->setObjectName(QStringLiteral("tw_page"));
        tw_page->setGeometry(QRect(220, 10, 351, 301));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        lb_name = new QLabel(tab_1);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setGeometry(QRect(30, 30, 54, 30));
        lb_password = new QLabel(tab_1);
        lb_password->setObjectName(QStringLiteral("lb_password"));
        lb_password->setGeometry(QRect(40, 100, 41, 30));
        le_name = new QLineEdit(tab_1);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(90, 30, 231, 30));
        le_password = new QLineEdit(tab_1);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setGeometry(QRect(90, 100, 231, 30));
        le_password->setEchoMode(QLineEdit::Password);
        pb_clear = new QPushButton(tab_1);
        pb_clear->setObjectName(QStringLiteral("pb_clear"));
        pb_clear->setGeometry(QRect(140, 220, 75, 30));
        pb_commit = new QPushButton(tab_1);
        pb_commit->setObjectName(QStringLiteral("pb_commit"));
        pb_commit->setGeometry(QRect(240, 220, 75, 30));
        tw_page->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lb_register_name = new QLabel(tab_2);
        lb_register_name->setObjectName(QStringLiteral("lb_register_name"));
        lb_register_name->setGeometry(QRect(30, 30, 54, 30));
        lb_register_password = new QLabel(tab_2);
        lb_register_password->setObjectName(QStringLiteral("lb_register_password"));
        lb_register_password->setGeometry(QRect(40, 100, 41, 30));
        le_register_password = new QLineEdit(tab_2);
        le_register_password->setObjectName(QStringLiteral("le_register_password"));
        le_register_password->setGeometry(QRect(90, 100, 231, 30));
        le_register_password->setEchoMode(QLineEdit::Password);
        le_register_name = new QLineEdit(tab_2);
        le_register_name->setObjectName(QStringLiteral("le_register_name"));
        le_register_name->setGeometry(QRect(90, 30, 231, 30));
        lb_register_confirm = new QLabel(tab_2);
        lb_register_confirm->setObjectName(QStringLiteral("lb_register_confirm"));
        lb_register_confirm->setGeometry(QRect(10, 170, 71, 30));
        le_register_confirm = new QLineEdit(tab_2);
        le_register_confirm->setObjectName(QStringLiteral("le_register_confirm"));
        le_register_confirm->setGeometry(QRect(90, 170, 231, 30));
        le_register_confirm->setEchoMode(QLineEdit::Password);
        pb_register_commit = new QPushButton(tab_2);
        pb_register_commit->setObjectName(QStringLiteral("pb_register_commit"));
        pb_register_commit->setGeometry(QRect(240, 220, 75, 30));
        pb_register_clear = new QPushButton(tab_2);
        pb_register_clear->setObjectName(QStringLiteral("pb_register_clear"));
        pb_register_clear->setGeometry(QRect(140, 220, 75, 30));
        tw_page->addTab(tab_2, QString());
        lb_icon = new QLabel(loginDialog);
        lb_icon->setObjectName(QStringLiteral("lb_icon"));
        lb_icon->setGeometry(QRect(0, 10, 221, 301));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/tx/6.png")));
        lb_icon->setScaledContents(true);
        lb_icon->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(tw_page, le_name);
        QWidget::setTabOrder(le_name, le_password);
        QWidget::setTabOrder(le_password, pb_commit);
        QWidget::setTabOrder(pb_commit, pb_clear);
        QWidget::setTabOrder(pb_clear, le_register_name);
        QWidget::setTabOrder(le_register_name, le_register_password);
        QWidget::setTabOrder(le_register_password, le_register_confirm);
        QWidget::setTabOrder(le_register_confirm, pb_register_commit);
        QWidget::setTabOrder(pb_register_commit, pb_register_clear);

        retranslateUi(loginDialog);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", 0));
        lb_name->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        lb_password->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        le_name->setToolTip(QApplication::translate("loginDialog", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\357\274\214\351\225\277\345\272\246\344\270\215\350\266\205\350\277\20710\344\275\215", 0));
#endif // QT_NO_TOOLTIP
        pb_clear->setText(QApplication::translate("loginDialog", "\346\270\205\347\251\272", 0));
        pb_commit->setText(QApplication::translate("loginDialog", "\346\217\220\344\272\244", 0));
        tw_page->setTabText(tw_page->indexOf(tab_1), QApplication::translate("loginDialog", "\347\231\273\345\275\225", 0));
        lb_register_name->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        lb_register_password->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201\357\274\232", 0));
        lb_register_confirm->setText(QApplication::translate("loginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        pb_register_commit->setText(QApplication::translate("loginDialog", "\346\217\220\344\272\244", 0));
        pb_register_clear->setText(QApplication::translate("loginDialog", "\346\270\205\347\251\272", 0));
        tw_page->setTabText(tw_page->indexOf(tab_2), QApplication::translate("loginDialog", "\346\263\250\345\206\214", 0));
        lb_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
