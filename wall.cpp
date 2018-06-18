#include "wall.h"
#include <QGraphicsScene>
#include "game.h"
#include <QTimer>
#include "enemy.h"
#include "bullet_enemy2.h"
#include "wall2.h"

extern Game * game;

Wall::Wall(int x): QObject(), QGraphicsPixmapItem()
{
    //set position of wall using parameters
    setPos(x,500);

    //drew the enemy
    setPixmap(QPixmap(":/images/wall1.png"));

    distance = x;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(defend()));
    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Wall::defend()
{
    //**************************************************************************
    //10C Implementations : Iterators, Generic Algorithms, and Lambda Functions
    //**************************************************************************

    QList<QGraphicsItem *> colliding_items4 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator l1 = colliding_items4.begin();
    QList<QGraphicsItem *>::Iterator l2 = colliding_items4.end();

    std::for_each(l1, l2, [this](QGraphicsItem* x){

            if ( typeid(*x) == typeid(Enemy))
            {
                   Wall2* wall2 = new Wall2(distance);
                   scene() -> addItem(wall2);
                   scene() -> removeItem(x);
                   scene() -> removeItem(this);

                   delete x;
                   delete this;
            }
            else if (typeid(*x) == typeid(Bullet_Enemy2))
            {
                   Wall2*  wall2 = new Wall2(distance);
                   scene() -> addItem(wall2);
                   scene() -> removeItem(x);
                   scene() -> removeItem(this);

                   delete x;
                   delete this;
            }
    });
}
