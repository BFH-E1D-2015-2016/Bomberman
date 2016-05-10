
#include <QApplication>
#include <QGraphicsView>
#include "myrect.h"
#include <QGraphicsScene>
#include <QThread>
#include "playfield.h"
#include "game.h"
#include "bomb.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game * game = new Game();
    game->draw();
    return a.exec();
/*
    //Scene erstellen
    QGraphicsScene * scene = new QGraphicsScene();

    //Rechteck erstellen
    myrect * rect  =new myrect();
    rect->setRect(0,0,100,100);                                             //Grösse und Position setzen
    rect->setFlag(QGraphicsItem::ItemIsFocusable);          //Fokusierbar machen (für Keyevents)
    rect->setFocus();                                                        //Fokus setzen. Jetzt können Keyevents erkennt werden

    // Spielfelg generieren
    Playfield * playfield = new Playfield();

    Block * block = new Block(100,00, MODE_DESTROYABLE);

    //Rechteck zeichen
    playfield->Draw(scene);
     scene-> addItem(block);

    //Scene mit Rechteck darstellen

     QGraphicsView * view = new QGraphicsView();

    playfield->current_hightlite(000,0);
    playfield->current_hightlite(100,50);
    playfield->current_hightlite(250,100);
    playfield->current_hightlite(000,0);



    view->setScene(scene);
    view->show();
*/


}
