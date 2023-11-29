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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QCheckBox *checkBox;

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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(DBuscar);

        QMetaObject::connectSlotsByName(DBuscar);
    } // setupUi

    void retranslateUi(QDialog *DBuscar)
    {
        DBuscar->setWindowTitle(QCoreApplication::translate("DBuscar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DBuscar", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("DBuscar", "Buscar", nullptr));
        checkBox->setText(QCoreApplication::translate("DBuscar", "GoBack", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBuscar: public Ui_DBuscar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBUSCAR_H
