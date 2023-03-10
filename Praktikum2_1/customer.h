#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "travel.h"
#include <string>
class Customer
{
public:
    Customer(long id, QString name);
    void addTravel(Travel* travel);
    long getId() const;
    QString showDetails();
    std::vector<Travel *> getTravelList() const;
private:
    long id;
    QString name;

    std::vector<Travel*> travelList;
};

#endif // CUSTOMER_H
