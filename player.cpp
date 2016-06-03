#include "player.h"


Player::Player(Playfield *field)
{
    setBrush(QBrush(Qt::blue));
    playfield = field;
    x=0;
    y=0;
    setRect(0,0,PLAYER_SIZE_X,PLAYER_SIZE_Y);


}
Player::Player(Playfield *field, int X, int Y, QBrush brush)
{

   playfield = field;
   x=X;
   y=Y;
   playerColor = brush;

   setColor(playerColor);
   setRect(x,y,PLAYER_SIZE_X,PLAYER_SIZE_Y);

}
void Player::gameLogic(int tick)
{
    move(Key_Up, Key_Down, Key_Left, Key_Right); //Spieler bewegen

    if(checkExpolsion()) // Spieler in Explosion?
    {
        if(move_interdiction==0 && lives>0) //Leben verringern
            lives--;

        move_interdiction = true; //er kann sich nicht bewegen,solange er in der Explosion ist
    }
    else
    {
         move_interdiction = false;
         setColor(playerColor);
    }

    if(lives==0)
        move_interdiction = true;

    //Blinkenlassen wenn im Explosionsradius
    //Schwarzfärben wenn tot
    //sonst normale Spielerfarbe
    if(move_interdiction && (tick/2)%2)
    {
        setColor(Qt::black);
    }
    else
    {
        if(move_interdiction && lives>0) setColor(Qt::gray);
        else
            if(lives>0)
                setColor(playerColor);
            else
                setColor(Qt::black);
    }



}

void Player::move(int Key_Up, int Key_Down, int Key_Left, int Key_Right)
{
    int moveX=0, moveY=0;

    if(Key_Up)
        moveY -= MOVE_PIXELS;
    if(Key_Down)
        moveY += MOVE_PIXELS;

    if(Key_Left)
       moveX -= MOVE_PIXELS;

    if(Key_Right)
       moveX += MOVE_PIXELS;

    move(moveX, moveY);

}

int Player::Get_PlayerPos_X()
{
    return x;
}

int Player::Get_PlayerPos_Y()
{
    return y;
}

int Player::Get_MaxBombCount()
{
    return bomb_max_count;
}

int Player::Get_Bombintensity()
{
    return bomb_intensity;
}

int Player::Get_Lives()
{
    return lives;
}



Block* Player::getCurrentBlockPosition()
{
    Block * current = playfield->getBlock(PLAYER_MIDDLE_X(x), PLAYER_MIDDLE_Y(y), CURRENT);
    return  current;
}

int Player::checkExpolsion()
{
    Block * block = getCurrentBlockPosition();

    if(block == NULL || block->get_Blockbehavoir() == MODE_EXPLOSION)
    {
        return 1;
    }
    return 0;

}
void Player::setColor(QBrush brush)
{
     setBrush(brush);
}

void Player::move(int X, int Y)
{

   if((x+X)>=0 && (y+Y)>=0 && move_interdiction==0) // Spielfeldbegrenzung keine neg.Position
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
                    x +=MOVE_PIXELS;
                if(nextblock2->istWalkable()==0)
                    x -=MOVE_PIXELS;
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
                    x +=MOVE_PIXELS;
                if(nextblock2->istWalkable()==0)
                    x -=MOVE_PIXELS;
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
                   y +=MOVE_PIXELS;
               if(nextblock2->istWalkable()==0)
                   y -=MOVE_PIXELS;
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
                    y +=MOVE_PIXELS;
                if(nextblock2->istWalkable()==0)
                    y -=MOVE_PIXELS;
           }
       }
       setRect(x,y,PLAYER_SIZE_X,PLAYER_SIZE_Y);
  }
}
