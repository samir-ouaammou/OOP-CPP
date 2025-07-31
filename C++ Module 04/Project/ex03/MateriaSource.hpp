#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &copy);
        MateriaSource &operator=(MateriaSource const &src);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const &type);
};

#endif
