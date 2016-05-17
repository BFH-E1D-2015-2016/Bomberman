#include "bomb.h"

#define Bomb_Size_X 16
#define Bomb_Size_Y 16

std::vector<Bomb*> bombs;

Bomb::Bomb(Playfield *Field, Player *Gameplayer)
{
    playfield = Field;
    player =  Gameplayer;
    setBomb();

    bombs.push_back(this);
}

void Bomb::setBomb()
{


    setRect(player->Get_PlayerPos_X(),player->Get_PlayerPos_Y(),Bomb_Size_X,Bomb_Size_Y);
    setBrush(QBrush(Qt::yellow));

    //Block*  current = player->getCurrentBlockPosition();
    //current->setBrush(QBrush(Qt::yellow));
}


//***************************************************
//Static Funktionen
//***************************************************
void Bomb::tick()
{
    if(bombs.size()>0 )
    {
         for(int i=0; i<bombs.size() ; i++)
        {
           Bomb * bomb = bombs.at(i);
           qDebug()<<i<<bomb->count;
           bomb->ticks++;
        }
    }

}
void Bomb::draw(QGraphicsScene * scene)
{
    if(bombs.size()>0 )
    {
         for(int i=0; i<bombs.size() ; i++)
        {
           Bomb * bomb = bombs.at(i);

           scene->addItem(bomb);
        }
    }
}
