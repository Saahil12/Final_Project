#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) :QGraphicsTextItem(parent){
    //inititalize score
    health = 3;

    //draw the text box
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",25)); //change this later
}

void Health::decrease_health()
{
    health--;
    setPlainText("Health: " + QString::number(health));
}

int Health::get_health()
{
    return health;
}
