#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "wall.h"

/*
 QGraphicsScene : a container for all your objects in the game (players and stuff)
 QGraphicsItem is where objects are derived before going into the scene above
 QGraphicsView a widget used to visualize the scene, scene is just a container that needs to be viewed
*/
/*
 event is anything that happens during the lifetime of application
    Ex: keyPressEvent()
 event propagation system : order of key events
*/
/*
 signal is just a signal
 slot is the reaction to the signal, usually a member function placed under public slots: in class
        1.... have to inherit from QObject
        2.... have to add Q_OBJECT macro
*/

Game::Game(QWidget *parent){
    //create a scene
    scene = new QGraphicsScene();
    scene -> setSceneRect(0,0,800,600);
    scene -> setBackgroundBrush(QBrush(QImage(":/images/spacebg.jpeg")));

    //add a view and show it
    /*
    QGraphicsView * view = new QGraphicsView();
    view -> setScene(scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> show();
    view -> setFixedSize(800,600);
    */

    setScene(scene);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(800,600);


    //create an item to put into the scene
    player = new Player();
    player -> setPos(340, 500);

    //only one item can respond to events at a time and that is the focus item
    player ->setFlag(QGraphicsItem::ItemIsFocusable); //makes rect focusable
    player -> setFocus(); //hey rect you are now the focused item so you will recieve all the keyboard events

    //add the item to scene
    scene ->addItem(player);

    //create the score
    score = new Score();
    scene ->addItem(score);

    //create the health
    health = new Health();
    health -> setPos(health->x(), health->y()+25);
    scene -> addItem(health);

    //spawn enemy
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer -> start(2000); //2000ms so every 2 sec

    //spawn enemy2
    QTimer * timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn2()));
    timer2 -> start(7000); //7000ms so every 7 sec

    //create defense walls;
    Wall * wall1 = new Wall(10);
    scene -> addItem(wall1);

    Wall * wall2 = new Wall(110);
    scene -> addItem(wall2);

    Wall * wall3 = new Wall(220);
    scene -> addItem(wall3);

    Wall * wall4 = new Wall(320);
    scene -> addItem(wall4);

    Wall * wall5 = new Wall(410);
    scene -> addItem(wall5);

    Wall * wall6 = new Wall(510);
    scene -> addItem(wall6);

    Wall * wall7 = new Wall(610);
    scene -> addItem(wall7);

    Wall * wall8 = new Wall(710);
    scene -> addItem(wall8);
}

