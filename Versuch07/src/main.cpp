/**
 * Praktikum Informatik 1 MMXXIII <BR>
 * Versuch 6 : Dynamische Datenstrukturen
 *
 * @file main.cpp
 *
 * Funktionen fuer die Verwaltung einer Studentenliste:w
 *
 */

#include "Student.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

/**
 * @brief
 * Entfernt das erste Element aus dem Vector
 *
 * @tparam T Typ des Vectors
 * @param vec Vector aus dem das erste Element entfernt werden soll
 */
template <typename T> void pop_front(std::vector<T> &vec)
{
    if (vec.size() > 0)
    {
        vec.erase(vec.begin());
    }
}

/**
 * @brief
 * Gibt alle Elemente des Vectors aus in der Reihenfolge in der sie im Vector stehen
 *
 * @tparam T Typ des Vectors
 * @param vec Vector der ausgegeben werden soll
 */
template <typename T> void ausgabeVorwaerts(std::vector<T> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it;
    }
}

/**
 * @brief
 * Gibt alle Elemente des Vectors aus in der rueckwaerts Reihenfolge
 *
 * @tparam T Typ des Vectors
 * @param vec Vector der ausgegeben werden soll
 */
template <typename T> void ausgabeRueckwaerts(std::vector<T> &vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        std::cout << *it;
    }
}

/**
 * @brief
 * Fuegt ein Element am Beginn des Vectors ein
 *
 * @tparam T Typ des Vectors
 * @param vec Vector in den das Element eingefuegt werden soll
 * @param element Element das eingefuegt werden soll
 */
template <typename T> void push_front(std::vector<T> &vec, T &element)
{
    vec.insert(vec.begin(), element);
}

/**
 * @brief Gibt die Daten eines Studenten aus
 *
 * @param o Ausgabe-Stream
 * @param student Student dessen Daten ausgegeben werden sollen
 * @return std::ostream& Ausgabe-Stream
 */
std::ostream &operator<<(std::ostream &o, const Student &student)
{

    student.ausgabe(o);
    return o;
};

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    unsigned int abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (1) Ja (2) Nein\n";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 1)
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank ausgeben (rueckwaerts)" << std::endl
                  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(5): Datenelement loeschen" << std::endl
                  << "(7): Daten aus einer Datei einlesen" << std::endl
                  << "(8): Daten in eine Datei sichern" << std::endl
                  << "(9): Liste leeren" << std::endl
                  << "(10): Liste sortieren" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
        // Datenelement hinten hinzufuegen
        case 1: {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
            getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            studentenListe.push_back(student);
        }
        break;

        // Datenelement vorne entfernen
        case 2: {
            if (!studentenListe.empty())
            {
                student = studentenListe.front();
                std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                std::cout << student << std::endl;
                pop_front(studentenListe);
            }
            else
            {
                std::cout << "Die Liste ist leer!\n";
                break;
            }
        }
        break;

        // Datenbank vorwaerts ausgeben
        case 3: {
            if (!studentenListe.empty())
            {
                std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                ausgabeVorwaerts(studentenListe);
            }
            else
            {
                std::cout << "Die Liste ist leer!\n\n";
            }
        }
        break;

        // Datenbank rueckwaerts ausgeben
        case 4: {
            if (!studentenListe.empty())
            {
                std::cout << "Inhalt der Liste in rueckwaertiger Reihenfolge:" << std::endl;
                ausgabeRueckwaerts(studentenListe);
            }
            else
            {
                std::cout << "Die Liste ist leer!\n\n";
            }
        }
        break;

        case 5: {

            if (studentenListe.empty())
            {
                std::cout << "Die Liste ist leer!\n\n";
                break;
            }
            else
            {
                unsigned int matNr = 0;

                std::cout << "Bitte geben sie die Matrikelnummer des zu loeschenden Studenten ein: ";
                std::cin >> matNr;

                auto it = std::find(studentenListe.begin(), studentenListe.end(), matNr);

                if (it != studentenListe.end())
                {
                    std::cout << *it << " wurde geloescht!" << std::endl;
                    studentenListe.erase(it);
                }
                else
                {
                    std::cout << "Student mit der Matrikelnummer " << matNr << " nicht gefunden!" << std::endl;
                    break;
                }
            }
        }
        break;

        // Datenelement vorne hinzufuegen
        case 6: {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
            getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            push_front(studentenListe, student);
        }
        break;

        // Daten aus einer Datei einlesen
        case 7: {
            int clear = 0;
            int dupe = 0;

            if (!studentenListe.empty())
            {
                // fragen ob Liste gelöscht werden soll
                std::cout << "Wollen Sie die Studentenliste loeschen? (1) Ja (2) Nein\n";
                std::cin >> clear;

                // liste leeren
                if (clear == 1)
                {
                    studentenListe.clear();
                }
                else if (clear == 2)
                {
                    // fragen ob Duplikate vermieden werden sollen
                    std::cout << "Wollen Sie Duplikate vermeiden? (1) Ja (2) Nein\n";
                    std::cin >> dupe;
                    if (dupe == 1)
                    {
                        std::cout << "Duplikate werden vermieden!\n";
                    }
                    else if (dupe == 2)
                    {
                        std::cout << "Duplikate werden nicht vermieden!\n";
                    }
                    else
                    {
                        std::cout << "Falsche Eingabe!\n";
                        break;
                    }
                }
                else
                {
                    std::cout << "Falsche Eingabe!\n";
                    break;
                }
            }

            std::ifstream eingabe("../studenten.txt");

            if (!eingabe)
            {
                std::cout << "Datei konnte nicht geoeffnet werden!\n";
                break;
            }

            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            while (!eingabe.eof())
            {
                std::cout << "Student wird bearbeitet..." << std::endl;

                eingabe >> matNr;

                // Duplikate vermeiden
                if (dupe == 1)
                {
                    bool existiert = false;

                    if (!studentenListe.empty())
                    {
                        // Liste durchlaufen und pruefen ob Student bereits existiert
                        for (auto &student : studentenListe)
                        {
                            if (student.getMatNr() == matNr)
                            {
                                std::cout << "Student mit der Matrikelnummer " << matNr << " existiert bereits!\n";

                                existiert = true;
                                break;
                            }
                        }
                    }

                    if (existiert)
                    {
                        // zum naechsten Studenten springen
                        std::string dummy;
                        for (int i = 0; i < 4; i++)
                        {
                            std::getline(eingabe, dummy);
                        }
                        continue;
                    }
                }

                eingabe.ignore(1, '\n');
                std::getline(eingabe, name);
                std::getline(eingabe, geburtstag);
                std::getline(eingabe, adresse);

                student = Student(matNr, name, geburtstag, adresse);
                studentenListe.push_back(student);
            }
        }
        break;

        // Daten in eine Datei schreiben
        case 8: {
            std::ofstream ausgabe("../studenten_out.txt");

            if (!ausgabe)
            {
                std::cout << "Datei konnte nicht geoeffnet werden!\n";
                break;
            }
            for (auto &student : studentenListe)
            {
                ausgabe << student.getMatNr() << std::endl;
                ausgabe << student.getName() << std::endl;
                ausgabe << student.getGeburtstag() << std::endl;
                ausgabe << student.getAdresse();

                // sorgt dafur, dass es am Ende keine Leerzeile gibt
                if (&student != &studentenListe.back())
                {
                    ausgabe << std::endl;
                }
            }
            std::cout << "Datei wurde erfolgreich geschrieben!\n";
        }
        break;

        // Datenbank leeren
        case 9: {
            if (studentenListe.empty())
            {
                std::cout << "Die Liste ist bereits leer!\n";
                break;
            }
            else
            {
                unsigned int input = ' ';
                std::cout << "Wollen Sie die Liste wirklich leeren? (1) Ja (2) Nein\n";
                std::cin >> input;

                if (input == 1)
                {
                    studentenListe.clear();
                    std::cout << "Die Liste wurde geleert!\n";
                }
                else if (input == 2)
                {
                    std::cout << "Die Liste wurde nicht geleert!\n";
                }
                else
                {
                    std::cout << "Falsche Eingabe!\n";
                    break;
                }
            }
        }
        break;

        case 10: {
            if (studentenListe.empty())
            {
                std::cout << "Die Liste ist leer!\n";
                break;
            }
            else
            {
                std::sort(studentenListe.begin(), studentenListe.end());
                std::cout << "Die Liste wurde sortiert!\n";
            }
        }
        break;

        case 0: {
            std::cout << "Das Programm wird nun beendet";
        }
        break;

        default: {
            std::cout << "Falsche Eingabe, bitte nochmal";
        }
        break;
        }
    } while (abfrage != 0);

    return 0;
}