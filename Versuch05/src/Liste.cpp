//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste() : front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement *neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (back == nullptr) // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement *neuesElement = new ListenElement(pData, nullptr, nullptr);
    if (back == nullptr) // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        front->setPrev(neuesElement);
        neuesElement->setNext(front);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement *cursor = front;

    if (front == nullptr) // Liste Leer?
    {
        return;
    }

    if (front == back) // Liste hat nur ein Element?
    {
        front = nullptr;
        back = nullptr;
        delete cursor;
    }

    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement *cursor = front;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement *cursor = back;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Loeschen eines Listenelements mit der uebergebenen Matrikelnummer.
 *
 * @param pMatrikelnummer Matrikelnummer des zu loeschenden Studenten
 * @return void
 */
void Liste::DeleteMatnr(unsigned int pMatrikelnummer)
{
    ListenElement *cursor = front;
    ListenElement *prev = nullptr;

    while (cursor != nullptr && cursor->getData().getMatNr() != pMatrikelnummer)
    {
        prev = cursor;
        cursor = cursor->getNext();
    }

    if (cursor == nullptr)
    {
        std::cout << "Node mit Matrikelnummer " << pMatrikelnummer << " nicht gefunden." << std::endl;
        return;
    }

    std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
    cursor->getData().ausgabe();

    if (cursor == front)
    {
        front = cursor->getNext();
        if (front != nullptr)
        {
            front->setPrev(nullptr);
        }
    }
    else if (cursor == back)
    {
        back = cursor->getPrev();
        if (back != nullptr)
        {
            back->setNext(nullptr);
        }
    }
    else
    {
        cursor->getPrev()->setNext(cursor->getNext());
        cursor->getNext()->setPrev(cursor->getPrev());
    }

    delete cursor;
}