#include "travelagency.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include "flightbooking.h"
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
using namespace std;

TravelAgency::TravelAgency()
{

}

TravelAgency::~TravelAgency()
{
    cleanBookings();
}

bool TravelAgency::readfile(QString fileName, QWidget *window)
{
    qDebug() << "Dateien werden eingelesen...\n";
    ifstream datei;
    datei.open(fileName.toStdString(), ios::in);
    if(!datei){
        qDebug() << "Datei konnte nicht geöffnet werden. \n";
        return false;
    }
    unsigned int flightImportCount = 0, rentalCarImportCount = 0
            , hotelImportCount = 0;
    double totalFlightCost = 0, totalRentalCarCost = 0, totalHotelImportCost = 0;
    int aktuelleZeile = 1;
    while(!datei.eof()){
        char typErkennung, erstesTrennZeichen;
        datei.get(typErkennung);   //liest die Typkennung
        if(typErkennung != 'F' && typErkennung != 'R'  && typErkennung != 'H'){
            throw runtime_error("Fehler: Falsche erkennung in der Zeile " + to_string(aktuelleZeile)
                                + " !\n");
        }
        datei.get(erstesTrennZeichen);
        if(erstesTrennZeichen != '|'){
            throw runtime_error("Fehler: Erstes Trennzeichen fehlt in Zeile " +
                                to_string(aktuelleZeile)+ " !\n");
        }
        string zeile;
        stringstream zeileStringStream;
        getline(datei, zeile);
        zeileStringStream << zeile;
        if(typErkennung == 'F'){
            //flug hinzufügen
            {
                string testString = zeileStringStream.str();
                int spaltenCounter = 0;

                ////Prüfung spalten:

                for(unsigned int i = 0; i < testString.length(); i++){
                    if (testString[i] == '|'){
                        spaltenCounter++;
                    }
                }
                if (spaltenCounter!=6){
                    if(spaltenCounter < 6){
                        throw runtime_error("Fehler: zu wenig Spalten in Zeile " + to_string(aktuelleZeile) + ".\n");
                    }
                    if(spaltenCounter > 6){
                        throw runtime_error("Fehler: zu viele Spalten in Zeile " + to_string(aktuelleZeile) + ".\n");
                    }
                }
            }
            int i = 0, id = 0;
            double price = 0.0;
            string idString, priceString, fromDate, toDate, fromDestination, toDestination, airline;
            //todo
            while (!zeileStringStream.eof()) {
                switch (i) {
                case 0: getline(zeileStringStream, idString, '|');
                    break;
                case 1: getline(zeileStringStream, priceString, '|');
                    break;
                case 2: getline(zeileStringStream, fromDate, '|');
                    break;
                case 3: getline(zeileStringStream, toDate, '|');
                    break;
                case 4: getline(zeileStringStream, fromDestination, '|');
                    break;
                case 5: getline(zeileStringStream, toDestination, '|');
                    break;
                case 6: getline(zeileStringStream, airline, '|');
                    break;
                default: {
                    char c = ' ';
                    zeileStringStream.get(c);
                    if(c == '|'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Zu viele Spalten";
                    }
                    else if (c != '\n'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Unerwartetes Zeichen";
                    }
                } break;
                }
                i++;
            }
            id = stoi(idString);
            ////PRÜFUNG NUMERISCHER WERT:
            if(!sindDasZahlen(QString::fromStdString(priceString))){
                throw runtime_error("Fehler: Wert ist nicht numerisch in Zeile" + to_string(aktuelleZeile) + "\n");
            }

            price = stod(priceString);


            ////PRÜFUNG FLUGHAFEN 3-STELLIG:

            if(fromDestination.length()!= 3){
                throw runtime_error("Startflughafen nicht 3Stellig Zeile: " + to_string(aktuelleZeile) + ".\n");
            }
            if(toDestination.length()!= 3){
                throw runtime_error("Zielflughafen nicht 3Stellig Zeile: " + to_string(aktuelleZeile) + ".\n");
            }
            //price = stod(priceString);
            FlightBooking* flightBooking =
                    new FlightBooking(id, price, QString::fromStdString(fromDate), QString::fromStdString(toDate),
                                      QString::fromStdString(fromDestination), QString::fromStdString(toDestination),QString::fromStdString(airline));
            allBookings.push_back(flightBooking);
            flightImportCount++;
            totalFlightCost += price;
        }else if(typErkennung == 'R'){
            //mietwagen hinzufügen
            {
                string testString = zeileStringStream.str();
                int spaltenCounter = 0;

                ////Prüfung spalten:

                for(unsigned int i = 0; i < testString.length(); i++){
                    if (testString[i] == '|'){
                        spaltenCounter++;
                    }
                }
                if (spaltenCounter!=6){
                    if(spaltenCounter < 6){
                        throw runtime_error("Fehler: zu wenig Spalten in Zeile " + to_string(aktuelleZeile) + ".\n");
                    }
                    if(spaltenCounter > 6){
                        throw runtime_error("Fehler: zu viele Spalten in Zeile " + to_string(aktuelleZeile) + ".\n");
                    }
                }
            }
            int i = 0, id = 0;
            double price = 0.0;
            string idString, priceString, fromDate, toDate, pickupLocation, returnLocation, company;
            //todo
            while (!zeileStringStream.eof()) {
                switch (i) {
                case 0: getline(zeileStringStream, idString, '|');
                    break;
                case 1: getline(zeileStringStream, priceString, '|');
                    break;
                case 2: getline(zeileStringStream, fromDate, '|');
                    break;
                case 3: getline(zeileStringStream, toDate, '|');
                    break;
                case 4: getline(zeileStringStream, pickupLocation, '|');
                    break;
                case 5: getline(zeileStringStream, returnLocation, '|');
                    break;
                case 6: getline(zeileStringStream, company, '|');
                    break;
                default: {
                    ////PRÜFUNG NUMERISCHER WERT:
                    if(!sindDasZahlen(QString::fromStdString(priceString))){
                        throw runtime_error("Fehler: Wert ist nicht numerisch in Zeile" + to_string(aktuelleZeile) + "\n");
                    }
                    price = stod(priceString);

                    /*
                    char c = ' ';
                    zeileStringStream.get(c);
                    if(c == '|'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Zu viele Spalten";
                    }
                    else if (c != '\n'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Unerwartetes Zeichen";
                        */
                }
                }
                i++;
            }
            id = stoi(idString);
            price = stod(priceString);
            RentalCarReservation* rentalCarReservation =
                    new RentalCarReservation(id, price, QString::fromStdString(fromDate), QString::fromStdString(toDate), QString::fromStdString(pickupLocation),
                                             QString::fromStdString(returnLocation), QString::fromStdString(company));
            allBookings.push_back(rentalCarReservation);
            rentalCarImportCount++;
            totalRentalCarCost += price;

        }
        else if(typErkennung == 'H'){

            string testString = zeileStringStream.str();
            int spaltenCounter = 0;

            ////Prüfung spalten:

            for(unsigned int i = 0; i < testString.length(); i++){
                if (testString[i] == '|'){
                    spaltenCounter++;
                }
            }
            if (spaltenCounter!=5){
                if(spaltenCounter < 5){
                    throw runtime_error("Fehler: zu wenig Spalten in Zeile " + to_string(aktuelleZeile) + ".\n");
                }
                if(spaltenCounter > 5){
                    throw runtime_error("Fehler: zu viele Spalten in Zeile " + to_string(aktuelleZeile) + ".\n");
                }
            }

            int i = 0, id = 0;
            double price = 0.0;
            string idString, priceString, fromDate, toDate, hotel, town;
            //todo
            while (!zeileStringStream.eof()) {
                switch (i) {
                case 0: getline(zeileStringStream, idString, '|');
                    break;
                case 1: getline(zeileStringStream, priceString, '|');
                    break;
                case 2: getline(zeileStringStream, fromDate, '|');
                    break;
                case 3: getline(zeileStringStream, toDate, '|');
                    break;
                case 4: getline(zeileStringStream, hotel, '|');
                    break;
                case 5: getline(zeileStringStream, town, '|');
                    break;
                default: {
                    char c = ' ';
                    zeileStringStream.get(c);
                    if(c == '|'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Zu viele Spalten";
                    }
                    else if (c != '\n'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Unerwartetes Zeichen";
                    }
                };
                    break;
                }
                i++;
            }
            id = stoi(idString);
            ////PRÜFUNG NUMERISCHER WERT:
            if(!sindDasZahlen(QString::fromStdString(priceString))){
                throw runtime_error("Fehler: Wert ist nicht numerisch in Zeile" + to_string(aktuelleZeile) + "\n");
            }
            price = stod(priceString);

            //price = stod(priceString);
            HotelBooking* hotelBooking =
                    new HotelBooking(id, price, QString::fromStdString(fromDate), QString::fromStdString(toDate), QString::fromStdString(hotel),
                                     QString::fromStdString(town));
            allBookings.push_back(hotelBooking);
            hotelImportCount++;
            totalHotelImportCost += price;
        }
        aktuelleZeile++;

    }
    QMessageBox::about(window, "Dateie erfolgreich eingelesen", "Es wurden " + QString::number(flightImportCount) +
                       " Fugbuchungen im Wert von " + QString::number(totalFlightCost, 'f', 2) + " €, " +
                       QString::number(rentalCarImportCount) + " Mietwagenbuchungen im Wert von " + QString::number(totalRentalCarCost, 'f', 2)
                       + " € und " + QString::number(hotelImportCount) +
                       " Hotelreservierungen im Wert von " +
                       QString::number(totalHotelImportCost, 'f', 2) + " € angelegt.\n");
    return true;
}
bool TravelAgency::createJSON(QString fileName)
{
    QJsonDocument jsonDocument;
    QJsonArray mietWagen, hotelBuchung, flugBuchung;
    QJsonObject bookings;
    for (unsigned int i = 0; i < allBookings.size(); i++){
        QJsonObject jsonObjectBuchung;        
        jsonObjectBuchung["id"] = allBookings[i]->getId();
        jsonObjectBuchung["fromDate"] = allBookings[i]->getFromDate();
        jsonObjectBuchung["toDate"] = allBookings[i]->getToDate();
        jsonObjectBuchung["price"] = allBookings[i]->getPrice();
        if(typeid(FlightBooking) == typeid(*(allBookings[i]))){
            jsonObjectBuchung["type"] = "F";
            jsonObjectBuchung["fromDestination"] = dynamic_cast<FlightBooking*>(allBookings[i])->getFromDestination();
            jsonObjectBuchung["toDestination"] = dynamic_cast<FlightBooking*>(allBookings[i])->getToDestination();
            jsonObjectBuchung["airline"] = dynamic_cast<FlightBooking*>(allBookings[i])->getAirline();
            flugBuchung.push_back(jsonObjectBuchung);
        }
        if(typeid(RentalCarReservation) == typeid(*(allBookings[i]))){
            jsonObjectBuchung["type"] = "R";
            jsonObjectBuchung["pickupLocation"] = dynamic_cast<RentalCarReservation*>(allBookings[i])->getPickupLocation();
            jsonObjectBuchung["returnLocation"] = dynamic_cast<RentalCarReservation*>(allBookings[i])->getReturnLocation();
            jsonObjectBuchung["company"] = dynamic_cast<RentalCarReservation*>(allBookings[i])->getCompany();
            mietWagen.push_back(jsonObjectBuchung);
        }
        if(typeid(HotelBooking) == typeid(*(allBookings[i]))){
            jsonObjectBuchung["type"] = "H";
            jsonObjectBuchung["hotel"] = dynamic_cast<HotelBooking*>(allBookings[i])->getHotel();
            jsonObjectBuchung["town"] = dynamic_cast<HotelBooking*>(allBookings[i])->getTown();
            hotelBuchung.push_back(jsonObjectBuchung);
        }

    }
    bookings["Mietwagenreservierungen"] = mietWagen;
    bookings["Hotelbuchungen"] = hotelBuchung;
    bookings["Flugbuchungen"] = flugBuchung;
    jsonDocument.setObject(bookings);
    QFile datei(fileName);
    if (!datei.open(QIODevice::WriteOnly)){
        qDebug() << "Datei konnte nicht geoeffnet werden";
        return false;
    }
    datei.write(jsonDocument.toJson());
    datei.close();
    return true;
}

int TravelAgency::suche(int zuSuchendeId)
{
for(unsigned int i = 0; i < allBookings.size(); i++){
    if(allBookings[i]->getId() == zuSuchendeId){
        return i;
    }
}
return -1;
}

void TravelAgency::cleanBookings()
{
    //ignoriert die funktion wenn vektor leer ist
    if(allBookings.size() == 0){
        return;
    }
    //löscht objekte
    for(unsigned long i = 0;i < allBookings.size();i++){
        delete this->allBookings[i];
    }
    //löscht die plätze im Vektor
    allBookings.clear();
}

bool TravelAgency::sindDasZahlen(QString testString)
{
    for (unsigned int i = 0; i<testString.length(); i++){
        if(!((testString[i] >= '0' && testString[i] <= '9')||testString[i] == '.')){
            return false;
        }
    }
    return true;
}

QString TravelAgency::datumFormatieren(QString datum)
{
    return datum.mid(6,2) + "." + datum.mid(4,2) + "." + datum.mid(0,4);
}


