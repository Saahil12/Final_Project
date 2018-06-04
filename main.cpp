#include <QApplication>
#include "game.h"

Game *game; //global b/c other objects need to access it

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();

    return a.exec();
}
\
