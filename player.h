#ifndef PLAYER_H
#define PLAYER_H


#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QBrush>

#include "playfield.h"
#include "defines.h"

#define PLAYER_SIZE_X (16 * GAMESCALE_FACTOR)
#define PLAYER_SIZE_Y (16 * GAMESCALE_FACTOR)

#define PLAYER_MIDDLE_X(x) (x + (PLAYER_SIZE_X/2))
#define PLAYER_MIDDLE_Y(x) (x + (PLAYER_SIZE_Y/2))

#define MOVE_PIXELS          (4 * GAMESCALE_FACTOR)

class Player :public QGraphicsRectItem
{

public:
    Player(Playfield * field);
    Player(Playfield *field, int X, int Y, QBrush brush);
    ~Player(){};
    void move(int X, int Y);
    void move(int Key_Up, int Key_Down, int Key_Left, int Key_Right);
    int Get_PlayerPos_X();
    int Get_PlayerPos_Y();
    int Get_MaxBombCount();
    int Get_Bombintensity();
    int Get_Lives();
    Block *getCurrentBlockPosition();
    int checkPosition(int X1, int Y1, int X2, int Y2);
    int checkPosition(int X1, int Y1);
    int checkExpolsion();


   void gameLogic(int tick);
   void setColor(QBrush brush);

   bool Key_Up=0, Key_Down=0, Key_Left=0, Key_Right=0,Key_Bomb=0;


private:
    Playfield * playfield;
    int x,y;
    int bomb_max_count=3, bomb_intensity=3;
    int move_interdiction=0;
    int lives = 3;
    QBrush playerColor;

};

#endif // PLAYER_H

