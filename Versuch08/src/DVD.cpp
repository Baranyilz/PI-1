#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), Altersfreigabe(initAltersfreigabe), Genre(initGenre)
{
}

void DVD::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "FSK: " << Altersfreigabe << std::endl;
    std::cout << "Genre: " << Genre << std::endl;
}

void DVD::ausgabe(std::ostream &o) const
{
    Medium::ausgabe(o);
    o << "FSK: " << Altersfreigabe << std::endl;
    o << "Genre: " << Genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    // pruefen, ob die Person die ALtersgrenze erreicht hat
    if ((ausleihdatum - person.getGeburtsdatum()) / 12 < Altersfreigabe)
    {
        std::cout << "Die Person ist zu jung um die DVD auszuleihen." << std::endl;
        return false;
    }
    else
        return Medium::ausleihen(person, ausleihdatum);
}
