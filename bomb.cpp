#include "bomb.h"
#include "block.h"
#include "playfield.h"


Bomb::Bomb(Playfield *Field, Player *Gameplayer)
{
    playfield = Field;
    player =  Gameplayer;

}

void Bomb::setBomb()
{
    Block*  current = player->getCurrentBlockPosition();
    current->setBrush(QBrush(Qt::yellow));


}

