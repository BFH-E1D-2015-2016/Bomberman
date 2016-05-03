#include "playfield.h"


Block * playfieldBlocks [PLAYFIELD_SIZE_Y][PLAYFIELD_SIZE_X];
Block  *  hightlite_block;

char playfieldDesign[PLAYFIELD_SIZE_Y][PLAYFIELD_SIZE_X] =
{
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#',' ','#',' ','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

Playfield::Playfield()
{

    int startpos_x = 0;
    int startpos_y = 0;

    int x=startpos_x;
    int y=startpos_y;

    for(int counter_y = 0; counter_y<PLAYFIELD_SIZE_Y; counter_y++)
    {
         for(int counter_x = 0; counter_x<PLAYFIELD_SIZE_X; counter_x++)
        {
            s_blockbehavoir blockmode;
            char block = playfieldDesign[counter_y][counter_x];
            switch(block)
            {
                case (' '):                             blockmode = MODE_PATH; break;
                case ('#'):                             blockmode = MODE_SOLID; break;
                case ('x'):                             blockmode = MODE_DESTROYABLE ;break;
            }
            playfieldBlocks[counter_y][counter_x] = new Block(x,y,blockmode);

            x += BLOCK_SIZE_X;
        }
        x=startpos_x;
        y+= BLOCK_SIZE_Y;

    }

}


void Playfield::Draw(QGraphicsScene * scene)
{
    int counter_y =0;
    int counter_x = 0;

    for(counter_y = 0; counter_y<PLAYFIELD_SIZE_Y; counter_y++)
    {
        for( counter_x = 0; counter_x<PLAYFIELD_SIZE_X; counter_x++)
        {
            if(playfieldBlocks[counter_y][counter_x]!=NULL)
                scene->addItem(playfieldBlocks[counter_y][counter_x]);
        }
    }
}

void Playfield::current_hightlite(int PosX, int PosY)
{
      int x = PosX / BLOCK_SIZE_X;
      int y = PosY / BLOCK_SIZE_Y;

      if(hightlite_block != NULL)
      {
        hightlite_block->reset_Blockbehavoir();
        //hightlite_block = NULL;
      }
      hightlite_block = playfieldBlocks[x][y];
      hightlite_block->set_Blockbehavoir(MODE_DEBUG);
}
