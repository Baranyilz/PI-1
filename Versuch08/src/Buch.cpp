#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel), Autor(initAutor)
{
}

void Buch::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Autor: " << Autor << std::endl;
}

void Buch::ausgabe(std::ostream &o) const
{
    Medium::ausgabe(o);
    o << "Autor: " << Autor << std::endl;
}
