

/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 3

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

#include <iostream>
using namespace std;

// Deklarationer av funktionerna
void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &a, int &b);
int berakna(int a, int b, char op);
void invalidInput();
void skrivResultat(int res);
int add(int a, int b);
int mul(int a, int b);
int quadSum(int a, int b);


// Globala variabler, dvs att deklarera
// variabler utanför funktionerna är ej tillåtet

//Härifrån anropas alla metoder som utgör programmet.
int main(){

  int a, b, res;
  char op;

  skrivInfo();

  a = lasEttTal();
  b = lasEttTal();
  op = lasOp();

  ordna(a, b);

  res = berakna(a, b, op);

  skrivResultat(res);

  return 0;
}
// Skriver ut en sammanfattning av programmets syfte och hur det används.
void skrivInfo(){
  cout << "Ange två tal och därefter vilken operation du vill utföra på talen.\nOperationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k)." << '\n';
}

//Promptar användaren om ett tal. Läser in och returnerar detta.
int lasEttTal(){
  int a;
  cout << "Ange ett tal: ";
  cin >> a;
  cout << '\n';
  return a;
}

//Promptar användaren om en operation. Läser in och returnerar detta.
char lasOp(){
  char op;
  cout << "Ange operation (a / m / k)" << '\n';
  cin >> op;
  cout << '\n';
  return op;
}

//Sorterar talen a och b.
void ordna(int &a, int &b){
  int temp;
  if(b < a){
    temp = a;
    a = b;
    b = temp;
  }
}

//Avgör vilken beräkning som ska utföras. Utför denna och returnerar resultatet.
//Säger till om användaren angivit ogiltig operration och returnerar då -1.
int berakna(int a, int b, char op){
  int res;
  if(op == 'a'){
    res = add(a, b);
  } else if(op == 'm'){
    res = mul(a, b);
  } else if(op == 'k'){
    res = quadSum(a, b);
  } else{
    res = -1;
    invalidInput();
  }
  return res;
}

//Skriver ut att operationen är ogiltig.
void invalidInput(){
  cout << "Ej giltig operation!" << '\n';
}

//Skriver ut resultatet.
void skrivResultat(int res) {
  cout << "Resultat: "<< res << '\n';
}

//Adderar a, b och alla mellanliggande tal. Returnerar summan.
int add(int a, int b){
  int sum = 0;
  do{
    sum = sum + a;
    a++;
  } while(a <= b);
  return sum;
}

//Multiplicerar a, b och alla mellanliggande tal. Returnerar produkten.
int mul(int a, int b){
  int prod = 1;
  do{
    prod = prod * a;
    a++;
  } while(a <= b);
  return prod;
}

//Kvadratsummerar a, b och alla mellanliggande tal. Returnerar summan.
int quadSum(int a, int b){
  int sum = 0;
  do{
    sum = sum + a * a;
    a++;
  } while(a <= b);
  return sum;
}


/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

TESTDATA1:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal:3

Ange ett tal:5

Ange operation (a / m / k)
a

Resultat: 12

TESTDATA2:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: 3

Ange ett tal: 5

Ange operation (a / m / k)
m

Resultat: 60

TESTDATA3:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: 3

Ange ett tal: 5

Ange operation (a / m / k)
k

Resultat: 50

TESTDATA4:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: -3

Ange ett tal: 5

Ange operation (a / m / k)
m

Resultat: 0

TESTDATA5:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: 5

Ange ett tal: 3

Ange operation (a / m / k)
a

Resultat: 12

TESTDATA6:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: -3

Ange ett tal: -5

Ange operation (a / m / k)
a

Resultat: -12

TESTDATA7:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: 1

Ange ett tal: 100

Ange operation (a / m / k)
k

Resultat: 338350


TESTDATA8:
Ange två tal och därefter vilken operation du vill utföra på talen.
Operationerna innefattar addition (a), multiplikation (m) och kvadratsummering (k).
Ange ett tal: 1

Ange ett tal: 1000

Ange operation (a / m / k)
m

Resultat: 0


================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.

  Kommentar TESTDATA8:
    Antagligen får vi svaret 0 eftersom en int inte har möjlighet att lagra så stora tal som resultatet faktiskt blir.

  1.Tycker du att det finns någon fördel att använda funktioner för att utföra olika uppgifter i programmet,
   jämfört med hur det såg ut i OU2 där allt hände i huvudprogrammet?
   - Ja. Koden blir mycket mer lättläst. Det blir lättare att hitta och fixa buggar och det blir lättare att köra enhetstester på programmet.

  2. I någon av dina skrivna funktioner använder du dig troligen av referensparametrar. Varför gör man inte det jämt?
    - Koden blir lite svårare att läsa när man använder referensvariabler.

  Uppgiften innebar inga större svårigheter. Allting gick bra och det gick ganska fort att implementera.

*/
