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
    QList<QGraphicsItem *> colliding_items3 = this->collidingItems();
    QList<QGraphicsItem *>::Iterator k = colliding_items3.begin();

    //traverse collidingItems() to see if it colliding with enemy2
    while(k != colliding_items3.end())
    {
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
        k++;
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
