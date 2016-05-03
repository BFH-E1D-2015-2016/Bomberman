#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QThread>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QMainWindow>
#include "playfield.h"
#include "myrect.h"

class Game : public QObject
{
    Q_OBJECT

/*Funktionen*/
public:
    explicit Game(QObject *parent = 0);
    void draw();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void gameloop();

/*Variabeln*/
private:
    QGraphicsScene * scene;
    QGraphicsView * view;
    Playfield * playfield;
    QTimer * timer;

    char Key_Up, Key_Down, Key_Left, Key_Right;
};

#endif // GAME_H
