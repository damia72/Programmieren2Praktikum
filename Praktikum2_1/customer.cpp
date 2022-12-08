#include "customer.h"

Customer::Customer(long id, QString name) : id(id), name(name)
{

}

void Customer::addTravel(Travel *travel)
{
    //guck ob der travel schon existiert und wenn ja dann pushback wenn nicht dann fehlermeldung

    long searchId = travel->getId();
    for(unsigned int i = 0; i < travelList.size(); i++){
        if(travelList[i]->getId() == searchId){
            qDebug() << "Achtung doppelung gefunden";
            return;
        }
    }
    travelList.push_back(travel);
    //um den zu viele travels problem zu debuggen:
    static int travelpushbacks = 0;
    travelpushbacks++;
    qDebug() << travelpushbacks << "\n";
}

long Customer::getId() const
{
    return id;
}

QString Customer::showDetails()
{
    return "Der Kunde mit der id " + QString::number(id) + " und dem Namen " + name + " hat " +  QString::number(travelList.size()) + " Reisen gebucht";
}

std::vector<Travel *> Customer::getTravelList() const
{
    return travelList;
}
