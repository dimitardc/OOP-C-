#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;


/*
class Nedviznina{
protected:
	 char *adress;
	 int kvad;
	 int cena;
public:
	Nedviznina(){
		adress = new char[0];
		kvad = 0;
		cena = 0;
	}
	int price(){
		return kvad * cena;
	}
	void pecati(){
		cout<<adress<<", Kvadratura: "<<kvad<<", Cena po Kvadrat: "<<cena<<endl;
	}
	float danokNaImot(){
		return(float)(5*price())/100;
	}
	friend istream& operator>>(istream& in,Nedviznina &n){
		in>>n.adress>>n.kvad>>n.cena;
		return in;
	}
	char * getAdress(){
		return adress;
	}
};


class Vila : public Nedviznina{
private:
	int danokLux;
public:
	Vila(){
		danokLux = 0;
	}
	void pecati(){
		 cout<<adress<<", Kvadratura: "<<kvad<<", Cena po Kvadrat: "<<cena<<", Danok na luksuz: "<<danokLux<<endl;
	}
	float danokNaImot(){
		return price()*(5+danokLux)/100;			//return Nedviznina::price()*(5+danokLux)/100;
	}
	friend istream& operator>>(istream& in, Vila &v){
		in>>v.adress>>v.kvad>>v.cena>>v.danokLux;
		return in;
	}
	char * getAdress(){
		return adress;
	}
};


int main(){
	Nedviznina n;
	Vila v;
	cin>>n;
	cin>>v;
	n.pecati();
	cout<<"Danok za: "<<n.getAdress()<<", e: "<<n.danokNaImot()<<endl;
	v.pecati();
	cout<<"Danok za: "<<v.getAdress()<<", e: "<<v.danokNaImot()<<endl;
	return 0;
}
*/

/*

class Ekipa{
protected:
	char ime[15];
	int wins;
	int loses;
public:
	Ekipa(){
		wins = 0;
		loses = 0;
	}
	Ekipa(const char* ime, int wins, int loses){
		strcpy(this->ime, ime);
		this->wins = wins;
		this->loses = loses;
	}
	void pecati(){
		cout<<" Pobedi: "<<wins<<" Porazi: "<<loses;
	}
	int getPoints(){
		return 3*wins;
	}
};

class FudbalskaEkipa : public Ekipa{
private:
	int brRedCards;
	int brYelCards;
	int draws;
public:
	FudbalskaEkipa(){
		brRedCards = 0;
		brYelCards = 0;
		draws = 0;
	}
	FudbalskaEkipa(const char *ime,int wins,int loses, int brRedCards, int brYelCards, int draws) : Ekipa(ime, wins, loses){
		this->brRedCards = brRedCards;
		this->brYelCards = brYelCards;
		this->draws = draws;
	}
	void pecati(){
		cout<<"Ime: "<<ime;
		Ekipa::pecati();
		cout<<" Nereseni: "<<draws<<" Poeni: "<<getPoints() + draws;
	}
};


int main(){
	char ime[15];
	int pob,por,ck,zk,ner;
	cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
	f1.pecati();
	return 0;
}
*/


/*
class Lekar{
protected:
	int fax;
	char name [10];
	char surname [10];
	double pay;
public:
	Lekar(int fax = 0,const char* name = "",const char* surname = "", double pay = 0.0){
		strcpy(this->name, name);
		strcpy(this->surname, surname);
		this->fax = fax;
		this->pay = pay;
	}
	Lekar(const Lekar &l){
		strcpy(name, l.name);
		strcpy(surname, l.surname);
		fax = l.fax;
		pay = l.pay;
	}
	Lekar& operator=(const Lekar &l){
		strcpy(name, l.name);
		strcpy(surname, l.surname);
		fax = l.fax;
		pay = l.pay;
		return *this;
	}
	void pecati(){
		cout<<fax<<": "<<name<<" "<<surname<<endl;
	}
	double plata(){
		return pay;
	}
};

class MaticenLekar : public Lekar{
private:
	int patients;
	double *kotizacii;
public:
	MaticenLekar(){
		patients = 0;
		kotizacii = new double[0];
	}
	MaticenLekar(Lekar &l, int patients, double* kotizacii) : Lekar(l){
		this->patients = patients;
		this->kotizacii = new double[patients];//YOU DONE FUCKED UP 
		for(int i = 0; i<patients;i++)
			this->kotizacii[i] = kotizacii[i];
	}
	MaticenLekar(const MaticenLekar &m){
		strcpy(name, m.name);
		strcpy(surname, m.surname);
		fax = m.fax;
		pay = m.pay;
		patients = m.patients;
		kotizacii = new double[patients];
		for(int i = 0; i<patients;i++)
			kotizacii[i] = m.kotizacii[i];
	}
	MaticenLekar& operator=(const MaticenLekar &m){
		strcpy(name, m.name);
		strcpy(surname, m.surname);
		fax = m.fax;
		pay = m.pay;
		patients = m.patients;
		delete [] kotizacii;
		kotizacii = new double[patients];
		for(int i = 0; i<patients;i++)
			kotizacii[i] = m.kotizacii[i];
		return *this;
	}
	~MaticenLekar(){
		delete [] kotizacii;
	}
	double aver(){
		double sum = 0;
		for(int i = 0; i<patients ; i++)
			sum+=kotizacii[i];
		return sum/patients;
	}
	void pecati(){
		Lekar::pecati();
		cout << "Prosek na kotizacii: " << aver() << endl;
	}
	double plata(){
		return Lekar::plata() + (aver()*30)/100;
	}
};

int main() {
	int n;
	cin>>n;
	int pacienti;
	double kotizacii[100];
	int faksimil;
	char ime [20];
	char prezime [20];
	double osnovnaPlata;
   
	Lekar * lekari = new Lekar [n];
	MaticenLekar * maticni = new MaticenLekar [n];
   
	for (int i=0;i<n;i++){
		cin >> faksimil >> ime >> prezime >> osnovnaPlata;
		lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);      
	}
   
	for (int i=0;i<n;i++){
		cin >> pacienti;
		for (int j=0;j<pacienti;j++){
			cin >> kotizacii[j];
		}
		maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
	}
   
	int testCase;
	cin>>testCase;
   
	if (testCase==1){
		cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
		for (int i=0;i<n;i++){
			lekari[i].pecati();
			cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
		}
	}
	else {
		cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
		for (int i=0;i<n;i++){
			maticni[i].pecati();
			cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
		}
	}
   
	delete [] lekari;
	delete [] maticni;
   
	return 0;
}
*/