
#include <QApplication>
#include <QGraphicsView>
#include "myrect.h"
#include <QGraphicsScene>
#include <QThread>
#include "playfield.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game * game = new Game();
    game->draw();

    return a.exec();
}
