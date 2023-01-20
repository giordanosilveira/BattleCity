CFLAGS= --std=c++17 -Wall

EXEC= battle_city

all: $(EXEC)

$(EXEC): main.cpp
	g++ main.cpp -o $(EXEC) $(CFLAGS)

clean: 
	rm -f *.o $(EXEC)
