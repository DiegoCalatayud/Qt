/********************************************************************************
** Form generated from reading UI file 'dbuscar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBUSCAR_H
#define UI_DBUSCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBuscar
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *DBuscar)
    {
        if (DBuscar->objectName().isEmpty())
            DBuscar->setObjectName(QString::fromUtf8("DBuscar"));
        DBuscar->resize(417, 298);
        horizontalLayoutWidget = new QWidget(DBuscar);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 271));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(DBuscar);

        QMetaObject::connectSlotsByName(DBuscar);
    } // setupUi

    void retranslateUi(QDialog *DBuscar)
    {
        DBuscar->setWindowTitle(QCoreApplication::translate("DBuscar", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DBuscar", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DBuscar", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBuscar: public Ui_DBuscar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBUSCAR_H
