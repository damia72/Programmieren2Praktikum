#ifndef TRAVEL_H
#define TRAVEL_H


#include "booking.h"
class Travel
{
public:
    Travel();
    void addBooking(Booking* booking);
private:
    long id;
    long customerId;
    std::vector<Booking*> travelbookings;
};

#endif // TRAVEL_H
