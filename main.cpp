
#include <QApplication>
#include <QGraphicsView>
#include "myrect.h"
#include <QGraphicsScene>
#include <QThread>
#include "playfield.h"
#include "game.h"

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);

        Game * game = new Game();
        return a.exec();

    }
    catch (const std::exception &exc)
    {
        // catch anything thrown within try block that derives from std::exception
        qDebug()<<"error: " << exc.what();
    }

}
