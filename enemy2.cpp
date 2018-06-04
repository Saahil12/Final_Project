#include "enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()
#include "game.h"
#include <QList> //using for colliding_items
#include "bullet.h"
#include <QMediaPlayer>
#include <iterator>


extern Game * game;

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    int random_number = rand() % 150;
    setPos(820,random_number);

    //drew the enemy
    setPixmap(QPixmap(":/images/enemy2.png"));

    //intitialize health
    enemy_health = 2;

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

int Enemy2::get_enemy_health()
{
    return enemy_health;
}

void Enemy2::decrease_enemy_health()
{
    enemy_health = enemy_health - 1;
}

void Enemy2::move()
{

    //move enemy left
    setPos(x()-5,y());

    //remove from the scene and then delete it to save memory
    if (pos().x() < -70 ) //want to delete if enemy goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}
