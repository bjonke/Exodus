#ifndef STILE_PROPERTIES_H
#define STILE_PROPERTIES_H

STileProperties
{
	bool bWall; // Wall true or false
	int GfxX, GfxY; // X and Y coordinates for the displayed graphics
};

TileProperties myTileset[2] = {
  { true,  0, 0 },  // tile 0 = solid wall; graphics at 0,0
  { false, 32, 0 } // tile 1 = open space, graphics at 32,0
};

const int MAP_WD = 5;  // 5x5 map for simplicity
const int MAP_HT = 5;

int map[MAP_WD * MAP_HT] = {
  1,1,1,1,1,
  1,1,0,0,1,
  1,0,0,0,1,
  1,0,1,0,1,
  1,1,1,1,1
};

//================================
//  now if you want to get the properties of a tile at a specific coords:

const TileProperties& GetTile(int x, int y)
{
    return myTileset[ map[ (y*MAP_HT) + x ] ];
}

// now you can do things like:
if( GetTile(player.x, player.y).bWall )
{
  // disallow the player to move here
}

//================================
// as for drawing, it's the same idea:
int y, x;
for(y = 0; y < MAP_HT; ++y)
{
    for(x = 0; x < MAP_WD; ++x)
    {
        const TileProperties& t = GetTile(x,y);
        DrawImage( /* draw 32x32 pixels from whatever tileset image you have.  Use t.nGfxX
                 and t.nGfxY as the source coords for the image */ );
    }
} 

void MapInit (int currentMap[], int width, int height)
{
	dbLoadImage ( "grass.bmp", 1 );
	dbLoadImage ( "water.bmp", 2 );

	int cell = 1;
	for(int H = 0; H < height; H++)
		for(int W = 0; W < width; W++)
		{
			dbSprite ( cell, 32 * W, 32 * H, currentMap[cell - 1]);
			cell++;
		}
} 

	const int width = 10
	const int height = 10;
	int SuperMap[width * height] = {
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 1, 1, 1, 1, 1, 1, 2, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 2, 1, 1, 1, 1, 1, 1, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

	MapInit(SuperMap, width, height); 








#endif