/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    struct Person
    {
        std::string sNachname;
        std::string sVorname;
        int iGeburtsjahr;
        int iAlter;
    };

    Person nBenutzer;
    nBenutzer = {"Yilmaz", "Baran", 2002, 0};
    nBenutzer.iAlter = 2023 - nBenutzer.iGeburtsjahr;

    std::cout << nBenutzer.sVorname << " " << nBenutzer.sNachname << " geboren in " << nBenutzer.iGeburtsjahr << " ist "
              << nBenutzer.iAlter << " Jahre alt." << std::endl;

    Person nKopieEinzeln;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    Person nKopieGesamt = nBenutzer;

    std::cout << nKopieEinzeln.sVorname << " " << nKopieEinzeln.sNachname << " geboren in "
              << nKopieEinzeln.iGeburtsjahr << " ist " << nKopieEinzeln.iAlter << " Jahre alt. "
              << "(Einzeln)" << std::endl;

    std::cout << nKopieGesamt.sVorname << " " << nKopieGesamt.sNachname << " geboren in " << nKopieGesamt.iGeburtsjahr
              << " ist " << nKopieGesamt.iAlter << " Jahre alt. "
              << "(Gesamt)" << std::endl;
    return 0;
}
