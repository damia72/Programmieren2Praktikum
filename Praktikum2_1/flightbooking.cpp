#include "flightbooking.h"
#include <iostream>
#include <iomanip>
using namespace std;
FlightBooking::FlightBooking()
{

}

FlightBooking::~FlightBooking()
{
cout << "Flug wird gelöscht\n";
}

FlightBooking::FlightBooking(int idInput, double priceInput, QString fromDateInput,
                             QString toDateInput, QString fromDestinationInput,
                             QString toDestinationinput, QString airlineInput):
    Booking(idInput, priceInput, fromDateInput, toDateInput),
    fromDestination(fromDestinationInput), toDestination(toDestinationinput),
    airline(airlineInput)
{
    cout << "Flug wird eingelesen.\n";
}

FlightBooking::FlightBooking(long idInput, double priceInput, char fromDateInput[],
                             char toDateInput[], char fromDestinationInput[],
                             char toDestinationInput[], char airlineInput[]):
    Booking(idInput, priceInput, fromDateInput, toDateInput)
{
    cout << "Flug wird eingelesen.\n";    
    //erstes Zeichen einfügen
    airline.push_back(airlineInput[0]);
    for (int i = 1; i<15; i++){
        //leerzeichen entfernen
        if (airlineInput[i] == ' ' && airlineInput[i-1] == ' '){
            break;
        }
        airline.push_back(airlineInput[i]);
    }
    for (int i = 0; i<3; i++){
        fromDestination.push_back(fromDestinationInput[i]);
    }
    for (int i = 0; i<3; i++){
        toDestination.push_back(toDestinationInput[i]);
    }
}

QString FlightBooking::showDetails()
{
    QString idString = idString.number(id);
    QString priceString = QString::number(price, 'f', 2);
    return "Flugbuchung " + idString + " von " + fromDestination + " nach " + toDestination
            + " mit " + airline + " am " + fromDate + ". Preis: " + priceString + " €.";
}

const QString &FlightBooking::getFromDestination() const
{
    return fromDestination;
}

void FlightBooking::setFromDestination(const QString &newFromDestination)
{
    fromDestination = newFromDestination.mid(0,3);
}

const QString &FlightBooking::getToDestination() const
{
    return toDestination;
}

void FlightBooking::setToDestination(const QString &newToDestination)
{
    toDestination = newToDestination.mid(0,3);
}

const QString &FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const QString &newAirline)
{
    airline = newAirline;
}

