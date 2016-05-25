#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "player.h"
#include "block.h"
#include "playfield.h"


#define TIME_FUSE                   20
#define TIME_EXPANDING_EXPLOSION    10


class Bomb : public QGraphicsEllipseItem
{

public:
    Bomb(Playfield *Field, Player *Gameplayer, QGraphicsScene *Scene );
    void setBomb();
    void burningFuse();

    static void tick();
    void draw();
    static int getBombCount(Player *player);
    void removeBomb(int id);

    int id;

    int ticks=0;
    int current_explosionsradius=0;
    int wall_up=1,wall_down=1, wall_left=1, wall_right=1;

private:
    Playfield * playfield;
    Player  * player;
    QGraphicsScene * scene;



};




#endif  //BOMB_H
