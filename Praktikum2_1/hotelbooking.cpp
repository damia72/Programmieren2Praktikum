#include "hotelbooking.h"
#include <iostream>
#include <iomanip>
using namespace std;
HotelBooking::HotelBooking()
{

}

HotelBooking::~HotelBooking()
{
cout << "Hotelbuchung wird gelöscht\n";
}

HotelBooking::HotelBooking(int idInput, double priceInput, QString fromDateInput,
                           QString toDateInput, QString hotelInput,
                           QString townInput)
    :Booking(idInput, priceInput, fromDateInput, toDateInput), hotel(hotelInput),
      town(townInput)
{
    cout << "Hotelbuchung wird eingelesen.\n";
}

HotelBooking::HotelBooking(long idInput, double priceInput, char fromDateInput[],
                           char toDateInput[], char hotelInput[], char townInput[]):
    Booking(idInput, priceInput, fromDateInput, toDateInput)
{
    cout << "Hotelbuchung wird eingelesen.\n";
    //erstes Zeichen einfügen
    hotel.push_back(hotelInput[0]);
    for(int i = 1; i < 15; i++){
        //leerzeichen entfernen
        if (hotelInput[i] == ' ' && hotelInput[i-1] == ' '){
            break;
        }
        hotel.push_back(hotelInput[i]);
    }
    //erstes Zeichen einfügen
    town.push_back(townInput[0]);
    for(int i = 1; i < 15; i++){
        //leerzeichen entfernen
        if (townInput[i] == ' ' && townInput[i-1] == ' '){
            break;
        }
        town.push_back(townInput[i]);
    }
}

QString HotelBooking::showDetails()
{
    QString idString = idString.number(id);
    QString priceString = QString::number(price, 'f', 2);
    return "Hotelreservierung " + idString + " im " + hotel + " in " + town + " vom " +
            fromDate + " bis zum " + toDate + ". Preis: " + priceString + " €.";
}

const QString &HotelBooking::getHotel() const
{
    return hotel;
}

void HotelBooking::setHotel(const QString &newHotel)
{
    hotel = newHotel;
}

const QString &HotelBooking::getTown() const
{
    return town;
}

void HotelBooking::setTown(const QString &newTown)
{
    town = newTown;
}
