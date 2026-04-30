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


int main()
{
    // char ** console = mem_alloc(HEIGHT, WIDTH);
    GRAPHLIB_MALLOC2D(char, console, HEIGHT, WIDTH);
    
    ConsoleClear(console, WIDTH, HEIGHT, '.');

    int ax = -20;
    int ay = 20;
    
    int bx = 0;
    int by = -20;
    
    int cx = 20;
    int cy = 20;

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, i, ay, bx, by, cx, cy, '#');
	PrintTriangle(console, WIDTH, HEIGHT, i+1, ay-1, bx, by+1, cx-1, cy-1, '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, ax, i, bx, by, cx, cy, '#');
	PrintTriangle(console, WIDTH, HEIGHT, ax+1, i+1, bx, by+1, cx-1, cy-1, '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, ax, ay, i, by, cx, cy, '#');
	PrintTriangle(console, WIDTH, HEIGHT, ax+1, ay-1, i, by+1, cx-1, cy-1, '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, ax, ay, bx, i, cx, cy, '#');
	if (i != 19)
	PrintTriangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, i+1, cx-1, cy-1, '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, ax, ay, bx, by, i, cy, '#');
	PrintTriangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, by+1, i-1, cy-1, '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, ax, ay, bx, by, cx, i, '#');
	PrintTriangle(console, WIDTH, HEIGHT, ax+1, ay-1, bx, by+1, cx-1, i-1, '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    // mem_free(console, HEIGHT);
    GRAPHLIB_FREE2D(console, HEIGHT);
    return 0;
}
