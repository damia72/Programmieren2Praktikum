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
    cleanEverything();
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
            , hotelImportCount = 0, travelImportCount = 0, customerImportCount = 0;
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

            spaltenPruefung(zeileStringStream.str(), 9, aktuelleZeile);
            int i = 0, id = 0;
            double price = 0.0;
            string fromDestination, toDestination, airline;
            //Bookingspezifische attribute werden in einer QStringlist mit der Reihenfolge wie in Datei abgespeichert:
            QStringList attributListe = bookingAusfuellen(zeileStringStream);
            while (!zeileStringStream.eof()) {
                switch (i) {
                case 0: getline(zeileStringStream, fromDestination, '|');
                    break;
                case 1: getline(zeileStringStream, toDestination, '|');
                    break;
                case 2: getline(zeileStringStream, airline, '|');
                    break;
                default: {
                    char c = ' ';
                    zeileStringStream.get(c);
                    if (c != '\n'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Unerwartetes Zeichen";
                    }
                };
                    break;
                }
                i++;
            }
            id = attributListe[AttributeBookingId].toInt();
            pruefungNumerischerWert(attributListe[AttributePrice], aktuelleZeile);
            price = attributListe[AttributePrice].toDouble();
            ////PRÜFUNG FLUGHAFEN 3-STELLIG:

            if(fromDestination.length()!= 3){
                throw runtime_error("Startflughafen nicht 3Stellig Zeile: " + to_string(aktuelleZeile) + ".\n");
            }
            if(toDestination.length()!= 3){
                throw runtime_error("Zielflughafen nicht 3Stellig Zeile: " + to_string(aktuelleZeile) + ".\n");
            }
            FlightBooking* flightBooking =
                    new FlightBooking(id, price, attributListe[AttributeFromDate], attributListe[AttributeToDate], QString::fromStdString(fromDestination),
                                      QString::fromStdString(toDestination), QString::fromStdString(airline));
            allBookings.push_back(flightBooking);
            if(findTravel(attributListe[AttributeTravelId].toLong()) != nullptr){
                findTravel(attributListe[AttributeTravelId].toLong())->addBooking(flightBooking);
                if(findCustomer(attributListe[AttributeCustomerId].toLong()) != nullptr){
                    findCustomer(attributListe[AttributeCustomerId].toLong())->addTravel(findTravel(attributListe[AttributeTravelId].toLong()));
                }else{
                    Customer* customer = new Customer(attributListe[AttributeCustomerId].toLong(), attributListe[AttributeName]);
                    customer->addTravel(findTravel(attributListe[AttributeTravelId].toLong()));
                    allCustomers.push_back(customer);
                    customerImportCount++;
                }
            }else{
                Travel* travel = new Travel(attributListe[AttributeTravelId].toLong(), attributListe[AttributeCustomerId].toLong());
                travel->addBooking(flightBooking);
                if(findCustomer(attributListe[AttributeCustomerId].toLong()) != nullptr){
                    findCustomer(attributListe[AttributeCustomerId].toLong())->addTravel(travel);
                }else{
                    Customer* customer = new Customer(attributListe[AttributeCustomerId].toLong(), attributListe[AttributeName]);
                    customer->addTravel(travel);
                    allCustomers.push_back(customer);
                    customerImportCount++;
                }
                allTravels.push_back(travel);
                travelImportCount++;
            }
            flightImportCount++;
            totalFlightCost += price;
        }else if(typErkennung == 'R'){
            spaltenPruefung(zeileStringStream.str(), 9, aktuelleZeile);
            int i = 0, id = 0;
            double price = 0.0;
            string pickupLocation, returnLocation, company;
            //Bookingspezifische attribute werden in einer QStringlist mit der Reihenfolge wie in Datei abgespeichert:
            QStringList attributListe = bookingAusfuellen(zeileStringStream);
            while (!zeileStringStream.eof()) {
                switch (i) {
                case 0: getline(zeileStringStream, pickupLocation, '|');
                    break;
                case 1: getline(zeileStringStream, returnLocation, '|');
                    break;
                case 2: getline(zeileStringStream, company, '|');
                    break;
                default: {
                    char c = ' ';
                    zeileStringStream.get(c);
                    if (c != '\n'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Unerwartetes Zeichen";
                    }
                };
                    break;
                }
                i++;
            }
            id = attributListe[AttributeBookingId].toInt();
            pruefungNumerischerWert(attributListe[AttributePrice], aktuelleZeile);
            price = attributListe[AttributePrice].toDouble();
            RentalCarReservation* rentalCarReservation =
                    new RentalCarReservation(id, price, attributListe[AttributeFromDate], attributListe[AttributeToDate], QString::fromStdString(pickupLocation),
                                     QString::fromStdString(returnLocation), QString::fromStdString(company));
            allBookings.push_back(rentalCarReservation);
            if(findTravel(attributListe[AttributeTravelId].toLong()) != nullptr){
                findTravel(attributListe[AttributeTravelId].toLong())->addBooking(rentalCarReservation);
                if(findCustomer(attributListe[AttributeCustomerId].toLong()) != nullptr){
                    findCustomer(attributListe[AttributeCustomerId].toLong())->addTravel(findTravel(attributListe[AttributeTravelId].toLong()));
                }else{
                    Customer* customer = new Customer(attributListe[AttributeCustomerId].toLong(), attributListe[AttributeName]);
                    customer->addTravel(findTravel(attributListe[AttributeTravelId].toLong()));
                    allCustomers.push_back(customer);
                    customerImportCount++;
                }
            }else{
                Travel* travel = new Travel(attributListe[AttributeTravelId].toLong(), attributListe[AttributeCustomerId].toLong());
                travel->addBooking(rentalCarReservation);
                if(findCustomer(attributListe[AttributeCustomerId].toLong()) != nullptr){
                    findCustomer(attributListe[AttributeCustomerId].toLong())->addTravel(travel);
                }else{
                    Customer* customer = new Customer(attributListe[AttributeCustomerId].toLong(), attributListe[AttributeName]);
                    customer->addTravel(travel);
                    allCustomers.push_back(customer);
                    customerImportCount++;
                }
                allTravels.push_back(travel);
                travelImportCount++;
            }
            rentalCarImportCount++;
            totalRentalCarCost += price;

        }
        else if(typErkennung == 'H'){
            spaltenPruefung(zeileStringStream.str(), 8, aktuelleZeile);
            int i = 0, id = 0;
            double price = 0.0;
            string hotel, town;
            //Bookingspezifische attribute werden in einer QStringlist mit der Reihenfolge wie in Datei abgespeichert:
            QStringList attributListe = bookingAusfuellen(zeileStringStream);
            while (!zeileStringStream.eof()) {
                switch (i) {
                case 0: getline(zeileStringStream, hotel, '|');
                    break;
                case 1: getline(zeileStringStream, town, '|');
                    break;
                default: {
                    char c = ' ';
                    zeileStringStream.get(c);
                    if (c != '\n'){
                        qDebug() << "Fehler: Zeile " << aktuelleZeile << " Unerwartetes Zeichen";
                    }
                };
                    break;
                }
                i++;
            }
            id = attributListe[AttributeBookingId].toInt();
            pruefungNumerischerWert(attributListe[AttributePrice], aktuelleZeile);
            price = attributListe[AttributePrice].toDouble();
            HotelBooking* hotelBooking =
                    new HotelBooking(id, price, attributListe[AttributeFromDate], attributListe[AttributeToDate], QString::fromStdString(hotel),
                                     QString::fromStdString(town));
            allBookings.push_back(hotelBooking);
            if(findTravel(attributListe[AttributeTravelId].toLong()) != nullptr){
                findTravel(attributListe[AttributeTravelId].toLong())->addBooking(hotelBooking);
                if(findCustomer(attributListe[AttributeCustomerId].toLong()) != nullptr){
                    findCustomer(attributListe[AttributeCustomerId].toLong())->addTravel(findTravel(attributListe[AttributeTravelId].toLong()));
                }else{
                    Customer* customer = new Customer(attributListe[AttributeCustomerId].toLong(), attributListe[AttributeName]);
                    customer->addTravel(findTravel(attributListe[AttributeTravelId].toLong()));
                    allCustomers.push_back(customer);
                    customerImportCount++;
                }
            }else{
                Travel* travel = new Travel(attributListe[AttributeTravelId].toLong(), attributListe[AttributeCustomerId].toLong());
                travel->addBooking(hotelBooking);
                if(findCustomer(attributListe[AttributeCustomerId].toLong()) != nullptr){
                    findCustomer(attributListe[AttributeCustomerId].toLong())->addTravel(travel);
                }else{
                    Customer* customer = new Customer(attributListe[AttributeCustomerId].toLong(), attributListe[AttributeName]);
                    customer->addTravel(travel);
                    allCustomers.push_back(customer);
                    customerImportCount++;
                }
                allTravels.push_back(travel);
                travelImportCount++;
            }
            hotelImportCount++;
            totalHotelImportCost += price;
        }
        aktuelleZeile++;
    }
    QMessageBox::about(window, "Dateien erfolgreich eingelesen", "Es wurden " + QString::number(flightImportCount) +
                       " Fugbuchungen im Wert von " + QString::number(totalFlightCost, 'f', 2) + " €, " +
                       QString::number(rentalCarImportCount) + " Mietwagenbuchungen im Wert von " + QString::number(totalRentalCarCost, 'f', 2)
                       + " € und " + QString::number(hotelImportCount) +
                       " Hotelreservierungen im Wert von " +
                       QString::number(totalHotelImportCost, 'f', 2) + " € angelegt." + " Gesamtwert: " +
                       QString::number(totalRentalCarCost + totalFlightCost + totalHotelImportCost, 'f', 2) + "€. Es wurden " + QString::number(travelImportCount)
                       +" Reisen und " + QString::number(customerImportCount) + " Kunden angelegt.\n");
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

Booking *TravelAgency::findBooking(long id)
{
    for(unsigned int i = 0; i < this->allBookings.size(); i++){
        if (allBookings[i]->getId() == id){
            return allBookings[i];
        }
    }
    return nullptr;
}

Travel *TravelAgency::findTravel(long id)
{
    for(unsigned int i = 0; i < this->allTravels.size(); i++){
        if (allTravels[i]->getId() == id){
            return allTravels[i];
        }
    }
    return nullptr;
}

Customer *TravelAgency::findCustomer(long id)
{
    for(unsigned int i = 0; i < this->allCustomers.size(); i++){
        if (allCustomers[i]->getId() == id){
            return allCustomers[i];
        }
    }
    return nullptr;
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

void TravelAgency::cleanTravels()
{
    if(allTravels.size() == 0){
        return;
    }
    for(unsigned int i = 0; i < allTravels.size();i++){
        delete this->allTravels[i];
    }
    allTravels.clear();
}

void TravelAgency::cleanCustomers()
{
    if(allCustomers.size() == 0){
        return;
    }
    for(unsigned int i = 0; i < allCustomers.size();i++){
        delete this->allCustomers[i];
    }
    allCustomers.clear();
}

void TravelAgency::cleanEverything()
{
    cleanBookings();
    cleanTravels();
    cleanCustomers();
}

QStringList TravelAgency::bookingAusfuellen(stringstream &textStream)
{
    string idString, priceString, fromDate, toDate, travelIdString, customerIdString, customerName;
    for(int i = 0; i <= 6; i++){
        switch(i){
        case 0: getline(textStream, idString, '|');
            break;
        case 1: getline(textStream, priceString, '|');
            break;
        case 2: getline(textStream, fromDate, '|');
            break;
        case 3: getline(textStream, toDate, '|');
            break;
        case 4: getline(textStream, travelIdString, '|');
            break;
        case 5: getline(textStream, customerIdString, '|');
            break;
        case 6: getline(textStream, customerName, '|');
            break;
        }
    }
    QStringList bookingAtributes = {QString::fromStdString(idString), QString::fromStdString(priceString),QString::fromStdString(fromDate)
                                    ,QString::fromStdString(toDate),QString::fromStdString(travelIdString),QString::fromStdString(customerIdString)
                                    ,QString::fromStdString(customerName)};
    return bookingAtributes;
}

void TravelAgency::spaltenPruefung(std::string testString, int spaltenanzahl, int aktuelleZeile)
{
    int spaltencounter = 0;
    for(unsigned int i = 0; i < testString.length(); i++){
        if(testString[i] == '|'){
            spaltencounter++;
        }
    }
    if(spaltencounter < spaltenanzahl){
        throw runtime_error("Fehler: Zu viele Spalten in Zeile" + to_string(aktuelleZeile)+"\n");
    }
    if(spaltencounter > spaltenanzahl){
        throw runtime_error("Fehler: Zu wenig Spalten"+ to_string(aktuelleZeile)+"\n");
    }
}

void TravelAgency::pruefungNumerischerWert(QString testString, int aktuelleZeile)
{
    for (unsigned int i = 0; i<testString.length(); i++){
        if(!((testString[i] >= '0' && testString[i] <= '9')||testString[i] == '.')){
            throw runtime_error("Fehler: Wert ist nicht numerisch in Zeile" + to_string(aktuelleZeile) + "\n");
        }
    }
}

QString TravelAgency::datumFormatieren(QString datum)
{
    return datum.mid(6,2) + "." + datum.mid(4,2) + "." + datum.mid(0,4);
}


