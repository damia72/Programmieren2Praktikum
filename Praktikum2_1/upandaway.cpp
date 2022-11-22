
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
        if(typeid(FlightBooking) == typeid(*(travelagency.booking[stelleImVektor]))){
            ui->textBrowser->setText("Typ: Flugbuchung\nID: "+ QString::number(travelagency.booking[stelleImVektor]->getId()) +
                                     "\nStartdatum: " + QString::fromStdString(travelagency.booking[stelleImVektor]->getFromDate())
                                     +"\nEnddatum: " + QString::fromStdString(travelagency.booking[stelleImVektor]->getToDate())+
                                     "\nPreis: " + QString::number(travelagency.booking[stelleImVektor]->getPrice())+
                                     "\nStartflughafen: " + QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getFromDestination())
                                     +"\nZielflughafen: " + QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getToDestination())+
                                     "\nFluggesellschaft: " +QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getAirline()));
        }else if(typeid(RentalCarReservation) == typeid(*(travelagency.booking[stelleImVektor]))){
            ui->textBrowser->setText("Typ: Flugbuchung\nID: "+ QString::number(travelagency.booking[stelleImVektor]->getId()) +
                                     "\nStartdatum: " + QString::fromStdString(travelagency.booking[stelleImVektor]->getFromDate())
                                     +"\nEnddatum: " + QString::fromStdString(travelagency.booking[stelleImVektor]->getToDate())+
                                     "\nPreis: " + QString::number(travelagency.booking[stelleImVektor]->getPrice())+
                                     "\nAbholstation: " + QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getPickupLocation())+
                                     "\nRückgabestation: " + QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getReturnLocation())+
                                     "\nFirma: " + QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getCompany()));
        }else if(typeid(HotelBooking) == typeid(*(travelagency.booking[stelleImVektor]))){
            ui->textBrowser->setText("Typ: Flugbuchung\nID: "+ QString::number(travelagency.booking[stelleImVektor]->getId()) +
                                     "\nStartdatum: " + QString::fromStdString(travelagency.booking[stelleImVektor]->getFromDate())
                                     +"\nEnddatum: " + QString::fromStdString(travelagency.booking[stelleImVektor]->getToDate())+
                                     "\nPreis: " + QString::number(travelagency.booking[stelleImVektor]->getPrice())+
                                     "\nHotel: " + QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency.booking[stelleImVektor])->getHotel())+
                                     "\nTown: " + QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency.booking[stelleImVektor])->getTown()));
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
        ui->pickupStationLineEdit->setText("");
        ui->returnStationLineEdit->setEnabled(false);
        ui->returnStationLineEdit->setText("");
        ui->hotelLineEdit->setEnabled(false);
        ui->hotelLineEdit->setText("");
        ui->townLineEdit->setEnabled(false);
        ui->townLineEdit->setText("");
        ui->fromDestinationLineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getFromDestination()));
        ui->toDestinationLineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getToDestination()));
        ui->companyLineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency.booking[stelleImVektor])->getAirline()));
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
        ui->pickupStationLineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getPickupLocation()));
        ui->returnStationLineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getReturnLocation()));
        ui->companyLineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency.booking[stelleImVektor])->getCompany()));
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

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_toDateEdit_userDateChanged(const QDate &date)
{
    travelagency.booking[selectedBookingVectorLocation]->settoQDate(date);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_priceSpinBox_textChanged(const QString &arg1)
{

}


void UpAndAway::on_priceSpinBox_valueChanged(double arg1)
{
    travelagency.booking[selectedBookingVectorLocation]->setPrice(arg1);
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren
    on_idInputSpinBox_valueChanged(selectedId);
}

void UpAndAway::on_fromDestinationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<FlightBooking*>(travelagency.booking[selectedBookingVectorLocation])->setFromDestination(arg1.toStdString());
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_toDestinationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<FlightBooking*>(travelagency.booking[selectedBookingVectorLocation])->setToDestination(arg1.toStdString());
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_companyLineEdit_textEdited(const QString &arg1)
{
    if(typeid(FlightBooking) == typeid(*(travelagency.booking[selectedBookingVectorLocation]))){
        dynamic_cast<FlightBooking*>(travelagency.booking[selectedBookingVectorLocation])->setAirline(arg1.toStdString());
    }else if(typeid(RentalCarReservation) == typeid(*(travelagency.booking[selectedBookingVectorLocation]))){
        dynamic_cast<RentalCarReservation*>(travelagency.booking[selectedBookingVectorLocation])->setCompany(arg1.toStdString());
    }
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_hotelLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<HotelBooking*>(travelagency.booking[selectedBookingVectorLocation])->setHotel(arg1.toStdString());
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_townLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<HotelBooking*>(travelagency.booking[selectedBookingVectorLocation])->setTown(arg1.toStdString());
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_pickupStationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<RentalCarReservation*>(travelagency.booking[selectedBookingVectorLocation])->setPickupLocation(arg1.toStdString());
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}


void UpAndAway::on_returnStationLineEdit_textEdited(const QString &arg1)
{
    dynamic_cast<RentalCarReservation*>(travelagency.booking[selectedBookingVectorLocation])->setReturnLocation(arg1.toStdString());
    //Widgetliste aktualisieren

    ////position in Widgetliste == position im Vektor
    ui->listWidget->item(selectedBookingVectorLocation)->setText(QString::fromStdString(travelagency.booking[selectedBookingVectorLocation]->showDetails()));

    //Attributliste aktualisieren

    on_idInputSpinBox_valueChanged(selectedId);
}

void UpAndAway::cleanEverything()
{
    travelagency.cleanBookings();
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

