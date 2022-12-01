#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "travel.h"
#include <string>
class Customer
{
public:
    Customer(long id, std::string name);
    void addTravel(Travel* travel);
private:
    long id;
    std::string name;
    std::vector<Travel*> travelList;
};

#endif // CUSTOMER_H
