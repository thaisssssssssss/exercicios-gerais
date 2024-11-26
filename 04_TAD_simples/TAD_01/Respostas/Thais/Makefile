CC=gcc
CFLAGS=-lm -Wall

DEPS= jogada.h jogador.h jogo.h tabuleiro.h

OBJ=jogada.o jogador.o jogo.o tabuleiro.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ponto: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

clean:
	rm -rf *.o main