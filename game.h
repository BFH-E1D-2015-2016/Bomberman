#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QThread>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include "playfield.h"
#include "myrect.h"
#include "bomb.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game();
    void draw();

public slots:
    void gameloop();


private:
    QGraphicsScene * scene;
    QGraphicsView * view;
    Playfield * playfield;
    QTimer * timer;
};

#endif // GAME_H
