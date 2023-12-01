/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QVBoxLayout *verticalLayout_2;
    QLineEdit *display;
    QHBoxLayout *horizontalLayout;
    QGridLayout *layoutbotones;
    QPushButton *pushButton_6;
    QPushButton *boton2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *boton1;
    QPushButton *boton3;
    QPushButton *pushButton_11;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *boton0;
    QVBoxLayout *verticalLayout;
    QPushButton *botonmas;
    QPushButton *botonigual;

    void setupUi(QDialog *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QString::fromUtf8("Calculadora"));
        Calculadora->resize(362, 171);
        verticalLayout_2 = new QVBoxLayout(Calculadora);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        display = new QLineEdit(Calculadora);
        display->setObjectName(QString::fromUtf8("display"));

        verticalLayout_2->addWidget(display);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        layoutbotones = new QGridLayout();
        layoutbotones->setObjectName(QString::fromUtf8("layoutbotones"));
        pushButton_6 = new QPushButton(Calculadora);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        layoutbotones->addWidget(pushButton_6, 1, 2, 1, 1);

        boton2 = new QPushButton(Calculadora);
        boton2->setObjectName(QString::fromUtf8("boton2"));

        layoutbotones->addWidget(boton2, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(Calculadora);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        layoutbotones->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(Calculadora);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        layoutbotones->addWidget(pushButton_3, 0, 0, 1, 1);

        boton1 = new QPushButton(Calculadora);
        boton1->setObjectName(QString::fromUtf8("boton1"));

        layoutbotones->addWidget(boton1, 2, 0, 1, 1);

        boton3 = new QPushButton(Calculadora);
        boton3->setObjectName(QString::fromUtf8("boton3"));

        layoutbotones->addWidget(boton3, 2, 2, 1, 1);

        pushButton_11 = new QPushButton(Calculadora);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        layoutbotones->addWidget(pushButton_11, 4, 2, 1, 1);

        pushButton = new QPushButton(Calculadora);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        layoutbotones->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(Calculadora);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        layoutbotones->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(Calculadora);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        layoutbotones->addWidget(pushButton_5, 1, 1, 1, 1);

        boton0 = new QPushButton(Calculadora);
        boton0->setObjectName(QString::fromUtf8("boton0"));

        layoutbotones->addWidget(boton0, 4, 1, 1, 1);


        horizontalLayout->addLayout(layoutbotones);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        botonmas = new QPushButton(Calculadora);
        botonmas->setObjectName(QString::fromUtf8("botonmas"));

        verticalLayout->addWidget(botonmas);

        botonigual = new QPushButton(Calculadora);
        botonigual->setObjectName(QString::fromUtf8("botonigual"));

        verticalLayout->addWidget(botonigual);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QDialog *Calculadora)
    {
        Calculadora->setWindowTitle(QCoreApplication::translate("Calculadora", "Dialog", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Calculadora", "6", nullptr));
        boton2->setText(QCoreApplication::translate("Calculadora", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Calculadora", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Calculadora", "7", nullptr));
        boton1->setText(QCoreApplication::translate("Calculadora", "1", nullptr));
        boton3->setText(QCoreApplication::translate("Calculadora", "3", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Calculadora", ".", nullptr));
        pushButton->setText(QCoreApplication::translate("Calculadora", "8", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Calculadora", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Calculadora", "5", nullptr));
        boton0->setText(QCoreApplication::translate("Calculadora", "0", nullptr));
        botonmas->setText(QCoreApplication::translate("Calculadora", "+", nullptr));
        botonigual->setText(QCoreApplication::translate("Calculadora", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
