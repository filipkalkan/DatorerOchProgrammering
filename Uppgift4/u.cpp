

/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 4b

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
// Programskal till obluppg4 - deluppgift B
//
// Hanterar fallet med 26 bokst�ver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Anv�nd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK
// ist�llet f�r v�rdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP inneh�ller bokstavsfrekvensen i %
// f�r fyra spr�k. TOLK_HJALP[0][0] �r frekvensen av
// bokstaven a f�r engelska.TOLK_HJALP[0][25] �r frekvensen av
// bokstaven z f�r engelska.
// Arrayen �r en GLOBAL KONSTANT och skall allts� ej skickas
// som parameter till den funktion som beh�ver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// Globala variabler �r ej till�tna

//--------------------------------------------------------
// Funktionsdeklarationer:

// Deklarationer av dina egna funktioner
// Anv�nd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
// denna skrevs i A-uppgiften och kan klippas in h�r
// Funktionen berakna_histogram_abs
void berakna_histogram_abs(string text, int nbrOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET);

// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int nbrOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET);


//Funktionen abs_till_rel
void abs_till_rel(int nbrOccurences[ANTAL_BOKSTAVER]);

// Funktionen plotta_histogram
void plotta_histogram_rel(int relOccurences[ANTAL_BOKSTAVER]);

// Funktionen tolka
string tolka(int relOccurences[ANTAL_BOKSTAVER]);

// Funktionen namn_pa_fil
string namn_pa_fil();

// Funktionen inlasning
string inlasning(string fileName);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  const int ASCII_OFFSET = 97;
  int nbrOccurences[ANTAL_BOKSTAVER];
  string fileName, text;
  fileName = namn_pa_fil();
  text = inlasning(fileName);
  berakna_histogram_abs(text, nbrOccurences[ANTAL_BOKSTAVER], ASCII_OFFSET);

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



// -------------------------------------------------------
// Rapport om uppgiften

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
