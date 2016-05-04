#include "player.h"


Player::Player(Playfield *field)
{
    playfield = field;
    x=0;
    y=0;
   setRect(0,0,16,16);

}
void Player::move(int X, int Y)
{

   if((x+X)>=0 && (y+Y)>=0)
   {
       x += X;
       y += Y;

       if(playfield != NULL)
            playfield->current_hightlite(x+8,y+8);

       setRect(x,y,16,16);
   }
   //qDebug()<<"Player"<<x<<y;
}
