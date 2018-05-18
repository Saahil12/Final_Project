#include "bullet.h"
#include <QTimer>

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
}