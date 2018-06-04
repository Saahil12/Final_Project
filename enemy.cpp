#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()
#include "game.h"
#include <QList> //using for colliding_items
#include "bullet.h"
#include <QMediaPlayer>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    int random_number = rand() % 720;
    setPos(random_number,0);

    //drew the enemy
    setPixmap(QPixmap(":/images/enemy.png"));

    //intitialize health
    enemy_health = 2;

    //connect timer to bullet
    QTimer * timer = new QTimer(this);

    //connect function allows you to connect certain signal with certain slot
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //this connects timeout signal from timer to move slot of the bullet

    timer -> start(50); //sets the timers time to every 50ms, thus when it's timeout signal will be emmited
}

int Enemy::get_enemy_health()
{
    return enemy_health;
}

void Enemy::decrease_enemy_health()
{
    enemy_health = enemy_health - 1;
}

void Enemy::move()
{
    //check if it is colliding with player....if so, destroy enemy & decrease health of player
    //use collidingItem
    QList<QGraphicsItem *> colliding_items = collidingItems(); //will return a list
                                                              // of pointers to all the QgraphicItems that
                                                              // the enemy is colliding with
    //traverse collidingItems() to see if it is a player or bullet
    //*****************************
    //MAYBE USE ITERATORS HERE LATER
    int n = colliding_items.size();
    for (int x=0; x<n; ++x)
    {
        if(typeid(*(colliding_items[x])) == typeid(Player))
        {
            //decrease the health
            game->health->decrease_health();

            //remove enemy & play explosion sound
            scene() -> removeItem(this);

            //delete enemy
            delete this;
            return; //so compiler doesn't try to run rest of move()
        }

        if(typeid(*(colliding_items[x])) == typeid(Bullet))
        {
            if (this -> get_enemy_health() >= 1)
            {
                //decrease enemy health
                this->decrease_enemy_health();

                //remove & delete bullet happens in bullet.move();
            }

            else if (this -> get_enemy_health() < 1)
            {
                //increase the score
                game->score->increase_score();

                //play explosion sound
                QMediaPlayer * explosion_sound = new QMediaPlayer();
                explosion_sound -> setMedia(QUrl("qrc:/sounds/explosion.wav"));
                explosion_sound -> play();

                //remove & delete enemy
                delete this;

                return; //so compiler doesn't try to run rest of move()
            }
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
    }
}
