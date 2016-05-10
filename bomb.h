#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "playfield.h"
#include "game.h"
#include "player.h"

class Bomb : public QGraphicsEllipseItem

{
public:
    Bomb(Playfield *Field, Player *Gameplayer);
    void setBomb();

private:
    Playfield * playfield;
    Player  * player;
};




#endif // BOMB_H
