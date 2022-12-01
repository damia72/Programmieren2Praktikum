#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include "booking.h"

class HotelBooking : public Booking
{
public:
    HotelBooking();
    ~HotelBooking();
    HotelBooking(int idInput, double priceInput, QString fromDateInput,
                 QString toDateInput, QString hotelInput, QString townInput);
    HotelBooking(long idInput, double priceInput, char fromDateInput[],
                                 char toDateInput[], char hotelInput[],
                                 char townInput[]);
    QString showDetails();
    const QString &getHotel() const;
    void setHotel(const QString &newHotel);

    const QString &getTown() const;
    void setTown(const QString &newTown);

private:
    QString hotel;
    QString town;
};

#endif // HOTELBOOKING_H
