#define GLIPH_IMPLEMENTATION
#include "gliph.h"

int main()
{
    // printf(BLACK"%s"RESET, "salut tout le monde\n");
    // printf(RED"%s"RESET, "salut tout le monde\n");
    // printf(GREEN"%s"RESET, "salut tout le monde\n");
    // printf(YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(BLUE"%s"RESET, "salut tout le monde\n");
    // printf(PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(CYAN"%s"RESET, "salut tout le monde\n");
    // printf(WHITE"%s"RESET, "salut tout le monde\n");

    // printf(BOLD_BLACK"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_RED"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_GREEN"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_BLUE"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_CYAN"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_WHITE"%s"RESET, "salut tout le monde\n");

    // printf(UL_BLACK"%s"RESET, "salut tout le monde\n");
    // printf(UL_RED"%s"RESET, "salut tout le monde\n");
    // printf(UL_GREEN"%s"RESET, "salut tout le monde\n");
    // printf(UL_YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(UL_BLUE"%s"RESET, "salut tout le monde\n");
    // printf(UL_PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(UL_CYAN"%s"RESET, "salut tout le monde\n");
    // printf(UL_WHITE"%s"RESET, "salut tout le monde\n");

    // printf(BG_BLACK"%s"RESET, "salut tout le monde\n");
    // printf(BG_RED"%s"RESET, "salut tout le monde\n");
    // printf(BG_GREEN"%s"RESET, "salut tout le monde\n");
    // printf(BG_YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(BG_BLUE"%s"RESET, "salut tout le monde\n");
    // printf(BG_PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(BG_CYAN"%s"RESET, "salut tout le monde\n");
    // printf(BG_WHITE"%s"RESET, "salut tout le monde\n");

    // printf(HI_BLACK"%s"RESET, "salut tout le monde\n");
    // printf(HI_RED"%s"RESET, "salut tout le monde\n");
    // printf(HI_GREEN"%s"RESET, "salut tout le monde\n");
    // printf(HI_YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(HI_BLUE"%s"RESET, "salut tout le monde\n");
    // printf(HI_PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(HI_CYAN"%s"RESET, "salut tout le monde\n");
    // printf(HI_WHITE"%s"RESET, "salut tout le monde\n");

    // printf(BOLD_HI_BLACK"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_RED"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_GREEN"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_BLUE"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_CYAN"%s"RESET, "salut tout le monde\n");
    // printf(BOLD_HI_WHITE"%s"RESET, "salut tout le monde\n");

    // printf(HI_BG_BLACK"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_RED"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_GREEN"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_YELLOW"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_BLUE"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_PURPLE"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_CYAN"%s"RESET, "salut tout le monde\n");
    // printf(HI_BG_WHITE"%s"RESET, "salut tout le monde\n");

    // for (int i = 0; i < 100; i++) {
    // 	for (int j = 0; j < 100; j++)
    // 	    printf("\e[%d;%dm%c", i, j, 'c');
    // 	printf("\n");
    // }

    for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 6; j++) {
	    for (int k = 0; k < 6; k++) {
		PRINT_CHAR_COLOR(i, j, k, '@');
		PRINT_CHAR_COLOR(i, j, k, '@');
	    }
	    printf(RESET"\n");
	}
	printf(RESET"%d\n", i);
    }
    printf(RESET"\n\n");

    int width = 100;
    int height = 30;

    for (int i = 0; i < height; i++) {
	for (int j = 0; j < width; j++) {
	    PRINT_BG_COLOR((int)(((float)j/(float)width)*6), (int)(((float)((height-i)*(width-j))/(float)(width*height))*6), (int)(((float)i/(float)height)*6), ' ');
	    // PRINT_BG_COLOR((int)(((float)j/(float)width)*5), 6, (int)(((float)i/(float)height)*5), ' ');
	}
	printf(RESET"\n");
    }

    return 0;
}
