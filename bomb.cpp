#include "bomb.h"
#include "playfield.h"
#include <algorithm>
#include <vector>

#define BOMB_SIZE_X 16
#define BOMB_SIZE_Y 16
#define BOMB_MIDDLE_X(x) (x + (BOMB_SIZE_X/2))
#define BOMB_MIDDLE_Y(x) (x + (BOMB_SIZE_Y/2))

std::vector<Bomb*> bombs;
int bomb_count=0;

Bomb::Bomb(Playfield *Field, Player *Gameplayer, QGraphicsScene *Scene )
{
    id = bomb_count++;

    scene = Scene;
    playfield = Field;
    player =  Gameplayer;

    setBomb();

    bombs.push_back(this);
}

void Bomb::setBomb()
{
    setRect(player->Get_PlayerPos_X(),player->Get_PlayerPos_Y(),BOMB_SIZE_X,BOMB_SIZE_Y);
    setBrush(QBrush(Qt::black));
}

void Bomb::draw()
{
     scene->addItem(this);
}

void Bomb::burningFuse()
{
    ticks++;


    if(current_explosionsradius == 0) //noch nicht explodiert
    {
        if((ticks/2)%2)
            setBrush(QBrush(Qt::black));
        else
            setBrush(QBrush(Qt::gray));

        //Warte bis Bombe explodiert
        if(ticks>TIME_FUSE)
        {
           current_explosionsradius=1;
        }
    }
    else
    {
       if(current_explosionsradius <= player->Get_Bombintensity())
       {
           if(ticks>TIME_EXPANDING_EXPLOSION)
           {

              if(current_explosionsradius==1)
              {
                    playfield->getBlock(BOMB_MIDDLE_X(rect().x()), BOMB_MIDDLE_Y(rect().y()),CURRENT)->exploding();
                    setBrush(QBrush(Qt::transparent));
                    setPen(QPen(Qt::transparent));

                    current_explosionsradius++;
              }
              else
              {
                  if(!wall_down && !wall_left && !wall_up && !wall_right)
                      current_explosionsradius = player->Get_Bombintensity();
                  else
                  {
                      for(int i=1; i<current_explosionsradius; i++)
                      {
                          if(wall_down) wall_down  = playfield->getBlock(BOMB_MIDDLE_X(rect().x()               ), BOMB_MIDDLE_Y(rect().y()+i*BLOCK_SIZE_Y),CURRENT)->exploding();
                          if(wall_left) wall_left  = playfield->getBlock(BOMB_MIDDLE_X(rect().x()+i*BLOCK_SIZE_X), BOMB_MIDDLE_Y(rect().y()               ),CURRENT)->exploding();
                          if(wall_up)   wall_up    = playfield->getBlock(BOMB_MIDDLE_X(rect().x()               ), BOMB_MIDDLE_Y(rect().y()-i*BLOCK_SIZE_Y),CURRENT)->exploding();
                          if(wall_right)wall_right = playfield->getBlock(BOMB_MIDDLE_X(rect().x()-i*BLOCK_SIZE_X), BOMB_MIDDLE_Y(rect().y()               ),CURRENT)->exploding();
                      }
                      current_explosionsradius++;
                  }
              }
              ticks=0;
           }
       }
       else
      {
           if(ticks>TIME_EXPANDING_EXPLOSION)
           {
               for(int i=current_explosionsradius; i>=0 ;i--)
                {
                   Block * block;
                   block = playfield->getBlock(BOMB_MIDDLE_X(rect().x()               ), BOMB_MIDDLE_Y(rect().y()+i*BLOCK_SIZE_Y),CURRENT);
                   if(block != NULL) block->reset_Blockbehavoir();
                   block = playfield->getBlock(BOMB_MIDDLE_X(rect().x()+i*BLOCK_SIZE_X), BOMB_MIDDLE_Y(rect().y()               ),CURRENT);
                   if(block != NULL) block->reset_Blockbehavoir();
                   block = playfield->getBlock(BOMB_MIDDLE_X(rect().x()               ), BOMB_MIDDLE_Y(rect().y()-i*BLOCK_SIZE_Y),CURRENT);
                   if(block != NULL) block->reset_Blockbehavoir();
                   block = playfield->getBlock(BOMB_MIDDLE_X(rect().x()-i*BLOCK_SIZE_X), BOMB_MIDDLE_Y(rect().y()               ),CURRENT);
                   if(block != NULL) block->reset_Blockbehavoir();
                }
                removeBomb(id);
           }
       }
    }


}

//***************************************************
//Static Funktionen
//***************************************************
int Bomb::getBombCount(Player * player)
{
   int count = 0;
   for(int i=0; i<bombs.size() ; i++)
   {
      Bomb * bomb = bombs.at(i);
      if(bomb->player == player)
          count++;
   }

   return count;
}

void Bomb::tick()
{
    if(bombs.size()>0 )
    {
         for(int i=0; i<bombs.size() ; i++)
        {
           Bomb * bomb = bombs.at(i);
           bomb->burningFuse();
        }
    }

}
void Bomb::removeBomb(int id)
{
   for(int i=0; i<bombs.size() ; i++)
   {
      Bomb * bomb = bombs.at(i);
      if(id == bomb->id)
      {
           scene->removeItem(this);
           bombs.erase(bombs.begin() + i);

           break;
      }
   }
}

