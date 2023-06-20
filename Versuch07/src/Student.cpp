//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

/**
 * @file Student.cpp
 *
 * Enthält die Implementierung der Klasse Student
 *
 */

#include "Student.h"
#include <iostream>

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse)
    : matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{
}

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{
}

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 *
 * @param o Ausgabestream
 */
void Student::ausgabe(std::ostream &o) const
{
    o << name << ", MatNr. " << matNr << ", geb. am " << geburtstag << ", wohnhaft in " << adresse << std::endl;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer
 *
 * @param s1 Student, mit dem der aktuelle Student verglichen wird
 *
 * @return true, wenn die Matrikelnummern gleich sind
 */

bool Student::operator==(const Student &s1)
{
    if (this->matNr == s1.matNr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Vergleicht die Matrikelnummer eines Studenten mit einer Zahl
 *
 * @param num Zahl, mit der die Matrikelnummer verglichen wird
 *
 * @return true, wenn die Matrikelnummern gleich sind
 */
bool Student::operator==(const unsigned int num)
{
    return matNr == num;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer
 *
 * @param s1 Student, mit dem der aktuelle Student verglichen wird
 *
 * @return true, wenn die Matrikelnummer des aktuellen Studenten kleiner ist
 */
bool Student::operator<(const Student &s1)
{
    if (this->matNr < s1.matNr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer
 *
 * @param s1 Student, mit dem der aktuelle Student verglichen wird
 *
 * @return true, wenn die Matrikelnummer des aktuellen Studenten groesser ist
 */
bool Student::operator>(const Student &s1)
{
    if (this->matNr > s1.matNr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
