#define GRAPHLIB_IMPLEMENTATION
#include "graphlib.h"

#define HEIGHT (9*2)
#define WIDTH (16*2)

int main()
{
    GRAPHLIB_MALLOC2D(char, console, WIDTH, HEIGHT);
    PrintRectangle(console, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, '#');
    PrintRectangle(console, WIDTH, HEIGHT, 1, 1, WIDTH-2, HEIGHT-2, ' ');
    PrintCircle(console, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, 5, '@');
    PrintConsoleSpace(console, WIDTH, HEIGHT);
    GRAPHLIB_FREE2D(console, HEIGHT);
    return 0;
}
