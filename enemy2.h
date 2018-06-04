#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Enemy2: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent = 0);

    int get_enemy_health();
    void decrease_enemy_health();

private:
    int enemy_health;

public slots:
    void move();

};
#endif // ENEMY2_H
