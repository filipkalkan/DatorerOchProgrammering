

/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

InlämningsuppgAift nr 6B

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

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int MAX_KOMPISAR = 30;
const int MAX_TRANSAKTIONER = 30;
const int MAX_PERSONER = 30;

class Transaktion
 {
  private:
   string datum;
   string typ;
   string namn;
   double belopp;
   int ant_kompisar;
   string *kompisar;

  public:
   Transaktion();
   ~Transaktion();
   Transaktion& operator=( const Transaktion& t);
   string haemta_namn();
   double haemta_belopp();
   int haemta_ant_kompisar();
   bool finnsKompis( string namnet );
   bool laesEnTrans( istream &is );
   void skrivEnTrans( ostream &os );
   string* haemta_kompisar();
 };

 class Person
 {
 private:
   string namn;
   double betalat_andras;   // ligger ute med totalt
   double skyldig;          // skyldig totalt

 public:
   Person();
   Person( string n, double b, double s );
   string haemta_namn();
   double haemta_betalat();
   double haemta_skyldig();
   void addDebt(double amount);
   void addCredit(double amount);
   void skrivUt();
};

class PersonLista
 {
 private:
   int antal_pers;
   Person *pers;

 public:
   PersonLista();
   ~PersonLista();
   void laggTillEn( Person pny );
   void skrivUtOchFixa();
   double summaSkyldig();
   double summaBetalat();
   bool finnsPerson(const string& namn);
   void addDebt(string namn, double amount);
   void addCredit(string namn, double amount);
 };

 class TransaktionsLista
{
 private:
   Transaktion *trans;
   int antalTrans;

 public:
   TransaktionsLista();
   ~TransaktionsLista();
   void laesin( istream & is );
   void skrivut( ostream & os );
   void laggTill( Transaktion & t );
   double totalkostnad();
   double liggerUteMed( string namnet );
   double aerSkyldig( string namnet );
   PersonLista FixaPersoner();
 };

 //#############FUNCTION DECLARATIONS#####################################
int menu();
void loadTransactions(TransaktionsLista &transList);
void saveAndExit(TransaktionsLista &transList);
void inputTransaction(TransaktionsLista &transList);
void printAllTransactions(TransaktionsLista &transList);
void calculateTotalCost(TransaktionsLista &transList);
void personDebt(TransaktionsLista &transList);
void personCredit(TransaktionsLista &transList);
void solve(TransaktionsLista &transList);
//##################MAIN##################################################
int main() {
  TransaktionsLista transList;
  cout << "Startar med att läsa från fil." << "\n\n";
  loadTransactions(transList);

  while(true){
    int choice = menu();

    switch (choice) {
      case 0:
        saveAndExit(transList);
      break;
      case 1:
        inputTransaction(transList);
      break;
      case 2:
        printAllTransactions(transList);
      break;
      case 3:
        calculateTotalCost(transList);
      break;
      case 4:
        personDebt(transList);
      break;
      case 5:
        personCredit(transList);
      break;
      case 6:
        solve(transList);
      break;
    }
  }

  return 0;
}
//#############FUNCTION IMPLEMENTATIONS##########################

int menu(){
  int choice = 0;

  cout << "\n\n\nVälj i menyn nedan:" << '\n';
  cout << "0. Avsluta. Alla transaktioner sparas på fil." << '\n';
  cout << "1. Läs in en transaktion från tangentbordet." << '\n';
  cout << "2. Skriv ut information om alla transaktioner." << '\n';
  cout << "3. Beräkna totala kostnaden." << '\n';
  cout << "4. Hur mycket är en viss person skyldig?" << '\n';
  cout << "5. Hur mycket ligger en viss person ute med?" << '\n';
  cout << "6. Lista alla personer mm och FIXA!!!" << '\n';

  cin >> choice;
  return choice;
}

//Loads transactions stored in a txt file.
void loadTransactions(TransaktionsLista &transList){
  string fileName = "resa.txt";
  ifstream fin(fileName.c_str());
  transList.laesin(fin);
  fin.close();
}

//Saves all transactions to out.txt and exits program.
void saveAndExit(TransaktionsLista &transList){
  string fileName = "out.txt";
  ofstream fout(fileName);
  if(!fout.is_open()){
    cout << "Kunde inte skriva till fil." << '\n';
    exit(EXIT_FAILURE);
  } else {
    transList.skrivut(fout);
    fout.flush();
    cout << "Sparat på fil. Stänger program." << '\n';
    exit(EXIT_SUCCESS);
  }
}

//Lets user input a transaction and adds it to a transaction list.
void inputTransaction(TransaktionsLista &transList){
  cout << "Ange transaktion på formen DATUM TYP NAMN SUMMA ANTAL_DELTAGARE DELTAGARE...:" << '\n';
  Transaktion t;
  t.laesEnTrans(cin);
  transList.laggTill(t);
}

//Prints all transactions in the console.
void printAllTransactions(TransaktionsLista &transList){
  transList.skrivut(cout);
}

//Calculates and prints the total cost of all transactions.
void calculateTotalCost(TransaktionsLista &transList){
  cout << "Total kostnad: " << transList.totalkostnad() << '\n';
}

//Lets user input a name and prints total debt for the person.
void personDebt(TransaktionsLista &transList){
  string name;
  cout << "Namn: " << '\n';
  cin >> name;
  cout << name << " är skyldig: " << transList.aerSkyldig(name) << '\n';
}

//Lets user input a name and prints total credit for the person.
void personCredit(TransaktionsLista &transList){
  string name;
  cout << "Namn: " << '\n';
  cin >> name;
  cout << name << " ligger ute med: " << transList.liggerUteMed(name) << '\n';
}

//Prints what all participants should put/get from the pot. Also verifies that expences and
//income are equal.
void solve(TransaktionsLista &transList){
  PersonLista persList = transList.FixaPersoner();
  persList.skrivUtOchFixa();
}

//############CLASS IMPLEMENTATIONS########################

Transaktion::Transaktion(){
  datum = "";
  typ = "";
  namn = "";
  belopp = 0;
  ant_kompisar = 0;
  kompisar = 0;
}

Transaktion::~Transaktion(){
  delete[] kompisar;
}

Transaktion& Transaktion::operator=( const Transaktion& t){
  if (this != &t)
    {
      delete[] kompisar;
      datum = t.datum;
      typ = t.typ;
      namn = t.namn;
      belopp = t.belopp;
      ant_kompisar = t.ant_kompisar;
      kompisar = new string[ant_kompisar];
      for (int i=0; i < ant_kompisar; i++)
	     kompisar[i] = t.kompisar[i];
    }
  return *this;
}

string Transaktion::haemta_namn(){
  return namn;
}

double Transaktion::haemta_belopp(){
  return belopp;
}

int Transaktion::haemta_ant_kompisar(){
  return ant_kompisar;
}

bool Transaktion::finnsKompis( string namnet ){
  for(int i = 0; i < MAX_KOMPISAR; i++){
    if(kompisar[i] == namnet){
      return true;
    }
  }
  return false;
}

bool Transaktion::laesEnTrans( istream &is ){
  is >> datum >> typ >> namn >> belopp >> ant_kompisar;
  kompisar = new string[ant_kompisar];
  for(int i = 0; i < ant_kompisar; i++){
    is >> kompisar[i];
  }
  return !is.eof();
}

void Transaktion::skrivEnTrans( ostream &os ){
  os << datum << " " << typ << " " << namn << " " << belopp << " " << ant_kompisar;
  for(int i = 0; i < ant_kompisar; i++){
    os << " " << kompisar[i];
  }
  os << '\n';
}

string* Transaktion::haemta_kompisar(){
  return kompisar;
}

//#####################TRANSAKTIONSLISTA############################

TransaktionsLista::TransaktionsLista(){
  trans = 0;
  antalTrans = 0;
}

TransaktionsLista::~TransaktionsLista(){
  delete[] trans;
}

void TransaktionsLista::laesin( istream & is ){
  Transaktion t;
  while(t.laesEnTrans(is)){
    laggTill(t);
  }
}

void TransaktionsLista::skrivut( ostream & os ){
  os << "Antal transaktioner: " << antalTrans << '\n';
  for(int i = 0; i < antalTrans; i++){
    trans[i].skrivEnTrans(os);
  }
}

void TransaktionsLista::laggTill( Transaktion & t ){
  Transaktion *temp = new Transaktion[antalTrans + 1];

  for(int i = 0; i < antalTrans; i++){
    temp[i] = trans[i];
  }
  temp[antalTrans] = t;
  delete[] trans;
  trans = temp;

  antalTrans++;
}

double TransaktionsLista::totalkostnad(){
  double sum = 0;
  for(int i = 0; i < antalTrans; i++){
    sum += trans[i].haemta_belopp();
  }
  return sum;
}

double TransaktionsLista::liggerUteMed( string namnet ){
  double sum = 0;
  for(int i = 0; i < antalTrans; i++){
    if(trans[i].haemta_namn() == namnet){
      sum += trans[i].haemta_belopp();
    }
  }
  return sum;
}

double TransaktionsLista::aerSkyldig( string namnet ){
  double sum = 0;
  for(int i = 0; i < antalTrans; i++){
    if(trans[i].finnsKompis(namnet)){
      sum += trans[i].haemta_belopp() / (trans[i].haemta_ant_kompisar());
    }
  }
  return sum;
}

PersonLista TransaktionsLista::FixaPersoner(){
  PersonLista persList;

  //Initialize and update all the person objects which made payments and add to persList.
  for(int i = 0; i < antalTrans; i++){
    Transaktion *currentTrans = &trans[i];
    if(!persList.finnsPerson(currentTrans->haemta_namn())){
      Person pers(currentTrans->haemta_namn(), currentTrans->haemta_belopp(), 0);
      persList.laggTillEn(pers);
    } else {
      persList.addCredit(currentTrans->haemta_namn(), currentTrans->haemta_belopp());
    }
  }

  //Initialize and update remaining person objects and add debts.
  for(int i = 0; i < antalTrans; i++){
    Transaktion *currentTrans = &trans[i];
    string *friends = currentTrans->haemta_kompisar();
    for(int j = 0; j < currentTrans->haemta_ant_kompisar(); j++){
      if(!persList.finnsPerson(friends[j])){
        Person pers(friends[j], 0, currentTrans->haemta_belopp() / (currentTrans->haemta_ant_kompisar()));
        persList.laggTillEn(pers);
      } else {
        persList.addDebt(friends[j], currentTrans->haemta_belopp() / (currentTrans->haemta_ant_kompisar()));
      }
    }
  }
  return persList;
}

//#######################PERSON##########################

Person::Person(){

}

Person::Person( string n, double b, double s ){
    namn = n;
    betalat_andras = b;
    skyldig = s;
}

string Person::haemta_namn(){
  return namn;
}

double Person::haemta_betalat(){
  return betalat_andras;
}

double Person::haemta_skyldig(){
  return skyldig;
}

//Adds a debt to this person.
void Person::addDebt(double amount){
  skyldig += amount;
}

//Adds a credit to this person.
void Person::addCredit(double amount){
  betalat_andras += amount;
}

void Person::skrivUt(){
  cout << namn << " ligger ute med: " << betalat_andras << " och är skyldig: " << skyldig;
  if(betalat_andras > skyldig){
    cout << ". Skall ha " << (betalat_andras - skyldig) << " från potten!" << '\n';
  } else {
    cout << ". Skall lägga " << (skyldig - betalat_andras) << " till potten!" << '\n';
  }
}

//############################PERSONLISTA#####################################

PersonLista::PersonLista(){
  antal_pers = 0;
  pers = 0;
}

PersonLista::~PersonLista(){
  delete[] pers;
}

void PersonLista::laggTillEn( Person pny ){
    Person *temp = new Person[antal_pers + 1];

    for(int i = 0; i < antal_pers; i++){
      temp[i] = pers[i];
    }
    temp[antal_pers] = pny;
    delete[] pers;
    pers = temp;

    antal_pers++;
}

void PersonLista::skrivUtOchFixa(){
  for(int i = 0; i < antal_pers; i++){
    pers[i].skrivUt();
  }

  if(round(summaBetalat()) == round(summaSkyldig())){
    cout << "Utlägg och skyldigheter stämmer överens." << '\n';
  } else {
    cout << "Utlägg och skyldigheter stämmer INTE överens." << '\n';
    std::cout << "Betalat: " << summaBetalat() << '\n';
    std::cout << "Skyldigheter: " << summaSkyldig() << '\n';
  }
}

double PersonLista::summaSkyldig(){
  double sum = 0;
  for(int i = 0; i < antal_pers; i++){
    sum += pers[i].haemta_skyldig();
  }
  return sum;
}

double PersonLista::summaBetalat(){
  double sum = 0;
  for(int i = 0; i < antal_pers; i++){
    sum += pers[i].haemta_betalat();
  }
  return sum;
}

bool PersonLista::finnsPerson(const string& namn){
  for(int i = 0; i < antal_pers; i++){
    if(namn == pers[i].haemta_namn()){
      return true;
    }
  }
  return false;
}

//Adds a debt to person with name namn.
void PersonLista::addDebt(string namn, double amount){
  for(int i = 0; i < antal_pers; i++){
    if(pers[i].haemta_namn() == namn){
      pers[i].addDebt(amount);
      break;
    }
  }
}

//Adds a credit to a person with name namn.
void PersonLista::addCredit(string namn, double amount){
  for(int i = 0; i < antal_pers; i++){
    if(pers[i].haemta_namn() == namn){
      pers[i].addCredit(amount);
      break;
    }
  }
}

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Programkörningarna ser likadana ut som i uppg 6A.

================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.

Tilldelningsoperatorn i Transaktion används i metoden laggTill i TRANSAKTIONSLISTA.
Den behövs för att vi kopierar över objekt från en gammal lista till en större.
Om vi inte hade haft den hade det funnits risk att objekten skrevs över efter en stund
eftersom vi deallokerar minnet som transaktionsobjekten ligger på.

if (this != &t) kontrollerar att this och t inte är samma objekt. I så fall
behöver nämligen inte alla operationer i blockat utföras. Det har ingen effekt då.

Implementeringen av dynamiska arrayer flöt på ganska bra. Det var inga större konstigheter.
Jag anser dock inte att det behövs någon kopieringskonstruktor i mitt program.
Jag kan inte se var det skulle hjälpa.

*/
