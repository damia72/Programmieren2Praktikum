#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include "booking.h"
class FlightBooking : public Booking
{
public:
    FlightBooking();
    ~FlightBooking();
    FlightBooking(int idInput, double priceInput, std::string fromDateInput,
                  std::string toDateInput, std::string fromDestinationInput,
                  std::string toDestinationinput, std::string airlineInput);
    FlightBooking(long idInput, double priceInput, char fromDateInput[],
    char toDateInput[], char fromDestinationInput[], char toDestinationInput[],
                  char airlineInput[]);
    std::string showDetails();
    const std::string &getFromDestination() const;
    void setFromDestination(const std::string &newFromDestination);

    const std::string &getToDestination() const;
    void setToDestination(const std::string &newToDestination);

    const std::string &getAirline() const;
    void setAirline(const std::string &newAirline);

private:
    std::string fromDestination;
    std::string toDestination;
    std::string airline;
};

#endif // FLIGHTBOOKING_H
