//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////
/**
 * @file  Student.h
 * Enthält die Klasse Student
 *
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <algorithm>
#include <iostream>
#include <string>

class Student
{
  public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe(std::ostream &o) const;

    /**
     * @brief Überladung des == Operators (anhand der Matrikelnummer)
     */
    bool operator==(const Student &s1);

    /**
     * @brief Überladung des ==  Operators (anhand der Matrikelnummer)
     */
    bool operator==(const unsigned int num);

    /**
     * @brief Überladung des <  Operators (anhand der Matrikelnummer)
     */
    bool operator<(const Student &s1);

    /**
     * @brief Überladung des >  Operators (anhand der Matrikelnummer)
     */
    bool operator>(const Student &s1);

  private:
    /**
     * @brief Matrikelnummer des Studenten
     */
    unsigned int matNr;

    /**
     * @brief Name des Studenten
     */
    std::string name;

    /**
     * @brief Geburtstag des Studenten
     */
    std::string geburtstag;

    /**
     * @brief Adresse des Studenten
     */
    std::string adresse;
};

#endif
