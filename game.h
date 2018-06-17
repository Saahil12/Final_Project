#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    void gameOver();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

public slots:
    void start();
    void restart();
};
#endif // GAME_H
