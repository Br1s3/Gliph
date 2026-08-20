#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GLIPH_PADDING
#define GLIPH_IMPLEMENTATION
#include "gliph.h"

# define HEIGHT	(10*9)
# define WIDTH	(10*16*2)

int main()
{
    GLIPH_ALLOC(console, WIDTH, HEIGHT);
    
    int i = -45, j = 1;
    for (i = -45; i < 45; i++, j++) {
	if (i<0) j = -i;
	ConsoleClear(console, '.');

	PrintRectangle(console, -i*2 + WIDTH/2, i + HEIGHT/2, 10, 10, '#');
	PrintRectangle(console, -i*2+1 + WIDTH/2, i+1 + HEIGHT/2, 8, 8, '*');
	PrintCircle(console, i + WIDTH/2, i + HEIGHT/2, j, '#');
	PrintCircle(console, i + WIDTH/2, i + HEIGHT/2, j-1, '.');

	PrintConsole(console);

	usleep(50000);
    }
    puts("tout c'est bien passé");
    return 0;
}
