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
    cleanEverything();
}

UpAndAway::~UpAndAway()
{
    delete ui;
}


void UpAndAway::on_readFileButton_clicked()
{
    cleanEverything();
    //hey wir wollen die eisbärn sehn whohoooo
    QString fileName = QFileDialog::getOpenFileName(this, "Bitte Datei auswählen", "");
    try{
        travelagency.readfile(fileName,this);
    }catch(std::runtime_error i){
        QString fehler = i.what();
        QMessageBox::critical(this, "Einlesen fehlgeschlagen!", "Das einlesen ist Fehlgeschlagen folgender Fehler"
                                                                " wurde entdeckt: " + fehler );
    }
    for(unsigned int i = 0; i < travelagency.allBookings.size(); i++){
        ui->listWidget->addItem(travelagency.allBookings[i]->showDetails());
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
        if(typeid(FlightBooking) == typeid(*(travelagency.allBookings[stelleImVektor]))){
            ui->textBrowser->setText("Typ: Flugbuchung\nID: "+ QString::number(travelagency.allBookings[stelleImVektor]->getId()) +
                                     "\nStartdatum: " + travelagency.allBookings[stelleImVektor]->getFromDate()
                                     +"\nEnddatum: " + travelagency.allBookings[stelleImVektor]->getToDate()+
                                     "\nPreis: " + QString::number(travelagency.allBookings[stelleImVektor]->getPrice(),'f',2)+
                                     "\nStartflughafen: " + dynamic_cast<FlightBooking*>(travelagency.allBookings[stelleImVektor])->getFromDestination()
                                     +"\nZielflughafen: " + dynamic_cast<FlightBooking*>(travelagency.allBookings[stelleImVektor])->getToDestination()+
                                     "\nFluggesellschaft: " +dynamic_cast<FlightBooking*>(travelagency.allBookings[stelleImVektor])->getAirline());
        }else if(typeid(RentalCarReservation) == typeid(*(travelagency.allBookings[stelleImVektor]))){
            ui->textBrowser->setText("Typ: Mietwagenreservierung\nID: "+ QString::number(travelagency.allBookings[stelleImVektor]->getId()) +
                                     "\nStartdatum: " + travelagency.allBookings[stelleImVektor]->getFromDate()
                                     +"\nEnddatum: " + travelagency.allBookings[stelleImVektor]->getToDate()+
                                     "\nPreis: " + QString::number(travelagency.allBookings[stelleImVektor]->getPrice(),'f',2)+
                                     "\nAbholstation: " + dynamic_cast<RentalCarReservation*>(travelagency.allBookings[stelleImVektor])->getPickupLocation()+
                                     "\nRückgabestation: " + dynamic_cast<RentalCarReservation*>(travelagency.allBookings[stelleImVektor])->getReturnLocation()+
                                     "\nFirma: " + dynamic_cast<RentalCarReservation*>(travelagency.allBookings[stelleImVektor])->getCompany());
        }else if(typeid(HotelBooking) == typeid(*(travelagency.allBookings[stelleImVektor]))){
            ui->textBrowser->setText("Typ: Hotelbuchung\nID: "+ QString::number(travelagency.allBookings[stelleImVektor]->getId()) +
                                     "\nStartdatum: " + travelagency.allBookings[stelleImVektor]->getFromDate()
                                     +"\nEnddatum: " + travelagency.allBookings[stelleImVektor]->getToDate()+
                                     "\nPreis: " + QString::number(travelagency.allBookings[stelleImVektor]->getPrice(),'f',2)+
                                     "\nHotel: " + dynamic_cast<HotelBooking*>(travelagency.allBookings[stelleImVektor])->getHotel()+
                                     "\nTown: " + dynamic_cast<HotelBooking*>(travelagency.allBookings[stelleImVektor])->getTown());
        }
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
    ui->fromDateEdit->setDate(travelagency.allBookings[stelleImVektor]->getFromQDate());
    ui->fromDateEdit->setEnabled(true);
    ui->toDateEdit->setDate(travelagency.allBookings[stelleImVektor]->getToQdate());
    ui->toDateEdit->setEnabled(true);
    ui->priceSpinBox->setValue(travelagency.allBookings[stelleImVektor]->getPrice());
    ui->priceSpinBox->setEnabled(true);
    if(info.split(' ')[0] == "Flugbuchung"){
        ui->fromDestinationLineEdit->setEnabled(true);
        ui->toDestinationLineEdit->setEnabled(true);
        ui->companyLineEdit->setEnabled(true);
        ui->pickupStationLineEdit->setEnabled(false);
        ui->pickupStationLineEdit->setText("");
        ui->returnStationLineEdit->setEnabled(false);
        ui->returnStationLineEdit->setText("");
        ui->hotelLineEdit->setEnabled(false);
        ui->hotelLineEdit->setText("");
        ui->townLineEdit->setEnabled(false);
        ui->townLineEdit->setText("");
        ui->fromDestinationLineEdit->setText(dynamic_cast<FlightBooking*>(travelagency.allBookings[stelleImVektor])->getFromDestination());
        ui->toDestinationLineEdit->setText(dynamic_cast<FlightBooking*>(travelagency.allBookings[stelleImVektor])->getToDestination());
        ui->companyLineEdit->setText(dynamic_cast<FlightBooking*>(travelagency.allBookings[stelleImVektor])->getAirline());
    }else if(info.split(' ')[0]== "Mietwagenreservierung"){
        ui->fromDestinationLineEdit->setEnabled(false);
        ui->fromDestinationLineEdit->setText("");
        ui->toDestinationLineEdit->setEnabled(false);
        ui->toDestinationLineEdit->setText("");
        ui->companyLineEdit->setEnabled(true);
        ui->pickupStationLineEdit->setEnabled(true);
        ui->returnStationLineEdit->setEnabled(true);
        ui->hotelLineEdit->setEnabled(false);
        ui->hotelLineEdit->setText("");
        ui->townLineEdit->setEnabled(false);
        ui->townLineEdit->setText("");
        ui->pickupStationLineEdit->setText(dynamic_cast<RentalCarReservation*>(travelagency.allBookings[stelleImVektor])->getPickupLocation());
        ui->returnStationLineEdit->setText(dynamic_cast<RentalCarReservation*>(travelagency.allBookings[stelleImVektor])->getReturnLocation());
        ui->companyLineEdit->setText(dynamic_cast<RentalCarReservation*>(travelagency.allBookings[stelleImVektor])->getCompany());
    }else if(info.split(' ')[0] == "Hotelreservierung"){
        ui->fromDestinationLineEdit->setEnabled(false);
        ui->fromDestinationLineEdit->setText("");
        ui->toDestinationLineEdit->setEnabled(false);
        ui->toDestinationLineEdit->setText("");
        ui->companyLineEdit->setEnabled(false);
        ui->companyLineEdit->setText("");
        ui->pickupStationLineEdit->setEnabled(false);
        ui->pickupStationLineEdit->setText("");
        ui->returnStationLineEdit->setEnabled(false);
        ui->returnStationLineEdit->setText("");
        ui->hotelLineEdit->setEnabled(true);
        ui->townLineEdit->setEnabled(true);
        ui->hotelLineEdit->setText(dynamic_cast<HotelBooking*>(travelagency.allBookings[stelleImVektor])->getHotel());
        ui->townLineEdit->setText(dynamic_cast<HotelBooking*>(travelagency.allBookings[stelleImVektor])->getTown());
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
    travelagency.allBookings[selectedBookingVectorLocation]->setFromQDate(date);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_toDateEdit_userDateChanged(const QDate &date)
{
    travelagency.allBookings[selectedBookingVectorLocation]->settoQDate(date);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_priceSpinBox_valueChanged(double arg1)
{
    travelagency.allBookings[selectedBookingVectorLocation]->setPrice(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren
    on_idInputSpinBox_valueChanged(selectedId);
}

void UpAndAway::on_fromDestinationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<FlightBooking*>(travelagency.allBookings[selectedBookingVectorLocation])->setFromDestination(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_toDestinationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<FlightBooking*>(travelagency.allBookings[selectedBookingVectorLocation])->setToDestination(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_companyLineEdit_textEdited(const QString &arg1)
{
    if(typeid(FlightBooking) == typeid(*(travelagency.allBookings[selectedBookingVectorLocation]))){
        dynamic_cast<FlightBooking*>(travelagency.allBookings[selectedBookingVectorLocation])->setAirline(arg1);
    }else if(typeid(RentalCarReservation) == typeid(*(travelagency.allBookings[selectedBookingVectorLocation]))){
        dynamic_cast<RentalCarReservation*>(travelagency.allBookings[selectedBookingVectorLocation])->setCompany(arg1);
    }
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_hotelLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<HotelBooking*>(travelagency.allBookings[selectedBookingVectorLocation])->setHotel(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_townLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<HotelBooking*>(travelagency.allBookings[selectedBookingVectorLocation])->setTown(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_pickupStationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<RentalCarReservation*>(travelagency.allBookings[selectedBookingVectorLocation])->setPickupLocation(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_returnStationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<RentalCarReservation*>(travelagency.allBookings[selectedBookingVectorLocation])->setReturnLocation(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(travelagency.allBookings[selectedBookingVectorLocation]->showDetails());

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}

void UpAndAway::cleanEverything()
{
    travelagency.cleanEverything();
    ui->listWidget->clear();
    ui->textBrowser->clear();
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

