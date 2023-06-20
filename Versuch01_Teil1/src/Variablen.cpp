//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    std::cout << "Bitte geben Sie die erste Zahl ein: ";
    std::cin >> iErste;

    std::cout << "Bitte geben Sie die zweite Zahl ein: ";
    std::cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;

    std::cout << "Die Summe der beiden Zahlen ist: " << iSumme << std::endl;
    std::cout << "Der Quotient der beiden Zahlen ist: " << iQuotient << std::endl;

    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;

    std::cout << "Die Summe (double) der beiden Zahlen ist: " << dSumme << std::endl;
    std::cout << "Der Quotient (double) der beiden Zahlen ist: " << dQuotient << std::endl;

    double dSummeCast = static_cast<double>(iErste) + static_cast<double>(iZweite);
    double dQuotientCast = static_cast<double>(iErste) / static_cast<double>(iZweite);

    std::cout << "Die Summe (doubleCast) der beiden Zahlen ist: " << dSummeCast << std::endl;
    std::cout << "Der Quotient (doubleCast) der beiden Zahlen ist: " << dQuotientCast << std::endl;

    std::string sVorname;
    std::string sNachname;

    std::cout << "Bitte geben Sie Ihren Vornamen ein: ";
    std::cin >> sVorname;

    std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    std::cin >> sNachname;

    std::string sVornameName = sVorname + " " + sNachname;
    std::string sNameVorname = sNachname + ", " + sVorname;

    std::cout << "Ihr Name lautet: " << sVornameName << std::endl;
    std::cout << "Ihr Name lautet: " << sNameVorname << std::endl;

    {
        int iFeld[2] = {1, 2};

        std::cout << "Das erste Element des Feldes ist: " << iFeld[0] << std::endl;
        std::cout << "Das zweite Element des Feldes ist: " << iFeld[1] << std::endl;

        int spielfeld[2][3] = {1, 2, 3, 4, 5, 6};

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << spielfeld[i][j] << " ";
            }
            std::cout << std::endl;
        }

        int iZwiete = 1;
        std::cout << "iZweite im Block: " << iZwiete << std::endl;
    }

    std::cout << "iZweite ausserhalb des Blocks: " << iZweite << std::endl;

    int iName1 = int(sVorname[0]);
    int iName2 = int(sVorname[1]);

    std::cout << "Der ASCII-Wert des ersten Buchstaben ist: " << iName1 << std::endl;
    std::cout << "Der ASCII-Wert des zweiten Buchstaben ist: " << iName2 << std::endl;

    std::cout << "Die Position des ersten Buchstaben im Alphabet ist: " << (std::toupper(iName1) - 'A' + 1) % 26
              << std::endl;
    std::cout << "Die Position des zweiten Buchstaben im Alphabet ist: " << (std::toupper(iName2) - 'A' + 1) % 26
              << std::endl;
    return 0;
}
