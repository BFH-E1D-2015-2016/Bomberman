#include "game.h"
#include <QMessageBox>

Game::Game()
{
    //Spieltimer initsialisieren
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(gameloop()));

    init();

    //Timer starten
    timer->start(GAME_UPDATEINTERVALL);
}

Game::~Game()
{
    timer->stop();
}

void Game::init()
{
   gametick=0;

    QMessageBox *box = new QMessageBox();
    box->setText("Bomberman V1.0\n*****************\n\nSpieler Blau\n  Bewegen: Pfeiltasten \n  Bombe: Space\n\nSpieler Grün\n  Bewegen: WASD \n  Bombe: Tab\n\n Esc: Neustart");
    box->exec();

    // Spielfelg generieren
    playfield = new Playfield();
    player1   = new Player(playfield,BLOCK_SIZE_X*1 ,  BLOCK_SIZE_Y*1 , QBrush(Qt::blue));
    player2   = new Player(playfield,BLOCK_SIZE_X*17,  BLOCK_SIZE_Y*13, QBrush(QColor(0,128,0))); //Grün

    //Scene erstellen
    scene = new QGraphicsScene();

    //Spielfeld zeichen
    playfield->Draw(scene);
    scene->addItem(player1);
    scene->addItem(player2);
}

void Game::gameloop()
{
    gametick++;

    Bomb::tick(); // Timer der Bomben triggern

    player1->gameLogic(gametick);
    player2->gameLogic(gametick);

    if(player1->Get_Lives()==0 || player2->Get_Lives() ==0)
    {
        QMessageBox *box = new QMessageBox();

        if(player1->Get_Lives()==0)
        {
            if(player2->Get_Lives()==0)
            {
                 box->setText("Spiel untenschieden!");
            }
            else
            {
                 box->setText(" Spieler Grün gewinnt!");
            }
        }
        else
        {
              box->setText(" Spieler Blau gewinnt!");
        }
        hide();
        box->exec();
        init();

    }

    if (player1->Key_Bomb) // Spieler 1 Bombe plaztieren
    {
        player1->Key_Bomb=0;

        if(Bomb::getBombCount(player1) < player1->Get_MaxBombCount()) //nur wenn noch Bomben verfügbar
        {
            Bomb * bomb = new Bomb(playfield,player1,scene);
            bomb->draw();
        }
    }

    if (player2->Key_Bomb) // Spieler 2 Bombe plaztieren
    {
        player2->Key_Bomb=0;

        if(Bomb::getBombCount(player2) < player2->Get_MaxBombCount()) //nur wenn noch Bomben verfügbar
        {
            Bomb * bomb = new Bomb(playfield,player2,scene);
            bomb->draw();
        }
    }


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

        /*Spieler 1*/
        if(event->key() == Qt::Key_Left)
            player1->Key_Left = 1;
        if(event->key() == Qt::Key_Right)
           player1->Key_Right = 1;
        if(event->key() == Qt::Key_Up)
           player1->Key_Up = 1;
        if(event->key() == Qt::Key_Down)
            player1->Key_Down = 1;
        if(event->key() == Qt::Key_Space)
        {
              if(event->isAutoRepeat()==false)
                player1->Key_Bomb =1;
        }


        /*Spieler 2*/
        if(event->key() == Qt::Key_A)
            player2->Key_Left = 1;
        if(event->key() == Qt::Key_D)
           player2->Key_Right = 1;
        if(event->key() == Qt::Key_W)
           player2->Key_Up = 1;
        if(event->key() == Qt::Key_S)
            player2->Key_Down = 1;
        if(event->key() == Qt::Key_Tab)
        {
              if(event->isAutoRepeat()==false)
                player2->Key_Bomb=1;
        }

    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    int count = event->count();
    int i =0;

    for(i=0; i<count;i++)
    {
        /*Spieler1*/
        if(event->key() == Qt::Key_Left)
            player1->Key_Left=0;
        if(event->key() == Qt::Key_Right)
           player1->Key_Right = 0;
        if(event->key() == Qt::Key_Up)
           player1->Key_Up = 0;
        if(event->key() == Qt::Key_Down)
           player1->Key_Down = 0;
        if(event->key() == Qt::Key_Space)
            player1->Key_Bomb =0;

        /*Spieler2*/
        if(event->key() == Qt::Key_A)
            player2->Key_Left = 0;
        if(event->key() == Qt::Key_D)
            player2->Key_Right = 0;
        if(event->key() == Qt::Key_W)
            player2->Key_Up = 0;
        if(event->key() == Qt::Key_S)
            player2->Key_Down = 0;
        if(event->key() == Qt::Key_Tab)
             player2->Key_Bomb=0;

        if(event->key() == Qt::Key_Escape)
             init();
    }

}

