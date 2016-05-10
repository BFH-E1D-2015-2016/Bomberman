#ifndef PLAYER_H
#define PLAYER_H


#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>

#include "playfield.h"

class Player :public QGraphicsRectItem
{

public:
    Player(Playfield * field);
    Player(Playfield *field, int X, int Y);
    void move(int X, int Y);


private:
    Playfield * playfield;
    int x,y;
};

#endif // PLAYER_H
