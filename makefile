CC = gcc
LDFLAGS = -I/usr/local/include -L/usr/local/lib 
CFLAGS = -std=c99 -Wall
LIBS = -lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_audio -lallegro_acodec
NAME = main
OBJ = main.o init.o draw.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBS) 

main.o: main.c structures.h
	$(CC) $(CFLAGS) -c main.c

init.o: init.c init.h structures.h
	$(CC) $(CFLAGS) -c init.c

draw.o: draw.c draw.h structures.h init.h
	$(CC) $(CFLAGS) -c draw.c

clean:
	rm -f *.o

purge:
	rm -f *.o
	rm -f $(NAME)
