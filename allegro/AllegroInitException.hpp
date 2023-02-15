#ifndef ALLEGRO_INIT_EXCEPTION_HPP
#define ALLEGRO_INIT_EXCEPTION_HPP

#include <string>
#include <stdexcept>

namespace allegro{
class AllegroInitException : public std::runtime_error{
    public:
        AllegroInitException(const std::string &name);
        virtual ~AllegroInitException() = default;
};
}

#endif