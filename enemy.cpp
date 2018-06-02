#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()
#include "game.h"
#include <QMediaPlayer>
#include <QList> //using for colliding_items

extern Game * game;

Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 720;
    setPos(random_number,0);

    //drew the enemy
    setPixmap(QPixmap(":/images/enemy.png"));

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Enemy::move()
{
    //check if it is colliding with player....if so, destroy enemy & decrease health
    //use collidingItem
    QList<QGraphicsItem *> colliding_items = collidingItems(); //will return a list
                                                              // of pointers to all the QgraphicItems that
                                                              // the enemy is colliding with
    //traverse collidingItems() to see if it is an enemy
    //*****************************
    //MAYBE USE ITERATORS HERE LATER
    int n = colliding_items.size();
    for (int x=0; x<n; x++)
    {
        if(typeid(*(colliding_items[x])) == typeid(Player))
        {
            //increase the score
            game->health->decrease_health();

            //remove enemy & play explosion sound
            scene() -> removeItem(this);

            QMediaPlayer * health_loss = new QMediaPlayer();
            health_loss -> setMedia(QUrl("qrc:/sounds/losing_health.mp3"));
            health_loss -> play();

            //delete enemy
            delete this;
            return; //so compiler doesn't try to run rest of move()
        }
    }

    //move enemy down
    setPos(x(),y()+5);

    //remove from the scene and then delete it to save memory
    if (pos().y() > scene()->height() ) //want to delete if enemy goes out of scene
    {
        game->health->decrease_health();
        scene() -> removeItem(this);
        delete this;

        QMediaPlayer * health_loss = new QMediaPlayer();
        health_loss -> setMedia(QUrl("qrc:/sounds/losing_health.mp3"));
        health_loss -> play();
    }
}
