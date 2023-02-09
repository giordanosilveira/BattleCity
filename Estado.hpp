#ifndef ESTADO_HPP
#define ESTADO_HPP

class Estado {
    public:
        static void jogo();
        static void encerrar();
        
        static short int atual;

        static const short int JOGO = 1; 
        static const short int ENCERRAR = 2; 
};

#endif
