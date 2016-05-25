#include "block.h"


Block::Block(){}
Block::Block(int XPos, int YPos, s_blockbehavoir blockmode)
{
    Block_Behavoir_init = blockmode;
    set_Blockbehavoir(blockmode);
    set_Position(XPos,YPos);
}

void Block::set_Position(int XPos, int YPos)
{
    setRect(XPos,YPos,BLOCK_SIZE_X,BLOCK_SIZE_Y);
}
int Block::exploding()
{
    switch(Block_Behavoir)
    {
        case (MODE_SOLID):              //nichts passiert
        case (MODE_DEBUG):
            return 0;

        case (MODE_DESTROYABLE):        //Rot färben und den Block in einen Pfad verwandeln
            set_Blockbehavoir(MODE_PATH);
            Block_Behavoir_init= MODE_PATH;
            setBrush(QBrush(Qt::red));
            return 0;

        case (MODE_PATH):               //Rot färben
            setBrush(QBrush(Qt::red));
            return 1;
    }
}

int Block::istWalkable()
{

    switch(Block_Behavoir)
    {
        case (MODE_SOLID):          return 0;
        case (MODE_PATH):           return 1;
        case (MODE_DESTROYABLE):    return 0;
        case(MODE_DEBUG):           return 1;
    }
}

void Block::reset_Blockbehavoir()
{
    set_Blockbehavoir(Block_Behavoir_init);
}

void Block::set_Blockbehavoir( s_blockbehavoir blockmode)
{
    Block_Behavoir = blockmode;

    switch(Block_Behavoir)
    {
        case (MODE_SOLID):            setBrush(QBrush(Qt::darkGray)); break;
        case (MODE_PATH):              setBrush(QBrush(Qt::white)); break;
        case (MODE_DESTROYABLE):setBrush(QBrush(Qt::green)); break;
        case(MODE_DEBUG):setBrush(QBrush(Qt::red)); break;
    }
}
s_blockbehavoir Block::get_Blockbehavoir()
{
    return Block_Behavoir;
}

