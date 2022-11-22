#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <QDate>
class Booking
{
public:
    Booking();
    virtual ~Booking();
    virtual std::string showDetails() = 0;
    int getId() const;

    double getPrice() const;
    QDate getFromQDate();
    QDate getToQdate();
    void setFromQDate(QDate fromDateInput);
    void settoQDate(QDate toDateInput);
    void setPrice(double newPrice);

    const std::string &getFromDate() const;
    void setFromDate(const std::string &newFromDate);

    const std::string &getToDate() const;

protected:

    int id;
    double price;
    std::string fromDate;
    std::string toDate;
    Booking(int idInput, double priceInput, std::string fromDateInput,
            std::string toDateInput);
    Booking(long idInput, double priceInput, char fromDateInput[], char toDateInput[]);

};

#endif // BOOKING_H

