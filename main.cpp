#include "final_project.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

/*
 QGraphicsScene : a container for all your objects in the game (players and stuff)
 QGraphicsItem is where objects are derived before going into the scene above
 QGraphicsView a widget used to visualize the scene, scene is just a container that needs to be viewed
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect -> setRect(0,0,100,100);

    //add the item to scene
    scene ->addItem(rect);

    //add a view and show it
    QGraphicsView * view = new QGraphicsView();
    view -> setScene(scene);
    view -> show();

    //Final_project w;
    //w.show();

    return a.exec();
}
\
