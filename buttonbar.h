#ifndef BUTTONBAR_H
#define BUTTONBAR_H

#include <QtWidgets>
#include <QFile>

class ButtonBar : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit ButtonBar(QGraphicsObject * parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    int numOfButtons = 4;
    int buttonLocation = 1; // 1-Bottom; 2-Top; 3-Left Side; 4-Right Side
    int buttonDisplay = 1; //1-Menu; 2-Fuel; 3-Settings


private:
    QRectF buttonRect1 = QRectF(0,-50.0,100,50);
    QRectF buttonRect2 = QRectF(100,-50.0,100,50);
    QRectF buttonRect3 = QRectF(200,-50.0,100,50);
    QRectF buttonRect4 = QRectF(300,-50.0,100,50);
    QRectF buttonRect5 = QRectF(400,-50.0,100,50);
    QRectF buttonRect6 = QRectF(500,-50.0,100,50);

    QLinearGradient gradient1 = QLinearGradient(buttonRect1.topLeft(), QPointF(0,0.7*buttonRect1.top()));
    QLinearGradient gradient2 = QLinearGradient(buttonRect2.topLeft(), QPointF(buttonRect2.left(),0.7*buttonRect2.top()));
    QLinearGradient gradient3 = QLinearGradient(buttonRect3.topLeft(), QPointF(buttonRect3.left(),0.7*buttonRect3.top()));



signals:
    void sendAlarmAck();
    void sendFuelChange(QString changeDirection); //  + or -
};

#endif // BUTTONBAR_H
