#include <QApplication>
#include "game.h"
#include "health.h"

Game *game; //global b/c other objects need to access it

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game-> show();

    return a.exec();
}
\
