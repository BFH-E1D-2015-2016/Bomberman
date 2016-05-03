#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#define PLAYFIELD_SIZE_X     19
#define PLAYFIELD_SIZE_Y     15

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include "block.h"

class Playfield
{

public:
    Playfield();
    void Draw(QGraphicsScene *scene);
    void current_hightlite(int PosX, int PosY);

private:
    s_blockbehavoir Block_Behavoir;
    s_blockbehavoir Block_Behavoir_init;
};
#endif // PLAYFIELD_H
