#include "Medium.h"

class Buch : public Medium
{
  public:
    /**
     * @brief Konstruktor fuer die Klasse Buch mit Titel und Autor
     * @param initTitel Titel des Buches
     * @param initAutor Autor des Buches
     */
    Buch(std::string initTitel, std::string initAutor);

    /**
     * @brief Ausgabefunktion
     *
     * Gibt alle Informationen des Buches auf der Konsole aus
     */
    void ausgabe() const;

    /// @brief Ausgabefunktion, fuer die Ueberladung des "<<" Operators
    /// @param o Output stream objekt
    void ausgabe(std::ostream &o) const;

  private:
    /**
     * @brief Autor des Buches
     */
    std::string Autor = "";
};
