#ifndef ESTADO_HPP
#define ESTADO_HPP

class Estado {
    public:
        static void jogo();
        static void encerrar();
        static void jogoVencido();
        static void jogoPerdido();
        
        static short int atual;

        enum estado_atual{
            JOGO = 0,
            JOGO_PERDIDO,
            JOGO_VENCIDO,
            ENCERRAR
        };
};

#endif
