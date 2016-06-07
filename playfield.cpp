#include "playfield.h"


/*
 * Spielfeld Design
 *    #   = Solider Block
 *    x   = zerstörbarer Block
 *    ' ' = Pfad auf dem sich der Spieler bewegen kann
 */
char playfieldDesign[PLAYFIELD_SIZE_Y][PLAYFIELD_SIZE_X] =
{
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#',' ','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','#'},
{'#','x','#','x','#','x','#','x','#','x','#','x','#','x','#','x','#',' ','#'},
{'#','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};


/*
 * Erstellt das Spielfeld
 */
Playfield::Playfield()
{
    //Startposition bestimmen
    int startpos_x = 0;
    int startpos_y = 0;

    int x=startpos_x;
    int y=startpos_y;

    //Jeder Block aus dem Designe herstellen und in playFieldblocks abspeichern
    for(int counter_y = 0; counter_y<PLAYFIELD_SIZE_Y; counter_y++)
    {
         for(int counter_x = 0; counter_x<PLAYFIELD_SIZE_X; counter_x++)
        {
            s_blockbehavoir blockmode;
            char block = playfieldDesign[counter_y][counter_x];
            switch(block)
            {
                case (' '):      blockmode = MODE_PATH; break;
                case ('#'):      blockmode = MODE_SOLID; break;
                case ('x'):      blockmode = MODE_DESTROYABLE ;break;
            }
            playfieldBlocks[counter_y][counter_x] = new Block(x,y,blockmode);

            x += BLOCK_SIZE_X;
        }
        x=startpos_x;
        y+= BLOCK_SIZE_Y;

    }
}

/*
 * Zeichnet das Spielfeld auf die Szene
 */
void Playfield::Draw(QGraphicsScene * scene)
{
    int counter_y = 0;
    int counter_x = 0;

    for(counter_y = 0; counter_y<PLAYFIELD_SIZE_Y; counter_y++)
    {
        for( counter_x = 0; counter_x<PLAYFIELD_SIZE_X; counter_x++)
        {
            if(playfieldBlocks[counter_y][counter_x]!=NULL)
                scene->addItem(playfieldBlocks[counter_y][counter_x]); //Block auf Szene zeichnen
        }
    }
}
/*
 * Anhand der Koordinate den Block bestimmen
 * Es kann ausgewählt werden ob der aktuelle Block oder ein nachbarblock zurückgegeben werden soll
 */
Block *  Playfield::getBlock(int PosX, int PosY, Nextblock dir)
{
    //Blockkoordinate berechen
    int x = PosX / BLOCK_SIZE_X;
    int y = PosY / BLOCK_SIZE_Y;

    //Nachbarblock bestimmen
    if(x>=0 && x)
    if(dir == UP)   y -= 1;
    if(dir == DOWN) y += 1;
    if(dir == RIGHT)x += 1;
    if(dir == LEFT) x -= 1;

    //Maximalwerte abfangen
    if(x<0 || y<0)
        return NULL;
    if(x>=PLAYFIELD_SIZE_X || y>=PLAYFIELD_SIZE_Y)
        return NULL;

     return playfieldBlocks[y][x];

}

