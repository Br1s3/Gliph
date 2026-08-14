#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GLIPH_IMPLEMENTATION
#include "gliph.h"

#define HEIGHT	(7*9)
#define WIDTH	(7*16)
#define XOFFSET(x) (x + WIDTH/2)
#define YOFFSET(y) (y + HEIGHT/2)

int main()
{
    // char ** console = mem_alloc(HEIGHT, WIDTH);
    GLIPH_MALLOC2D(char, console, WIDTH, HEIGHT);
    
    ConsoleClear(console, WIDTH, HEIGHT, '.');

    int ax = -20;
    int ay = 20;
    
    int bx = 0;
    int by = -20;
    
    int cx = 20;
    int cy = 20;

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(i), YOFFSET(ay), XOFFSET(bx), YOFFSET(by), XOFFSET(cx), YOFFSET(cy), '#');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(i+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, WIDTH, HEIGHT, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	// PrintConsoleSpace(console, WIDTH, HEIGHT);
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax)  , YOFFSET(i)  , XOFFSET(bx), YOFFSET(by)  , XOFFSET(cx)  , YOFFSET(cy), '#');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax+1), YOFFSET(i), XOFFSET(bx), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, WIDTH, HEIGHT, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	PrintConsoleSpace(console, WIDTH, HEIGHT);
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax)  , YOFFSET(ay)  , XOFFSET(i), YOFFSET(by)  , XOFFSET(cx)  , YOFFSET(cy), '#');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(i), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, WIDTH, HEIGHT, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	// PrintConsoleSpace(console, WIDTH, HEIGHT);
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax), YOFFSET(ay), XOFFSET(bx), YOFFSET(i), XOFFSET(cx), YOFFSET(cy), '#');
	if (i != 19)
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(i+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, WIDTH, HEIGHT, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	// PrintConsoleSpace(console, WIDTH, HEIGHT);
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax), YOFFSET(ay), XOFFSET(bx), YOFFSET(by), XOFFSET(i), YOFFSET(cy), '#');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(by+1), XOFFSET(i-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, WIDTH, HEIGHT, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	// PrintConsoleSpace(console, WIDTH, HEIGHT);
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, WIDTH, HEIGHT, '.');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax), YOFFSET(ay), XOFFSET(bx), YOFFSET(by), XOFFSET(cx), YOFFSET(i), '#');
	PrintTriangle(console, WIDTH, HEIGHT, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(i-1), '+');
	PrintRectangle(console, WIDTH, HEIGHT, 0, 0, 1, 1, '*');
	// PrintConsole(console, WIDTH, HEIGHT);
	// PrintConsoleSpace(console, WIDTH, HEIGHT);
	PrintConsolePadded(console, WIDTH, HEIGHT);
	usleep(100000);
    }

    // mem_free(console, HEIGHT);
    GLIPH_FREE2D(console, HEIGHT);
    return 0;
}
