// talvez classe de cor pra fazer depois
#ifndef COR_HPP
#define COR_HPP

class Cor {
    public:
        Cor(const unsigned short int r, const unsigned short int g, const unsigned short int b);
        Cor(const unsigned short int r, const unsigned short int g, const unsigned short int b, const float a);

        Cor(Cor )

    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        float a;
}

#endif