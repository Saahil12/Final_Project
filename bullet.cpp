#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList> //using for colliding_items
#include "enemy.h"

Bullet::Bullet()
{
    //drew the bullet
    setRect(0,0,10,50);

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Bullet::move()
{
    //check if it is colliding with an enemy....if so, destroy both
    //use collidingItem
    QList<QGraphicsItem *> colliding_items = collidingItems(); //will return a list
                                                              // of pointers to all the QgraphicItems that
                                                              // the bullet is colliding with
    //traverse collidingItems() to see if it is an enemy
    //MAYBE USE ITERATORS HERE LATER
    int n = colliding_items.size();
    for (int x=0; x<n; x++)
    {
        if(typeid(*(colliding_items[x])) == typeid(Enemy))
        {
            //remove both
            scene() -> removeItem(colliding_items[x]);
            scene() -> removeItem(this);
            //delete both
            delete colliding_items[x];
            delete this;
            return; //so compiler doesn't try to run rest of move()
        }
    }

    //move bullet up
    setPos(x(),y()-10);

    //remove from the scene and then delete it to save memory
    if (pos().y() + rect().height() < 0 ) //want to delete if bottom right of bullet goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}
