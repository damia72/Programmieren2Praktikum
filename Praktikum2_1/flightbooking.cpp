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

FlightBooking::FlightBooking(int idInput, double priceInput, std::string fromDateInput,
                             std::string toDateInput, std::string fromDestinationInput,
                             std::string toDestinationinput, std::string airlineInput):
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

string FlightBooking::showDetails()
{
    cout << "Flugbuchung " << id << " von " << fromDestination << " nach " << toDestination
         << " mit " << airline << " am " << fromDate << ". Preis: " << fixed << setprecision(2) << price << " €.\n";
    string idString, priceString;
    idString = to_string(id);
    priceString = to_string(price);
    return "Flugbuchung " + idString + " von " + fromDestination + " nach " + toDestination
            + " mit " + airline + " am " + fromDate + ". Preis: " + priceString + " €.";
}

const std::string &FlightBooking::getFromDestination() const
{
    return fromDestination;
}

void FlightBooking::setFromDestination(const std::string &newFromDestination)
{
    fromDestination = newFromDestination.substr(0,3);
}

const std::string &FlightBooking::getToDestination() const
{
    return toDestination;
}

void FlightBooking::setToDestination(const std::string &newToDestination)
{
    toDestination = newToDestination.substr(0,3);
}

const std::string &FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const std::string &newAirline)
{
    airline = newAirline;
}

