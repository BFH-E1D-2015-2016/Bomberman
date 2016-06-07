#ifndef GAME_H
#define GAME_H

#include <QCloseEvent>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

#include "playfield.h"
#include "bomb.h"
#include "player.h"
#include "block.h"
#include "defines.h"

class Game : public QGraphicsView
{
    Q_OBJECT

/*Funktionen*/
public:

    Game();
    ~Game();
    void draw();
    void init();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event)
    {
        timer->stop();
        qDebug()<<"ende";
    }

public slots:
    void gameloop();


/*Variabeln*/
public:
    static const unsigned int Update_Intervall = GAME_UPDATEINTERVALL;

private:
    QGraphicsScene * scene;
    QTimer * timer;
    Bomb * bomb;
    Playfield * playfield;
    Player * player1, *player2;

    unsigned int gametick;
};

#endif // GAME_H
