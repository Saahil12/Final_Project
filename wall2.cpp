#include "wall2.h"
#include <QGraphicsScene>
#include "game.h"
#include <QTimer>
#include "enemy.h"
#include "bullet_enemy2.h"

extern Game * game;

Wall2::Wall2(int x): QObject(), QGraphicsPixmapItem()
{
    //set position of wall using parameters
    setPos(x,500);

    //drew the enemy
    setPixmap(QPixmap(":/images/wall2.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(defend()));
    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Wall2::defend()
{
    //**************************************************************************
    //10C Implementations : Iterators, Generic Algorithms, and Lambda Functions
    //**************************************************************************

    QList<QGraphicsItem *> colliding_items5 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator s1 = colliding_items5.begin();
    QList<QGraphicsItem *>::Iterator s2 = colliding_items5.end();

    //traverse collidingItems() to see if it is enemy or enemy_bullet
    std::for_each(s1, s2, [this](QGraphicsItem* x){

        if ( typeid(*x) == typeid(Enemy))
        {
                scene() -> removeItem(x);
                scene() -> removeItem(this);

                delete x;
                delete this;
        }

        else if (typeid(*x) == typeid(Bullet_Enemy2))
        {
                scene() -> removeItem(x);
                scene() -> removeItem(this);

                delete x;
                delete this;
        }
    });
}
