#include "final_project.h"
#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>

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
        2.... have to ass Q_OBJECT macro
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put into the scene
    MyRect * player = new MyRect();
    player -> setRect(0,0,100,100);

    //add the item to scene
    scene ->addItem(player);
    scene -> setSceneRect(0,0,600,450);

    //only one item can respond to events at a time and that is the focus item
    player ->setFlag(QGraphicsItem::ItemIsFocusable); //makes rect focusable
    player -> setFocus(); //hey rect you are now the focused item so you will recieve all the keyboard events

    //add a view and show it
    QGraphicsView * view = new QGraphicsView();
    view -> setScene(scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> show();
    view -> setFixedSize(600,450);

    player -> setPos(view->width()/2, view->height() - player->rect().height());

    //Final_project w;
    //w.show();

    return a.exec();
}
\
