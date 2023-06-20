///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	for (int i = 0; i <=wort.length(); i++) {
		wort[i] = schluessel[1][int(wort[i]) - 65];
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	for (int i = 0; i <= wort.length(); i++) {
		wort[i] = schluessel[0][int(wort[i]) - 65];
	}

	return wort;
}

int main()
{
	char Enc_Table[2][26] = {
	{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
	{'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'},
	};

	string Wort;
	cout << "Geben Sie ein Wort mit Grossbuchstaben ein:";
	cin >> Wort;


	cout << "Verschuluesselte Wort:" << verschluesseln(Enc_Table, Wort);
	cout << "\n";
	cout << "Entschuluesselte Wort:" << entschluesseln(Enc_Table, Wort);

	return 0;
}
