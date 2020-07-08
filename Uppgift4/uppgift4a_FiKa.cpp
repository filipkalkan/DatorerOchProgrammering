

/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 4

Namn:Filip Kalkan

Personummer: 9802150038

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja/Nej
     Om Nej, beskriv vilka testdata som ger problem:  Ja

Jag har använt kompilator/editor (namn/version) g++ v.7.2.0 / Atom

Jag har använt följande dator (PC/Mac/Annat): PC
      med operativsystemet: Windows

Jag har arbetat ungefär 1 timmar med denna uppgift
================================================================================
*/
// Slut på kommentar
//
// Programskal till obluppg4 - deluppgift A
//
// Hanterar fallet med 26 bokst�ver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

const int ANTAL_BOKSTAVER = 26;  //A-Z


//--------------------------------------------------------
// Funktionsdeklarationer:
// Anv�nd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
void berakna_histogram_abs(string text, int nbr_occurences[ANTAL_BOKSTAVER], int ASCII_OFFSET);

// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int nbr_occurences[ANTAL_BOKSTAVER], int ASCII_OFFSET);
//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // Deklarera variabler
  string text;
  int nbrOccurences [ANTAL_BOKSTAVER];
  const int ASCII_OFFSET = 97;

  cout << "Ge en rad med text: " << '\n';
  getline(cin, text);

  // Anropa funktionen berakna_histogram_abs som ber�knar histogrammet
  // och antalet bokst�ver.
  berakna_histogram_abs(text, nbrOccurences, ASCII_OFFSET);


  // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
  skriv_histogram_abs(nbrOccurences, ASCII_OFFSET);

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
void berakna_histogram_abs(string text, int nbrOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET){
  //Initialize array
  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    nbrOccurences[i] = 0;
  }

  //Count occurrences
  for(int i = 0; i < text.length(); i++){
    if(isalpha(text.at(i))){
      nbrOccurences[int(tolower(text.at(i))) - ASCII_OFFSET]++;
    }
  }
}

void skriv_histogram_abs(int nbrOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET){
  int nbrLetters;

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    nbrLetters += nbrOccurences[i];
  }

  cout << "\nResultat för bokstäverna a-z" << "\n\n";
  cout << "Totala antalet bokstäver: " << nbrLetters << "\n\n";
  cout << "Bokstavsfördelning:" << "\n\n";

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    std::cout << char(i + ASCII_OFFSET) << " : " << nbrOccurences[i] << '\n';
  }
}

// Redovisning av uppgiften i ord.


/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.

*/
