#include "game.h"

int x=0;
Game::Game()
{
    //Neues Grafikfenster erstellen
    view = new QGraphicsView();

    //Spieltimer initsialisieren
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(gameloop()));

    // Spielfelg generieren
    playfield = new Playfield();

    //Timer starten
    timer->start(1000);
}

void Game::gameloop()
{

    draw();
}

void Game::draw()
{
    //Scene erstellen
    scene = new QGraphicsScene();

    //Spielfeld zeichen
    playfield->Draw(scene);

    //Scene mit Spielfeld darstellen

    //if(view==NULL)
     //   view = new QGraphicsView();
    view->setScene(scene);
    view->show();
}
