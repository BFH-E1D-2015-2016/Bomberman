#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

#include "playfield.h"


class Game : public QGraphicsView
{
    Q_OBJECT

/*Funktionen*/
public:

    Game();
    void draw();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void gameloop();

/*Variabeln*/
private:
    QGraphicsScene * scene;
    Playfield * playfield;
    QTimer * timer;

    char Key_Up, Key_Down, Key_Left, Key_Right;
};

#endif // GAME_H
