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

# define HEIGHT	(10*9)
# define WIDTH	(10*16)

int main()
{
    // char **console = mem_alloc(HEIGHT, WIDTH);
    GRAPHLIB_MALLOC2D(char, console, HEIGHT, WIDTH);
    
    int i = -45, j = 1;
    for (i = -45; i < 45; i++, j++) {
	if (i<0) j = -i;
	ConsoleClear(console, WIDTH, HEIGHT, ' ');

	PrintRectangle(console, WIDTH, HEIGHT, -i*2, i, 10, 5, '#');
	PrintRectangle(console, WIDTH, HEIGHT, -i*2+1, i+1, 8, 3, '.');
	PrintCircle(console, WIDTH, HEIGHT, i, i, j, '#');
	PrintCircle(console, WIDTH, HEIGHT, i, i, j-1, '.');

	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);

	usleep(50000);
    }
    puts("tout c'est bien passé");

    // mem_free(console, HEIGHT);
    GRAPHLIB_FREE2D(console, HEIGHT);
    return 0;
}
