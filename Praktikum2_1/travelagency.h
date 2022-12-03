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
    void cleanEverything();
    QStringList bookingAusfuellen(std::stringstream &textStream);
private:
    void cleanBookings();
    void cleanTravels();
    void cleanCustomers();
    void spaltenPruefung(std::string testString, int spaltenanzahl, int aktuelleZeile);
    void pruefungNumerischerWert(QString testString, int aktuelleZeile);
    QString datumFormatieren(QString datum);
    enum Attribute : unsigned int{AttributeBookingId, AttributePrice, AttributeFromDate, AttributeToDate, AttributeTravelId,
                                  AttributeCustomerId, AttributeName};
};

#endif // TRAVELAGENCY_H
