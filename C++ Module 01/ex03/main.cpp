# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"
# include <iostream>

int main()
{
    {
        Weapon club = Weapon("\'HumanA aaa\'");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("\'HumanA aaa\'");
        bob.attack();
    }
    {
        Weapon club = Weapon("\'HumanB bbb\'");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("\'HumanB bbb\'");
        jim.attack();
    }
    return 0;
}