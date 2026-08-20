#define GLIPH_IMPLEMENTATION
#include "gliph.h"

#define HEIGHT (9*2)
#define WIDTH (16*2)

int main()
{
    GLIPH_INIT(console, WIDTH, HEIGHT);
    ConsoleClear(console, ' ');
    PrintRectangle(console, 0, 0, WIDTH, HEIGHT, '#');
    PrintRectangle(console, 1, 1, WIDTH-2, HEIGHT-2, ' ');
    PrintCircle(console, WIDTH/2, HEIGHT/2, 5, '@');
    PrintConsole(console);
    return 0;
}
