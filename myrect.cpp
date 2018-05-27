#include "myrect.h"
#include <QDebug>
#include <QKeyEvent>
#include <bullet.h>
#include <QGraphicsScene>
#include <enemy.h>
#include <QDebug>
#include <QMediaPlayer> //for sounds
void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Left)
    {
        if (pos().x() >0)  //to stay on view
        { setPos(x()-30,y()); }
    }
    else if (event -> key() == Qt::Key_Right)
    {
        if (pos().x()+ rect().width() < 800) //to stay on view
        { setPos(x()+30,y()); }
    }
    else if (event -> key() == Qt::Key_Up)
    {
        setPos(x(),y()-20);
    }
    else if (event -> key() == Qt::Key_Down)
    {
        setPos(x(),y()+20);
    }
    else if (event -> key() == Qt::Key_Space)
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet -> setPos(x()+45,y()); //set position at rectangles x & y
        scene() -> addItem(bullet); //add it to the scene

        //play bullet sound
        QMediaPlayer * bullet_sound = new QMediaPlayer();
        bullet_sound -> setMedia(QUrl("qrc:/sounds/bullet.wav"));
        bullet_sound -> play();
    }
}

void MyRect::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);
}
