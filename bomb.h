#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "player.h"
#include "block.h"
#include "playfield.h"

class Bomb : public QGraphicsEllipseItem

{
public:
    Bomb(Playfield *Field, Player *Gameplayer);
    void setBomb();

    static void tick();
    static void draw(QGraphicsScene *scene);

public:
    int count;



private:
    Playfield * playfield;
    Player  * player;


};




#endif // BOMB_H
