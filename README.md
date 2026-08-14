# Graphlib

Short and simple library to draw shapes

## Ready to start

```console
$ make all
$ ./BasicExemple 
$ ./animation
$ ./raytracing
$ ./triangle
$ ./3DSquare
$ ./MeshGrid
$ ./MeshGrid2
```

## Exemple of uses with the BasicExmple program:
```c
#define GLIPH_IMPLEMENTATION
#include "gliph.h"

#define HEIGHT (9*2)
#define WIDTH (16*2)

int main()
{
    GLIPH_MALLOC2D(char, console, WIDTH, HEIGHT);
    PrintRectangle(console, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, '#');
    PrintRectangle(console, WIDTH, HEIGHT, 1, 1, WIDTH-2, HEIGHT-2, ' ');
    PrintCircle(console, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, 5, '@');
    PrintConsoleSpace(console, WIDTH, HEIGHT);
    GLIPH_FREE2D(console, HEIGHT);
    return 0;
}
```

_The Result:_
```
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                                             #
#                                                             #
#                                                             #
#                               @                             #
#                         @ @ @ @ @ @ @                       #
#                       @ @ @ @ @ @ @ @ @                     #
#                       @ @ @ @ @ @ @ @ @                     #
#                       @ @ @ @ @ @ @ @ @                     #
#                     @ @ @ @ @ @ @ @ @ @ @                   #
#                       @ @ @ @ @ @ @ @ @                     #
#                       @ @ @ @ @ @ @ @ @                     #
#                       @ @ @ @ @ @ @ @ @                     #
#                         @ @ @ @ @ @ @                       #
#                               @                             #
#                                                             #
#                                                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
```

All programs are exemples of use of the library.

## Exemples:

_Ray tracing_

[![Ray Tracing](./picture/Raytracing.png)](/picture)

_Square in 3 Dimensions_

[![Square in 3 Dimension](./picture/3DSquare.gif)](/picture)

_All triangles_

[![Triangles](./picture/Triangles.gif)](/picture)


_How to draw a line:_

https://www.desmos.com/calculator/z1dthkvot0

## TODO:
- Correct difference between graphlib.h and graph.h/c with valgrind
- Update the graph.c and graph.h files
