#include "block.h"


Block::Block(){}
/*
 * Blockkonstruktor platziert den Block auf den Koordinaten mit definiertem Verhalten
 */
Block::Block(int XPos, int YPos, s_blockbehavoir blockmode)
{
    Block_Behavoir_init = blockmode;
    set_Blockbehavoir(blockmode);
    set_Position(XPos,YPos);
}

/*
 * Setzt den Block an der gewählten Position
 */
void Block::set_Position(int XPos, int YPos)
{
    setRect(XPos,YPos,BLOCK_SIZE_X,BLOCK_SIZE_Y);
}

/*
 * Bestimmt das Verhalten wenn der Block expodieren soll
 * return: Wenn 1 dann geht die Explosion weiter
 *         Wenn 0 ist die Explosion in diese Richtung beendet
 */
int Block::exploding()
{
    switch(Block_Behavoir)
    {
        case (MODE_SOLID):              //nichts passiert
        case (MODE_DEBUG):
             return 0;

        case (MODE_DESTROYABLE):
            set_Blockbehavoir(MODE_EXPLOSION);
            return 0;

        case (MODE_PATH):
            set_Blockbehavoir(MODE_EXPLOSION);
            return 1;

        case (MODE_EXPLOSION):
            return 1;

    }
    return 0;
}

/*
 * return: Wenn 1 darf sich der Spieler auf dem Block bewegen
 *         Wenn 0 ist es nicht erlaubt
 */
int Block::istWalkable()
{

    switch(Block_Behavoir)
    {
        case (MODE_SOLID):          return 0;
        case (MODE_PATH):           return 1;
        case (MODE_DESTROYABLE):    return 0;
        case (MODE_DEBUG):          return 1;
        case (MODE_EXPLOSION):      return 1;

    }
    return 0;
}

/*
 * Stellt das Ursprüngliche Blockverhalten wieder her
 */
void Block::reset_Blockbehavoir()
{
    set_Blockbehavoir(Block_Behavoir_init);
}

/*
 * Speichert das neue Verhalten des Blocks ab
 */
void Block::set_Blockbehavoir( s_blockbehavoir blockmode)
{
    Block_Behavoir = blockmode;

    switch(Block_Behavoir)
    {
        case (MODE_SOLID):            setBrush(QBrush(QColor(150,150,150)));   break; //grau
        case (MODE_PATH):             setBrush(QBrush(QColor(242,225,115)));   break; //Sandfarbe
        case (MODE_DESTROYABLE):      setBrush(QBrush(QColor(128,64,0)));      break; //braun
        case (MODE_DEBUG):            setBrush(QBrush(Qt::blue));              break; //blau
        case (MODE_EXPLOSION):        setBrush(QBrush(Qt::red));                      //rot
                                      Block_Behavoir_init= MODE_PATH;          break; //nach der Explosion muss dieser Block zu einem Pfad werden
    }
}
/*
 * return: Das Verhalten des Blockes
 */
s_blockbehavoir Block::get_Blockbehavoir()
{
    return Block_Behavoir;
}

