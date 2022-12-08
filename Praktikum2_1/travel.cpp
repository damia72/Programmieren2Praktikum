#include "travel.h"

void Travel::addBooking(Booking *booking)
{
    travelBookings.push_back(booking);
}



long Travel::getId() const
{
    return id;
}

std::vector<Booking *> Travel::getTravelBookings() const
{
    return travelBookings;
}

QString Travel::showDetails()
{
    return "Zur reise mit der Id " + QString::number(id) + " gehören " + QString::number(travelBookings.size()) + " Buchungen.\n";
}

QDate Travel::findEarliestBooking()
{
    //für den fall das travel keine bookings hat:
    if(this->getTravelBookings().empty() == true){
        QDate nichts(1,1,1);
        return nichts;
    }
    QDate minQDate = this->getTravelBookings()[0]->getFromQDate();
    for(unsigned int i = 0; i < this->getTravelBookings().size(); i++){
        if(this->getTravelBookings()[i]->getFromQDate() < minQDate){
            minQDate = this->getTravelBookings()[i]->getFromQDate();
        }
    }
    return minQDate;
}

QDate Travel::findLatestBooking()
{
    //für den fall das travel keine bookings hat:
    if(this->getTravelBookings().empty() == true){
        QDate nichts(1,1,1);
        return nichts;
    }
    QDate maxQDate = this->getTravelBookings()[0]->getFromQDate();
    for(unsigned int i = 0; i < this->getTravelBookings().size(); i++){
        if(this->getTravelBookings()[i]->getFromQDate() > maxQDate){
            maxQDate = this->getTravelBookings()[i]->getFromQDate();
        }
    }
    return maxQDate;
}


Travel::Travel(long id, long customerId) : id(id),
    customerId(customerId)
{

}
