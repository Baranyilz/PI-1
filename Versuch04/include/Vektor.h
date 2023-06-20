//
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//
#pragma once
#ifndef Vektor_H
#define Vektor_H

#include <cmath>
#include <iomanip>
#include <iostream>

const double pi = 3.14159265358979;

class Vektor
{
  public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor sub(const Vektor &input) const;
    double laenge() const;
    double skalarProd(const Vektor &input) const;
    double winkel(const Vektor &input) const;
    void rotiereUmZ(const double rad);

  private:
    /**
     * @brief x-Komponente des Vektors
     */
    double x;

    /**
     * @brief y-Komponente des Vektors
     */
    double y;

    /**
     * @brief z-Komponente des Vektors
     */
    double z;
};

#endif
