#ifndef GAME_H
#define GAME_H


#include <QCloseEvent>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

#include "playfield.h"
#include "myrect.h"
#include "bomb.h"
#include "player.h"
#include "block.h"

#define GAME_UPDATEINTERVALL 33

class Game : public QGraphicsView
{
    Q_OBJECT

/*Funktionen*/
public:

    Game();
    ~Game();
    void draw();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event)
    {
        qDebug()<<"ende";
        timer->stop();

        scene = NULL;
        this->destroy(true);
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
    Player * player;
    char Key_Up, Key_Down, Key_Left, Key_Right,Key_Space;


};

#endif // GAME_H
