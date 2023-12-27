CC = gcc
LDFLAGS = -I/usr/local/include -L/usr/local/lib 
CFLAGS = -std=c99 -Wall
LIBS = -lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_audio -lallegro_acodec
NAME = main
OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBS) 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o

purge:
	rm -f *.o
	rm -f $(NAME)
