#ifndef WALL_H
#define WALL_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Wall: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Wall(int x);

private:

public slots:
    void remove();

};
#endif // WALL_H
