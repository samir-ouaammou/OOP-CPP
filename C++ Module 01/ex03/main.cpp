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
        club.setType("\'HumanA bbb\'");
        bob.attack();
    }
    {
        Weapon club = Weapon("\'HumanB aaa\'");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("\'HumanB aaa\'");
        jim.attack();
    }
    return 0;
}