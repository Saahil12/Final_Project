#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "wall.h"
#include <QDebug>
#include "button.h"

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

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    start();
}

void Game::start()
{
    //create an item to put into the scene
    player = new Player();
    player -> setPos(330, 500);

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


void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
        QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(color);
        panel->setBrush(brush);
        panel->setOpacity(opacity);
        scene->addItem(panel);
}

void Game::restart()
{
    scene->clear();
    start();
}

void Game::gameOver()
{
    //disable scene items
    int n = scene->items().size();

    for (int i=0; i<n; i++)
    {
        scene->items()[i] -> setEnabled(false);
    }

    //pop up game over screen
    drawPanel(0,0,scene->width(),scene->height(),Qt::black,0.65);
    drawPanel(250,100,300,300,Qt::lightGray,0.75);

    //create "Game Over" text
    QString end = "Game Over";
    QGraphicsTextItem* gameover = new QGraphicsTextItem(QString(end));
    gameover -> setPos(400,150);
    scene -> addItem(gameover);

    //create playagain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain -> setPos(300,225);
    scene -> addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restart()));

    //create quit button
    Button* quit = new Button(QString("Quit"));
    quit -> setPos(300,300);
    scene -> addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
}


