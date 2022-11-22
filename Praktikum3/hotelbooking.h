#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include "booking.h"

class HotelBooking : public Booking
{
public:
    HotelBooking();
    ~HotelBooking();
    HotelBooking(int idInput, double priceInput, std::string fromDateInput,
                 std::string toDateInput, std::string hotelInput, std::string townInput);
    HotelBooking(long idInput, double priceInput, char fromDateInput[],
                                 char toDateInput[], char hotelInput[],
                                 char townInput[]);
    std::string showDetails();
    const std::string &getHotel() const;
    void setHotel(const std::string &newHotel);

    const std::string &getTown() const;
    void setTown(const std::string &newTown);

private:
    std::string hotel;
    std::string town;
};

#endif // HOTELBOOKING_H
