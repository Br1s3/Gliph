CC = gcc
RM = rm -rf
EXEC = BasicExemple animation raytracing triangle 3DSquare MeshGrid MeshGrid2

CFLAGS +=	\
-Wextra		\
-Wall   	\
-lm   	        \
-g3

#-O3

.PHONY: all clean

all: $(EXEC)

%: %.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	$(RM) $(EXEC)
