#include "graph.h"


void PrintConsole(char **pixels, short width, short height)
{
    short i, j;
    char pixels_1D[(width+1) * height];
    for (i = 0; i < height; ++i) {
	for (j = 0; j < width+1; ++j) {
            if      (j < width)     pixels_1D[DEC_GRAPHLIB(i, j)] = pixels[i][j];
            else if (i < height-1)  pixels_1D[DEC_GRAPHLIB(i, j)] = '\n';
            else                    pixels_1D[DEC_GRAPHLIB(i, j)] = '\0';
	}
    }

    MOVETO_GRAPHLIB(0, 0);
    puts(pixels_1D);
}

void PrintConsoleSpace(char **pixels, short width, short height)
{
    short i, j;
    MOVETO_GRAPHLIB(0, 0);
    for (i = 0; i < height; ++i) {
	for (j = 0; j < width+1; ++j) {
            putchar(pixels[i][j]);
            putchar(' ');
	}
	putchar('\n');
    }
}


void ConsoleClear(char **pixels, short width, short height, const char clear)
{
    short i, j;
    for (i = 0; i < height; ++i) {
	for (j = 0; j < width; j++) {
            pixels[i][j] = clear;
        }
    }
}

void PrintRectangle(char **pixels, short width, short height, int x, int y, int largeur, int hauteur, const char fd)
{
    short i, j;
    for (i = -height/2; i < height/2; i++) {
        for (j = -width/2; j < width/2; j++) {
            if (((j >= x) && (j < x+largeur)) && ((i >= y) && (i < y+hauteur)))
            pixels[i+height/2][j+width/2] = fd;
        }
    }
}


void PrintLine(char **pixels, const short width, const short height, int ax, int ay, int bx, int by, const char fd)
{
    COORDF a, b, AB;
    const float midH = (float)height/2.f;
    const float midW = (float)width/2.f;
    a.x = (float)ax/(midW);
    a.y = (float)ay/(-midH);
    b.x = (float)bx/(midW);
    b.y = (float)by/(-midH);
    AB.x = b.x - a.x;
    AB.y = b.y - a.y;
    // TODO: Modify t step with 3 if statement if (sqrt(h² + w²) > 1000) t+=0.0001 else reduce

    double x;
    double y;
    for (double t = 0; t < 1; t+=0.01) {
        x = (AB.x*t + a.x);
        y = (AB.y*t + a.y);
        if ((int)(ABS_GRAPHLIB(x*(midW))) > midW-1 || (int)(ABS_GRAPHLIB(y*(midH))) > midH-1) break;
        pixels[(int)((midH)*(1 - y))][(int)((midW)*(1 + x))] = fd;
    }
}


void PrintCircle(char **pixels, short width, short height, int x, int y, int radius, const char fd)
{
    short i, j;
    for (i = -height/2; i < height/2; i++) {
        for (j = -width/2; j < width/2; j++) {
            if ((i-y)*(i-y) + (j-x)*(j-x) <= radius*radius)
            pixels[i + height/2][j + width/2] = fd;
        }
    }
}

#ifdef TODO
void RotateConsole(char **pixels, short width, short height, float tetha)
{
    RECT wind;
}
#endif

void PrintTriangle(char **pixels, short width, short height, int ax, int ay, int bx, int by, int cx, int cy, const char fd)
{
    COORDF a, b, c;
    a.x = ax;
    a.y = ay;
    b.x = bx;
    b.y = by;
    c.x = cx;
    c.y = cy;

    float gA, gB, gC;

    short x, y;
    for (y = -height/2; y < height/2; y++) {
	for (x = -width/2; x < width/2; x++) {
            gA = ((float)x*(b.y - c.y) + b.x*(c.y - (float)y) + c.x*((float)y - b.y))/(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
            gB = (a.x*((float)y - c.y) + (float)x*(c.y - a.y) + c.x*(a.y - (float)y))/(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
            gC = (a.x*(b.y - (float)y) + b.x*((float)y - a.y) + (float)x*(a.y - b.y))/(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));

            if(gA >= 0 && gB >= 0 && gC >= 0)
            pixels[y+height/2][x+width/2] = fd;
	}
    }
}


void ClearDrawing(uint8_t ***pixels, short width, short height, const uint32_t fd)
{
    short i, j;
    for (i = 0; i < height; ++i) {
	for (j = 0; j < width; j++) {
            pixels[i][j][0] = fd;
            pixels[i][j][1] = fd;
            pixels[i][j][2] = fd;
	}
    }
}

void DrawLine(uint8_t ***pixels, short width, short height, int ax, int ay, int bx, int by, const uint32_t fd)
{
    COORDF a, b, AB;
    a.x = (float)ax/(float)(width/2);
    a.y = (float)ay/(float)(-height/2);
    b.x = (float)bx/(float)(width/2);
    b.y = (float)by/(float)(-height/2);
    AB.x = b.x - a.x;
    AB.y = b.y - a.y;
    // TODO: Modify t step with 3 if statement if (sqrt(h² + w²) > 1000) t+=0.0001 else reduce

    for (double t = 0; t < 1; t+=0.01) {
        double x = (AB.x*t + a.x);
        double y = (AB.y*t + a.y);
        if (ABS_GRAPHLIB(x*(width/2)) > width/2-1 || ABS_GRAPHLIB(y*(height/2)) > height/2-1) break;
        pixels[(int)(-y*(height/2)) + height/2][(int)(x*width/2) + width/2][0] = fd>>(8*3);
        pixels[(int)(-y*(height/2)) + height/2][(int)(x*width/2) + width/2][1] = fd>>(8*2);
        pixels[(int)(-y*(height/2)) + height/2][(int)(x*width/2) + width/2][2] = fd>>(8*1);
    }
}

void DrawCircle(uint8_t ***pixels, short width, short height, int x, int y, int radius, const uint32_t fd)
{
    short i, j;
    for (i = -height/2; i < height/2; i++) {
	for (j = -width/2; j < width/2; j++) {
            if ((i-y)*(i-y) + (j-x)*(j-x) <= radius*radius) {
                pixels[i + height/2][j + width/2][0] |= fd>>(8*3);
                pixels[i + height/2][j + width/2][1] |= fd>>(8*2);
                pixels[i + height/2][j + width/2][2] |= fd>>(8*1);
            }
	}
    }
}

// char **mem_alloc(int H, int W)
// {
//    char **ptr = (char **)malloc(sizeof(char *) * H);
//    TESTMALLOC(ptr);
//    for (int i = 0; i < H; i++) {
//       ptr[i] = (char *)malloc(sizeof(char)*W + 1);
//       TESTMALLOC(ptr[i]);
//    }
//    return ptr;
// }

// void mem_free(char **ptr, int H)
// {
//    for (int i = 0; i < H; i++) {
//       free(ptr[i]);
//    }
//    free(ptr);
// }

// void print_cons(char **pixels, short width, short height)
// {
//    short i, j;
//    char pixels_1D[(width+1) * height];
//    for (i = 0; i < height; ++i) {
//       for (j = 0; j < width+1; ++j) {
//          if      (j < width)     pixels_1D[dec(i, j)] = pixels[i][j];
//          else if (i < height-1)  pixels_1D[dec(i, j)] = '\n';
//             else                    pixels_1D[dec(i, j)] = '\0';
//       }
//    }

//    moveto(0, 0);
//    puts(pixels_1D);
// }

// void print_cons_comp(char **pixels, short width, short height)
// {
//    short i, j;
//    moveto(0, 0);
//    for (i = 0; i < height; ++i) {
//        for (j = 0; j < width+1; ++j) {
//            putchar(pixels[i][j]);
//            putchar(' ');
//        }
//        putchar('\n');
//    }
// }

// void cons_clear(char **pixels, short width, short height, const char clear)
// {
//    short i, j;
//    for (i = 0; i < height; ++i) {
//       for (j = 0; j < width; j++) {
//          pixels[i][j] = clear;
//       }
//    }
// }

// // Fonction revérifié pas de point faible !
// void cons_rect(char **pixels, short width, short height, int x, int y, int largeur, int hauteur, const char fd)
// {
//     short i, j;
//     for (i = -height/2; i < height/2; i++) {
//         for (j = -width/2; j < width/2; j++) {
//             if (((j >= x) && (j < x+largeur)) && ((i >= y) && (i < y+hauteur)))
//                 pixels[i+height/2][j+width/2] = fd;
//         }
//     }
// }

// void cons_ligne(char **pixels, short width, short height, int ax, int ay, int bx, int by, const char fd)
// {
//     COORDF a, b, AB;
//     a.x = (float)ax/(float)(width/2);
//     a.y = (float)ay/(float)(-height/2);
//     b.x = (float)bx/(float)(width/2);
//     b.y = (float)by/(float)(-height/2);
//     AB.x = b.x - a.x;
//     AB.y = b.y - a.y;


//     for (double t = 0; t < 1; t+=0.01) {
//         double x = (AB.x*t + a.x);
//         double y = (AB.y*t + a.y);
// if ((int)(ABS(x*(width/2))) > width/2-1 || (int)(ABS(y*(height/2))) > height/2-1) break;
// pixels[(int)((height/2)*(1 - y))][(int)((width/2)*(1 + x))] = fd; 
//     }
// }


// void cons_cercle(char **pixels, short width, short height, int x, int y, int radius, const char fd)
// {
//     short i, j;
//     for (i = -height/2; i < height/2; i++) {
// for (j = -width/2; j < width/2; j++) {
//     if ((i-y)*(i-y) + (j-x)*(j-x) <= radius*radius)
// pixels[i + height/2][j + width/2] = fd;
// }
//     }
// }

// #ifdef TODO
// void cons_rotate(char **pixels, short width, short height, float tetha)
// {
//    RECT wind;
// }
// #endif

// void cons_triangle(char **pixels, short width, short height, int ax, int ay, int bx, int by, int cx, int cy, const char fd)
// {
//    COORDF a, b, c;
//    a.x = ax;
//    a.y = ay;
//    b.x = bx;
//    b.y = by;
//    c.x = cx;
//    c.y = cy;

//    float gA, gB, gC;

//    short x, y;
//    for (y = -height/2; y < height/2; y++) {
//        for (x = -width/2; x < width/2; x++) {
//    gA = ((float)x*(b.y - c.y) + b.x*(c.y - (float)y) + c.x*((float)y - b.y))/(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
//    gB = (a.x*((float)y - c.y) + (float)x*(c.y - a.y) + c.x*(a.y - (float)y))/(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
//    gC = (a.x*(b.y - (float)y) + b.x*((float)y - a.y) + (float)x*(a.y - b.y))/(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));

//    if(gA >= 0 && gB >= 0 && gC >= 0)
//    pixels[y+height/2][x+width/2] = fd;
//        }
//    }
// }


// void draw_clear(uint8_t ***pixels, short width, short height, const uint32_t fd)
// {
//    short i, j;
//    for (i = 0; i < height; ++i) {
//       for (j = 0; j < width; j++) {
//   pixels[i][j][0] = fd;
//   pixels[i][j][1] = fd;
//   pixels[i][j][2] = fd;
//       }
//    }
// }

// void draw_ligne(uint8_t ***pixels, short width, short height, int ax, int ay, int bx, int by, const uint32_t fd)
// {
//     COORDF a, b, AB;
//     a.x = (float)ax/(float)(width/2);
//     a.y = (float)ay/(float)(-height/2);
//     b.x = (float)bx/(float)(width/2);
//     b.y = (float)by/(float)(-height/2);
//     AB.x = b.x - a.x;
//     AB.y = b.y - a.y;


//     for (double t = 0; t < 1; t+=0.01) {
// double x = (AB.x*t + a.x);
// double y = (AB.y*t + a.y);
// if ((int)(ABS(x*(width/2))) > width/2-1 || (int)(ABS(y*(height/2))) > height/2-1) break;
// pixels[(int)(-y*(height/2)) + height/2][(int)(x*width/2) + width/2][0] = fd>>(8*3);
// pixels[(int)(-y*(height/2)) + height/2][(int)(x*width/2) + width/2][1] = fd>>(8*2);
// pixels[(int)(-y*(height/2)) + height/2][(int)(x*width/2) + width/2][2] = fd>>(8*1);
//     }
// }

// void draw_cercle(uint8_t ***pixels, short width, short height, int x, int y, int radius, const uint32_t fd)
// {
//    short i, j;
//    for (i = -height/2; i < height/2; i++) {
//       for (j = -width/2; j < width/2; j++) {
//   if ((i-y)*(i-y) + (j-x)*(j-x) <= radius*radius) {
//       pixels[i + height/2][j + width/2][0] |= fd>>(8*3);
//       pixels[i + height/2][j + width/2][1] |= fd>>(8*2);
//       pixels[i + height/2][j + width/2][2] |= fd>>(8*1);
//   }
//       }
//    }
// }
