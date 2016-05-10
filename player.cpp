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
/*
void Player::move(int Key_Up, int Key_Down, int Key_Left, int Key_Right)
{
    int move=4, moveX=0, moveY=0;

    if(Key_Up)
        moveY -= move;
    if(Key_Down)
        moveY += move;

    if(Key_Left)
       moveX -= move;

    if(Key_Right)
       moveX += move;

    //move(moveX, moveY);

}
*/
Block* Player::getCurrentBlockPosition()
{
    Block * current = playfield->getBlock(PLAYER_MIDDLE_X(x), PLAYER_MIDDLE_Y(y), CURRENT);
    return  current;
}


void Player::move(int X, int Y)
{

   if((x+X)>=0 && (y+Y)>=0) // Spielfeldbegrenzung keine neg.Position
   {
       if(playfield != NULL)
       {
           //aktuellen Block hervorheben
           // playfield->current_hightlite(PLAYER_MIDDLE_X(x), PLAYER_MIDDLE_Y(y));

           //Nach unten verschieben
           if(Y>0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X,               (y+Y+PLAYER_SIZE_Y), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y+PLAYER_SIZE_Y), CURRENT);

                if(nextblock1->istWalkable() && nextblock2->istWalkable())
                    y += Y;

                //Eckt ein Ecke an? So verschiebe in X Richtung bis das Hinderniss nicht mehr im Weg ist
                if(nextblock1->istWalkable()==0)
                    x +=4;
                if(nextblock2->istWalkable()==0)
                    x -=4;
           }
           //Nach oben verschieben
           if(Y<0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X,               (y+Y), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y), CURRENT);

                if(nextblock1->istWalkable() && nextblock2->istWalkable())
                        y += Y;

                //Eckt ein Ecke an? So verschiebe in X Richtung bis das Hinderniss nicht mehr im Weg ist
                if(nextblock1->istWalkable()==0)
                    x +=4;
                if(nextblock2->istWalkable()==0)
                    x -=4;
            }
           //Nach rechts verschieben
           if(X>0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y              ), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X+PLAYER_SIZE_X, (y+Y+PLAYER_SIZE_Y), CURRENT);

               if(nextblock1->istWalkable() && nextblock2->istWalkable())
                        x += X;

               //Eckt ein Ecke an? So verschiebe in X Richtung bis das Hinderniss nicht mehr im Weg ist
               if(nextblock1->istWalkable()==0)
                   y +=4;
               if(nextblock2->istWalkable()==0)
                   y -=4;
           }
           //Nach links verschieben
           if(X<0)
           {
                Block * nextblock1 =  playfield->getBlock(x+X, (y+Y              ), CURRENT);
                Block * nextblock2 =  playfield->getBlock(x+X, (y+Y+PLAYER_SIZE_Y), CURRENT);

                if(nextblock1->istWalkable() && nextblock2->istWalkable())
                        x += X;

                //Eckt ein Ecke an? So verschiebe in X Richtung bis das Hinderniss nicht mehr im Weg ist
                if(nextblock1->istWalkable()==0)
                    y +=4;
                if(nextblock2->istWalkable()==0)
                    y -=4;
           }
       }
       setRect(x,y,PLAYER_SIZE_X,PLAYER_SIZE_Y);
  }
}
