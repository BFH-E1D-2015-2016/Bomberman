#include "bomb.h"
#include "block.h"
#include "playfield.h"

Bomb::Bomb(Playfield *Field)
{
    playfield = Field;
    SetBomb();
    Explode();
}

void Bomb::SetBomb()
{
    playfield.current_hightlite(100,100);

}

void Bomb::Explode()
{

}

