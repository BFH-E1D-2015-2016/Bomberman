
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QThread>
#include "playfield.h"
#include "game.h"
#include "bomb.h"


int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);


        Game * game = new Game(); //Das Spiel wird erstellt und gestartet

        return a.exec();

    }
    catch (const std::exception &exc)
    {
        // catch anything thrown within try block that derives from std::exception
        qDebug()<<"error: " << exc.what();
    }

    return 0;
}

