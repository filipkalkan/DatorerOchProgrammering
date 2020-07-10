

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
void skriv_histogram_abs(string text, int nbrOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET);


//Funktionen abs_till_rel
void abs_till_rel(int nbrOccurences[ANTAL_BOKSTAVER], double relOccurences[ANTAL_BOKSTAVER]);

// Funktionen plotta_histogram
void plotta_histogram_rel(double relOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET);

// Funktionen tolka
void tolka(int nbrOccurences[ANTAL_BOKSTAVER], double relOccurences[ANTAL_BOKSTAVER]);

// Funktionen namn_pa_fil
string namn_pa_fil();

// Funktionen inlasning
string inlasning(string fileName);

int countLetters(int nbrOccurences[ANTAL_BOKSTAVER]);

string getLanguage(int languageNbr);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  const int ASCII_OFFSET = 97;  //Used for mapping ascii-codes to array indices.
  int nbrOccurences[ANTAL_BOKSTAVER];
  double relOccurences[ANTAL_BOKSTAVER];
  string fileName, text;

  fileName = namn_pa_fil();
  text = inlasning(fileName);
  berakna_histogram_abs(text, nbrOccurences, ASCII_OFFSET);
  abs_till_rel(nbrOccurences, relOccurences);
  tolka(nbrOccurences, relOccurences);
  plotta_histogram_rel(relOccurences, ASCII_OFFSET);

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

//Count total number of letters
int countLetters(int nbrOccurences[ANTAL_BOKSTAVER]){
  int nbrLetters;

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    nbrLetters += nbrOccurences[i];
  }

  return nbrLetters;
}

void skriv_histogram_abs(int nbrOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET){
  int nbrLetters = countLetters(nbrOccurences);

  cout << "\nResultat för bokstäverna a-z" << "\n\n";
  cout << "Totala antalet bokstäver: " << nbrLetters << "\n\n";
  cout << "Bokstavsfördelning:" << "\n\n";

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    cout << char(i + ASCII_OFFSET) << " : " << nbrOccurences[i] << '\n';
  }
}

void abs_till_rel(int nbrOccurences[ANTAL_BOKSTAVER], double relOccurences[ANTAL_BOKSTAVER]){
  int nbrLetters = countLetters(nbrOccurences);

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    relOccurences[i] = double(nbrOccurences[i]) / double(nbrLetters);
  }
}

void plotta_histogram_rel(double relOccurences[ANTAL_BOKSTAVER], int ASCII_OFFSET){
  cout << "Bokstavsfördelning:" << "\n\n";

  for(int i = 0; i < ANTAL_BOKSTAVER; i++){
    cout << char(i + ASCII_OFFSET) << " ";
    for(int j = 0; j < floor((relOccurences[i] * 100 * 2) + 0.5); j++){
      cout << '*';
    }
    cout << '\n';
  }
}

string namn_pa_fil(){
  string fileName;
  cout << "Filnamn: ";
  cin >> fileName;

  if(fileName.rfind(".txt") == string::npos){
    fileName += ".txt";
  }

  return fileName;
}

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

void tolka(int nbrOccurences[ANTAL_BOKSTAVER], double relOccurences[ANTAL_BOKSTAVER]){
  double sum = 0;
  int minLanguage = 0;
  double minSum = INT_MAX;

  cout << '\n' << "Resultat för bokstäverna a-z" << "\n\n";
  cout << "Totala antalet bokstäver: " << countLetters(nbrOccurences) << '\n';

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

string getLanguage(int languageNbr){
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


// -------------------------------------------------------
// Rapport om uppgiften

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

TESTDATA1
Filnamn: doyle

Resultat för bokstäverna a-z

Totala antalet bokstäver: 12885
Engelska har kvadratsumma = 1.75771
Franska har kvadratsumma = 96.1956
Svenska har kvadratsumma = 73.3371
Tyska har kvadratsumma = 116.072
Det är mest troligt att språket är Engelska

Bokstavsfördelning:

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

TESTDATA2
Filnamn: goethe

Resultat för bokstäverna a-z

Totala antalet bokstäver: 14027
Engelska har kvadratsumma = 107.856
Franska har kvadratsumma = 85.205
Svenska har kvadratsumma = 160.318
Tyska har kvadratsumma = 1.04313
Det är mest troligt att språket är Tyska

Bokstavsfördelning:

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

TESTDATA3
Filnamn: lagerlof

Resultat för bokstäverna a-z

Totala antalet bokstäver: 12221
Engelska har kvadratsumma = 86.6804
Franska har kvadratsumma = 145.722
Svenska har kvadratsumma = 8.88258
Tyska har kvadratsumma = 170.223
Det är mest troligt att språket är Svenska

Bokstavsfördelning:

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

TESTDATA4
Filnamn: verne

Resultat för bokstäverna a-z

Totala antalet bokstäver: 11417
Engelska har kvadratsumma = 112.425
Franska har kvadratsumma = 0.885142
Svenska har kvadratsumma = 149.256
Tyska har kvadratsumma = 90.491
Det är mest troligt att språket är Franska

Bokstavsfördelning:

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

TESTDATA5
Filnamn: hejhej
Det finns ingen fil med namnet hejhej.txt


================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.

Det svåraste i uppgiften var att få språkklassificeringen att fungera. Anledningen är att jag från
början hade relOccurences som en int-vektor vilket gjorde att decimalerna jag försökte hantera trunkerades.
Detta resulterade i att jag fick fel kvadratsummor.

1. I lösningsförslagen tipsar vi om att man ska skapa/ladda hem en fil med bara lite innehåll medan man testar sitt program.
Varför, tror du?
- Detta gjorde jag innan jag läste det i övningsförslagen. Eftersom jag skapade datan vet jag hur den ska representeras
i diagrammet och vad förekomsten av bokstäverna är från början. Då kan jag jämföra programmets utfall med vad jag vet.
Datan i ex. doyle.txt är lite svårare att kunna utantill.


2. Texten i filen lagerlof.txt innehåller de svenska bokstäverna å, ä och ö. Som programet fungerar nu räknas inte dessa bokstäver alls.
Hur skulle man gå tillväga för att också inkludera å, ä och ö i histogrammet?
- Du behöver inte ge en program-lösning, men resonera kring hur man skulle kunna göra.
Eftersom dessa tecken inte ligger i anslutning till a-z i ascii tabellen kan man inte använda ascii offset
för att mappa ascii-koden till index i en array. Man får skapa specialfall för å, ä, ö där man kollar om ascii-koden
är större än koden för 'z'. 'Ä' har till exempel ascii-koden 196.

*/
