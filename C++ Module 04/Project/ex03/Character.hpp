#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria    *_inventory[4];
        AMateria    *_tmp[1000];
        int         _tmpIndex;

    public:
        Character(std::string const & name);
        Character(Character const &copy);
        Character &operator=(Character const &src);
        ~Character();

        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
