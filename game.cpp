#include "game.h"
#include <QKeyEvent>

int x=0;
Game::Game(QObject *parent) : QObject(parent)
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
    qDebug()<<"tick..";
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


void Game::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Taste gedrückt";
    if(event->key() == Qt::Key_Left)
        Key_Left = 1;
    if(event->key() == Qt::Key_Right)
       Key_Right = 1;
    if(event->key() == Qt::Key_Up)
       Key_Up = 1;
    if(event->key() == Qt::Key_Down)
        Key_Down = 1;
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    qDebug()<<"Taste losgelassen";
    if(event->key() == Qt::Key_Left)
        Key_Left = 0;
    if(event->key() == Qt::Key_Right)
       Key_Right = 0;
    if(event->key() == Qt::Key_Up)
       Key_Up = 0;
    if(event->key() == Qt::Key_Down)
       Key_Down = 0;
}
