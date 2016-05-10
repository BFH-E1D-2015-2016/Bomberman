#include "player.h"


Player::Player(Playfield *field)
{
    playfield = field;
    x=0;
    y=0;
   setRect(0,0,PLAYER_SIZE_X,PLAYER_SIZE_Y);

}
Player::Player(Playfield *field, int X, int Y)
{
    playfield = field;
    x=X;
    y=Y;
   setRect(x,y,PLAYER_SIZE_X,PLAYER_SIZE_Y);

}
void Player::move(int X, int Y)
{

   if((x+X)>=0 && (y+Y)>=0)
   {
       if(playfield != NULL)
       {
            //playfield->current_hightlite(PLAYER_MIDDLE_X(x), PLAYER_MIDDLE_Y(y));

           //Nach unten verschieben
           if(Y>0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X,               (y+Y+PLAYER_SIZE_Y), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y+PLAYER_SIZE_Y), CURRENT);

                if(nextblock1->get_Blockbehavoir() == MODE_PATH && nextblock2->get_Blockbehavoir() == MODE_PATH )
                        y += Y;

           }
           //Nach oben verschieben
           if(Y<0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X,               (y+Y), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y), CURRENT);

                if(nextblock1->get_Blockbehavoir() == MODE_PATH && nextblock2->get_Blockbehavoir() == MODE_PATH )
                        y += Y;

            }
           //Nach rechts verschieben
           if(X>0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y              ), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y+PLAYER_SIZE_Y), CURRENT);

                if(nextblock1->get_Blockbehavoir() == MODE_PATH && nextblock2->get_Blockbehavoir() == MODE_PATH )
                        x += X;

           }
           //Nach links verschieben
           if(X<0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X, (y+Y              ), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X, (y+Y+PLAYER_SIZE_Y), CURRENT);

                if(nextblock1->get_Blockbehavoir() == MODE_PATH && nextblock2->get_Blockbehavoir() == MODE_PATH )
                        x += X;

           }
       }
       setRect(x,y,PLAYER_SIZE_X,PLAYER_SIZE_Y);
  }
}
