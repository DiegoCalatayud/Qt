/********************************************************************************
** Form generated from reading UI file 'DialogoDesigner.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGODESIGNER_H
#define UI_DIALOGODESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogoDesigner
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *botonIncrementar;
    QPushButton *botonDecrementar;
    QGroupBox *groupBox;
    QRadioButton *rbUnidades;
    QRadioButton *rbDecenas;
    QSpinBox *spinBoxCantidad;

    void setupUi(QDialog *DialogoDesigner)
    {
        if (DialogoDesigner->objectName().isEmpty())
            DialogoDesigner->setObjectName(QString::fromUtf8("DialogoDesigner"));
        DialogoDesigner->resize(605, 484);
        buttonBox = new QDialogButtonBox(DialogoDesigner);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(240, 440, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        botonIncrementar = new QPushButton(DialogoDesigner);
        botonIncrementar->setObjectName(QString::fromUtf8("botonIncrementar"));
        botonIncrementar->setGeometry(QRect(40, 40, 89, 25));
        botonDecrementar = new QPushButton(DialogoDesigner);
        botonDecrementar->setObjectName(QString::fromUtf8("botonDecrementar"));
        botonDecrementar->setGeometry(QRect(230, 40, 89, 25));
        groupBox = new QGroupBox(DialogoDesigner);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 100, 120, 141));
        rbUnidades = new QRadioButton(groupBox);
        rbUnidades->setObjectName(QString::fromUtf8("rbUnidades"));
        rbUnidades->setGeometry(QRect(20, 40, 112, 23));
        rbDecenas = new QRadioButton(groupBox);
        rbDecenas->setObjectName(QString::fromUtf8("rbDecenas"));
        rbDecenas->setGeometry(QRect(20, 70, 112, 23));
        spinBoxCantidad = new QSpinBox(DialogoDesigner);
        spinBoxCantidad->setObjectName(QString::fromUtf8("spinBoxCantidad"));
        spinBoxCantidad->setGeometry(QRect(210, 160, 131, 26));

        retranslateUi(DialogoDesigner);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoDesigner, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoDesigner, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoDesigner);
    } // setupUi

    void retranslateUi(QDialog *DialogoDesigner)
    {
        DialogoDesigner->setWindowTitle(QCoreApplication::translate("DialogoDesigner", "Dialog", nullptr));
        botonIncrementar->setText(QCoreApplication::translate("DialogoDesigner", "Incrementar", nullptr));
        botonDecrementar->setText(QCoreApplication::translate("DialogoDesigner", "Decrementar", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogoDesigner", "Incrementos", nullptr));
        rbUnidades->setText(QCoreApplication::translate("DialogoDesigner", "Unidades", nullptr));
        rbDecenas->setText(QCoreApplication::translate("DialogoDesigner", "Decenas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoDesigner: public Ui_DialogoDesigner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGODESIGNER_H
