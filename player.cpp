#include "player.h"
#include <QKeyEvent>
#include <bullet.h>
#include <QGraphicsScene>
#include <enemy.h>
#include <enemy2.h>
#include <QMediaPlayer> //for sounds


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    //set graphics
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Left)
    {
        if (pos().x() >0)  //to stay on view
        { setPos(x()-53,y()); }
    }
    else if (event -> key() == Qt::Key_Right)
    {
        if (pos().x()+ 150 < 800) //to stay on view
        { setPos(x()+53,y()); }
    }
    /*
    else if (event -> key() == Qt::Key_Up)
    {
        setPos(x(),y()-20);
    }
    else if (event -> key() == Qt::Key_Down)
    {
        setPos(x(),y()+20);
    }
    */
    else if (event -> key() == Qt::Key_Space)
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet -> setPos(x()+69,y()); //set position at rectangles x & y
        scene() -> addItem(bullet); //add it to the scene

        //play bullet sound
        QMediaPlayer * bullet_sound = new QMediaPlayer();
        bullet_sound -> setMedia(QUrl("qrc:/sounds/bullet.wav"));
        bullet_sound -> play();
    }
}

void Player::spawn()
{
    //create enemy
    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);
}

void Player::spawn2()
{
    //create enemy2
    Enemy2 * enemy2 = new Enemy2();
    scene() -> addItem(enemy2);
}
