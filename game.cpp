#include "game.h"

Game::Game()
{
    Key_Down = Key_Left = Key_Right = Key_Up =0;

    //Spieltimer initsialisieren
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(gameloop()));


    // Spielfelg generieren
    playfield = new Playfield();
    player = new Player(playfield,31,31);

    bomb = new Bomb(playfield,player);
    bomb->setBomb();

    //Scene erstellen
    scene = new QGraphicsScene();

    //Spielfeld zeichen
    playfield->Draw(scene);
    scene->addItem(player);
    scene->addItem(bomb);

    //Timer starten
    timer->start(33);
}

Game::~Game()
{
    timer->stop();
}

void Game::gameloop()
{

    //player->move(moveX, moveY);
    draw();
}

void Game::draw()
{

    //Scene mit Spielfeld darstellen
    setScene(scene);
    show();
    setFocus();
}


void Game::keyPressEvent(QKeyEvent *event)
{
    int count = event->count();
    int i =0;

    for(i=0; i<count;i++)
    {

        if(event->key() == Qt::Key_Left)
            Key_Left = 1;
        if(event->key() == Qt::Key_Right)
           Key_Right = 1;
        if(event->key() == Qt::Key_Up)
           Key_Up = 1;
        if(event->key() == Qt::Key_Down)
            Key_Down = 1;
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    int count = event->count();
    int i =0;

    for(i=0; i<count;i++)
    {
        if(event->key() == Qt::Key_Left)
            Key_Left = 0;
        if(event->key() == Qt::Key_Right)
           Key_Right = 0;
        if(event->key() == Qt::Key_Up)
           Key_Up = 0;
        if(event->key() == Qt::Key_Down)
           Key_Down = 0;
    }

}

