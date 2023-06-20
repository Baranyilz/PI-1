//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////
#include "Vektor.h"

/**
 * @brief Konstruktor der Klasse Vektor
 *
 * @param inX x-Komponente des Vektors
 * @param inY y-Komponente des Vektors
 * @param inZ z-Komponente des Vektors
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

Vektor::~Vektor()
{
}

/**
 * @brief Function printing the components of the vector
 *
 * @return void
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
/**
 * @brief Funktion zur Substaktion zweier Vektoren
 *
 * @param input Vektor, der von dem aktuellen Vektor abgezogen wird
 * @return Differenz der beiden Vektoren
 */
Vektor Vektor::sub(const Vektor &input) const
{
    return Vektor(this->x - input.x, this->y - input.y, this->z - input.z);
}

/**
 * @brief Funktion zur berechnung der Länge eines Vektors
 *
 * @return Länge des Vektors als double
 */
double Vektor::laenge() const
{
    return sqrt(x * x + y * y + z * z);
}

/**
 * @brief Funktion zur Berechnung des Skalarprodukts zweier Vektoren
 *
 * @param input Vektor, mit dem das Skalarprodukt berechnet wird
 *
 * @return Skalarprodukt der beiden Vektoren als double
 */
double Vektor::skalarProd(const Vektor &input) const
{
    return this->x * input.x + this->y * input.y + this->z * input.z;
}

/**
 * @brief Funktion zur Berechnung des Winkels zwischen zwei Vektoren
 *
 * @param input Vektor, mit dem der Winkel berechnet wird
 *
 * @return Winkel zwischen den beiden Vektoren in Grad als double
 */
double Vektor::winkel(const Vektor &input) const
{
    double winkel_rad = acos(this->skalarProd(input) / (this->laenge() * input.laenge()));
    return winkel_rad * 180 / pi;
}

/**
 * @brief Funktion um einen Vektor um die Z-Achse zu rotieren
 *
 * @param rad Winkel, um den der Vektor rotiert werden soll
 *
 * @return void
 */
void Vektor::rotiereUmZ(const double rad)
{
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);

    double neu_x = this->x * cos_rad - this->y * sin_rad;
    double neu_y = this->x * sin_rad + this->y * cos_rad;

    this->x = neu_x;
    this->y = neu_y;
}
