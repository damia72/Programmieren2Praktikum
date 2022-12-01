#include "customer.h"

Customer::Customer(long id, std::string name) : id(id), name(name)
{

}

void Customer::addTravel(Travel *travel)
{
    travelList.push_back(travel);
}
