

/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 2

Namn:Filip Kalkan

Personummer: 9802150038

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja/Nej
     Om Nej, beskriv vilka testdata som ger problem:  Ja

Jag har använt kompilator/editor (namn/version) g++ v.7.2.0 / Atom

Jag har använt följande dator (PC/Mac/Annat): PC
      med operativsystemet: Windows

Jag har arbetat ungefär 2 timmar med denna uppgift
================================================================================
*/
// Slut på kommentar


#include <iostream>
using namespace std;

int calcSeconds(int hrs, int minutes, int seconds){
  int totSeconds = 0;
  totSeconds += hrs*60*60;
  totSeconds += minutes*60;
  totSeconds += seconds;
  return totSeconds;
}

int displayResult(int startNbr, int totSeconds, int nbrContestants){
  int hours = (int) (totSeconds / 3600);
  int minutes = ((int) (totSeconds / 60)) % 60;
  int seconds = totSeconds % 60;

  if (nbrContestants != 0){
    cout << "Vinnare är startnr: " << startNbr << '\n';
    cout << "Tim: " << hours << " Min: " << minutes << " Sek: " << seconds << '\n';
    cout << "Antal tävlande: " << nbrContestants << '\n';
  } else {
    cout << "Inga tävlande" << '\n';
  }


  return 0;

}

int main(){
  const int dygn = 24*60*60;
  int minSeconds = 2147483647, minStart = 2147483647;

  int startNbr, startHr, startMinutes, startSec, finishHr, finishMinutes, finishSec, nbrContestants;

  while(startNbr >= 0){
    cout << "Startnummer? ";
    cin >> startNbr;
    cout << "\n";

    if(startNbr > 0){
      nbrContestants++;

      cout << "Starttid? ";
      cin >> startHr >> startMinutes >> startSec;
      cout << "\n";

      cout << "Måltid? ";
      cin >> finishHr >> finishMinutes >> finishSec;
      cout << "\n";

      int startSeconds = calcSeconds(startHr, startMinutes, startSec);
      int finishSeconds = calcSeconds(finishHr, finishMinutes, finishSec);
      int totSeconds;

      if(finishSeconds < startSeconds){
        finishSeconds += dygn;
      }

      totSeconds = finishSeconds - startSeconds;

      if(totSeconds < minSeconds){
        minSeconds = totSeconds;
        minStart = startNbr;
      }
    }

  }

  displayResult(minStart, minSeconds, nbrContestants);
  cout << "Programmet avslutas" << '\n';

  return 0;
}




/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

TESTDATA1:
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? -1
Vinnare är startnr: 33
Tim: 0 Min: 52 Sek: 20
Antal tävlande: 1
Programmet avslutas

TESTDATA2:
Startnummer? 33
Starttid? 00 30 15
Måltid? 19 22 35
Startnummer? -1
Vinnare är startnr: 33
Tim: 18 Min: 52 Sek: 20
Antal tävlande: 1
Programmet avslutas

TESTDATA3:
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? 14
Starttid? 23 35 00
Måltid? 0 12 24
Startnummer? 26
Starttid? 10 11 12
Måltid? 20 21 22
Startnummer? -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas

TESTDATA4:
Startnummer? 14
Starttid? 23 35 00
Måltid? 0 12 24
Startnummer? 26
Starttid? 10 11 12
Måltid? 20 21 22
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas

TESTDATA5:
Startnummer? 26
Starttid? 10 11 12
Måltid? 20 21 22
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? 14
Starttid? 23 35 00
Måltid? 0 12 24
Startnummer? -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas

TESTDATA6:
Startnummer? 17
Starttid? 00 00 50
Måltid? 00 00 30
Startnummer? -1
Vinnare är startnr: 17
Tim: 23 Min: 59 Sek: 40
Antal tävlande: 1
Programmet avslutas

TESTDATA7:
Startnummer? -1
Inga tävlande
Programmet avslutas

TESTDATA8:
Startnummer? 15
Starttid? 10 00 00
Måltid? 11 00 00
Startnummer? 12
Starttid? 11 00 00
Måltid? 10 00 10
Startnummer? -1
Vinnare är startnr: 15
Tim: 1 Min: 0 Sek: 0
Antal tävlande: 2
Programmet avslutas

TESTDATA9:
Startnummer? 8
Starttid? 00 00 10
Måltid? 00 00 20
Startnummer? -1
Vinnare är startnr: 8
Tim: 0 Min: 0 Sek: 10
Antal tävlande: 1
Programmet avslutas




================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.

1. Vad händer i ditt program (testa om du vill) om du rapporterar in två tävlande med olika nummer som har samma totaltid?
Är det den första eller den andra som vinner? Varför?
  - Det är den första som vinner eftersom if-satsen på rad 91 säger att en tävlande måste ha bättre tid än den nuvarande bästa för att bli den bästa.

2. Varför har vi så många testdata? Är det för att det är kul att köra programmet många gånger?
  - För att det finns många olika fall att täcka in i programmet. Utan många testfall kan man inte garantera att det fungerar i alla lägen.

3. Ibland vid programmering börjar man med att skriva sina testdata, sedan gör man programmet. Finns det några fördelar med det?
  - Testdriven programmering är bra eftersom det finns specificerat vad som ska göras på ett väldigt konkret sätt. Det är enkelt att se när man är klar med
  sin del av programmet.

Reflektion:
Det klurigaste med uppgiften var att komma på hur tiderna skulle hanteras när tiderna löpte över dygnsgränserna.
För att lösa detta kollade jag om sluttiden var mindre än starttiden. I så fall lade jag på ett dygn på sluttiden och räknade sedan ut differensen.


*/
