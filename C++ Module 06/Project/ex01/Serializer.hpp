#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &src);
        ~Serializer();

    public:
        static uintptr_t    serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif
