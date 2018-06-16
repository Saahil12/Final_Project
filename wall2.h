#ifndef WALL2_H
#define WALL2_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for anything using signal and slots

class Wall2: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Wall2(int x);

private:

public slots:
    void defend();
};
#endif // WALL2_H
