#include "wall.h"
#include <QGraphicsScene>
#include "game.h"

extern Game * game;

Wall::Wall(int x): QObject(), QGraphicsPixmapItem()
{
    //set position of wall using parameters
    setPos(x,500);

    //drew the enemy
    setPixmap(QPixmap(":/images/wall1.png"));
}

void Wall::remove()
{

    delete this;
}
