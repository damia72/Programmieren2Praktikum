#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include "booking.h"

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation();
    ~RentalCarReservation();
    std::string showDetails();
    RentalCarReservation(int idInput, double priceInput, std::string fromDateInput,
                         std::string toDateInput, std::string pickupLocationInput,
                         std::string returnLocationInput, std::string companyInput);
    RentalCarReservation(long idInput, double priceInput, char fromDateInput[],
                               char toDateInput[], char pickupLocationInput[],
                         char returnLocationInput[], char companyInput[]);
    const std::string &getPickupLocation() const;
    void setPickupLocation(const std::string &newPickupLocation);

    const std::string &getReturnLocation() const;
    void setReturnLocation(const std::string &newReturnLocation);

    const std::string &getCompany() const;
    void setCompany(const std::string &newCompany);

private:
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
};

#endif // RENTALCARRESERVATION_H
