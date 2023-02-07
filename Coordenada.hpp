#ifndef COORDENADA_HPP
#define COORDENADA_HPP

class Coordenada {
    public:
        Coordenada();
        Coordenada(const unsigned int x, const unsigned int y);

        const unsigned int getX() const;
        void setY(const unsigned int y);

        const unsigned int getY() const;
        void setX(const unsigned int x);

        virtual ~Coordenada();
    private:
        unsigned int x;
        unsigned int y;
};

#endif