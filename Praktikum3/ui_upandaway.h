/********************************************************************************
** Form generated from reading UI file 'upandaway.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPANDAWAY_H
#define UI_UPANDAWAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpAndAway
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox;
    QDateEdit *fromDateEdit;
    QDateEdit *toDateEdit;
    QDoubleSpinBox *priceSpinBox;
    QLineEdit *fromDestinationLineEdit;
    QLineEdit *toDestinationLineEdit;
    QLineEdit *companyLineEdit;
    QLineEdit *hotelLineEdit;
    QLineEdit *townLineEdit;
    QLineEdit *pickupStationLineEdit;
    QLineEdit *returnStationLineEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *readFileButton;
    QPushButton *JSONErstellenButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QSpinBox *idInputSpinBox;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UpAndAway)
    {
        if (UpAndAway->objectName().isEmpty())
            UpAndAway->setObjectName(QString::fromUtf8("UpAndAway"));
        UpAndAway->resize(952, 462);
        centralwidget = new QWidget(UpAndAway);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(310, 10, 371, 401));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(690, 20, 241, 391));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 208, 332));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout_2->addWidget(spinBox);

        fromDateEdit = new QDateEdit(layoutWidget);
        fromDateEdit->setObjectName(QString::fromUtf8("fromDateEdit"));

        verticalLayout_2->addWidget(fromDateEdit);

        toDateEdit = new QDateEdit(layoutWidget);
        toDateEdit->setObjectName(QString::fromUtf8("toDateEdit"));

        verticalLayout_2->addWidget(toDateEdit);

        priceSpinBox = new QDoubleSpinBox(layoutWidget);
        priceSpinBox->setObjectName(QString::fromUtf8("priceSpinBox"));
        priceSpinBox->setMaximum(9999999.000000000000000);

        verticalLayout_2->addWidget(priceSpinBox);

        fromDestinationLineEdit = new QLineEdit(layoutWidget);
        fromDestinationLineEdit->setObjectName(QString::fromUtf8("fromDestinationLineEdit"));

        verticalLayout_2->addWidget(fromDestinationLineEdit);

        toDestinationLineEdit = new QLineEdit(layoutWidget);
        toDestinationLineEdit->setObjectName(QString::fromUtf8("toDestinationLineEdit"));

        verticalLayout_2->addWidget(toDestinationLineEdit);

        companyLineEdit = new QLineEdit(layoutWidget);
        companyLineEdit->setObjectName(QString::fromUtf8("companyLineEdit"));

        verticalLayout_2->addWidget(companyLineEdit);

        hotelLineEdit = new QLineEdit(layoutWidget);
        hotelLineEdit->setObjectName(QString::fromUtf8("hotelLineEdit"));

        verticalLayout_2->addWidget(hotelLineEdit);

        townLineEdit = new QLineEdit(layoutWidget);
        townLineEdit->setObjectName(QString::fromUtf8("townLineEdit"));

        verticalLayout_2->addWidget(townLineEdit);

        pickupStationLineEdit = new QLineEdit(layoutWidget);
        pickupStationLineEdit->setObjectName(QString::fromUtf8("pickupStationLineEdit"));

        verticalLayout_2->addWidget(pickupStationLineEdit);

        returnStationLineEdit = new QLineEdit(layoutWidget);
        returnStationLineEdit->setObjectName(QString::fromUtf8("returnStationLineEdit"));

        verticalLayout_2->addWidget(returnStationLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 282, 401));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        readFileButton = new QPushButton(groupBox);
        readFileButton->setObjectName(QString::fromUtf8("readFileButton"));

        verticalLayout_3->addWidget(readFileButton);

        JSONErstellenButton = new QPushButton(groupBox);
        JSONErstellenButton->setObjectName(QString::fromUtf8("JSONErstellenButton"));

        verticalLayout_3->addWidget(JSONErstellenButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(81, 16));

        verticalLayout_5->addWidget(label);

        idInputSpinBox = new QSpinBox(groupBox_2);
        idInputSpinBox->setObjectName(QString::fromUtf8("idInputSpinBox"));
        idInputSpinBox->setMinimumSize(QSize(81, 25));
        idInputSpinBox->setMaximum(1234567);

        verticalLayout_5->addWidget(idInputSpinBox);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(81, 101));

        verticalLayout_5->addWidget(textBrowser);


        verticalLayout_6->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        UpAndAway->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UpAndAway);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 21));
        UpAndAway->setMenuBar(menubar);
        statusbar = new QStatusBar(UpAndAway);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UpAndAway->setStatusBar(statusbar);

        retranslateUi(UpAndAway);

        QMetaObject::connectSlotsByName(UpAndAway);
    } // setupUi

    void retranslateUi(QMainWindow *UpAndAway)
    {
        UpAndAway->setWindowTitle(QCoreApplication::translate("UpAndAway", "UpAndAway", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("UpAndAway", "Daten \303\244ndern", nullptr));
        label_2->setText(QCoreApplication::translate("UpAndAway", "Id", nullptr));
        label_3->setText(QCoreApplication::translate("UpAndAway", "Startdatum", nullptr));
        label_4->setText(QCoreApplication::translate("UpAndAway", "Enddatum", nullptr));
        label_5->setText(QCoreApplication::translate("UpAndAway", "Preis", nullptr));
        label_6->setText(QCoreApplication::translate("UpAndAway", "Startflughafen", nullptr));
        label_7->setText(QCoreApplication::translate("UpAndAway", "Zielflughafen", nullptr));
        label_8->setText(QCoreApplication::translate("UpAndAway", "Firma", nullptr));
        label_9->setText(QCoreApplication::translate("UpAndAway", "Hotel", nullptr));
        label_10->setText(QCoreApplication::translate("UpAndAway", "Stadt", nullptr));
        label_11->setText(QCoreApplication::translate("UpAndAway", "Abholstation", nullptr));
        label_12->setText(QCoreApplication::translate("UpAndAway", "R\303\274ckgabestation", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UpAndAway", "Datei", nullptr));
        readFileButton->setText(QCoreApplication::translate("UpAndAway", "Datei einlesen", nullptr));
        JSONErstellenButton->setText(QCoreApplication::translate("UpAndAway", "JSON erstellen", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("UpAndAway", "Suche \303\274ber ID", nullptr));
        label->setText(QCoreApplication::translate("UpAndAway", "ID eingeben:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpAndAway: public Ui_UpAndAway {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPANDAWAY_H
