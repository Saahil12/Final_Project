#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    //drew the bullet
    setRect(0,0,10,50);

    //connect timer to bullet
    QTimer * timer = new QTimer();

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Bullet::move()
{
    //move bullet up
    setPos(x(),y()-10);

    //remove from the scene and then delete it to save memory
    if (pos().y() + rect().height() < 0 ) //want to delete if bottom right of bullet goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}
