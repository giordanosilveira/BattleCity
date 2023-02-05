#ifndef ALLEGRO_INIT_EXCEPTION_HPP
#define ALLEGRO_INIT_EXCEPTION_HPP

#include <stdexcept>

class AllegroInitException : public std::runtime_error{
    public:
        AllegroInitException();
        virtual ~AllegroInitException() = default;
};

#endif