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
       {
            playfield->current_hightlite(x+8,y+8);

            Block * up = playfield->getBlock(x+8,y+8,UP);
            if(up != NULL)
             up->setBrush(QBrush(Qt::black));

            Block * down = playfield->getBlock(x+8,y+8,DOWN);
            if(down != NULL)
             down->setBrush(QBrush(Qt::darkMagenta));

           Block *left = playfield->getBlock(x+8,y+8,LEFT);
            if(left != NULL)
             left->setBrush(QBrush(Qt::blue));

            Block * right = playfield->getBlock(x+8,y+8,RIGHT);
            if(right != NULL)
             right->setBrush(QBrush(Qt::yellow));

       }

       setRect(x,y,16,16);
   }
   //qDebug()<<"Player"<<x<<y;
}
