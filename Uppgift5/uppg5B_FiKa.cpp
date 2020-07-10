

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

Jag har arbetat ungefär 3 timmar med denna uppgift
================================================================================
*/
// Slut på kommentar

//
// Programskal till obluppg5A
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
// H�r kommer klassdeklarationen
class Text{
private:
  string text;
  int length;
  int nbrOccurences[ANTAL_BOKSTAVER];
  double relOccurences[ANTAL_BOKSTAVER];
  const int ASCII_OFFSET = 97;
  int countLetters();
  void absTillRel();
  bool beraknaHistogramAbs();
  string getLanguage(int languageNbr);
public:
  Text();
  void setText(string newText);
  void skrivHistogramAbs();
  void plottaHistogramRel();
  void beraknaHistogram();
  string tolka();
};

string namn_pa_fil();
string inlasning(string fileName);
// -------------------------------------------------------

// Huvudprogram:

int main()
{
 // Deklarera variabler
  string text;
  string fileName;
  bool histOK;
  Text minText;  // Ett objekt av typen Text skapas

  // L�s in en rad med text fr�n tangentbordet

  fileName = namn_pa_fil();
  text = inlasning(fileName);

  // Skicka str�ngen text till objektet minText
  minText.setText(text);

  // Ber�kna och skriv ut histogrammet
  minText.beraknaHistogram( );
  minText.tolka();

  return 0;
}

// -------------------------------------------------------
// H�r skriver du klassimplementationen

Text::Text(){
  text = "";
  length = 0;

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    nbrOccurences[i] = 0;
    relOccurences[i] = 0;
  }
}

//Counts the letters shown in the diagram.
int Text::countLetters(){
  int nbrLetters = 0;

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    nbrLetters += nbrOccurences[i];
  }

  return nbrLetters;
}

void Text::setText(string newText){
  text = newText;
  length = 0;
}

//Calculates the absolute histogram. Returns true if there are valid letters in text.
bool Text::beraknaHistogramAbs(){
  bool empty = true;
  for(int i = 0; i < text.length(); i++){
    if(isalpha(text.at(i))){
      nbrOccurences[int(tolower(text.at(i))) - ASCII_OFFSET]++;
      empty = false;
    }
  }
  length = countLetters();
  std::cout << empty << '\n';
  return !empty;
}

//Prints the absolute table.
void Text::skrivHistogramAbs(){
  cout << "\nResultat för bokstäverna a-z" << "\n\n";
  cout << "Totala antalet bokstäver: " << length << "\n\n";
  cout << "Bokstavsfördelning:" << "\n\n";

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    cout << char(i + ASCII_OFFSET) << " : " << nbrOccurences[i] << '\n';
  }
}

//Converts the absolute data to relative data.
void Text::absTillRel(){
  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    relOccurences[i] = double(nbrOccurences[i]) / double(length);
  }
}

//Prints the relative histogram.
void Text::plottaHistogramRel(){
  cout << "Bokstavsfördelning:" << "\n\n";

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    cout << char(i + ASCII_OFFSET) << " ";
    for(int j = 0; j < floor((relOccurences[i] * 100 * 2) + 0.5); j++){
      cout << '*';
    }
    cout << '\n';
  }
}

//Calculates the absolute histogram, and if there are any valid letters also calculates and plots the relative histogram.
void Text::beraknaHistogram(){
  if(beraknaHistogramAbs()){
    absTillRel();
    plottaHistogramRel();
  }
}

//Checks which language is the most alike the text. Prints its results.
string Text::tolka(){
  double sum = 0;
  int minLanguage = 0;
  double minSum = INT_MAX;

  cout << '\n' << "Resultat för bokstäverna a-z" << "\n\n";
  cout << "Totala antalet bokstäver: " << length << '\n';

  for(int i = 0; i < ANTAL_SPRAK; i++){
    for(int j = 0; j < ANTAL_BOKSTAVER; j++){
      sum += (TOLK_HJALP[i][j] - relOccurences[j] * 100) * (TOLK_HJALP[i][j] - relOccurences[j] * 100);
    }
    if(sum < minSum){
      minSum = sum;
      minLanguage = i;
    }
    cout << getLanguage(i) << " har kvadratsumma = " << sum << '\n';
    sum = 0;
  }

  std::cout << "Det är mest troligt att språket är " << getLanguage(minLanguage) << "\n\n";
}

//Maps the index of a language to a string representing the language.
string Text::getLanguage(int languageNbr){
  string language;
  switch (languageNbr) {
    case 0:
    language = "Engelska";
    break;

    case 1:
    language = "Franska";
    break;

    case 2:
    language = "Svenska";
    break;

    case 3:
    language = "Tyska";
    break;
  }
  return language;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

//Gets the name of the file by prompting the user.
string namn_pa_fil(){
  string fileName;
  cout << "Filnamn: " << '\n';
  getline(cin, fileName);

  if(fileName.rfind(".txt") == string::npos){
    fileName += ".txt";
  }

  return fileName;
}

//Reads the given file and returns it in a string.
string inlasning(string fileName){
  string text = "", row;
  ifstream fin(fileName.c_str());

  if(!fin){
    cout << "Det finns ingen fil med namnet " << fileName << endl;
    exit( EXIT_FAILURE );
  }

  while(getline(fin, row)){
      text += row;
  }

  return text;
}

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

TESTDATA1
Filnamn:
doyle
0
Bokstavsf├Ârdelning:

a ****************
b ***
c *******
d ********
e ************************
f ****
g ***
h ************
i ***************
j
k **
l ********
m *****
n *************
o ***************
p ****
q
r ***********
s *************
t ******************
u ******
v **
w ****
x
y *****
z

Resultat f├Âr bokst├ñverna a-z

Totala antalet bokst├ñver: 12885
Engelska har kvadratsumma = 1.75771
Franska har kvadratsumma = 96.1956
Svenska har kvadratsumma = 73.3371
Tyska har kvadratsumma = 116.072
Det ├ñr mest troligt att spr├Ñket ├ñr Engelska

TESTDATA2
Filnamn:
goethe
0
Bokstavsf├Ârdelning:

a ***********
b ***
c *******
d *********
e *********************************
f ***
g *******
h ***********
i ******************
j
k **
l *******
m ******
n **********************
o ****
p *
q
r ************
s **************
t ***********
u ********
v **
w ****
x
y *
z ***

Resultat f├Âr bokst├ñverna a-z

Totala antalet bokst├ñver: 14027
Engelska har kvadratsumma = 107.856
Franska har kvadratsumma = 85.205
Svenska har kvadratsumma = 160.318
Tyska har kvadratsumma = 1.04313
Det ├ñr mest troligt att spr├Ñket ├ñr Tyska

TESTDATA3
Filnamn:
lagerlof
0
Bokstavsf├Ârdelning:

a ***********************
b **
c ***
d ************
e *******************
f ****
g ********
h *******
i ********
j ***
k *******
l **********
m *******
n ******************
o *********
p ***
q
r ***************
s **************
t ******************
u ***
v ******
w
x
y *
z

Resultat f├Âr bokst├ñverna a-z

Totala antalet bokst├ñver: 12221
Engelska har kvadratsumma = 86.6804
Franska har kvadratsumma = 145.722
Svenska har kvadratsumma = 8.88258
Tyska har kvadratsumma = 170.223
Det ├ñr mest troligt att spr├Ñket ├ñr Svenska

TESTDATA4
Filnamn:
verne
0
Bokstavsf├Ârdelning:

a ****************
b ***
c *******
d ********
e ***********************************
f **
g **
h *
i **************
j *
k
l ***********
m ******
n ***************
o **********
p ******
q **
r **************
s *****************
t **************
u ************
v ***
w
x *
y *
z

Resultat f├Âr bokst├ñverna a-z

Totala antalet bokst├ñver: 11417
Engelska har kvadratsumma = 112.425
Franska har kvadratsumma = 0.885142
Svenska har kvadratsumma = 149.256
Tyska har kvadratsumma = 90.491
Det ├ñr mest troligt att spr├Ñket ├ñr Franska

TESTDATA5
Filnamn:
abc
Det finns ingen fil med namnet abc.txt

================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.

Jag hade mycket problem med att inläsningen av filen inte fungerade när jag exekverade programmet i Bash.
När jag sedan exekverade det via Code Blocks så gick det bra, men icke-engelska bokstäver blev lite konstiga, vilket de inte
brukar bli i Bash.

I övrigt gick det bra.

1. Finns det någon anledning till varför vi beräknar både det absoluta och det relativa histogrammet i samma funktionsanrop?
- En bra anledning är att funktionen som anropar beräkningarna sköter hela den biten. Det följer Single Responsibility Principle vilket
gör koden lättar att utveckla och underhålla.


2. Tänk dig att vi lägger till en rad sist i huvudprogrammet som anropar funktionen setText med en ny text,
 då får vi resultatet att attributet text ändras, men histogrammen fortfarande är desamma och alltså inte hör ihop med den aktuella texten.
 Finns det något sätt att lösa det problemet? Du behöver bara svara med ord, inte programmera något nytt.
 - Man skulle kunna beräkna histogrammen direkt i setText.



3. Skulle man kunna inkludera funktionerna namn_pa_fil och inlasning i klassen?
Skulle det göra någon skillnad på resultatet? Finns det några fördelar med att använda samma funktioner som tidigare?
- Man skulle kunna inkludera dem utan att påverka utfallet, men det vore inte speciellt logiskt att göra det i en klass som beräknar histogram.
Fördelen är att jag vet att funktionerna från tidigare fungerar och jag slipper testa dem igen.

*/
