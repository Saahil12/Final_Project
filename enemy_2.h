#ifndef ENEMY_2_H
#define ENEMY_2_H


class Enemy_2: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy_2(QGraphicsItem * parent = 0);

    int get_enemy_health();
    void decrease_enemy_health();

private:
    int enemy_health;

public slots:
    void move();

};

#endif // ENEMY_2_H
