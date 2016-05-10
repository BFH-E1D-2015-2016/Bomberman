#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include "game.h"

class Bomb
{
public:
    Bomb(Playfield *Field, Player *Gameplayer);
    void setBomb();

public:
    Playfield * playfield;
    Player  * player;
};

#endif // BOMB_H
