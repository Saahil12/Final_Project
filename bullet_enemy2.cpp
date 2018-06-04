#include "bullet_enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList> //using for colliding_items
#include "game.h"
#include "enemy2.h"

extern Game * game; // there is an external global object called game

Bullet_Enemy2::Bullet_Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //drew the bullet
    setPixmap(QPixmap(":/images/enemy2_bullet.png"));

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Bullet_Enemy2::move()
{

    //move bullet down
    setPos(x(),y()+10);

    //remove from the scene and then delete it to save memory
    if (pos().y() > 600) //want to delete if bottom of bullet goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}


