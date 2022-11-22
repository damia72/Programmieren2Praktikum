
#include <QListWidgetItem>
#include "flightbooking.h"
#include "upandaway.h"
#include "ui_upandaway.h"
#include <QFileDialog>
#include <travelagency.h>
#include <QMessageBox>
#include "rentalcarreservation.h"
#include "hotelbooking.h"
UpAndAway::UpAndAway(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UpAndAway)
{
    ui->setupUi(this);
    ui->spinBox->setEnabled(false);
    ui->fromDestinationLineEdit->setEnabled(false);
    ui->toDestinationLineEdit->setEnabled(false);
    ui->hotelLineEdit->setEnabled(false);
    ui->companyLineEdit->setEnabled(false);
    ui->townLineEdit->setEnabled(false);
    ui->pickupStationLineEdit->setEnabled(false);
    ui->returnStationLineEdit->setEnabled(false);
    ui->fromDateEdit->setEnabled(false);
    ui->toDateEdit->setEnabled(false);
    ui->priceSpinBox->setEnabled(false);
}

UpAndAway::~UpAndAway()
{
    delete ui;
}


void UpAndAway::on_readFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Bitte Datei auswählen", "");
    try{
        travelagency.readfile(fileName.toStdString(),this);
    }catch(std::runtime_error i){
        QString fehler = i.what();
        QMessageBox::critical(this, "Einlesen fehlgeschlagen!", "Das einlesen ist Fehlgeschlagen folgender Fehler"
                                                                " wurde entdeckt: " + fehler );
    }
    for(unsigned int i = 0; i < travelagency.booking.size(); i++){
        ui->listWidget->addItem(QString::fromStdString(travelagency.booking[i]->showDetails()));
    }

}


void UpAndAway::on_idInputSpinBox_valueChanged(int arg1)
{
    selectedId = arg1;
    selectedBookingVectorLocation = travelagency.suche(selectedId);
   for(int i = 0; i < ui->listWidget->count(); i++){
        QRegularExpression sucheErsteZahl("\\d+");
        QStringList textListe = sucheErsteZahl.match(ui->listWidget->item(i)->text()).capturedTexts();
        if(textListe[0].toInt() == arg1){
            ui->listWidget->item(i)->setSelected(true);
            on_listWidget_itemDoubleClicked(ui->listWidget->item(i));
        }
    }
    int stelleImVektor = travelagency.suche(arg1);
    if(stelleImVektor >= 0){
        ui->textBrowser->setText(QString::fromStdString(travelagency.booking[stelleImVektor]->showDetails()));
    }else if (stelleImVektor == -1){
        ui->textBrowser->setText("Buchung Existiert nicht");
    }else{
        ui->textBrowser->setText("Unerwarteter Fehler in der Suche der Buchung");
    }
}


void UpAndAway::on_listWidget_itemClicked(QListWidgetItem *item)
{

}


void UpAndAway::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //schauen was angeklickt wurde
    QString info = item->text();
    //suche nach der ID
    QRegularExpression sucheErsteZahl("\\d+");
    QStringList textListe = sucheErsteZahl.match(info).capturedTexts();
    int id = textListe[0].toInt();
    selectedId = id;
    unsigned int stelleImVektor= travelagency.suche(id);
    selectedBookingVectorLocation = stelleImVektor;
    ui->spinBox->setValue(id);
    ui->fromDateEdit->setDate(travelagency.booking[stelleImVektor]->getFromQDate());
    ui->fromDateEdit->setEnabled(true);
    ui->toDateEdit->setDate(travelagency.booking[stelleImVektor]->getToQdate());
    ui->toDateEdit->setEnabled(true);
    ui->priceSpinBox->setValue(travelagency.booking[stelleImVektor]->getPrice());
    ui->priceSpinBox->setEnabled(true);
    if(info.split(' ')[0] == "Flugbuchung"){
        ui->fromDestinationLineEdit->setEnabled(true);
        ui->toDestinationLineEdit->setEnabled(true);
        ui->companyLineEdit->setEnabled(true);
        ui->pickupStationLineEdit->setEnabled(false);
        ui->returnStationLineEdit->setEnabled(false);
        ui->hotelLineEdit->setEnabled(false);
        ui->townLineEdit->setEnabled(false);
        ui->fromDestinationLineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getFromDestination()));
        ui->toDestinationLineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getToDestination()));
        ui->companyLineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getAirline()));
    }else if(info.split(' ')[0]== "Mietwagenreservierung"){
        ui->fromDestinationLineEdit->setEnabled(false);
        ui->toDestinationLineEdit->setEnabled(false);
        ui->companyLineEdit->setEnabled(true);
        ui->pickupStationLineEdit->setEnabled(true);
        ui->returnStationLineEdit->setEnabled(true);
        ui->hotelLineEdit->setEnabled(false);
        ui->townLineEdit->setEnabled(false);
        ui->pickupStationLineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getPickupLocation()));
        ui->returnStationLineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getReturnLocation()));
        ui->companyLineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getCompany()));
    }else if(info.split(' ')[0] == "Hotelreservierung"){
        ui->fromDestinationLineEdit->setEnabled(false);
        ui->toDestinationLineEdit->setEnabled(false);
        ui->companyLineEdit->setEnabled(false);
        ui->pickupStationLineEdit->setEnabled(false);
        ui->returnStationLineEdit->setEnabled(false);
        ui->hotelLineEdit->setEnabled(true);
        ui->townLineEdit->setEnabled(true);
        ui->hotelLineEdit->setText(QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency.booking[stelleImVektor])->getHotel()));
        ui->townLineEdit->setText(QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency.booking[stelleImVektor])->getTown()));
    }
    ui->idInputSpinBox->setValue(id);
}


void UpAndAway::on_JSONErstellenButton_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "Bitte pfad auswählen", "", "*.json");
    travelagency.createJSON(path);
}


void UpAndAway::on_fromDateEdit_userDateChanged(const QDate &date)
{
    travelagency.booking[selectedBookingVectorLocation]->setFromQDate(date);
    //Widgetliste aktualisieren
    //Attributliste aktualisieren
}

