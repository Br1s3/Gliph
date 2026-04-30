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

# define HEIGHT	(7*9)
# define WIDTH	(7*16)

typedef struct
{
    int grid;
    
    struct
    {
	int x, y;
    } Offset;
    
    int width;
    int height;
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
    win->width = w/win->grid;
    win->height = h/win->grid;
    win->Offset.x = ((int)((((float)w/(float)win->grid) - (w/win->grid))*win->grid/2));
    win->Offset.y = ((int)((((float)h/(float)win->grid) - (h/win->grid))*win->grid/2));
}


int main()
{
    // char **console = mem_alloc(HEIGHT, WIDTH);
    GRAPHLIB_MALLOC2D(char, console, HEIGHT, WIDTH);
    Window wind;

    for (int k = 0; k < 255; k++) {
	ConsoleClear(console, WIDTH, HEIGHT, ' ');
	PrintRectangle(console, WIDTH, HEIGHT, -WIDTH/2, -HEIGHT/2, WIDTH, HEIGHT, '#');
	PrintRectangle(console, WIDTH, HEIGHT, -WIDTH/2+1, -HEIGHT/2+1, WIDTH-2, HEIGHT-3, ' ');
	PrintCircle(console, WIDTH, HEIGHT, 0, 0, 17, '.');
	
	SetMeshGrid(&wind, WIDTH, HEIGHT, k+1);
	for (int i = 0; i < wind.width; i++) {
	    for (int j = 0; j < wind.height; j++) {
		if ((((i-wind.width/2))*((i-wind.width/2)) + ((j-wind.height/2))*((j-wind.height/2)))*wind.grid*wind.grid <= 300)
		PrintRectangle(console, WIDTH, HEIGHT, wind.grid*i + wind.Offset.x - WIDTH/2, wind.grid*j + wind.Offset.y - HEIGHT/2, wind.grid, wind.grid, '@');
	    }
	}

	// PrintCircle(console, WIDTH, HEIGHT, 0, 0, 17, '.');
	
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	// PrintConsole(console, WIDTH, HEIGHT);
	usleep(100000);
	printf("k = %d\n", k);
    }
    // mem_free(console, HEIGHT);
    GRAPHLIB_FREE2D(console, HEIGHT);
    return 0;
}
