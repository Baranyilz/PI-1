//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include "Vektor.h"
#define epsilon 1e-6

int main()
{
    double Radius = 6371;
    double Hoehe = 555.7;
    double Groesse = 1.7;

    double Schrittweite = 0.00000001;
    int Schritte = 0;
    double Winkel = 0;

    Vektor V_R(0, Radius, 0);                            // Radiusvektor
    Vektor V_H(0, Radius + (Hoehe + Groesse) / 1000, 0); // Hoehevektor
    Vektor V_T = V_H.sub(V_R);                           // Vektor der die Erdoberflache tangiert

    while (abs(90 - V_T.winkel(V_R)) >= epsilon)
    {
        V_R.rotiereUmZ(Schrittweite);
        V_T = V_H.sub(V_R);
        Winkel += Schrittweite;
        Schritte++;
    }

    std::cout << std ::setprecision(4) << "Sie koennen " << V_T.laenge() << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << Hoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << Winkel * (180 / pi) << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << Schritte << std::endl;
}