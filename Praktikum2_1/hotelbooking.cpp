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

HotelBooking::HotelBooking(int idInput, double priceInput, std::string fromDateInput,
                           std::string toDateInput, std::string hotelInput,
                           std::string townInput)
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

string HotelBooking::showDetails()
{
    cout << "Hotelreservierung " << id << " im " << hotel << " in " << town << " vom " <<
            fromDate << " bis zum " << toDate << ". Preis: " << fixed << setprecision(2)<< price << " €.\n";
    string idString, priceString;
    idString = to_string(id);
    priceString = to_string(price);
    return "Hotelreservierung " + idString + " im " + hotel + " in " + town + " vom " +
            fromDate + " bis zum " + toDate + ". Preis: " + priceString + " €.";
}

const std::string &HotelBooking::getHotel() const
{
    return hotel;
}

void HotelBooking::setHotel(const std::string &newHotel)
{
    hotel = newHotel;
}

const std::string &HotelBooking::getTown() const
{
    return town;
}

void HotelBooking::setTown(const std::string &newTown)
{
    town = newTown;
}
