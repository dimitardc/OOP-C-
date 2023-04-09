#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
class Transport{
protected:
	char destinacija [100];
	int cena;
	int km;
public:
	Transport(){
	}
	Transport(const char * destinacija, int cena, int km){
		strcpy(this->destinacija, destinacija);
		this->cena = cena;
		this->km = km;
	}
	bool operator <(Transport &t){
		return km  < t.km;
	}
	char  * getDest(){
		return destinacija;
	}
	int getKm(){
		return km;
	}
	virtual int cenaTransport(){
		return cena;
	}
	virtual ~Transport()		{}
};

class AvtomobilTransport : public Transport{
protected:
	bool shofer;
public:
	AvtomobilTransport(){
	}
	AvtomobilTransport(const char * destinacija, int cena, int km, bool shofer) : Transport(destinacija,cena,km){
		this->shofer = shofer;
	}
	int cenaTransport(){
		if(shofer){
			return cena + cena/5;
		}
		else
			return cena;
	}
	~AvtomobilTransport()		{}
};

class KombeTransport : public Transport{
protected:
	int passengers;
public:
	KombeTransport(){
	}
	KombeTransport(const char * destinacija, int cena, int km, int passengers) : Transport(destinacija,cena,km){
		this->passengers = passengers;
	}
	int cenaTransport(){
		return  cena - (200*passengers);
	}
	~KombeTransport()		{}
};

void pecatiPoloshiPonudi(Transport ** niza, int n, Transport &t){
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n-i-1;j++)
			if(niza[j]->getKm() > niza[j+1]->getKm()){
				Transport *temp = niza[j];
				niza[j] = niza[j+1];
				niza[j+1] = temp;
			}
	for(int i = 0;i<n;i++){
		if(niza[i]->cenaTransport() > t.cenaTransport())
			cout<<niza[i]->getDest() << " "<<niza[i]->getKm() << " " <<niza[i]->cenaTransport()<<endl;
	}
}


int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

	cin>>tip>>destinacija>>cena>>rastojanie;
	if (tip==1) {
		cin>>shofer;
		ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

	}
	else {
		cin>>lugje;
		ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
	}


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
*/

/*
class NoCourseException{
private:
	int indeks;
public:
	NoCourseException(int indeks){
		this->indeks = indeks;
	}
	void print(){
		cout<<"Demonstratorot so indeks " <<indeks<<" ne drzi laboratoriski vezbi"<<endl;
	}
};

class Kurs{
private:
	char ime[20];
	int krediti;
public:
	Kurs (char *ime,int krediti){
		strcpy(this->ime,ime);
		this->krediti=krediti;
	}
	Kurs (){
		strcpy(this->ime,"");
		krediti=0;
	}
	bool operator==(const char *ime) const{
		return strcmp(this->ime,ime)==0;
	}
	char const * getIme()const{
		return ime;
	}
	void pecati ()const{cout<<ime<<" "<<krediti<<"ECTS";}
};

class Student{
protected:
	int brojOcenki;
	int *ocenki;
	int indeks;
public:
	Student(int indeks,int *ocenki, int brojOcenki){
		this->indeks=indeks;
		this->brojOcenki=brojOcenki;
		this->ocenki=new int[brojOcenki];
		for (int i=0;i<brojOcenki;i++)
			this->ocenki[i]=ocenki[i];
	}
	Student(const Student &k){
		this->indeks=k.indeks;
		this->brojOcenki=k.brojOcenki;
		this->ocenki=new int[brojOcenki];
		for (int i=0;i<brojOcenki;i++) 
			this->ocenki[i]=k.ocenki[i];
	}
	Student operator=(const Student &k){
		if (&k==this) 
			return *this;
		this->indeks=k.indeks;
		this->brojOcenki=k.brojOcenki;
		delete [] ocenki;
		this->ocenki=new int[brojOcenki];
		for (int i=0;i<k.brojOcenki;i++) 
			this->ocenki[i]=k.ocenki[i];
		return *this;
	}
	virtual ~Student(){
		delete [] ocenki;
	}
	//dopolni ja klasata
	virtual int getBodovi(){
		int preodni = 0;
		for(int i=0; i<brojOcenki; i++) {
			if(ocenki[i]>5)
				preodni++;
		}
		return (1.0*preodni/brojOcenki) * 100;
	}
	virtual void pecati(){
		cout<<indeks;
	}
};

class Predavach{
protected:
	Kurs kursevi[10];
	int brojKursevi;
	char *imeIPrezime;
public:
	Predavach(char *imeIPrezime,Kurs *kursevi,int brojKursevi){
		this->brojKursevi=brojKursevi;
		for (int i=0;i<brojKursevi;i++) 
			this->kursevi[i]=kursevi[i];
		this->imeIPrezime=new char[strlen(imeIPrezime)+1];
		strcpy(this->imeIPrezime,imeIPrezime);
	}
	Predavach(const Predavach &p){
		this->brojKursevi=p.brojKursevi;
		for (int i=0;i<p.brojKursevi;i++) 
			this->kursevi[i]=p.kursevi[i];
		this->imeIPrezime=new char[strlen(p.imeIPrezime)+1];
		strcpy(this->imeIPrezime,p.imeIPrezime);
	}
	Predavach operator=(const Predavach &p){
		if (this==&p) 
			return *this;
		this->brojKursevi=p.brojKursevi;
		for (int i=0;i<p.brojKursevi;i++) this->kursevi[i]=p.kursevi[i];
		this->imeIPrezime=new char[strlen(p.imeIPrezime)+1];
		delete [] imeIPrezime;
		strcpy(this->imeIPrezime,p.imeIPrezime);
		return *this;
	}
	~Predavach(){
		delete [] imeIPrezime;
	}
	int getBrojKursevi()const {
		return brojKursevi;
	}
	char * const getImeIPrezime()const {
		return imeIPrezime;
	}
	Kurs operator[](int i) const {
	   if (i < brojKursevi && i >= 0) 
		   return kursevi[i]; 
	   else 
		   return Kurs();
	}
	void pecati() const  {
		 cout<<imeIPrezime<<" (";
		 for (int i=0;i<brojKursevi;i++){
			 kursevi[i].pecati();
			 if (i<brojKursevi-1) 
				 cout<<", ";  
			else 
				cout<<")";
		}
	}
};


//mesto za vashiot kod

class Demonstrator : public Student, public Predavach{
private:
	int brCasovi;
public:
	Demonstrator(int indeks, int *ocenki, int brojOcenki, char *imeIPrezime, Kurs *kursevi, int brojKursevi, int brCasovi) : Student(indeks,ocenki,brojOcenki), Predavach(imeIPrezime,kursevi,brojKursevi){
		this->brCasovi = brCasovi;
	}
	int getBodovi(){
		if(brCasovi == 0)
			throw NoCourseException(indeks);
		else{
			return Student::getBodovi() + 20*brCasovi/brojKursevi;
		}
	}
	void pecati(){
		Student::pecati();
		cout<<": ";
		Predavach::pecati();
	}
	~Demonstrator()		{}
};

Student& vratiNajdobroRangiran(Student ** studenti, int n ){
	Student *max = studenti[0];
	for(int i = 0;i<n;i++){
		try{
			if(studenti[i]->getBodovi() > max->getBodovi())
				max  = studenti[i];
		}
		catch(NoCourseException &n){
			n.print();
		}
	}
	return *max;
}

void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n){
	for(int i = 0;i<n;i++){
		Demonstrator *d = dynamic_cast<Demonstrator*>(studenti[i]);
		if(d){
			for(int j = 0 ;j < d->getBrojKursevi() ; j++){
				if(strcmp(kurs, (*d)[j].getIme()) == 0){
					d->pecati();
					cout<<endl;
					break;
				}
			}
		}
	}
}



int main(){
	Kurs kursevi[10];
	int indeks,brojKursevi, ocenki[20],ocenka,brojOcenki,tip,brojCasovi,krediti;
	char ime[20],imeIPrezime[50];

	cin>>tip;

	if (tip==1) //test class Demonstrator
	{
		cout<<"-----TEST Demonstrator-----"<<endl;
		cin>>indeks>>brojOcenki;
		for (int i=0;i<brojOcenki;i++){
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		}
		cin>>imeIPrezime>>brojKursevi;
		for (int i=0;i<brojKursevi;i++){
			 cin>>ime>>krediti;
			 kursevi[i]=Kurs(ime,krediti);
		}
		cin>>brojCasovi;

	Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
	cout<<"Objekt od klasata Demonstrator e kreiran";

	} else if (tip==2) //funkcija pecati vo Student
	{
		cout<<"-----TEST pecati-----"<<endl;
		cin>>indeks>>brojOcenki;
		for (int i=0;i<brojOcenki;i++){
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		}

	Student s(indeks,ocenki,brojOcenki);
	s.pecati();

	} else if (tip==3) //funkcija getVkupnaOcenka vo Student
	{
		cout<<"-----TEST getVkupnaOcenka-----"<<endl;
		cin>>indeks>>brojOcenki;
		for (int i=0;i<brojOcenki;i++){
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		}
	Student s(indeks,ocenki,brojOcenki);
	cout<<"Broj na bodovi: "<<s.getBodovi()<<endl;

	} else if (tip==4) //funkcija getVkupnaOcenka vo Demonstrator
	{
	  cout<<"-----TEST getVkupnaOcenka-----"<<endl;
	  cin>>indeks>>brojOcenki;
		for (int i=0;i<brojOcenki;i++){
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		}
		cin>>imeIPrezime>>brojKursevi;
		for (int i=0;i<brojKursevi;i++){
			 cin>>ime>>krediti;
			 kursevi[i]=Kurs(ime,krediti);
		}
		cin>>brojCasovi;

	Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
	cout<<"Broj na bodovi: "<<d.getBodovi()<<endl;

	} else if (tip==5) //funkcija pecati vo Demonstrator
	{
	 cout<<"-----TEST pecati -----"<<endl;
	 cin>>indeks>>brojOcenki;
		for (int i=0;i<brojOcenki;i++){
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		}
		cin>>imeIPrezime>>brojKursevi;
		for (int i=0;i<brojKursevi;i++){
			 cin>>ime>>krediti;
			 kursevi[i]=Kurs(ime,krediti);
		}
		cin>>brojCasovi;

	Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
	d.pecati();

	} else if (tip==6) //site klasi
	{
		cout<<"-----TEST Student i Demonstrator-----"<<endl;
	 cin>>indeks>>brojOcenki;
		for (int i=0;i<brojOcenki;i++){
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		}
		cin>>imeIPrezime>>brojKursevi;
		for (int i=0;i<brojKursevi;i++){
			 cin>>ime>>krediti;
			 kursevi[i]=Kurs(ime,krediti);
		}
		cin>>brojCasovi;

	Student *s=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
	s->pecati();
	cout<<"\nBroj na bodovi: "<<s->getBodovi()<<endl;
	delete s;


	} else if (tip==7) //funkcija vratiNajdobroRangiran
	{
		cout<<"-----TEST vratiNajdobroRangiran-----"<<endl;
	int k, opt;
	cin>>k;
	Student **studenti=new Student*[k];
	for (int j=0;j<k;j++){
	   cin>>opt; //1 Student 2 Demonstrator
	   cin>>indeks>>brojOcenki;
	   for (int i=0;i<brojOcenki;i++)
		  {
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		  }
	   if (opt==1){
			studenti[j]=new Student(indeks,ocenki,brojOcenki);
	   }else{
		   cin>>imeIPrezime>>brojKursevi;
			for (int i=0;i<brojKursevi;i++){
			 cin>>ime>>krediti;
			 kursevi[i]=Kurs(ime,krediti);
			}
			cin>>brojCasovi;
			studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
	   }
	}
	Student& najdobar=vratiNajdobroRangiran(studenti,k);
	cout<<"Maksimalniot broj na bodovi e:"<<najdobar.getBodovi();
	cout<<"\nNajdobro rangiran:";
	najdobar.pecati();
	for (int j=0;j<k;j++) delete studenti[j];
	 delete [] studenti;
	} else if (tip==8) //funkcija pecatiDemonstratoriKurs
	{
	cout<<"-----TEST pecatiDemonstratoriKurs-----"<<endl;
	int k, opt;
	cin>>k;
	Student **studenti=new Student*[k];
	for (int j=0;j<k;j++){
	   cin>>opt; //1 Student 2 Demonstrator
	   cin>>indeks>>brojOcenki;
	   for (int i=0;i<brojOcenki;i++)
		  {
			 cin>>ocenka;
			 ocenki[i]=ocenka;
		  }
	   if (opt==1){
			studenti[j]=new Student(indeks,ocenki,brojOcenki);
	   }else{
	   cin>>imeIPrezime>>brojKursevi;
		for (int i=0;i<brojKursevi;i++)
		  {
			 cin>>ime>>krediti;
			 kursevi[i]=Kurs(ime,krediti);
		  }
		  cin>>brojCasovi;
		  studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
	   }
	}
	char kurs[20];
	cin>>kurs;
	cout<<"Demonstratori na "<<kurs<<" se:"<<endl;
	pecatiDemonstratoriKurs (kurs,studenti,k);
	for (int j=0;j<k;j++) delete studenti[j];
	delete [] studenti;

	}

	return 0;
}
*/

/*
class Vozac{
protected:
	char name[100];
	int age;
	int races;
	bool veteran;
public:
	Vozac(const char* name, int age, int races, bool veteran){
		strcpy(this->name, name);
		this->age = age;
		this->races = races;
		this->veteran = veteran;
	}
	friend ostream& operator<<(ostream &out, const Vozac &v){
		out<<v.name<<endl<<v.age<<endl<<v.races<<endl;
		if(v.veteran)
			out<<"VETERAN"<<endl;
		return out;
	}
	bool operator==(Vozac &v){
		return getPay() == v.getPay();
	}
	virtual float danok() = 0;
	virtual float getPay() = 0;
	virtual ~Vozac()	{};
};

class Avtomobilist: public Vozac{
protected:
	float price;
public:
	Avtomobilist(const char* name, int age, int races, bool veteran, float price) : Vozac(name,age,races,veteran){
		this->price = price;
	}
	float getPay(){
		return price/5;
	}
	float danok(){
		if(races>10)
			return getPay() *0.15;
		else
			return getPay() *0.10;
	}
	~Avtomobilist()		{};
};

class Motociklist: public Vozac{
protected:
	int power;
public:
	Motociklist(const char* name, int age, int races, bool veteran, int power) : Vozac(name,age,races,veteran){
		this->power = power;
	}
	float getPay(){
		return power*20;
	}
	float danok(){
		if(veteran)
			return getPay() * 0.25;
		else
			return getPay() * 0.20;
	}
	~Motociklist()		{};
};

int soIstaZarabotuvachka(Vozac ** niza, int n, Vozac *vx){
	int counter = 0;
	for(int i = 0; i<n;i++){
		if(niza[i]->danok() == vx->danok())
			counter++;
	}
	return counter;
}



int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
	for(int i = 0; i < n; ++i) {
		delete v[i];
	}
	delete [] v;
	delete vx;
	return 0;
}
*/

/*
class OutOfBoundException{
public:
	char error[100];
	OutOfBoundException(const char* error){
		strcpy(this->error, error);
	}
	void print(){
		cout<<error;
	}
};

class Karticka{
protected:
	char smetka[16];
	int pin;
	bool povekjePin;
	const static int P;
public:
	Karticka(const char* smetka,int pin){
		strcpy(this->smetka,smetka);
		this->pin=pin;
		this->povekjePin=false;
	}
	Karticka(const Karticka &k){
		strcpy(smetka, k.smetka);
		pin = k.pin;
		povekjePin = k.povekjePin;
	}
	 // дополниете ја класата
	virtual int tezinaProbivanje(){
		int temp = pin;
		int counter = 0;
		while(temp){
			temp/=10;
			counter++;
		}
		return counter;
	 }
	friend ostream& operator<<(ostream& out, Karticka &k){
		cout<<k.smetka<<": "<<k.tezinaProbivanje()<<endl;
		return out;
	}
	char * getSmetka(){
		return smetka;
	}
	bool getDopolnitelenPin(){
		return povekjePin;
	}
	virtual ~Karticka()		{}
};

const int Karticka::P = 4;

//вметнете го кодот за SpecijalnaKarticka 
class SpecijalnaKarticka: public Karticka{
protected:
	int * pinKodovi;
	int brPinKodovi;
public:
	SpecijalnaKarticka(const char * smetka,int pin) : Karticka(smetka,pin){
		pinKodovi = new int[0];
		brPinKodovi = 0;
		povekjePin = true;
	}
	int tezinaProbivanje(){
		return Karticka::tezinaProbivanje() + brPinKodovi;
	}
	SpecijalnaKarticka& operator+=(int novBroj){
		int *temp = new int[brPinKodovi+1];
		for(int i = 0;i<brPinKodovi;i++)
			temp[i] = pinKodovi[i];
		temp[brPinKodovi] = novBroj;
		brPinKodovi++;
		delete [] pinKodovi;
		pinKodovi = temp;
		return *this;
	}
	int getBrKodovi(){
		 return brPinKodovi;
	}
	~SpecijalnaKarticka()		{}
};



class Banka {
private:
	char naziv[30];
	Karticka *karticki[20];
	int broj;
	static int LIMIT;
public:
	Banka(const char *naziv, Karticka** karticki,int broj ){
		strcpy(this->naziv,naziv);
		for(int i=0;i<broj;i++){
			//ako kartickata ima dopolnitelni pin kodovi
			if (karticki[i]->getDopolnitelenPin()){
				this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
			}
			else 
				this->karticki[i]=new Karticka(*karticki[i]);
		}
		this->broj=broj;
	}
	~Banka(){
		for (int i=0;i<broj;i++) 
			delete karticki[i];
	}
	//да се дополни класата
	static void setLIMIT(int x){
		LIMIT = x;
	}
	void pecatiKarticki(){
		cout<<"Vo bankata "<<naziv<<" moze da se probijat kartickite:"<<endl;
		for(int i = 0;i<broj;i++){
			if(karticki[i]->tezinaProbivanje() <=LIMIT)
				cout<<*karticki[i];//ako ja nema* ke ja printa adresata
		}
	}
	void dodadiDopolnitelenPin(char * smetka, int novPin){
		for(int i = 0; i<broj;i++){
			bool flag = false;
			int index;
			if(strcmp(karticki[i]->getSmetka(), smetka)==0){
				flag = true;
				index = i;
			}
			if(flag){
				SpecijalnaKarticka *sk = dynamic_cast<SpecijalnaKarticka*>(karticki[index]);
				if(sk){
					if(sk->getBrKodovi() >= 4)
						throw OutOfBoundException("Brojot na pin kodovi ne moze da go nadmine dozvolenoto");
					*sk+=novPin;
				}
			}
		}
	}
};

int Banka::LIMIT = 7;


int main(){
	Karticka **niza;
	int n,m,pin;
	char smetka[16];
	bool daliDopolnitelniPin;
	cin>>n;
	niza=new Karticka*[n];
	for (int i=0;i<n;i++){
	   cin>>smetka;
	   cin>>pin;
	   cin>>daliDopolnitelniPin;
		if (!daliDopolnitelniPin)
			niza[i]=new Karticka(smetka,pin);
		else
			niza[i]=new SpecijalnaKarticka(smetka,pin);
	}
	Banka komercijalna("Komercijalna",niza,n);
	for (int i=0;i<n;i++) 
		delete niza[i];
	delete [] niza;
	cin>>m;
	for (int i=0;i<m;i++){
	   cin>>smetka>>pin;
	   try{
		   komercijalna.dodadiDopolnitelenPin(smetka,pin);
	   }
	   catch(OutOfBoundException &o){
		   o.print();
	   }
	}

	Banka::setLIMIT(5);

	komercijalna.pecatiKarticki();

}
*/

/*

class Delo{
protected:
	char name[50];
	int year;
	char origin[50];
public:
	Delo(){
		year = 0;
		strcpy(name ,"");
		strcpy(origin,"");
	}
	Delo(const char* name, int year, const char* origin){
		strcpy(this->name, name);
		strcpy(this->origin, origin);
		this->year =year;
	}
	Delo(const Delo &d){
		strcpy(name, d.name);
		strcpy(origin, d.origin);
		year =d.year;
	}
	char * getIme(){
		return name;
	}
	char * getOrigin(){
		return origin;
	}
	int getAge(){
		return year;
	}
	bool operator==(Delo &d){
		return (strcmp(name, d.name) == 0);
	}
	~Delo()		{}
};

class Pretstava{
protected:
	Delo delo;
	int tickets;
	char data[15];
public:
	Pretstava(Delo delo, int tickets, const char* data){
		this->delo = delo;
		this->tickets = tickets;
		strcpy(this->data, data);
	}
	virtual int cena(){
		if(delo.getAge() >= 1900){
			if(strcmp(delo.getOrigin(),"Italija") == 0)
				return 100+50;
			else if(strcmp(delo.getOrigin(),"Rusija") == 0)
				return 150+50;
			else
				return 80+50;
		}
		else if(delo.getAge() >= 1800 && delo.getAge() <= 1899){
			if(strcmp(delo.getOrigin(),"Italija") == 0)
				return 100+75;
			else if(strcmp(delo.getOrigin(),"Rusija") == 0)
				return 150+75;
			else
				return 80+75;
		}
		else{
			if(strcmp(delo.getOrigin(),"Italija") == 0)
				return 100+100;
			else if(strcmp(delo.getOrigin(),"Rusija") == 0)
				return 150+100;
			else
				return 80+100;
		}
	}
	Delo getDelo(){
		return delo;
	}
	int getTickets(){
		return tickets;
	}
	~Pretstava() 		{}
};

class Balet: public Pretstava{
protected:
	static int additionalPrice;
public:
	Balet(Delo delo, int tickets, const char* data) : Pretstava(delo,tickets,data){
		
	}
	int cena(){
		return Pretstava::cena() +additionalPrice;
	}
	static void setCenaBalet(int x){
		Balet::additionalPrice = x;
	}
};

int Balet::additionalPrice = 150;


class Opera : public Pretstava{
public:
	Opera(Delo delo, int tickets, const char* data) : Pretstava(delo,tickets,data){
		
	}
	int cena(){
		return Pretstava::cena();
	}
};

int prihod(Pretstava **niza, int n){
	int sum = 0;
	for(int i = 0;i<n;i++)
		sum += niza[i]->cena()*niza[i]->getTickets();
	return sum;
}

int brojPretstaviNaDelo(Pretstava **niza, int n, Delo &d){
	int counter = 0;
	for(int i = 0;i<n;i++)
		if(niza[i]->getDelo() == d)
			counter++;
	return counter;
}

//место за вашиот код


//citanje na delo
Delo readDelo(){
	char ime[50];
	int godina;
	char zemja[50];
	cin>>ime>>godina>>zemja;
	return Delo(ime,godina,zemja);
}

//citanje na pretstava
Pretstava* readPretstava(){
	int tip; //0 za Balet , 1 za Opera
	cin>>tip;
	Delo d=readDelo();
	int brojProdadeni;
	char data[15];
	cin>>brojProdadeni>>data;
	if (tip==0)  return new Balet(d,brojProdadeni,data);
	else return new Opera(d,brojProdadeni,data);
}


int main(){
	int test_case;
	cin>>test_case;
	
	switch(test_case){
	case 1:
	//Testiranje na klasite Opera i Balet
	{
		cout<<"======TEST CASE 1======="<<endl;
		Pretstava* p1=readPretstava();
		cout<<p1->getDelo().getIme()<<endl;
		Pretstava* p2=readPretstava();
		cout<<p2->getDelo().getIme()<<endl;
	}break;
		
	case 2:
	//Testiranje na  klasite Opera i Balet so cena
	{
		cout<<"======TEST CASE 2======="<<endl;
		Pretstava* p1=readPretstava();
		cout<<p1->cena()<<endl;
		Pretstava* p2=readPretstava();
		cout<<p2->cena()<<endl;
	}break;
	
	case 3:
	//Testiranje na operator ==
	{
		cout<<"======TEST CASE 3======="<<endl;
		Delo f1=readDelo();
		Delo f2=readDelo();
		Delo f3=readDelo();
		
		if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
		if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
	
	}break;
	
	case 4:
	//testiranje na funkcijata prihod
	{
		cout<<"======TEST CASE 4======="<<endl;
		int n;
		cin>>n;
		Pretstava **pole=new Pretstava*[n];
		for (int i=0;i<n;i++){
			pole[i]=readPretstava();
		
		}
		cout<<prihod(pole,n);
	}break;
	
	case 5:
	//testiranje na prihod so izmena na cena za 3d proekcii
	{
		cout<<"======TEST CASE 5======="<<endl;
		int cenaBalet;
		cin>>cenaBalet;
		Balet::setCenaBalet(cenaBalet);
		int n;
		cin>>n;
		Pretstava **pole=new Pretstava*[n];
		for (int i=0;i<n;i++){
			pole[i]=readPretstava();
		}
		cout<<prihod(pole,n);
		}break;
		
	case 6:
	//testiranje na brojPretstaviNaDelo
	{
		cout<<"======TEST CASE 6======="<<endl;
		int n;
		cin>>n;
		Pretstava **pole=new Pretstava*[n];
		for (int i=0;i<n;i++){
			pole[i]=readPretstava();
		}
		
		Delo f=readDelo();
		cout<<brojPretstaviNaDelo(pole,n,f);
	}break;
	
	};


return 0;
}
*/


class BadInputException{
public:
	char error[100];
	BadInputException(const char* error){
		strcpy(this->error, error);
	}
	void print(){
		cout<<error;
	}
};

class StudentKurs{
protected:
	char ime[30];
	int ocenkaPismeno;
	bool daliUsno;
	static int MAX;
public:
	StudentKurs(char* ime,int ocenkaPismeno){
	   strcpy(this->ime,ime);
	   this->ocenkaPismeno=ocenkaPismeno;
	   this->daliUsno=false;
	 }
	 //дополни ја класата
	 static void setMAX(int x){
		 MAX = x;
	 }
	 friend ostream& operator<<(ostream &out, StudentKurs &sk){
		 out<<sk.ime<<" --- "<<sk.getOcenka()<<endl;
		 return out;
	 }
	 char *getIme(){
		 return ime;
	 }
	 bool getDaliUsno(){
		 return daliUsno;
	 }
	 virtual int getOcenka(){
		 return ocenkaPismeno;
	 }
	virtual ~StudentKurs()		{}
};

int StudentKurs::MAX = 10;


//вметни го кодот за StudentKursUsno 

class StudentKursUsno: public StudentKurs{
protected:
	char* opisnaOcenka;
public:
	StudentKursUsno(char* ime,int ocenkaPismeno) : StudentKurs(ime,ocenkaPismeno){
		this->daliUsno=true;
	}
	int getOcenka(){
		if(strcmp(this->opisnaOcenka,"odlicen")==0 && ocenkaPismeno+2<=MAX)
			return StudentKurs::getOcenka()+2;
		else if(strcmp(this->opisnaOcenka,"dobro")==0 && ocenkaPismeno+1<=MAX)
			return StudentKurs::getOcenka()+1;
		else if(strcmp(this->opisnaOcenka,"losho")==0 && ocenkaPismeno-1<=MAX)
			return StudentKurs::getOcenka()-1;
		else 
			return StudentKurs::getOcenka();
	}
	StudentKursUsno &operator+=(char* novaOcenka){
		int flag = 0, k = 0;
		opisnaOcenka = new char[strlen(novaOcenka)+1];
		for(int i = 0;i<strlen(novaOcenka);i++){
			if(isalpha(novaOcenka[i])){
				opisnaOcenka[k] = novaOcenka[i];
				k++;
			}
			else
				flag = 1;		//when number tedected activate the if below
		}
		if(flag)
			throw BadInputException("Greshna opisna ocenka");
		return *this;
	}
	~StudentKursUsno(){
		delete [] opisnaOcenka;
	}
};

class KursFakultet{
private:
	char naziv[30];
	StudentKurs *studenti[20];
	int broj;
	const static int MINOCENKA = 6;
public:
	KursFakultet(char *naziv, StudentKurs** studenti,int broj ){
		strcpy(this->naziv,naziv);
		for (int i=0;i<broj;i++){
			if (studenti[i]->getDaliUsno()){
				this->studenti[i]=new StudentKursUsno(*dynamic_cast<StudentKursUsno*>(studenti[i]));
			}
			else this->studenti[i]=new StudentKurs(*studenti[i]);
		}
		this->broj=broj;
	}
	~KursFakultet(){
		for (int i=0;i<broj;i++) 
			delete studenti[i];
	}
	//дополни ја класата
	void pecatiStudenti(){
		cout<<"Kursot "<<naziv<<" go polozile:"<<endl;
		for(int i = 0;i<broj;i++)
			if(studenti[i]->getOcenka() >= MINOCENKA)
				cout<<*studenti[i];
	}
	void postaviOpisnaOcenka(char *ime, char* opisnaOcenka){
		for(int i = 0;i<broj;i++)
			if(strcmp(ime, studenti[i]->getIme()) == 0){
				StudentKursUsno *sk =dynamic_cast<StudentKursUsno *>(studenti[i]);
				if(sk)
					*sk+=opisnaOcenka;
			}
	}
};

int main(){
	StudentKurs **niza;
	int n,m,ocenka;
	char ime[30],opisna[10];
	bool daliUsno;
	cin>>n;
	niza=new StudentKurs*[n];
	for (int i=0;i<n;i++){
		cin>>ime;
		cin>>ocenka;
		cin>>daliUsno;
		if (!daliUsno)
			niza[i]=new StudentKurs(ime,ocenka);
		else
			niza[i]=new StudentKursUsno(ime,ocenka);
	}
	KursFakultet programiranje("OOP",niza,n);
	for (int i=0;i<n;i++) delete niza[i];
	delete [] niza;
	cin>>m;
		
	for (int i=0;i<m;i++){
		cin>>ime>>opisna;
		try{
			programiranje.postaviOpisnaOcenka(ime,opisna);
		}
		catch(BadInputException &b){
			b.print();
			cout<<endl;
		}
	}

	StudentKurs::setMAX(9);

	programiranje.pecatiStudenti();

}



/*																						Игри 
class ExistingGame{
public:
	char error[100];
	ExistingGame(const char * error){
		strcpy(this->error, error);
	}
	void message(){
		cout<<error;
	}
};


class Game{
protected:
	char name[100];
	int price;
	bool sold;
public:
	Game(){
	}
	Game(const char* name, int price, bool sold){
		strcpy(this->name, name);
		this->price =price;
		this->sold = sold;
	}
	Game(const Game &g){
		strcpy(this->name, g.name);
		this->price =g.price;
		this->sold = g.sold;
	}
	Game& operator=(const Game &g){
		strcpy(this->name, g.name);
		this->price =g.price;
		this->sold = g.sold;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Game &g){
		out<<"Game: "<<g.name<<", ";
		out<<"regular price: $"<<g.price ;
		if(g.sold)
			out<<", bought on sale";
		return out;
	}
	friend istream& operator>>(istream& in, Game &g){
		in.get();
		in.getline(g.name,100);
		in>>g.price>>g.sold;
		return in;
	}
	bool operator==(Game &g){
		return (strcmp(name, g.name) == 0);
	}
	bool getSold(){
		return sold;
	}
	char* getName(){
		return name;
	}
	virtual int getPrice(){
		if(sold)
			return price*0.30;
		return price;
	}
};



class SubscriptionGame: public Game{
protected:
	float monthlyFee;
	int month,year;
public:
	SubscriptionGame(){
		monthlyFee = 0.0;
		month = 0;
		year = 0;
	}
	SubscriptionGame(const char* name, int price, bool sold, float monthlyFee, int month, int year) : Game(name,price,sold){
		this->monthlyFee = monthlyFee;
		this->month = month;
		this->year = year;
	}
	SubscriptionGame(const SubscriptionGame &s) : Game(s){
		this->monthlyFee = s.monthlyFee;
		this->month = s.month;
		this->year =s.year;
	}
	SubscriptionGame& operator=(const SubscriptionGame &s){
		strcpy(this->name, s.name);
		this->price =s.price;
		this->sold = s.sold;
		this->monthlyFee = s.monthlyFee;
		this->month = s.month;
		this->year =s.year;
		return *this;
	}
	friend ostream& operator<<(ostream& out, SubscriptionGame &s){
		out<<"Game: "<<s.name<<", ";
		out<<"regular price: $"<<s.price ;
		if(s.sold)
			out<<", bought on sale";
		out<<", monthly fee: $"<<s.monthlyFee;
		out<<", purchased: "<<s.month<<"-"<<s.year<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, SubscriptionGame &s){
		in.get();
		in.getline(s.name,100);
		in>>s.price>>s.sold;
		in>>s.monthlyFee >> s.month >> s.year;
		return in;
	}
	int getPrice(){
		float price = Game::getPrice();
		int months = 0;
		if(year<2018)
			months = (12- month) + (2017-year)*12 + 5;
		else
			months = 5- month;
		price+= months*monthlyFee;
		return price;
	}
	int getMonth(){
		return month;
	}
	int getYear(){
		return year;
	}
};


class User{
protected:
	char username[100];
	Game** niza;
	int numGames;
public:
	User(const char* username){
		strcpy(this->username, username);
		niza = new Game*[0];
		numGames = 0;
	}
	User(const User &u){
		strcpy(username, u.username);
		numGames = u.numGames;
		niza = new Game*[numGames];
		for(int i = 0;i<numGames;i++)
			niza[i] = u.niza[i];
	}
	User& operator=(const User &u){
		strcpy(username, u.username);
		numGames = u.numGames;
		delete [] niza;
		niza = new Game*[numGames];
		for(int i = 0;i<numGames;i++)
			niza[i] = u.niza[i];
		return *this;
	}
	User& operator+=(Game &g){
		Game **temp = new Game*[numGames+1];
		for(int i = 0;i<numGames;i++){
			if(*niza[i] == g){
				throw(ExistingGame("The game is already in the collection\n"));
			}
			temp[i] = niza[i];
		}
		SubscriptionGame *sg = dynamic_cast<SubscriptionGame*>(&g);
		if(sg){
			temp[numGames] = new SubscriptionGame(*sg);
		}
		else{
			temp[numGames] = new Game(g);
		}
		numGames++;
		delete [] niza;
		niza = temp;
		return *this;
	}
	int total_spent(){
		int suma = 0;
		for(int i = 0;i<numGames;i++){
			suma+=niza[i]->getPrice();
		}
		return suma;
	}
	friend ostream& operator<<(ostream& out, User &u){
		out<<endl;
		out<<"User: "<<u.username<<endl;
		for(int i = 0;i<u.numGames;i++){
			SubscriptionGame *s = dynamic_cast<SubscriptionGame*>(u.niza[i]);
			if(s){
				out<<"- ";
				out<<*s;
				out<<endl;
			}
			else{
				out<<"- ";
				out<<*u.niza[i];
				out<<endl;
			}
		}
		return out;
	}
};



int main() {
  int test_case_num;

  cin>>test_case_num;

  // for Game
  char game_name[100];
  float game_price;
  bool game_on_sale;

  // for SubscritionGame
  float sub_game_monthly_fee;
  int sub_game_month, sub_game_year;

  // for User
  char username[100];
  int num_user_games;

  if (test_case_num == 1){
	cout<<"Testing class Game and operator<< for Game"<<std::endl;
	cin.get();
	cin.getline(game_name,100);
	//cin.get();
	cin>>game_price>>game_on_sale;

	Game g(game_name, game_price, game_on_sale);

	cout<<g;
  }
  else if (test_case_num == 2){
	cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
	cin.get();
	cin.getline(game_name, 100);

	cin>>game_price>>game_on_sale;

	cin>>sub_game_monthly_fee;
	cin>>sub_game_month>>sub_game_year;

	SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
	cout<<sg;
  }
  else if (test_case_num == 3){
	cout<<"Testing operator>> for Game"<<std::endl;
	Game g;

	cin>>g;

	cout<<g;
  }
  else if (test_case_num == 4){
	cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
	SubscriptionGame sg;

	cin>>sg;

	cout<<sg;
  }
  else if (test_case_num == 5){
	cout<<"Testing class User and operator+= for User"<<std::endl;
	cin.get();
	cin.getline(username,100);
	User u(username);

	int num_user_games;
	int game_type;
	cin >>num_user_games;

	try {

	  for (int i=0; i<num_user_games; ++i){

		cin >> game_type;

		Game *g;
		// 1 - Game, 2 - SubscriptionGame
		if (game_type == 1){
		  cin.get();
		  cin.getline(game_name, 100);

		  cin>>game_price>>game_on_sale;
		  g = new Game(game_name, game_price, game_on_sale);
		}
		else if (game_type == 2){
		  cin.get();
		  cin.getline(game_name, 100);

		  cin>>game_price>>game_on_sale;

		  cin>>sub_game_monthly_fee;
		  cin>>sub_game_month>>sub_game_year;
		  g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
		}

		//cout<<(*g);


		u+=(*g);
	  }
	}catch(ExistingGame &ex){
	  ex.message();
	}

	cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

  }
  else if (test_case_num == 6){
	  cout<<"Testing exception ExistingGame for User"<<std::endl;
	  cin.get();
	  cin.getline(username,100);
	  User u(username);

	  int num_user_games;
	  int game_type;
	  cin >>num_user_games;

	  for (int i=0; i<num_user_games; ++i){

		  cin >> game_type;

		  Game *g;
		  // 1 - Game, 2 - SubscriptionGame
		  if (game_type == 1){
			cin.get();
			cin.getline(game_name, 100);

			cin>>game_price>>game_on_sale;
			g = new Game(game_name, game_price, game_on_sale);
		  }
		  else if (game_type == 2){
			cin.get();
			cin.getline(game_name, 100);

			cin>>game_price>>game_on_sale;

			cin>>sub_game_monthly_fee;
			cin>>sub_game_month>>sub_game_year;
			g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
		  }

		  //cout<<(*g);

		  try {
			u+=(*g);
		  }
		  catch(ExistingGame &ex){
			ex.message();
		  }
		}

	  cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
  }
  else if (test_case_num == 7){
	  cout<<"Testing total_spent method() for User"<<std::endl;
	  cin.get();
	  cin.getline(username,100);
	  User u(username);

	  int num_user_games;
	  int game_type;
	  cin >>num_user_games;

	  for (int i=0; i<num_user_games; ++i){

		  cin >> game_type;

		  Game *g;
		  // 1 - Game, 2 - SubscriptionGame
		  if (game_type == 1){
			cin.get();
			cin.getline(game_name, 100);

			cin>>game_price>>game_on_sale;
			g = new Game(game_name, game_price, game_on_sale);
		  }
		  else if (game_type == 2){
			cin.get();
			cin.getline(game_name, 100);

			cin>>game_price>>game_on_sale;

			cin>>sub_game_monthly_fee;
			cin>>sub_game_month>>sub_game_year;
			g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
		  }

		  //cout<<(*g);


		  u+=(*g);
		}

	  cout<<u;

	  cout<<"Total money spent: $"<<u.total_spent()<<endl;
  }
}
*/

/*																							Концерти 
class Koncert{
private:
	char naziv[20];
	char lokacija [20];
	static float popust;
	float cenaBilet;
public:
	Koncert(const char* naziv, const char* lokacija,float cenaBilet){
		strcpy(this->naziv, naziv);
		strcpy(this->lokacija, lokacija);
		this->cenaBilet = cenaBilet;
	}
	Koncert(const Koncert &k){
		strcpy(this->naziv, k.naziv);
		strcpy(this->lokacija, k.lokacija);
		this->cenaBilet = k.cenaBilet;
		popust = k.popust;
	}
	char* getNaziv(){
		return naziv;
	}
	void setSezonskiPopust(float x){
		this->popust = x;
	}
	virtual float cena(){
		return cenaBilet * (1-popust);
	}
	float getSezonskiPopust(){
		return popust;
	}
};

float Koncert::popust = 0.20;

class ElektronskiKoncert: public Koncert{
protected:
	char* DJname;
	float time;
	bool shift;
public:
	ElektronskiKoncert(const char* naziv, const char* lokacija,float cenaBilet, char* DJname, float time, bool shift) : Koncert(naziv,lokacija,cenaBilet){
		this->DJname = new char[strlen(DJname)+1];
		strcpy(this->DJname, DJname);
		this->time = time;
		this->shift  = shift;
	}
	ElektronskiKoncert(const ElektronskiKoncert &e) : Koncert(e){
		this->DJname = new char[strlen(e.DJname)+1];
		strcpy(this->DJname, e.DJname);
		this->time = e.time;
		this->shift  = e.shift;
	}
	float cena(){
		if(shift){
			if(time > 5 && time<7)
				return Koncert::cena() + 150 - 50;
			else if(time>7)
				return Koncert::cena() + 360 - 50;
			else
				return Koncert::cena() - 50;
		}
		else{
			if(time > 5 && time<7)
				return Koncert::cena() + 150 + 100;
			else if(time>7)
				return Koncert::cena() + 360 + 100;
			else
				return Koncert::cena() + 100;
		}
	}
};

void najskapKoncert(Koncert ** koncerti, int n) {
	float max = 0;
	int index = -1;
	int counterElek=0;
	for(int i = 0;i<n;i++){
		if(koncerti[i]->cena() > max){
			max = koncerti[i]->cena();
			index = i;
		}
		ElektronskiKoncert *ek = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
		if(ek)
			counterElek++;
	}
	cout<<"Najskap koncert: "<<koncerti[index]->getNaziv()<<" "<<koncerti[index]->cena()<<endl;
	cout<<"Elektronski koncerti: "<<counterElek<<" od vkupno "<<n;
}

bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski){
	if(elektronski == true){
		for(int i = 0;i<n;i++){
			ElektronskiKoncert *ek = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
			if(ek){
				if(strcmp(ek->getNaziv(), naziv) == 0){
					cout<<ek->getNaziv()<<" "<<ek->cena()<<endl;
					return true;
				}
			}
		}
		return false;
	}
	else{
		for(int i = 0;i<n;i++){
			if(strcmp(koncerti[i]->getNaziv(), naziv) == 0){
				cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
				return true;
			}
		}
		return false;
	}
}

int main(){

	int tip,n,novaCena;
	char naziv[100], lokacija[100], imeDJ[40];
	bool dnevna;
	float cenaBilet, novPopust;
	float casovi;

		cin>>tip;
		if (tip==1){//Koncert
			cin>>naziv>>lokacija>>cenaBilet;
			Koncert k1(naziv,lokacija,cenaBilet);
			cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
		}
		else if (tip==2){//cena - Koncert
			cin>>naziv>>lokacija>>cenaBilet;
			Koncert k1(naziv,lokacija,cenaBilet);
			cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
		}
		else if (tip==3){//ElektronskiKoncert
			cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
			ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
			cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
		}
		else if (tip==4){//cena - ElektronskiKoncert
			 cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
			 ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
			 cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
		}
		else if (tip==5) {//najskapKoncert

		}
		else if (tip==6) {//prebarajKoncert
			Koncert ** koncerti = new Koncert *[5];
			int n;
			koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
			koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
			koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
			koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
			koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
			char naziv[100];
			najskapKoncert(koncerti,5);
		}
		else if (tip==7){//prebaraj
			  Koncert ** koncerti = new Koncert *[5];
			int n;
			koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
			koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
			koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
			koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
			koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
			char naziv[100];
			bool elektronski;
			cin>>elektronski;
			if(prebarajKoncert(koncerti,5, "Area",elektronski))
				cout<<"Pronajden"<<endl;
			else cout<<"Ne e pronajden"<<endl;

			if(prebarajKoncert(koncerti,5, "Area",!elektronski))
				cout<<"Pronajden"<<endl;
			else cout<<"Ne e pronajden"<<endl;

		}
		else if (tip==8){//smeni cena
			  Koncert ** koncerti = new Koncert *[5];
			int n;
			koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
			koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
			koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
			koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
			koncerti[2] -> setSezonskiPopust(0.9);
			najskapKoncert(koncerti,4);
		}

	return 0;
}
*/

/*																						Фудбалска екипа
class FudbalskaEkipa{
protected:
	char ime[100];
	int golovi[10];
public:
	FudbalskaEkipa(const char* ime, int golovi[]){
		strcpy(this->ime, ime);
		for(int i = 0;i<10;i++)
			this->golovi[i] = golovi[i];
	}
	friend ostream& operator<<(ostream &out, FudbalskaEkipa &f){
		out<<f.getIme()<<endl<<f.ime<<endl<<f.uspeh()<<endl;
		return out;
	}
	virtual int uspeh() = 0;
	virtual char * getIme() = 0;
	bool operator>(FudbalskaEkipa &f){
		return uspeh() > f.uspeh();
	}
	FudbalskaEkipa& operator+=(int newGoal){
		int novi[10];
		for(int i=0; i<9; i++)
			novi[i]=golovi[i+1];
		novi[9]=newGoal;
		for(int i=0; i<10; i++)
			golovi[i]=novi[i];
		return *this;
	}
	virtual ~FudbalskaEkipa(){
	}
};

class Klub: public FudbalskaEkipa{
protected:
	char klubName[100];
	int tituli;
public:
	Klub(const char* ime, int * golovi, const char* klubName,  int tituli) : FudbalskaEkipa(ime,golovi){
		strcpy(this->klubName, klubName);
		this->tituli = tituli;
	}
	friend ostream& operator<<(ostream &out, Klub &k){
		out<<k.klubName<<endl<<k.ime<<endl<<k.golovi<<endl;
		return out;
	}
	int uspeh(){
		int suma = 0;
		for(int i = 0;i<10;i++)
			suma+=golovi[i];
		return suma * 3 + tituli*1000;
	}
	char *getIme(){
		return klubName;
	}
};

class Reprezentacija: public FudbalskaEkipa{
protected:
	char country[100];
	int nastapi;
public:
	Reprezentacija(const char* ime, int *golovi, const char* country,  int nastapi) : FudbalskaEkipa(ime,golovi){
		strcpy(this->country, country);
		this->nastapi = nastapi;
	}
	friend ostream& operator<<(ostream &out, Reprezentacija &r){
		out<<r.country<<endl<<r.ime<<endl<<r.golovi<<endl;
		return out;
	}
	int uspeh(){
		int suma = 0;
		for(int i = 0;i<10;i++)
			suma+=golovi[i];
		return suma*3 + nastapi*50;
	}
	char* getIme(){
		return country;
	}
};

void najdobarTrener(FudbalskaEkipa** niza, int n){
	int max = 0;
	int index = -1;
	for(int i = 0;i<n;i++)
		if(niza[i]->uspeh() > max){
			max = niza[i]->uspeh();
			index = i;
		}
	cout<<*niza[index];
}

int main() {
	int n;
	cin >> n;
	FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
	char coach[100];
	int goals[10];
	char x[100];
	int tg;
	for (int i = 0; i < n; ++i) {
		int type;
		cin >> type;
		cin.getline(coach, 100);
		cin.getline(coach, 100);
		for (int j = 0; j < 10; ++j) {
			cin >> goals[j];
		}
		cin.getline(x, 100);
		cin.getline(x, 100);
		cin >> tg;
		if (type == 0) {
			ekipi[i] = new Klub(coach, goals, x, tg);
		} else if (type == 1) {
			ekipi[i] = new Reprezentacija(coach, goals, x, tg);
		}
	}
	cout << "===== SITE EKIPI =====" << endl;
	for (int i = 0; i < n; ++i) {
		cout << *ekipi[i];
	}
	cout << "===== DODADI GOLOVI =====" << endl;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		cout << "dodavam golovi: " << p << endl;
		*ekipi[i] += p;
	}
	cout << "===== SITE EKIPI =====" << endl;
	for (int i = 0; i < n; ++i) {
		cout << *ekipi[i];
	}
	cout << "===== NAJDOBAR TRENER =====" << endl;
	najdobarTrener(ekipi, n);
	for (int i = 0; i < n; ++i) {
		delete ekipi[i];
	}
	delete [] ekipi;
	return 0;
}
*/


/*																							FINKI-издавачка куќа
class Book{
protected:
	char ISBN [20];
	char naslov [50];
	char avtor [30];
	float price;
public:
	Book(const char* ISBN, const char* naslov, const char* avtor, float price){
		strcpy(this->ISBN, ISBN);
		strcpy(this->naslov, naslov);
		strcpy(this->avtor, avtor);
		this->price = price;
	};
	virtual float bookPrice() = 0;
	virtual float getPrice() = 0;

	bool operator>(Book &b){
		return getPrice() > b.getPrice(); 
	}
	friend ostream& operator<<(ostream& out, Book &b){
		out<<b.ISBN<<": "<<b.naslov<<", "<<b.avtor<<" "<<b.bookPrice()<<endl;
		return out;
	}
	void setISBN(const char* isbn){
		strcpy(ISBN, isbn);
	}
	virtual~Book()		{}
};

class OnlineBook: public Book{
protected:
	char* url;
	int size;
public:
	OnlineBook(const char* ISBN, const char* naslov, const char* avtor, float price,const char* url, int size) : Book(ISBN, naslov, avtor,price){
		this->url = new char[strlen(url)+1];
		strcpy(this->url, url);
		this->size = size;
	};
	float bookPrice(){
		if(size>20)
			return getPrice() * 1.20;
		return getPrice();
	}
	float getPrice(){
		return Book::price;
	}
};

class PrintBook: public Book{
protected:
	float weight;
	bool zaliha;
public:
	PrintBook(const char* ISBN, const char* naslov, const char* avtor, float price,float weight, bool zaliha) : Book(ISBN, naslov, avtor,price){
		this->zaliha = zaliha;
		this->weight = weight;
	};
	float bookPrice(){
		if(weight>0.7)
			return getPrice() *1.15;
		return getPrice();
	}
	float getPrice(){
		return Book::price;
	}
};


void mostExpensiveBook (Book** books, int n){
	int onlinebooks = 0;
	int index = -1;
	int max = 0;
	for(int i  = 0;i<n;i++){
		OnlineBook *ob = dynamic_cast<OnlineBook*>(books[i]);
		if(ob)
			onlinebooks++;
		if(books[i]->getPrice() > max){
			max = books[i]->getPrice();
			index = i;
		}
	}
	cout<<"FINKI-Education"<<endl;
	cout<<"Total number of online books: "<<onlinebooks<<endl;
	cout<<"Total number of print books: "<<n-onlinebooks<<endl;
	cout<<"The most expensive book is: "<<endl;
	cout<<*books[index];
}

int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}
*/

/*																							Научни трудови
class Exception{
public:
	char error[100];
	Exception(const char* error){
		strcpy(this->error,error);
	}
	void message(){
		cout<<error;
	}
};

class Trud{
private:
	char tip;
	int year;
	static int J;
	static int C;
public:
	Trud(){
		
	}
	Trud(char tip, int year){
		this->tip = tip;
		this->year = year;
	}
	Trud(const Trud &t){
		tip = t.tip;
		year = t.year;
	}
	~Trud(){
		
	}
	char getType(){
		return tip;
	}
	void setType(char tip){
		this->tip = tip;
	}
	void setYear(int year){
		this->year = year;
	}
	int getYear(){
		return year;
	}
	static void setC(int c){
		C = c;
	}
	static void setJ(int j){
		J = j;
	}
	static int getC(){
		return C;
	}
	static int getJ(){
		return J;
	}
	friend istream &operator>>(istream &in, Trud &t) {
		in>>t.tip;
		in>>t.year;
		return in;
	}
};

int Trud::C = 1;
int Trud::J = 3;

class Student{
private:
	char ime[30];
	int index;
	int upis;
	int * polozeni;
	int numPassed;
public:
	Student(){
		
	}
	Student(const char* ime, int index, int upis, int *polozeni,  int numPassed){
		strcpy(this->ime, ime);
		this->index = index;
		this->upis = upis;
		this->numPassed = numPassed;
		this->polozeni = new int[numPassed];
		for(int i = 0;i<numPassed;i++)
			this->polozeni[i] = polozeni[i];
	}
	Student(const Student& s){
		strcpy(this->ime, s.ime);
		this->index = s.index;
		this->upis = s.upis;
		this->numPassed = s.numPassed;
		this->polozeni = new int[numPassed];
		for(int i = 0;i<numPassed;i++)
			this->polozeni[i] = s.polozeni[i];
	}
	virtual float rang(){
		float prosek = 0.0;
		for(int i = 0;i<numPassed;i++)
			prosek+=polozeni[i];
		return (float)prosek/numPassed;
	}
	friend ostream& operator<<(ostream& out, Student &s){
		out<<s.index<<" "<<s.ime<<" "<<s.upis<<" "<<s.rang()<<endl;
		return out;
	}
	int getGodinaUpis(){
		return upis;
	}
	int getIndex(){
		return index;
	}
	~Student(){
		delete[] polozeni;
	}
};

class PhDStudent: public Student{
private:
	Trud *niza;
	int numTrud;
public:
	PhDStudent(const char* ime, int index, int upis, int *polozeni,  int numPassed, Trud *niza, int numTrud) : Student(ime,index,upis,polozeni,numPassed){
		this->numTrud = numTrud;
		int j = 0;
		this->niza = new Trud[numTrud];
		for(int i = 0;i<numTrud;i++){
			try{
				if(getGodinaUpis() > niza[i].getYear())
					throw Exception("Ne moze da se vnese dadeniot trud\n");
				this->niza[j] = niza[i];
				j++;
			}
			catch(Exception &e){
				e.message();
			}
		}
		this->numTrud = j;
	}
	PhDStudent& operator=(const PhDStudent &p){
		delete [] niza;
		numTrud = p.numTrud;
		this->niza = new Trud[numTrud];
		for(int i = 0;i<numTrud;i++)
			niza[i] = p.niza[i];
		return *this;
	}
	PhDStudent(const PhDStudent &p) : Student(p){
		this->numTrud = p.numTrud;
		this->niza = new Trud[numTrud];
		for(int i = 0;i<numTrud;i++)
			this->niza[i] = p.niza[i];
	}
	float rang(){
		float total = Student::rang();
		for(int i=0; i<numTrud; i++){
			if(niza[i].getType()=='c' || niza[i].getType()=='C' )
				total+=niza[i].getC();
			else
			  total+=niza[i].getJ();
		}
		return total;
	}
	Student& operator+=(Trud &d){
		if(d.getYear() < getGodinaUpis() )
			throw Exception("Ne moze da se vnese dadeniot trud\n");
		else{																//works without the else aswell
			Trud *temp = new Trud[numTrud +1];
			for(int i = 0;i<numTrud;i++)
				temp[i] = niza[i];
			temp[numTrud] = d;
			numTrud++;
			delete [] niza;
			niza = temp;
		}
		return *this;
	}
	~PhDStudent(){
		delete [] niza;
	};
};


int main(){
	int testCase;
	cin >> testCase;

	int god, indeks, n, god_tr, m, n_tr;
	int izbor; //0 za Student, 1 za PhDStudent 
	char ime[30];
	int oceni[50];
	char tip;
	Trud trud[50];

	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		Student s(ime, indeks, god, oceni, n);
		cout << s;

		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;
		int flag = 1;
		for (int i = 0; i < m; i++) {
			if ((*niza[i]).getIndex() == indeks) {
				PhDStudent* nov = dynamic_cast<PhDStudent*>(niza[i]);
				if (nov) {
					try {
						flag = 0;
						(*nov) += t;
					} 
					catch (Exception &e) {
						e.message();
					}
				}
			}
		}
		if (flag)
			cout << "Ne postoi PhD student so indeks " << indeks << endl;
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 3){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;
		int flag = 1;
		for (int i = 0; i < m; i++) {
			if ((*niza[i]).getIndex() == indeks) {
				PhDStudent* nov = dynamic_cast<PhDStudent*>(niza[i]);
				if (nov) {
					try {
						flag = 0;
						(*nov) += t;
					} 
					catch (Exception &e) {
						e.message();
					}
				}
			}
		}
		if (flag)
			cout << "Ne postoi PhD student so indeks " << indeks << endl;
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2


		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 4){
		cout << "===== Testiranje na isklucoci ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 5){
		cout << "===== Testiranje na isklucoci ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;
		
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot
		
		int flag = 1;
		for (int i = 0; i < m; i++) {
			if ((*niza[i]).getIndex() == indeks) {
				PhDStudent* nov = dynamic_cast<PhDStudent*>(niza[i]);
				if (nov) {
					try {
						flag = 0;
						(*nov) += t;
					} 
					catch (Exception &e) {
						e.message();
					}
				}
			}
		}
		if (flag)
			cout << "Ne postoi PhD student so indeks " << indeks << endl;
		
		
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 6){
		cout << "===== Testiranje na static clenovi ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		int conf, journal;
		cin >> conf;
		cin >> journal;
		
		//postavete gi soodvetnite vrednosti za statickite promenlivi 
		Trud::setC(conf);
		Trud::setJ(journal);
		
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	return 0;
}
*/




