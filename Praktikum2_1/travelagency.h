#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include "booking.h"
#include <QWidget>
class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();
    bool readfile(std::string fileName, QWidget* window);
    bool readBinaryFile();
    bool createJSON(QString fileName);
    std::vector<Booking*> booking;
    int suche(int zuSuchendeId);
    void cleanBookings();
private:


    bool sindDasZahlen(std::string testString);
    std::string datumFormatieren(std::string datum);
};

#endif // TRAVELAGENCY_H
