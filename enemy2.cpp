#include "enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()
#include "game.h"
#include <QList> //using for colliding_items
#include "bullet_enemy2.h"
#include <QMediaPlayer>
#include <iterator>


extern Game * game;

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    int random_number = rand() % 150;
    setPos(815,random_number);

    //drew the enemy
    setPixmap(QPixmap(":/images/enemy2.png"));

    //intitialize health
    enemy_health = 2;


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer -> start(50);

    //connect timer to enemy bullet
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(fire()));
    timer2 -> start(1000); //4000ms so every 4 sec

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
    setPos(x()-10,y());

    //remove from the scene and then delete it to save memory
    if (pos().x() < -70 ) //want to delete if enemy goes out of scene
    {
        scene() -> removeItem(this);
        delete this;
    }
}

void Enemy2::fire()
{
    //create a bullet
    Bullet_Enemy2 * enemy_bullet = new Bullet_Enemy2();
    enemy_bullet -> setPos(x()+30,y()+50);
    scene() -> addItem(enemy_bullet); //add it to the scene
}
