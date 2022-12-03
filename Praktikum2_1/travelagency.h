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
    bool readfile(QString fileName, QWidget* window);
    bool createJSON(QString fileName);
    Booking * findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    std::vector<Customer*> allCustomers;
    std::vector<Travel*> allTravels;
    std::vector<Booking*> allBookings;
    int suche(int zuSuchendeId);
    void cleanBookings();
    QStringList bookingAusfuellen(std::stringstream &textStream);
private:

    void spaltenPruefung(std::string testString, int spaltenanzahl, int aktuelleZeile);
    bool sindDasZahlen(QString testString);
    QString datumFormatieren(QString datum);
};

#endif // TRAVELAGENCY_H
