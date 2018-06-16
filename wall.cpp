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
    QList<QGraphicsItem *> colliding_items2 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator l = colliding_items2.begin();

    //traverse collidingItems() to see if it is enemy or enemy_bullet

    while(l != colliding_items2.end())
    {
        if ( typeid(**l) == typeid(Enemy))
        {
               Wall2* wall2 = new Wall2(distance);
               scene() -> addItem(wall2);
               scene() -> removeItem(*l);
               scene() -> removeItem(this);

               delete *l;
               delete this;
        }
        else if (typeid(**l) == typeid(Bullet_Enemy2))
        {
               Wall2*  wall2 = new Wall2(distance);
               scene() -> addItem(wall2);
               scene() -> removeItem(*l);
               scene() -> removeItem(this);

               delete *l;
               delete this;
        }

        l++;
    }
}
