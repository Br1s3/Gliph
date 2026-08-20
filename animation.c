#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// #define GLIPH_PADDING
#define GLIPH_IMPLEMENTATION
#include "gliph.h"

# define HEIGHT	(10*9)
# define WIDTH	(10*16)
// # define WIDTH	(10*16*2)

int main()
{
    GLIPH_ALLOC(char, console, WIDTH, HEIGHT);
    
    int i = -45, j = 1;
    for (i = -45; i < 45; i++, j++) {
	if (i<0) j = -i;
	ConsoleClear(console, WIDTH, HEIGHT, ' ');

	PrintRectangle(console, WIDTH, HEIGHT, -i*2 + WIDTH/2, i + HEIGHT/2, 8, 8, '#');
	PrintRectangle(console, WIDTH, HEIGHT, -i*2+1 + WIDTH/2, i+1 + HEIGHT/2, 6, 6, '.');
	PrintCircle(console, WIDTH, HEIGHT, i + WIDTH/2, i + HEIGHT/2, j, '#');
	PrintCircle(console, WIDTH, HEIGHT, i + WIDTH/2, i + HEIGHT/2, j-1, '.');

	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);

	usleep(50000);
    }
    puts("tout c'est bien passé");

    // mem_free(console, HEIGHT);
    // GLIPH_FREE2D(console, HEIGHT);
    return 0;
}
