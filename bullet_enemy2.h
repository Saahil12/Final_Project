#ifndef BULLET_ENEMY2_H
#define BULLET_ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Bullet_Enemy2: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet_Enemy2(QGraphicsItem * parent = 0);

public slots:
    void move();
};

#endif // BULLET_ENEMY2_H
