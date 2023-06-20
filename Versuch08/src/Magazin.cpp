#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), ErscheinungsDatum(initDatumAusgabe), Sparte(initSparte)
{
}

void Magazin::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Ausgabe: " << ErscheinungsDatum << std::endl;
    std::cout << "Sparte: " << Sparte << std::endl;
}

void Magazin::ausgabe(std::ostream &o) const
{
    Medium::ausgabe(o);
    o << "Ausgabe: " << ErscheinungsDatum << std::endl;
    o << "Sparte: " << Sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    // pruefen, ob das Magazin die neueste Ausgabe ist
    if (ErscheinungsDatum - ausleihdatum > 1)
    {
        std::cout << "Das Magazin " << titel << " ist die neueste Ausgabe und kann nicht ausgeliehen werden."
                  << std::endl;
        return false;
    }
    else
        return Medium::ausleihen(person, ausleihdatum);
}