#ifndef GAME_H
#define GAME_H

#include <QCloseEvent>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

#include "playfield.h"
#include "player.h"

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
private:
    QGraphicsScene * scene;
    QTimer * timer;

    Playfield * playfield;
    Player * player;
    char Key_Up, Key_Down, Key_Left, Key_Right;
};

#endif // GAME_H
