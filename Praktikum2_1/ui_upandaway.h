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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpAndAway
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *JSONErstellenButton;
    QPushButton *readFileButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QSpinBox *idInputSpinBox;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_13;
    QSpinBox *spinBox_2;
    QTableWidget *travelTableWidget;
    QTableWidget *travelBookingsTableWidget;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UpAndAway)
    {
        if (UpAndAway->objectName().isEmpty())
            UpAndAway->setObjectName(QString::fromUtf8("UpAndAway"));
        UpAndAway->resize(1241, 465);
        centralwidget = new QWidget(UpAndAway);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        JSONErstellenButton = new QPushButton(groupBox);
        JSONErstellenButton->setObjectName(QString::fromUtf8("JSONErstellenButton"));

        verticalLayout_3->addWidget(JSONErstellenButton);

        readFileButton = new QPushButton(groupBox);
        readFileButton->setObjectName(QString::fromUtf8("readFileButton"));

        verticalLayout_3->addWidget(readFileButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(159, 288));
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
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(135, 192));
        textBrowser->setMaximumSize(QSize(135, 192));

        verticalLayout_5->addWidget(textBrowser);


        verticalLayout_6->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_6);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_7->addWidget(label_13);

        spinBox_2 = new QSpinBox(groupBox_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        verticalLayout_7->addWidget(spinBox_2);

        travelTableWidget = new QTableWidget(groupBox_4);
        if (travelTableWidget->columnCount() < 3)
            travelTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        travelTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        travelTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        travelTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        travelTableWidget->setObjectName(QString::fromUtf8("travelTableWidget"));
        travelTableWidget->setMinimumSize(QSize(400, 141));
        travelTableWidget->setMaximumSize(QSize(200, 141));
        travelTableWidget->setAutoFillBackground(true);
        travelTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        travelTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        travelTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        travelTableWidget->setSortingEnabled(true);
        travelTableWidget->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(travelTableWidget);

        travelBookingsTableWidget = new QTableWidget(groupBox_4);
        if (travelBookingsTableWidget->columnCount() < 4)
            travelBookingsTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        travelBookingsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        travelBookingsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        travelBookingsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        travelBookingsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        travelBookingsTableWidget->setObjectName(QString::fromUtf8("travelBookingsTableWidget"));
        travelBookingsTableWidget->setMinimumSize(QSize(400, 161));
        travelBookingsTableWidget->setMaximumSize(QSize(200, 161));
        travelBookingsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        travelBookingsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        travelBookingsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        travelBookingsTableWidget->setSortingEnabled(true);
        travelBookingsTableWidget->horizontalHeader()->setVisible(true);
        travelBookingsTableWidget->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(travelBookingsTableWidget);


        horizontalLayout_2->addWidget(groupBox_4);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(241, 391));
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


        horizontalLayout_2->addWidget(groupBox_3);

        UpAndAway->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UpAndAway);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1241, 21));
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
        groupBox->setTitle(QCoreApplication::translate("UpAndAway", "Datei", nullptr));
        JSONErstellenButton->setText(QCoreApplication::translate("UpAndAway", "JSON erstellen", nullptr));
        readFileButton->setText(QCoreApplication::translate("UpAndAway", "Datei einlesen", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("UpAndAway", "Suche \303\274ber Buchungs-ID", nullptr));
        label->setText(QCoreApplication::translate("UpAndAway", "Buchungs-ID eingeben:", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("UpAndAway", "Suche \303\274ber Kunden-ID", nullptr));
        label_13->setText(QCoreApplication::translate("UpAndAway", "Kunden-ID eingeben:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = travelTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UpAndAway", "TId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = travelTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UpAndAway", "fromDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = travelTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UpAndAway", "toDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = travelBookingsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("UpAndAway", "BId", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = travelBookingsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("UpAndAway", "fromDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = travelBookingsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("UpAndAway", "toDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = travelBookingsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("UpAndAway", "price", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class UpAndAway: public Ui_UpAndAway {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPANDAWAY_H
