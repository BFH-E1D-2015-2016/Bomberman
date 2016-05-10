#ifndef PLAYER_H
#define PLAYER_H


#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>

#include "playfield.h"


#define PLAYER_SIZE_X 16
#define PLAYER_SIZE_Y 16
#define PLAYER_MIDDLE_X(x) (x + (PLAYER_SIZE_X/2))
#define PLAYER_MIDDLE_Y(x) (x + (PLAYER_SIZE_Y/2))

class Player :public QGraphicsRectItem
{

public:
    Player(Playfield * field);
    Player(Playfield *field, int X, int Y);
    void move(int X, int Y);
    //void move(int Key_Up, int Key_Down, int Key_Left, int Key_Right);
    Block *getCurrentBlockPosition();
private:
    Playfield * playfield;
    int x,y;
};

#endif // PLAYER_H
