#include "travel.h"

void Travel::addBooking(Booking *booking)
{
    travelBookings.push_back(booking);
}


Travel::Travel(long id, long customerId) : id(id),
    customerId(customerId)
{

}
