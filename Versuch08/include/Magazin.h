#include "Medium.h"
class Magazin : public Medium
{
  public:
    /**
     * @brief Konstruktor fuer die Klasse Magazin mit Titel, Datum der Ausgabe und Sparte
     * @param initTitel Titel der Magazin
     * @param initDatumAusgabe Datum der Ausgabe der Magazin
     * @param initSparte Sparte der Magazin
     */
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /*!
     * @brief Ausgabefunktion
     *
     * Funktion gibt alle Informationen einer Magazin auf der Konsole aus
     */
    void ausgabe() const;

    /// @brief Ausgabefunktion, fuer die Ueberladung des "<<" Operators
    /// @param o Output stream objekt
    void ausgabe(std::ostream &o) const;

    /*!
     * @brief Ausleihen-Funktion
     *
     * \param Person person: Person die die Magazin ausleihen m�chte
     * \param Datum ausleihdatum: Datum an dem die Magazin ausgeliehen wird
     *
     * \return bool: true,  wenn die Ausleihbeschr�nkungen erf�llt sind und die Magazin ausgeliehen werden kann
     *               false, wenn die Ausleihbeschr�nkungen nicht erf�llt sind und die Magazin nicht ausgeliehen werden
     * kann
     */
    bool ausleihen(Person person, Datum ausleihdatum);

  private:
    /// @brief Erscheinungsdatum der Magazin
    Datum ErscheinungsDatum = Datum();

    /// @brief Sparte der Magazin
    std::string Sparte = "";
};