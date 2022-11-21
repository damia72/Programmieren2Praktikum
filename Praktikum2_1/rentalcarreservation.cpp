#include "rentalcarreservation.h"
#include <iostream>
#include <iomanip>
using namespace std;
RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::~RentalCarReservation()
{
    cout << "Mietwagen wird gelöscht\n";
}

string RentalCarReservation::showDetails()
{
    cout << "Mietwagenreservierung " << id << " mit " << company << ". Abholung am " <<
            fromDate << " im " << pickupLocation << ". Rückgabe am " << toDate <<
            " in " << returnLocation << ". Preis: " << fixed << setprecision(2) << price << " €.\n";
    string idString, priceString;
    idString = to_string(id);
    priceString = to_string(price);
    stringstream string;
    string << fixed << setprecision(2) << priceString;
    return "Mietwagenreservierung " + idString + " mit " + company +  ". Abholung am " +
            fromDate + " im " + pickupLocation + ". Rückgabe am " + toDate +
            " in " + returnLocation + ". Preis: " + string.str() + " €.";

}

RentalCarReservation::RentalCarReservation(int idInput, double priceInput,
                                           std::string fromDateInput,
                                           std::string toDateInput,
                                           std::string pickupLocationInput,
                                           std::string returnLocationInput,
                                           std::string companyInput)
    :Booking(idInput, priceInput, fromDateInput, toDateInput),
      pickupLocation(pickupLocationInput),  returnLocation(returnLocationInput),
      company(companyInput)
{
    cout << "Mietwagen wird eingelesen.\n";
}

RentalCarReservation::RentalCarReservation(long idInput, double priceInput,
                                           char fromDateInput[], char toDateInput[],
                                           char pickupLocationInput[],
                                           char returnLocationInput[],
                                           char companyInput[])
    :Booking(idInput, priceInput, fromDateInput, toDateInput)
{
    cout << "Mietwagen wird eingelesen.\n";
    //erstes zeichen einfügen
    pickupLocation.push_back(pickupLocationInput[0]);
    for(int i = 1; i < 15; i++){
        //erstes Zeichen einfüg
        //leerzeichen entfernen
        if (pickupLocationInput[i] == ' ' &&pickupLocationInput[i-1] == ' '){
            break;
        }
        pickupLocation.push_back(pickupLocationInput[i]);
    }
    //erstes zeichen einfügen
    returnLocation.push_back(returnLocationInput[0]);
    for(int i = 1; i < 15; i++){
        //leerzeichen entfernen
        if (returnLocationInput[i] == ' ' && returnLocationInput[i-1] == ' '){
            break;
        }
        returnLocation.push_back(returnLocationInput[i]);
    }
    //erstes zeichen einfügen
    company.push_back(companyInput[0]);
    for(int i = 1; i < 15; i++){
        //leerzeichen entfernen
        if (companyInput[i] == ' ' && companyInput[i-1]){
            break;
        }
        company.push_back(companyInput[i]);
    }
}

const std::string &RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

void RentalCarReservation::setPickupLocation(const std::string &newPickupLocation)
{
    pickupLocation = newPickupLocation;
}

const std::string &RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

void RentalCarReservation::setReturnLocation(const std::string &newReturnLocation)
{
    returnLocation = newReturnLocation;
}

const std::string &RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setCompany(const std::string &newCompany)
{
    company = newCompany;
}
