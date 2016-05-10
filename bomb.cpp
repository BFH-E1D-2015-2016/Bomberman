#include "bomb.h"

Bomb::Bomb(Playfield *Field, Player *Gameplayer)
{
    playfield = Field;
    player = Gameplayer;
}

void Bomb::setBomb()
{
    Block*  current = player->getCurrentBlockPosition();
    current->setBrush(QBrush(Qt::yellow));


}

