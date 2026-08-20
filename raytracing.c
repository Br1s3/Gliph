#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <math.h>

#define GLIPH_PADDING
#define GLIPH_IMPLEMENTATION
#include "gliph.h"

# define HEIGHT	(7*9)
# define WIDTH	(10*16*2)

typedef struct {
    int x;
    int y;
} Vector2;


typedef struct {
    Vector2 pos;
    char color;
    int radius;
    int brighness;
} Corp;

int raytracing(Corp l, int l_len, double srcx, double srcy, Corp c)
{
    int j = 0;
    for (j = 0; j < l_len; j++) {
	Vector2 brighness_len = {
	    .x = l.pos.x + srcx*j,
	    .y = l.pos.y + srcy*j
	};
	if ((brighness_len.x - c.pos.x)*(brighness_len.x - c.pos.x) + (brighness_len.y - c.pos.y)*(brighness_len.y - c.pos.y) <= c.radius*c.radius) break;
    }
    return j;
}

int main()
{
    Corp light;
    light.pos.x = 0;
    light.pos.y = 0;
    light.color = '@';
    light.radius = 2;
    light.brighness = 70;

    Corp shadow1;
    shadow1.pos.x = 25;
    shadow1.pos.y = 0;
    shadow1.color = ' ';
    shadow1.radius = 10;

    Corp shadow2;
    shadow2.pos.x = -25;
    shadow2.pos.y = 0;
    shadow2.color = ' ';
    shadow2.radius = 10;

    // char **console = mem_alloc(HEIGHT, WIDTH);
    GLIPH_ALLOC(console, WIDTH, HEIGHT);

    for (double k = 0; k < 5*M_PI; k+=0.01) {
	ConsoleClear(console, ' ');
	light.pos.y = sin(k)*(HEIGHT/2.5);

	for (double j = 0; j < 2*M_PI; j+=M_PI/50) {
	    int len = raytracing(light, light.brighness, cos(j), sin(j), shadow1);
	    if(raytracing(light, 1000, cos(j), sin(j), shadow2) < len)
	        len = raytracing(light, light.brighness, cos(j), sin(j), shadow2);
	    PrintLine(console, light.pos.x, light.pos.y, light.pos.x + cos(j)*(len), light.pos.y + sin(j)*(len), '.');
	}
	
	PrintCircle(console, light.pos.x + WIDTH/2, light.pos.y + HEIGHT/2, light.radius, light.color);
	PrintCircle(console, shadow1.pos.x + WIDTH/2, shadow1.pos.y + HEIGHT/2, shadow1.radius, shadow1.color);
	PrintCircle(console, shadow2.pos.x + WIDTH/2, shadow2.pos.y + HEIGHT/2, shadow2.radius, shadow2.color);

	PrintConsole(console);
	// usleep(5000);
    }
    

    // mem_free(console, HEIGHT);
    // GLIPH_FREE2D(console, HEIGHT);
    return 0;
}

/*
 * with "PrintConsolePadded(console, WIDTH, HEIGHT);"
 * time ./raytracing
 * real	0m2,904s
 * user	0m1,648s
 * sys	0m0,160s
 *
 * Or
 *
 * with "PrintConsole(console, WIDTH, HEIGHT);"
 * time ./raytracing
 * real	0m1,952s
 * user	0m1,295s
 * sys	0m0,092s
 */
