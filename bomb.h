#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "player.h"
#include "block.h"
#include "playfield.h"
#include "defines.h"

#define BOMB_SIZE_X (16 * GAMESCALE_FACTOR)
#define BOMB_SIZE_Y (16 * GAMESCALE_FACTOR)

//Berechnet die Mittelkoordinaten der Bombe
#define BOMB_MIDDLE_X(x) (x + (BOMB_SIZE_X/2))
#define BOMB_MIDDLE_Y(x) (x + (BOMB_SIZE_Y/2))

#define TIME_FUSE                   20  // Luntenbrennzeit
#define TIME_EXPANDING_EXPLOSION    5   // Zeit bis der Explosionsradius vergrössert wird


class Bomb : public QGraphicsEllipseItem
{

public:
    Bomb(Playfield *Field, Player *Gameplayer, QGraphicsScene *Scene );
    ~Bomb(){};
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
