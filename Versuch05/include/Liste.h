//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
  private:
    /**
     * @brief Zeiger auf das erste Listenelement
     */
    ListenElement *front;

    /**
     * @brief Zeiger auf das letzte Listenelement
     */
    ListenElement *back; // Zeiger auf das letzte Listenelement

  public:
    Liste(); // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);
    void pushFront(Student pData);
    void popFront();
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const;
    void DeleteMatnr(unsigned int pMatrikelnummer);
};

#endif /*LISTE_H_*/
