#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(std::string name);
        std::string getName(void);
        void setName(std::string newName);
        void announce() const;
        ~Zombie();
};

#endif
