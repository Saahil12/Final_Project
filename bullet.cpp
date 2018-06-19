#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList> //using for colliding_items
#include "game.h"
#include "enemy2.h"
#include <QMediaPlayer>

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //drew the bullet
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

void Bullet::move()
{
    //**************************************************************************
    //10C Implementations : Iterators, Generic Algorithms, and Lambda Functions
    //**************************************************************************

    QList<QGraphicsItem *> colliding_items2 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator k1 = colliding_items2.begin();
    QList<QGraphicsItem *>::Iterator k2 = colliding_items2.end();

/*
    //Generic Algorithm and Lambda Function causes program to crash unpredictably here

    std::for_each(k1, k2, [this](QGraphicsItem* k){

    if ( typeid(**k) == typeid(Enemy2))
    {
        //play explosion sound
        QMediaPlayer * explosion_sound = new QMediaPlayer();
        explosion_sound -> setMedia(QUrl("qrc:/sounds/explosion.wav"));
        explosion_sound -> play();

        //remove enemy & bullet
        //scene() -> removeItem(this);
        scene() -> removeItem(*k);

        //delete the enemy bullet
        delete this;
        delete *k;
        return; //so compiler doesn't try to run rest of move()
    }
    });
*/

    //traverse collidingItems() to see if it colliding with enemy2
    while(k1 != k2)
    {
        if ( typeid(**k1) == typeid(Enemy2))
        {
            //play explosion sound
            QMediaPlayer * explosion_sound = new QMediaPlayer();
            explosion_sound -> setMedia(QUrl("qrc:/sounds/invaderkilled.wav"));
            explosion_sound -> play();

            //increase score;
            game -> score -> increase_score();

            //remove enemy & bullet
            //scene() -> removeItem(this);
            scene() -> removeItem(*k1);

            //delete the enemy bullet
            delete this;
            delete *k1;
            return; //so compiler doesn't try to run rest of move()
        }
        ++k1;
    }

    //move bullet up
    setPos(x(),y()-20);

    //remove from the scene and then delete it to save memory
    if (pos().y() < 0 ) //want to delete if bottom of bullet goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}
