CFLAGS= --std=c++17 -Wall
PKG_CONFIG=`pkg-config allegro-5 allegro_font-5 allegro_image-5 allegro_audio-5 allegro_acodec-5 allegro_primitives-5 --libs --cflags`
EXEC= battle_city

all: $(EXEC)

$(EXEC): main.o Estado.o ControleJogo.o Tela.o AllegroInitException.o Jogo.o Sprite.o Util.o
	g++ main.o Estado.o ControleJogo.o Tela.o AllegroInitException.o Jogo.o Sprite.o Util.o -o $(EXEC) $(CFLAGS) $(PKG_CONFIG)

main.o: main.cpp
	g++ -c main.cpp -o main.o $(CFLAGS)

Estado.o: Estado.cpp Estado.hpp
	g++ -c Estado.cpp -o Estado.o $(CFLAGS)

ControleJogo.o: ControleJogo.cpp ControleJogo.hpp
	g++ -c ControleJogo.cpp -o ControleJogo.o $(CFLAGS)

Tela.o: Tela.cpp Tela.hpp
	g++ -c Tela.cpp -o Tela.o $(CFLAGS)

AllegroInitException.o: AllegroInitException.cpp AllegroInitException.hpp
	g++ -c AllegroInitException.cpp -o AllegroInitException.o $(CFLAGS)

Jogo.o: Jogo.cpp Jogo.hpp
	g++ -c Jogo.cpp -o Jogo.o $(CFLAGS)

Sprite.o: Sprite.cpp Sprite.hpp
	g++ -c Sprite.cpp -o Sprite.o $(CFLAGS)

Util.o: Util.cpp Util.hpp
	g++ -c Util.cpp -o Util.o $(CFLAGS)


clean: 
	rm -f *.o $(EXEC)
