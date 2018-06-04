#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject> //to use signals and slots.... also include Q_OBJECT macro
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();
    void spawn2();
};


#endif // MYRECT_H
