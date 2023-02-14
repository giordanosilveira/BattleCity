#ifndef ESTADO_HPP
#define ESTADO_HPP

class Estado {
    public:
        static void jogo();
        static void encerrar();
        static void jogoTerminado();
        
        static short int atual;

        enum estado_atual{
            JOGO = 0,
            JOGO_TERMINADO,
            ENCERRAR
        };
};

#endif
