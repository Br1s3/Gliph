#ifndef GRAPHLIB_H_INCLUED
#define GRAPHLIB_H_INCLUED

#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// #define max(x, y) ((x)<(y) ? (y) : (x))
// #define min(x, y) ((x)>(y) ? (y) : (x))
#define MOVETO_GRAPHLIB(y, x) printf("\033[%d;%dH", (y), (x))
#define DEC_GRAPHLIB(x, y) (((x)*(width+1)) + (y))
#define ABS_GRAPHLIB(x) ((x) < 0 ? (-x) : (x))


#define GRAPHLIB_MALLOC2D(type, name, H, W)	                \
    type **name = (type **)malloc(sizeof(type *) * ((H)+1));    \
    TESTMALLOC(name);					        \
    for (ssize_t i = 0; i < ((H)); i++) {        	        \
	name[i] = (type *)malloc(sizeof(type)*((W) + 1));	\
	TESTMALLOC(name[i]);					\
    }								\
    name[(H)] = NULL;	        				\
do {} while (0) 


#define GRAPHLIB_FREE2D(name, H)	                                             \
    if (name == NULL) fprintf(stdout, "WARNING: %s is NULL, %d\n", #name, __LINE__); \
    for (ssize_t i = 0; i < (H); i++) free(name[i]);			             \
    free(name);								             \
do {} while (0) 


#define TESTMALLOC(x)                                                          \
do                                                                             \
{                                                                              \
    if (x == NULL) {                                                           \
        fprintf(stderr, "ERROR: %s, ligne : %d\n", strerror(errno), __LINE__); \
        exit(EXIT_FAILURE);                                                    \
    }                                                                          \
} while(0)


typedef struct
{
   int x, y;
}COORD;

typedef struct
{
   float x, y;
}COORDF;

char **mem_alloc(int H, int W);
void mem_free(char **ptr, int H);

void PrintConsole(char **pixels, short width, short height);
void PrintConsoleSpace(char **pixels, short width, short height);

void ConsoleClear(char **pixels, short width, short height, const char clear);

void PrintRectangle(char **pixels, short width, short height, int x, int y, int largeur, int hauteur, const char fd);
void PrintCircle(char **pixels, short width, short height, int x, int y, int radius, const char fd);
void PrintLine(char **pixels, const short width, const short height, int ax, int ay, int bx, int by, const char fd);
void PrintTriangle(char **pixels, short width, short height, int ax, int ay, int bx, int by, int cx, int cy, const char fd);



void ClearDrawing(uint8_t ***pixels, short width, short height, const uint32_t fd);

void DrawLine(uint8_t ***pixels, short width, short height, int ax, int ay, int bx, int by, const uint32_t fd);
void DrawCircle(uint8_t ***pixels, short width, short height, int x, int y, int radius, const uint32_t fd);


#endif //GRAPHLIB_H_INCLUED
