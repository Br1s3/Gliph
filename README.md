# gliph.h - Graphical library

This library is useful for drawing or console printing some shape.

## Ready to start

```console
make all
./BasicExemple
./animation
./raytracing
./triangle
./3DSquare
./MeshGrid
./MeshGrid2
```

## Exemple of uses with the BasicExmple program:
```c
#define GLIPH_SPACEPADDED
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
TODO:
- Modify t step to verify this condition: (step >= 1/sqrt((by-ay)² + (bx-ax)²))
  - [ ] PrintLine()
  - [ ] DrawLine()
- [ ] Add DrawRectangle()
- [ ] Line: 230:
    Change PrintDisk name by PrintCercle and vice vera


- [ ] Modify t step with 3 if statement if (sqrt(h² + w²) > 1000) t+=0.0001 else reduce
in PrintLine() and DrawLine()
- [ ] Add DrawRectangle()

