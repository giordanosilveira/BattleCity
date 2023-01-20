#ifndef ESTADO_HPP
#define ESTADO_HPP

class Estado {
    public:
        static void inicializar();
        static void jogo();
        static void encerrar();
        
        static short int atual;

        static constexpr short int INICIALIZAR = 0; // mudar estados para enum
        static constexpr short int JOGO = 1; 
        static constexpr short int ENCERRAR = 2; 
};

#endif
