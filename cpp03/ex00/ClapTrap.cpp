#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("none"), HP(10), ENG(10), ATT(0)
{
    std::cout << "DEFAULT CONSTRUCTOR CALLED !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "COPY CONSTRUCTOR CALLED !" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "OPERATOT '=' CALLED !" << std::endl;
    if (this != &copy)
    {
        this->name = copy.GetName();
        this->ATT = copy.GetATT();
        this->HP = copy.GetHP();
        this->ENG = copy.GetENG();
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "DESTRUCTOR CALLED !" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), HP(10), ENG(10), ATT(0)
{
    std::cout << "PARAMETERIZED CONSTRUCTOR CALLED !" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->HP > 0 && this->ENG > 0)
    {
        this->ENG--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ATT << " points of damage!" << std::endl;
    }
    else if (this->HP == 0)
        std::cout << "ClapTrap " << name << " cannot attack cuz he is FR DEAD!" << std::endl;
    else if (this->ENG == 0)
        std::cout << "ClapTrap " << name << " is out of ENERGY !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HP > 0)
    {
        if (this->HP >= amount)
            this->HP -= amount;
        else
            this->HP = 0;
        std::cout << "ClapTrap " << name << " have teken damage, causing " << amount << " points of damage!" << std::endl;
    }
    if (this->HP == 0)
        std::cout << "ClapTrap " << name << " is DEAD !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HP > 0 && this->ENG > 0)
    {
        this->ENG--;
        if (this->HP + amount <= 10) {
            this->HP += amount;
            std::cout << "ClapTrap " << name << " is healing, causing " << amount << " points of heal!" << std::endl;
        }
        else {
            std::cout << "ClapTrap " << name << " is healing, causing " << 10 - this->HP << " points of heal!" << std::endl;
            this->HP = 10;
        }
    }
    else if (this->HP == 0)
        std::cout << "ClapTrap " << name << " cannot heal what already DEAD sry!" << std::endl;
    else if (this->ENG == 0)
        std::cout << "ClapTrap " << name << " is out of MANA !" << std::endl;
}

std::string ClapTrap::GetName(void) const
{
    // std::cout << "GETNAME IS CALLED !" << std::endl;
    return name;
}

unsigned int ClapTrap::GetHP(void) const
{
    // std::cout << "GETHP IS CALLED !" << std::endl;
    return HP;
}

unsigned int ClapTrap::GetATT(void) const
{
    // std::cout << "GETATT IS CALLED !" << std::endl;
    return ATT;
}

unsigned int ClapTrap::GetENG(void) const
{
    // std::cout << "GETENG IS CALLED !" << std::endl;
    return ENG;
}