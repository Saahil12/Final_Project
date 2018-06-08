#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Enemy2: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent = 0);


private:

public slots:
    void move();
    void fire();

};
#endif // ENEMY2_H
