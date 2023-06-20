#include "Medium.h"

class DVD : public Medium
{
  public:
    /**
     * @brief Konstruktor fuer die Klasse DVD mit Titel, ALtersfreigabe und Genre
     * @param initTitel Titel der DVD
     * @param initAltersfreigabe Altersfreigabe der DVD
     * @param initGenre Genre der DVD
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /// @brief Gibt alle Informationen der DVD auf die Konsole aus
    void ausgabe() const;

    /// @brief Ausgabefunktion, fuer die Ueberladung des "<<" Operators
    /// @param o Output stream objekt
    void ausgabe(std::ostream &o) const;

    /*!
     * @brief Ausleihen-Funktion
     *
     * \param Person person: Person die die DVD ausleihen m�chte
     * \param Datum ausleihdatum: Datum an dem die DVD ausgeliehen wird
     *
     * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und die DVD ausgeliehen werden kann
     *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und die DVD nicht ausgeliehen werden
     * kann
     */
    bool ausleihen(Person person, Datum ausleihdatum);

  private:
    /// @brief Altersfreigabe der DVD
    int Altersfreigabe = 0;

    /// @brief Genre der DVD
    std::string Genre = "";
};