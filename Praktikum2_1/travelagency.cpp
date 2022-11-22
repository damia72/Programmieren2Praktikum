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

bool TravelAgency::readfile(string fileName, QWidget *window)
{
    qDebug() << "Dateien werden eingelesen...\n";
    ifstream datei;
    datei.open(fileName, ios::in);
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
            if(!sindDasZahlen(priceString)){
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
                    new FlightBooking(id, price, fromDate, toDate,
                                      fromDestination, toDestination,airline);
            booking.push_back(flightBooking);
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
                    if(!sindDasZahlen(priceString)){
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
                    new RentalCarReservation(id, price, fromDate, toDate, pickupLocation,
                                             returnLocation, company);
            booking.push_back(rentalCarReservation);
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
            if(!sindDasZahlen(priceString)){
                throw runtime_error("Fehler: Wert ist nicht numerisch in Zeile" + to_string(aktuelleZeile) + "\n");
            }
            price = stod(priceString);

            //price = stod(priceString);
            HotelBooking* hotelBooking =
                    new HotelBooking(id, price, fromDate, toDate, hotel,
                                     town);
            booking.push_back(hotelBooking);
            hotelImportCount++;
            totalHotelImportCost += price;
        }
        aktuelleZeile++;

    }
    QMessageBox::about(window, "Datei erfolgreich eingelesen", "Es wurden " + QString::number(flightImportCount) +
                       " Fugbuchungen im Wert von " + QString::number(totalFlightCost, 'f', 2) + " €, " +
                       QString::number(rentalCarImportCount) + " Mietwagenbuchungen im Wert von " + QString::number(totalRentalCarCost, 'f', 2)
                       + " € und " + QString::number(hotelImportCount) +
                       " Hotelreservierungen im Wert von " +
                       QString::number(totalHotelImportCost, 'f', 2) + " € angelegt.\n");
    return true;
}

bool TravelAgency::readBinaryFile()
{
    ifstream datei;
    qDebug() << "Binaerdatei wird eingelesen...\n";
    datei.open("bookingsBinary.bin", ios::in | ios::binary);
    if(!datei){
        cerr << "Datei konnte nicht geöffnet werden. \n";
        return false;
    }
    unsigned int flightImportCount = 0, rentalCarImportCount = 0
            , hotelImportCount = 0;
    double totalFlightCost = 0, totalRentalCarCost = 0, totalHotelImportCost = 0;
    int aktuelleZeile = 1;
    while(datei.peek()!=EOF){
        char typErkennung = '\0';
        datei.read((char*) &typErkennung, sizeof typErkennung);
        if(datei.peek()==EOF){
            qDebug() << "Dateiende erreicht\n";
            break;
        }
        //fehlerüberprüfung nicht möglich da kein eof eingebaut ist:
        /*if(typErkennung != 'F' && typErkennung != 'R'  && typErkennung != 'H'){
            if(datei.eof()){
                qDebug() << "Datei wurde zuende gelsen.\n";
                return true;
            }
            cerr << "Fehler: Falsche erkennung in der Zeile " << aktuelleZeile
                 << " !\n";
            cleanBookings();
            return false;
            break;
        }*/
        if(typErkennung == 'F'){
            long id;
            double price;
            char fromDestination[3], toDestination[3], fromDate[8], toDate[8], airline[15];
            datei.read((char*) &id, sizeof id);
            datei.read((char*) &price, sizeof price);
            for(int i = 0; i < 8; i++){
                datei.read((char*) &fromDate[i], sizeof fromDate[i]);
            }
            for(int i = 0; i < 8; i++){
                datei.read((char*) &toDate[i], sizeof toDate[i]);
            }
            for(int i = 0; i < 3; i++){
                datei.read((char*) &fromDestination[i], sizeof fromDestination[i]);
            }
            for(int i = 0; i < 3; i++){
                datei.read((char*) &toDestination[i], sizeof toDestination[i]);
            }
            for(int i = 0; i < 15; i++){
                datei.read((char*) &airline[i], sizeof airline[i]);
            }
            FlightBooking* flightBooking =
                    new FlightBooking(id, price, fromDate, toDate, fromDestination, toDestination, airline);
            booking.push_back(flightBooking);
            flightImportCount++;
            totalFlightCost += price;
        }else if(typErkennung == 'H'){
            long id;
            double price;
            char hotel[15], town[15], fromDate[8], toDate[8];
            datei.read((char*) &id, sizeof id);
            datei.read((char*) &price, sizeof price);
            for(int i = 0; i < 8; i++){
                datei.read((char*) &fromDate[i], sizeof fromDate[i]);
            }
            for(int i = 0; i < 8; i++){
                datei.read((char*) &toDate[i], sizeof toDate[i]);
            }
            for(int i = 0; i < 15; i++){
                datei.read((char*) &hotel[i], sizeof hotel[i]);
            }
            for(int i = 0; i < 15; i++){
                datei.read((char*) &town[i], sizeof town[i]);
            }
            HotelBooking* hotelBooking =
                    new HotelBooking(id, price, fromDate, toDate, hotel, town);
            booking.push_back(hotelBooking);
            hotelImportCount++;
            totalHotelImportCost += price;
        }else if(typErkennung == 'R'){
            long id;
            double price;
            char pickupLocation[15], returnLocation[15], company[15],fromDate[8], toDate[8];
            datei.read((char*) &id, sizeof id);
            datei.read((char*) &price, sizeof price);
            for(int i = 0; i < 8; i++){
                datei.read((char*) &fromDate[i], sizeof fromDate[i]);
            }
            for(int i = 0; i < 8; i++){
                datei.read((char*) &toDate[i], sizeof toDate[i]);
            }
            for(int i = 0; i < 15; i++){
                datei.read((char*) &pickupLocation[i], sizeof pickupLocation[i]);
            }
            for(int i = 0; i < 15; i++){
                datei.read((char*) &returnLocation[i], sizeof returnLocation[i]);
            }
            for(int i = 0; i < 15; i++){
                datei.read((char*) &company[i], sizeof company[i]);
            }
            RentalCarReservation* rentalCarReservation =
                    new RentalCarReservation(id, price, fromDate, toDate, pickupLocation, returnLocation, company);
            booking.push_back(rentalCarReservation);
            rentalCarImportCount++;
            totalRentalCarCost += price;
        }
        aktuelleZeile++;
    }
    cout << "Es wurden " << flightImportCount << " Fugbuchungen im Wert von " <<
            fixed << setprecision(2) << totalFlightCost << " €, " << rentalCarImportCount <<
            " Mietwagenbuchungen im Wert von " << fixed << setprecision(2) <<
            totalRentalCarCost << " € und " << hotelImportCount <<
            " Hotelreservierungen im Wert von " << fixed << setprecision(2) <<
            totalHotelImportCost << " € angelegt.\n";
    return true;
}

bool TravelAgency::createJSON(QString fileName)
{
    QJsonDocument jsonDocument;
    QJsonArray bookings;
    for (unsigned int i = 0; i < booking.size(); i++){
        QJsonObject jsonObjectBuchung;
        if(typeid(FlightBooking) == typeid(*(booking[i]))){
            jsonObjectBuchung["type"] = "F";
            jsonObjectBuchung["fromDestination"] = QString::fromStdString(dynamic_cast<FlightBooking*>(booking[i])->getFromDestination());
            jsonObjectBuchung["toDestination"] = QString::fromStdString(dynamic_cast<FlightBooking*>(booking[i])->getToDestination());
            jsonObjectBuchung["airline"] = QString::fromStdString(dynamic_cast<FlightBooking*>(booking[i])->getAirline());
        }
        if(typeid(RentalCarReservation) == typeid(*(booking[i]))){
            jsonObjectBuchung["type"] = "R";
            jsonObjectBuchung["pickupLocation"] = QString::fromStdString(dynamic_cast<RentalCarReservation*>(booking[i])->getPickupLocation());
            jsonObjectBuchung["returnLocation"] = QString::fromStdString(dynamic_cast<RentalCarReservation*>(booking[i])->getReturnLocation());
            jsonObjectBuchung["company"] = QString::fromStdString(dynamic_cast<RentalCarReservation*>(booking[i])->getCompany());
        }
        if(typeid(HotelBooking) == typeid(*(booking[i]))){
            jsonObjectBuchung["type"] = "H";
            jsonObjectBuchung["hotel"] = QString::fromStdString(dynamic_cast<HotelBooking*>(booking[i])->getHotel());
            jsonObjectBuchung["town"] = QString::fromStdString(dynamic_cast<HotelBooking*>(booking[i])->getTown());
        }
        jsonObjectBuchung["id"] = booking[i]->getId();
        jsonObjectBuchung["fromDate"] = QString::fromStdString(booking[i]->getFromDate());
        jsonObjectBuchung["toDate"] = QString::fromStdString(booking[i]->getToDate());
        jsonObjectBuchung["price"] = booking[i]->getPrice();
        bookings.push_back(jsonObjectBuchung);
    }
    jsonDocument.setArray(bookings);
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
for(unsigned int i = 0; i < booking.size(); i++){
    if(booking[i]->getId() == zuSuchendeId){
        return i;
    }
}
return -1;
}

void TravelAgency::cleanBookings()
{
    //ignoriert die funktion wenn vektor leer ist
    if(booking.size() == 0){
        return;
    }
    //löscht objekte
    for(unsigned long i = 0;i < booking.size();i++){
        delete this->booking[i];
    }
    //löscht die plätze im Vektor
    while(booking.size()!= 0){
        booking.pop_back();
    }
}

bool TravelAgency::sindDasZahlen(std::string testString)
{
    for (unsigned int i = 0; i<testString.length(); i++){
        if(!((testString[i] >= '0' && testString[i] <= '9')||testString[i] == '.')){
            return false;
        }
    }
    return true;
}

string TravelAgency::datumFormatieren(std::string datum)
{
    return datum.substr(6,2) + "." + datum.substr(4,2) + "." + datum.substr(0,4);
}


