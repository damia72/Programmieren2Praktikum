#include "travel.h"

void Travel::addBooking(Booking *booking)
{
    travelBookings.push_back(booking);
}

QString Travel::showDetails()
{

}

long Travel::getId() const
{
    return id;
}


Travel::Travel(long id, long customerId) : id(id),
    customerId(customerId)
{

}
