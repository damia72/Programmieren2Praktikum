#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include "booking.h"

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation();
    ~RentalCarReservation();
    QString showDetails();
    RentalCarReservation(int idInput, double priceInput, QString fromDateInput,
                         QString toDateInput, QString pickupLocationInput,
                         QString returnLocationInput, QString companyInput);
    RentalCarReservation(long idInput, double priceInput, char fromDateInput[],
                               char toDateInput[], char pickupLocationInput[],
                         char returnLocationInput[], char companyInput[]);
    const QString &getPickupLocation() const;
    void setPickupLocation(const QString &newPickupLocation);

    const QString &getReturnLocation() const;
    void setReturnLocation(const QString &newReturnLocation);

    const QString &getCompany() const;
    void setCompany(const QString &newCompany);

private:
    QString pickupLocation;
    QString returnLocation;
    QString company;
};

#endif // RENTALCARRESERVATION_H
