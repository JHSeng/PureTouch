/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *labTitle;
    QLabel *labWriter;
    QPushButton *btnOK;
    QLabel *labGithub;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(431, 285);
        labTitle = new QLabel(About);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setGeometry(QRect(140, 10, 161, 81));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Light"));
        font.setPointSize(26);
        labTitle->setFont(font);
        labWriter = new QLabel(About);
        labWriter->setObjectName(QStringLiteral("labWriter"));
        labWriter->setGeometry(QRect(170, 90, 91, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Light"));
        font1.setPointSize(14);
        labWriter->setFont(font1);
        btnOK = new QPushButton(About);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(160, 220, 111, 41));
        btnOK->setFont(font1);
        labGithub = new QLabel(About);
        labGithub->setObjectName(QStringLiteral("labGithub"));
        labGithub->setGeometry(QRect(120, 140, 251, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI Light"));
        font2.setPointSize(13);
        labGithub->setFont(font2);

        retranslateUi(About);
        QObject::connect(btnOK, SIGNAL(clicked()), About, SLOT(close()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Dialog", nullptr));
        labTitle->setText(QApplication::translate("About", "PureTouch", nullptr));
        labWriter->setText(QApplication::translate("About", "by JHSeng", nullptr));
        btnOK->setText(QApplication::translate("About", "OK", nullptr));
        labGithub->setText(QApplication::translate("About", "<html><head/><body><p><a href=\"https://github.com/JHSeng/PureTouch\"><span style=\" text-decoration: underline; color:#007af4;\">\346\254\242\350\277\216\350\256\277\351\227\256\350\257\245\351\241\271\347\233\256\347\232\204Github\347\275\221\345\235\200</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
