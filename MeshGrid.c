#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if defined(PROG1)
#    define GRAPHLIB_IMPLEMENTATION
#    include "graphlib.h"
#elif defined(PROG2)
#    include "graphlib.h"
#else
#    include "graph.h"
#endif

# define HEIGHT	(9*9)
# define WIDTH	(16*9)

#define MESHOFFSET_X(M, px) (M.Offset.x + (M.grid*px))
#define MESHOFFSET_Y(M, py) (M.Offset.y + (M.grid*py))

typedef struct
{
    int grid;
    
    struct
    {
	int x, y;
    } Offset;
    
    int x;
    int y;
} Window;

void SetMeshGrid(Window *win, unsigned int w, unsigned int h, unsigned int meshgrid)
{
    if (meshgrid <= 0) {
	fprintf(stdout, "WARNING: The parameter meshgrid <= 0\n");
	meshgrid = 1;
    }
    win->grid = ((h + w)/meshgrid);
    if (win->grid == 0) {
	fprintf(stdout, "WARNING: Grid < pixel size\n");
	win->grid = 1;
    }
    win->x = w/win->grid;
    win->y = h/win->grid;
    win->Offset.x = ((int)((((float)w/(float)win->grid) - (w/win->grid))*win->grid/2));
    win->Offset.y = ((int)((((float)h/(float)win->grid) - (h/win->grid))*win->grid/2));
}

#if 1
int main()
{
    GRAPHLIB_MALLOC2D(char, console, WIDTH, HEIGHT);
    Window wind;

    for (int k = 0; k < 255; k++) {
	// ConsoleClear(console, WIDTH, HEIGHT, ' ');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, '#');
	PrintRectangle(console, WIDTH, HEIGHT, 1, 1, WIDTH-2, HEIGHT-2, ' ');
	PrintCircle(console, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, 17, '.');
	
	SetMeshGrid(&wind, WIDTH, HEIGHT, k+1);
	for (int i = 0; i < wind.x; i++) {
	    for (int j = 0; j < wind.y; j++) {
		if ((((i-wind.x/2))*((i-wind.x/2)) + ((j-wind.y/2))*((j-wind.y/2)))*wind.grid*wind.grid <= 300)
		PrintRectangle(console, WIDTH, HEIGHT, MESHOFFSET_X(wind, i), MESHOFFSET_Y(wind, j), wind.grid, wind.grid, '@');
	    }
	}

	// PrintCircle(console, WIDTH, HEIGHT, 0, 0, 17, '.');
	
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
	printf("k = %d     \n", k);
    }

    GRAPHLIB_FREE2D(console, HEIGHT);
    return 0;
}

#else
int main()
{
    GRAPHLIB_MALLOC2D(char, console, WIDTH, HEIGHT);
    Window wind;

    int k = 20;
    int i = 0, j = 0;
    
    SetMeshGrid(&wind, WIDTH, HEIGHT, k);
    
    for (;;) {
	if (++i >= wind.x) {
	    i = 0;
	    if (++j >= wind.y) j = 0;
	}

	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, '#');
	PrintRectangle(console, WIDTH, HEIGHT, 1, 1, WIDTH-2, HEIGHT-2, ' ');

	PrintRectangle(console, WIDTH, HEIGHT, MESHOFFSET_X(wind, i), MESHOFFSET_Y(wind, j), wind.grid, wind.grid, '@');

	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(30000);
	printf("k = %d     \n", k);
    }

    GRAPHLIB_FREE2D(console, HEIGHT);
    return 0;
}
#endif
