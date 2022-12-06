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
return "Der Kunde mit der id " + QString::number(id) + " und dem Namen " + name + " hat " +  QString::number(travelList.size()) + " Reisen gebucht";
}
