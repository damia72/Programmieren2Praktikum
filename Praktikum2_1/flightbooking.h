#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include "booking.h"
class FlightBooking : public Booking
{
public:
    FlightBooking();
    ~FlightBooking();
    FlightBooking(int idInput, double priceInput, QString fromDateInput,
                  QString toDateInput, QString fromDestinationInput,
                  QString toDestinationinput, QString airlineInput);
    FlightBooking(long idInput, double priceInput, char fromDateInput[],
    char toDateInput[], char fromDestinationInput[], char toDestinationInput[],
                  char airlineInput[]);
    QString showDetails();
    const QString &getFromDestination() const;
    void setFromDestination(const QString &newFromDestination);

    const QString &getToDestination() const;
    void setToDestination(const QString &newToDestination);

    const QString &getAirline() const;
    void setAirline(const QString &newAirline);

private:
    QString fromDestination;
    QString toDestination;
    QString airline;
};

#endif // FLIGHTBOOKING_H
