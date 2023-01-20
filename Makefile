CFLAGS= --std=c++17 -Wall
PKG_CONFIG=`pkg-config allegro-5 allegro_font-5 --libs --cflags`
EXEC= battle_city

all: $(EXEC)

$(EXEC): main.o Estado.o
	g++ main.o Estado.o -o $(EXEC) $(CFLAGS) $(PKG_CONFIG)

main.o: main.cpp
	g++ -c main.cpp -o main.o $(CFLAGS)

Estado.o: Estado.cpp Estado.hpp
	g++ -c Estado.cpp -o Estado.o $(CFLAGS)

clean: 
	rm -f *.o $(EXEC)
