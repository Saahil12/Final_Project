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
    QList<QGraphicsItem *> colliding_items3 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator s = colliding_items3.begin();

    //traverse collidingItems() to see if it is enemy or enemy_bullet
    while(s != colliding_items3.end())
    {
        if ( typeid(**s) == typeid(Enemy))
        {
                scene() -> removeItem(*s);
                scene() -> removeItem(this);

                delete *s;
                delete this;
        }

        else if (typeid(**s) == typeid(Bullet_Enemy2))
        {
                scene() -> removeItem(*s);
                scene() -> removeItem(this);

                delete *s;
                delete this;
        }

        s++;
    }
}
