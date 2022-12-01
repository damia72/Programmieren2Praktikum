#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include "booking.h"
#include <QWidget>
#include "customer.h"
class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();
    bool readfile(std::string fileName, QWidget* window);
    bool readBinaryFile();
    bool createJSON(QString fileName);
    Booking * findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    std::vector<Customer*> allCustomers;
    std::vector<Travel*> allTravels;
    std::vector<Booking*> allBookings;
    int suche(int zuSuchendeId);
    void cleanBookings();
private:


    bool sindDasZahlen(std::string testString);
    std::string datumFormatieren(std::string datum);
};

#endif // TRAVELAGENCY_H
