#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GLIPH_PADDING
#define GLIPH_IMPLEMENTATION
#include "gliph.h"

#define HEIGHT	(7*9)
#define WIDTH	(7*16*2)
#define XOFFSET(x) (x + WIDTH/2)
#define YOFFSET(y) (y + HEIGHT/2)

int main()
{
    GLIPH_INIT(console, WIDTH, HEIGHT);
    
    ConsoleClear(console, '.');

    int ax = -20;
    int ay = 20;
    
    int bx = 0;
    int by = -20;
    
    int cx = 20;
    int cy = 20;

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, '.');
	PrintTriangle(console, XOFFSET(i), YOFFSET(ay), XOFFSET(bx), YOFFSET(by), XOFFSET(cx), YOFFSET(cy), '#');
	PrintTriangle(console, XOFFSET(i+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	PrintConsole(console);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, '.');
	PrintTriangle(console, XOFFSET(ax)  , YOFFSET(i)  , XOFFSET(bx), YOFFSET(by)  , XOFFSET(cx)  , YOFFSET(cy), '#');
	PrintTriangle(console, XOFFSET(ax+1), YOFFSET(i), XOFFSET(bx), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	PrintConsole(console);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, '.');
	PrintTriangle(console, XOFFSET(ax)  , YOFFSET(ay)  , XOFFSET(i), YOFFSET(by)  , XOFFSET(cx)  , YOFFSET(cy), '#');
	PrintTriangle(console, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(i), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	PrintConsole(console);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, '.');
	PrintTriangle(console, XOFFSET(ax), YOFFSET(ay), XOFFSET(bx), YOFFSET(i), XOFFSET(cx), YOFFSET(cy), '#');
	if (i != 19)
	PrintTriangle(console, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(i+1), XOFFSET(cx-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	PrintConsole(console);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, '.');
	PrintTriangle(console, XOFFSET(ax), YOFFSET(ay), XOFFSET(bx), YOFFSET(by), XOFFSET(i), YOFFSET(cy), '#');
	PrintTriangle(console, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(by+1), XOFFSET(i-1), YOFFSET(cy-1), '+');
	PrintRectangle(console, XOFFSET(0), YOFFSET(0), 1, 1, '*');
	PrintConsole(console);
	usleep(100000);
    }

    for (int i = -20; i < 20; i++) {
	ConsoleClear(console, '.');
	PrintTriangle(console, XOFFSET(ax), YOFFSET(ay), XOFFSET(bx), YOFFSET(by), XOFFSET(cx), YOFFSET(i), '#');
	PrintTriangle(console, XOFFSET(ax+1), YOFFSET(ay-1), XOFFSET(bx), YOFFSET(by+1), XOFFSET(cx-1), YOFFSET(i-1), '+');
	PrintRectangle(console, 0, 0, 1, 1, '*');
	PrintConsole(console);
	usleep(100000);
    }

    return 0;
}
