#ifndef FUELDISPLAY_H
#define FUELDISPLAY_H

#include <QtWidgets>
#include "bargraph.h"

//! FuelDisplay Class
/*!
 * This class creates a compact fuel window to display various calculations related to fuel flow and flight plan information if available.
*/

class FuelDisplay : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit FuelDisplay(QGraphicsObject* parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setFuelFlow(double value);
    void setTimeToDestination(double time);
    void reduceFuelAmount(double fuel)
    {
        fuelAmount -= fuel;
        this->update();
    }
private:
    QSettings settings;
    double fuelAmount;
    QString fuelUnits;
    double fuelFlow;
    double timeToDestination;
    QRectF remainingFuelRect;
    QRectF remainingFuelAtDestinationRect;
    QRectF mpgRect;
    QRectF rangeRect;
    BarGraph fuelFlowGraph;

public slots:
    void onFuelAmountChange(QString changeDirection); // Direction is + or -
};

#endif // FUELDISPLAY_H
