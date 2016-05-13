#include "bomb.h"

#define Bomb_Size_X 16
#define Bomb_Size_Y 16

Bomb::Bomb(Playfield *Field, Player *Gameplayer)
{
    playfield = Field;
    player =  Gameplayer;

}

void Bomb::setBomb()
{
    setRect(0,0,Bomb_Size_X,Bomb_Size_Y);
    setBrush(QBrush(Qt::yellow));

    Block*  current = player->getCurrentBlockPosition();
    //current->setBrush(QBrush(Qt::yellow));


}

