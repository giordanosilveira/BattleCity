#ifndef COORDENADA_HPP
#define COORDENADA_HPP

class Coordenada {
    public:
        Coordenada();
        Coordenada(const unsigned short int x, const unsigned short int y);

        const unsigned short int getX() const;
        void setY(const unsigned short int y);

        const unsigned short int getY() const;
        void setX(const unsigned short int x);

        virtual ~Coordenada();
    private:
        unsigned short int x;
        unsigned short int y;
};

#endif