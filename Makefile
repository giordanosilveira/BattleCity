CFLAGS= --std=c++17 -Wall
PKG_CONFIG=`pkg-config allegro-5 allegro_font-5 allegro_image-5 allegro_audio-5 allegro_acodec-5 allegro_primitives-5 --libs --cflags`
EXEC= battle_city
FILES= main.o Estado.o ControleJogo.o Tela.o AllegroInitException.o Jogo.o Sprite.o Util.o Player.o Objeto.o Tanque.o Coordenada.o 

all: $(EXEC)

$(EXEC): $(FILES)
	g++ $^ -o $(EXEC) $(CFLAGS) $(PKG_CONFIG)


clean: 
	rm -f *.o $(EXEC)
