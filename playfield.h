#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#define PLAYFIELD_SIZE_X     19
#define PLAYFIELD_SIZE_Y     15

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include "block.h"

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
    void Draw(QGraphicsScene *scene);
    void current_hightlite(int PosX, int PosY);

    Block *getBlock(int PosX, int PosY, Nextblock dir);
private:
    s_blockbehavoir Block_Behavoir;
    s_blockbehavoir Block_Behavoir_init;
};
#endif // PLAYFIELD_H
