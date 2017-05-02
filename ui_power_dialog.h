/********************************************************************************
** Form generated from reading UI file 'power_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWER_DIALOG_H
#define UI_POWER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_dial.h"
#include "qwt_plot.h"
#include "qwt_thermo.h"

QT_BEGIN_NAMESPACE

class Ui_PowerDialog
{
public:
    QwtDial *Dial;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QwtThermo *Thermo;
    QwtPlot *qwtPlot;

    void setupUi(QDialog *PowerDialog)
    {
        if (PowerDialog->objectName().isEmpty())
            PowerDialog->setObjectName(QStringLiteral("PowerDialog"));
        PowerDialog->resize(640, 480);
        Dial = new QwtDial(PowerDialog);
        Dial->setObjectName(QStringLiteral("Dial"));
        Dial->setEnabled(true);
        Dial->setGeometry(QRect(30, 300, 158, 144));
        Dial->setValue(51);
        Dial->setStepAlignment(false);
        Dial->setReadOnly(false);
        Dial->setTracking(true);
        Dial->setWrapping(true);
        Dial->setInvertedControls(true);
        Dial->setLineWidth(2);
        Dial->setFrameShadow(QwtDial::Sunken);
        Dial->setMode(QwtDial::RotateNeedle);
        Dial->setOrigin(120);
        Dial->setMaxScaleArc(240);
        widget = new QWidget(PowerDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 21, 601, 234));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);

        Thermo = new QwtThermo(widget);
        Thermo->setObjectName(QStringLiteral("Thermo"));
        Thermo->setUpperBound(10);

        horizontalLayout->addWidget(Thermo);

        qwtPlot = new QwtPlot(widget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));

        horizontalLayout->addWidget(qwtPlot);


        retranslateUi(PowerDialog);

        QMetaObject::connectSlotsByName(PowerDialog);
    } // setupUi

    void retranslateUi(QDialog *PowerDialog)
    {
        PowerDialog->setWindowTitle(QApplication::translate("PowerDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PowerDialog: public Ui_PowerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWER_DIALOG_H
