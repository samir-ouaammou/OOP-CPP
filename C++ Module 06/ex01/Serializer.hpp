#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &src);
        ~Serializer();

    public:
        static unsigned long serialize(Data *ptr);
        static Data *deserialize(unsigned long raw);
};

#endif
