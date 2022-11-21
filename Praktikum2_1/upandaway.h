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

private:
    Ui::UpAndAway *ui;
    int selectedBookingVectorLocation;
    int selectedId;
    TravelAgency travelagency;
};
#endif // UPANDAWAY_H
