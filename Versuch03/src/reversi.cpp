/**
 * Praktikum Informatik 1 MMXXIII
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

#include "config.h"
#include "reversiKI.h"
#include "test.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            spielfeld[j][i] = 0;
        }
    }
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    // Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char)i) << " | ";

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
            case 0:
                std::cout << "   ";
                break;
            case 1:
                std::cout << " X ";
                break;
            case 2:
                std::cout << " O ";
                break;
            default:
                std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                std::cout << "Abbruch .... " << std::endl;
                exit(0);
                break;
            }
            std::cout << "|";
        }; // for i
        std::cout << std::endl;
    } // for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }
        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
    if (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (i == 0 && j == 0)
                continue;

            int posXneu = posX + i;
            int posYneu = posY + j;
            bool gegnerGefunden = false;

            while (aufSpielfeld(posXneu, posYneu) && spielfeld[posYneu][posXneu] == gegner)
            {
                posXneu += i;
                posYneu += j;
                gegnerGefunden = true;
            }

            if (gegnerGefunden && aufSpielfeld(posXneu, posYneu) && spielfeld[posYneu][posXneu] == aktuellerSpieler)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    if (spielfeld[posY][posX] != 0)
    {
        return;
    }
    else
    {
        spielfeld[posY][posX] = aktuellerSpieler;
    }

    // Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            if (i == 0 && j == 0)
                continue;

            int posXneu = posX + i;
            int posYneu = posY + j;
            bool gegnerGefunden = false;

            while (aufSpielfeld(posXneu, posYneu) && spielfeld[posYneu][posXneu] == gegner)
            {
                posXneu += i;
                posYneu += j;
                gegnerGefunden = true;
            }

            if (gegnerGefunden && aufSpielfeld(posXneu, posYneu) && spielfeld[posYneu][posXneu] == aktuellerSpieler)
            {
                posXneu -= i;
                posYneu -= j;

                while (posXneu != posX || posYneu != posY)
                {
                    spielfeld[posYneu][posXneu] = aktuellerSpieler;
                    posXneu -= i;
                    posYneu -= j;
                }
            }
        }
    }
}

/**
 * @brief Berechnet die Anzahl der möglichen Züge für den aktuellen Spieler
 *
 * Die Funktion durchläuft das gesamte Spielfeld und prüft für jedes Feld, ob
 * ein Zug für den aktuellen Spieler möglich ist. Wenn ja, wird die Anzahl der
 * möglichen Züge um eins erhöht.
 *
 * @param spielfeld Das Spielfeld, auf dem der Zug ausgeführt werden soll.
 * @param aktuellerSpieler Der aktuelle Spieler, für den die möglichen Züge berechnet werden sollen.
 * @return Die Anzahl der möglichen Züge für den aktuellen Spieler.
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int anzahlZuge = 0;

    for (int posY = 0; posY < GROESSE_Y; posY++)
    {
        for (int posX = 0; posX < GROESSE_X; posX++)
        {
            if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
            {
                anzahlZuge++;
            }
        }
    }
    return anzahlZuge;
}
/**
 * @brief Erlaubt es einem menschlichen Spieler, einen Zug auszuführen.
 *
 * Wenn es für den aktuellen Spieler mindestens einen möglichen Zug gibt, wird der
 * Spieler aufgefordert, seinen Zug einzugeben. Die Eingabe wird überprüft und falls
 * sie gültig ist, wird der Zug auf dem Spielfeld ausgeführt. Andernfalls wird der
 * Spieler erneut aufgefordert, seinen Zug einzugeben.
 *
 * @param spielfeld Das Spielfeld, auf dem der Zug ausgeführt werden soll.
 * @param aktuellerSpieler Der aktuelle Spieler, der einen Zug ausführen soll.
 * @return Gibt true zurück, wenn ein Zug ausgeführt wurde, andernfalls false.
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): ";
        std::cin >> eingabe;
        posX = (int)eingabe[0] % 32 - 1;
        posY = (int)eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            // accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl
              << "Spieler " << aktuellerSpieler << " setzt auf " << (char)(posX + 65) << (posY + 1) << std::endl;

    return true;
}
/**
 * @brief Spielt Reversi zwischen zwei Spielern.
 *
 * @param spielerTyp Array mit den Typen der beiden Spieler (COMPUTER oder MENSCH).
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    // Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    while (moeglicheZuege(spielfeld, 1) > 0 || moeglicheZuege(spielfeld, 2) > 0)
    {
        if (spielerTyp[aktuellerSpieler - 1] == COMPUTER)
        {
            computerZug(spielfeld, aktuellerSpieler);
            // std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else
        {
            menschlicherZug(spielfeld, aktuellerSpieler);
        }

        zeigeSpielfeld(spielfeld);
        aktuellerSpieler = 3 - aktuellerSpieler;
    }

    switch (gewinner(spielfeld))
    {
    case 0:
        std::cout << "Unentschieden!" << std::endl;
        break;
    case 1:
        std::cout << "Spieler 1 hat gewonnen!" << std::endl;
        break;
    case 2:
        std::cout << "Spieler 2 hat gewonnen!" << std::endl;
        break;
    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }

    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    // int spielfeld[GROESSE_Y][GROESSE_X];

    // initialisiereSpielfeld(spielfeld);

    // zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt.
    // MENSCH(=1) oder COPMUTER(=2) spielen(spielerTyp);
    //
    int spielerTyp[2] = {COMPUTER, COMPUTER};
    spielen(spielerTyp);
    return 0;
}
