#ifndef UPANDAWAY_H
#define UPANDAWAY_H

#include "qlistwidget.h"
#include "travelagency.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UpAndAway; }
QT_END_NAMESPACE

class UpAndAway : public QMainWindow
{
    Q_OBJECT

public:
    UpAndAway(QWidget *parent = nullptr);
    ~UpAndAway();

private slots:
    void on_readFileButton_clicked();

    void on_idInputSpinBox_valueChanged(int arg1);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_JSONErstellenButton_clicked();

    void on_fromDateEdit_userDateChanged(const QDate &date);

    void on_toDateEdit_userDateChanged(const QDate &date);

    void on_priceSpinBox_textChanged(const QString &arg1);

    void on_priceSpinBox_valueChanged(double arg1);

    void on_fromDestinationLineEdit_textChanged(const QString &arg1);

    void on_toDestinationLineEdit_textChanged(const QString &arg1);

    void on_companyLineEdit_textChanged(const QString &arg1);

    void on_pickupStationLineEdit_textChanged(const QString &arg1);

    void on_returnStationLineEdit_textChanged(const QString &arg1);

    void on_hotelLineEdit_textChanged(const QString &arg1);

    void on_townLineEdit_textChanged(const QString &arg1);

    void on_fromDestinationLineEdit_textEdited(const QString &arg1);

    void on_toDestinationLineEdit_textEdited(const QString &arg1);

    void on_companyLineEdit_textEdited(const QString &arg1);

    void on_hotelLineEdit_textEdited(const QString &arg1);

    void on_townLineEdit_textEdited(const QString &arg1);

    void on_pickupStationLineEdit_textEdited(const QString &arg1);

    void on_returnStationLineEdit_textEdited(const QString &arg1);

private:
    Ui::UpAndAway *ui;
    int selectedBookingVectorLocation;
    int selectedId;
    TravelAgency travelagency;
};
#endif // UPANDAWAY_H
