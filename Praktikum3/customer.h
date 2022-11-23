#ifndef CUSTOMER_H
#define CUSTOMER_H


#include "travel.h"
#include <string>
#include <vector>
class Customer
{
public:
    Customer();
    void addTravel(Travel* travel);
private:
    long id;
    std::string name;
    std::vector<Travel*> travelList;
};

#endif // CUSTOMER_H
