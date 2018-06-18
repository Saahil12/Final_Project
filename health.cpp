#include "health.h"
#include <QFont>
#include <QMediaPlayer>
#include "game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent) :QGraphicsTextItem(parent){
    //inititalize score
    health = 3;

    //draw the text box
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",25)); //change this later
}

void Health::decrease_health()
{
    if (health > 1)
    {
        QMediaPlayer * health_loss = new QMediaPlayer();
        health_loss -> setMedia(QUrl("qrc:/sounds/losing_health.mp3"));
        health_loss -> play();

        health--;
        setPlainText("Health: " + QString::number(health));
    }

    else if (health == 1)
    {
        QMediaPlayer * game_over = new QMediaPlayer();
        game_over -> setMedia(QUrl("qrc:/sounds/game_over.mp3"));
        game_over -> play();

        health--;
        setPlainText("Health: " + QString::number(health));

        game -> gameOver();
    }
}

int Health::get_health()
{
    return health;
}
