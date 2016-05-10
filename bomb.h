#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>
#include "playfield.h"


class Bomb

{
public:

    Bomb(Playfield *Field);
    void SetBomb ();

private:


    void Explode ();
    Playfield playfield;

};




#endif // BOMB_H
