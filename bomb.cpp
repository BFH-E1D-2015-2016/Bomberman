#include "bomb.h"
#include "playfield.h"
#include <algorithm>
#include <vector>



std::vector<Bomb*> bombs; //In dieser Liste werden alle Bomben auf dem Spielfeld abgespeichert
int bomb_count=0;         //anzahl Bomben die erstellt wurden um eine einmalige ID zu erhalten

/*
 * Konstuktor: Erstellt eine Bombe an der Position des aktuellen Spielers
 */
Bomb::Bomb(Playfield *Field, Player *Gameplayer, QGraphicsScene *Scene )
{
    id = bomb_count++; //einmalige ID abspeichern

    scene = Scene;
    playfield = Field;
    player =  Gameplayer;

    setBomb(); //Bombe platzieren

    bombs.push_back(this); //in Liste abspeichern
}

/*
 * Plaziert eine Bombe an der aktuellen Spielerposition
 */
void Bomb::setBomb()
{
    setRect(player->Get_PlayerPos_X(),player->Get_PlayerPos_Y(),BOMB_SIZE_X,BOMB_SIZE_Y);
    setBrush(QBrush(Qt::black)); //Schwarze Bombe
}

/*
 * Zeichnet die Bombe auf die Szene
 */
void Bomb::draw()
{
     scene->addItem(this);
}

/*
 * Wird zyklisch aufgerufen für eine Bombe. Hier ist das Verhalten definiert, wie die Lunte abbrennt
 * und die Bombe explodiert, Blöcke zerstört, etc...
 */
void Bomb::burningFuse()
{
    ticks++;  //Timer für die Bombe incrementieren

    if(current_explosionsradius == 0) //Bombe ist noch nicht explodiert
    {
        //Blombe Grau/Schwarz blinken lassen
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
       if(current_explosionsradius <= player->Get_Bombintensity()) //maximaler Ausbreitungsradius ist noch nicht erreicht
       {
           if(ticks>TIME_EXPANDING_EXPLOSION)   //Wartezeit für nächste Explosionsstufe ist erreicht
           {

              if(current_explosionsradius==1) //Erste Explosionsstufe
              {
                    //Das Feld wo die Bombe drauf ist expodiert
                    playfield->getBlock(BOMB_MIDDLE_X(rect().x()), BOMB_MIDDLE_Y(rect().y()),CURRENT)->exploding();

                    //"Bombe" verschwinden lassen
                    setBrush(QBrush(Qt::transparent));
                    setPen(QPen(Qt::transparent));

                    current_explosionsradius++;
              }
              else //nicht erste Explosionsstufe
              {
                  if(!wall_down && !wall_left && !wall_up && !wall_right) //frühzeitig abberech
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
   for(unsigned int i=0; i<bombs.size() ; i++)
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
         for(unsigned int i=0; i<bombs.size() ; i++)
        {
           Bomb * bomb = bombs.at(i);
           bomb->burningFuse();
        }
    }

}
void Bomb::removeBomb(int id)
{
   for(unsigned int i=0; i<bombs.size() ; i++)
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

