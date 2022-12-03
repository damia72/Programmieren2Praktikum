#ifndef TRAVEL_H
#define TRAVEL_H
#include "booking.h"

class Travel
{
public:
    Travel(long id, long customerId);
    void addBooking(Booking *booking);

    long getId() const;

private:
    long id;
    long customerId;
    std::vector<Booking*> travelBookings;
};

#endif // TRAVEL_H
