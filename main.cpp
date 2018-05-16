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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put into the scene
    MyRect * rect = new MyRect();
    rect -> setRect(0,0,100,100);

    //add the item to scene
    scene ->addItem(rect);

    //only one item can respond to events at a time and that is the focus item
    rect ->setFlag(QGraphicsItem::ItemIsFocusable); //makes rect focusable
    rect -> setFocus(); //hey rect you are now the focused item so you will recieve all the keyboard events

    //add a view and show it
    QGraphicsView * view = new QGraphicsView();
    view -> setScene(scene);
    view -> show();


    //Final_project w;
    //w.show();

    return a.exec();
}
\
