#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>

#include "playfield.h"
#include "game.h"
#include "player.h"

class Bomb

{
public:

    Bomb(Playfield *Field, Player *Gameplayer);
    void setBomb();

public:
    void SetBomb ();

private:
    Playfield * playfield;
    Player  * player;


};




#endif // BOMB_H
