#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()

Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 500;
    setPos(random_number,0);

    //drew the enemy
    setRect(0,0,100,100);

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Enemy::move()
{
    //move enemy down
    setPos(x(),y()+5);

    //remove from the scene and then delete it to save memory
    if (pos().y() + rect().height() < 0 ) //want to delete if bottom right of bullet goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}
