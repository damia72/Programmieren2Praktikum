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
    QDate date(stoi(fromDate.substr(6,4)),stoi(fromDate.substr(3,2)),stoi(fromDate.substr(0,2)));
    return date;
}

QDate Booking::getToQdate()
{
    QDate date(stoi(toDate.substr(6,4)),stoi(toDate.substr(3,2)),stoi(toDate.substr(0,2)));
    return date;
}

void Booking::setFromQDate(QDate fromDateInput)
{
    fromDate = fromDateInput.toString("dd.MM.yyyy").toStdString();
}

void Booking::settoQDate(QDate toDateInput)
{
    toDate = toDateInput.toString("dd.MM.yyyy").toStdString();
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

Booking::Booking(int idInput, double priceInput, std::string fromDateInput,
                 std::string toDateInput)
    :id(idInput), price(priceInput), fromDate(fromDateInput), toDate(toDateInput)
{
    //DatumFormatierung:
fromDate = fromDate.substr(6,2) + "." + fromDate.substr(4,2) + "." + fromDate.substr(0,4);
toDate = toDate.substr(6,2) + "." + toDate.substr(4,2) + "." + toDate.substr(0,4);
}

Booking::Booking(long idInput, double priceInput, char fromDateInput[], char toDateInput[])
{
    id = idInput;
    price = priceInput;
    //fromDate formatieren:
    {
    std::string tag, monat, jahr;
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
    std::string tag, monat, jahr;
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
