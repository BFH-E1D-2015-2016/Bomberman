#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include "block.h"
#include "defines.h"

#define PLAYFIELD_SIZE_X     19
#define PLAYFIELD_SIZE_Y     15

//Nachbarblöcke
enum Nextblock
{
    UP=0,
    DOWN,
    LEFT,
    RIGHT,
    CURRENT
};

class Playfield
{

public:
    Playfield();
    ~Playfield(){};
    void Draw(QGraphicsScene *scene);
    Block *getBlock(int PosX, int PosY, Nextblock dir);
private:
    s_blockbehavoir Block_Behavoir;
    s_blockbehavoir Block_Behavoir_init;

    Block *playfieldBlocks [PLAYFIELD_SIZE_Y][PLAYFIELD_SIZE_X];

};
#endif // PLAYFIELD_H
