#include "booking.h"
Booking::Booking()
{

}

Booking::~Booking()
{

}

int Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

QDate Booking::getFromQDate()
{
    QDate date(fromDate.mid(6,4).toInt(),fromDate.mid(3,2).toInt(),fromDate.mid(0,2).toInt());
    return date;
}

QDate Booking::getToQdate()
{
    QDate date(toDate.mid(6,4).toInt(),toDate.mid(3,2).toInt(),toDate.mid(0,2).toInt());
    QDate test2(1234,12,23);
    return date;
}

void Booking::setFromQDate(QDate fromDateInput)
{
    fromDate = fromDateInput.toString("dd.MM.yyyy");
}

void Booking::settoQDate(QDate toDateInput)
{
    toDate = toDateInput.toString("dd.MM.yyyy");
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

const QString &Booking::getFromDate() const
{
    return fromDate;
}

void Booking::setFromDate(const QString &newFromDate)
{
    fromDate = newFromDate;
}

const QString &Booking::getToDate() const
{
    return toDate;
}

Booking::Booking(int idInput, double priceInput, QString fromDateInput,
                 QString toDateInput)
    :id(idInput), price(priceInput), fromDate(fromDateInput), toDate(toDateInput)
{
    //DatumFormatierung:
fromDate = fromDate.mid(6,2) + "." + fromDate.mid(4,2) + "." + fromDate.mid(0,4);
toDate = toDate.mid(6,2) + "." + toDate.mid(4,2) + "." + toDate.mid(0,4);
}

Booking::Booking(long idInput, double priceInput, char fromDateInput[], char toDateInput[])
{
    id = idInput;
    price = priceInput;
    //fromDate formatieren:
    {
    QString tag, monat, jahr;
    for(int i = 0; i < 4; i++){
        jahr.push_back(fromDateInput[i]);
    }
    monat.push_back(fromDateInput[4]);
    monat.push_back(fromDateInput[5]);
    tag.push_back(fromDateInput[6]);
    tag.push_back(fromDateInput[7]);
    fromDate = tag + '.' + monat + '.' + jahr;
    }
    //toDate formatieren:
    {
    QString tag, monat, jahr;
    for(int i = 0; i < 4; i++){
        jahr.push_back(toDateInput[i]);
    }
    monat.push_back(toDateInput[4]);
    monat.push_back(toDateInput[5]);
    tag.push_back(toDateInput[6]);
    tag.push_back(toDateInput[7]);
    toDate = tag + '.' + monat + '.' + jahr;
    }
}
