#define GLIPH_PADDING
#define GLIPH_IMPLEMENTATION
#include "gliph.h"

#define HEIGHT (9*2)
#define WIDTH (16*2*2)

int main()
{
    GLIPH_ALLOC(char, console, WIDTH, HEIGHT);
    ConsoleClear(console, WIDTH, HEIGHT, ' ');
    PrintRectangle(console, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, '#');
    PrintRectangle(console, WIDTH, HEIGHT, 1, 1, WIDTH-2, HEIGHT-2, ' ');
    PrintCircle(console, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, 5, '*');
    PrintCircle(console, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, 5, '@');
    // PrintConsolePadded(console, WIDTH, HEIGHT);
    PrintConsole(console, WIDTH, HEIGHT);
    return 0;
}
