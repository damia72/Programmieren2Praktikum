#include "customer.h"

Customer::Customer(long id, QString name) : id(id), name(name)
{

}

void Customer::addTravel(Travel *travel)
{
    travelList.push_back(travel);
}

long Customer::getId() const
{
    return id;
}

QString Customer::showDetails()
{

}
