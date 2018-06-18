#include "bullet_enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList> //using for colliding_items
#include "game.h"
#include "enemy2.h"
#include "wall.h"

extern Game * game; // there is an external global object called game

Bullet_Enemy2::Bullet_Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //drew the bullet
    setPixmap(QPixmap(":/images/enemy2_bullet.png"));


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer -> start(50);
}

void Bullet_Enemy2::move()
{
    //**************************************************************************
    //10C Implementations : Iterators, Generic Algorithms, and Lambda Functions
    //**************************************************************************

    QList<QGraphicsItem *> colliding_items2 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator j1 = colliding_items2.begin();
    QList<QGraphicsItem *>::Iterator j2 = colliding_items2.end();

/*
    //Generic Algorithm and Lambda Function causes program to crash unpredictably here
    //It works about 80% of the time

    //traverse collidingItems() to see if it is the player
    std::for_each(j1, j2, [this](QGraphicsItem* j){

        if ( typeid(*j) == typeid(Player))
        {
            //decrease the health
            game->health->decrease_health();

            //remove enemy & play explosion sound
            scene() -> removeItem(this);

            //delete the enemy bullet
            delete this;
            return; //so compiler doesn't try to run rest of move()
        }
    });
*/
    //traverse collidingItems() to see if it is the player
    while(j1 != j2)
    {
        if ( typeid(**j1) == typeid(Player))
        {
            //decrease the health
            game->health->decrease_health();

            //remove enemy & play explosion sound
            scene() -> removeItem(this);

            //delete the enemy bullet
            delete this;
            return; //so compiler doesn't try to run rest of move()
        }
        ++j1;

    }

    //move bullet down
    setPos(x(),y()+20);

    //remove from the scene and then delete it to save memory
    if (pos().y() > 600) //want to delete if bottom of bullet goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}


