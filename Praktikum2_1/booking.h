#ifndef BOOKING_H
#define BOOKING_H
#include <QString>
#include <QDate>
class Booking
{
public:
    Booking();
    virtual ~Booking();
    virtual QString showDetails() = 0;
    int getId() const;

    double getPrice() const;
    QDate getFromQDate();
    QDate getToQdate();
    void setFromQDate(QDate fromDateInput);
    void settoQDate(QDate toDateInput);
    void setPrice(double newPrice);

    const QString &getFromDate() const;
    void setFromDate(const QString &newFromDate);

    const QString &getToDate() const;

protected:
    long travelId;
    int id;
    double price;
    QString fromDate;
    QString toDate;
    Booking(int idInput, double priceInput, QString fromDateInput,
            QString toDateInput);
    Booking(long idInput, double priceInput, char fromDateInput[], char toDateInput[]);

};

#endif // BOOKING_H

