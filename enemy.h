#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0);

    int get_enemy_health();
    void decrease_enemy_health();

private:
    int enemy_health;

public slots:
    void move();

};

#endif // ENEMY_H
