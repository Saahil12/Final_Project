#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
};

#endif // ENEMY_H
