#include "block.h"



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
