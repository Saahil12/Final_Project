#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QDebug>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    text->setPos(x,13);

    //to allow hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}
