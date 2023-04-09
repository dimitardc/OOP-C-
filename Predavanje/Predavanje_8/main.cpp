#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
class Publikacija{
private:
	char naziv [100];
protected:
	int godina;
	char* getNaziv(){
		return naziv;
	}
public:
	int getGodina(){
		return godina;
	}
	void pecati(){
		cout << "Publikacija: "<< naziv << " - " << godina << endl;
	}
	Publikacija(char *naziv, int godina){
		strcpy(this->naziv, naziv);
		this->godina = godina;
	}
};

class Kniga: public Publikacija{
private:
	int broj_strani;
public:
	Kniga(char* naziv, int godina, int broj_strani) : Publikacija(naziv,godina){
		this->broj_strani = broj_strani;
	}
	void pecatiGodinaKniga(){
		cout << godina;
	}
	void pecatiNazivKniga(){
		cout<< getNaziv();// protected e i moze da se akcesira vo hierarhijata
	}
	void pecatiBrojStrani(){
		cout<< broj_strani;
	}
};

class Vesnik : protected Publikacija{
private:
	int broj;
public:
	Vesnik(char* naziv, int godina, int broj) : Publikacija(naziv,godina){
		this->broj = broj;
	}
	void pecatiGodinaVesnik(){
		cout << godina;
	}
	void pecatiNazivVesnik(){
		cout<< getNaziv();// protected e i moze da se akcesira vo hierarhijata
	}
	void pecatiBroj(){
		cout << broj;
	}
};

class DnevenVesnik : private Vesnik{
private:
	int den, mesec;
public:
	DnevenVesnik(char* naziv, int den, int mesec ,int godina, int broj) : Vesnik(naziv,godina, broj){
		this->den = den;
		this->mesec = mesec;
	}
	using Vesnik::pecati;
	using Vesnik::pecatiBroj;
};

int main(){
	  Publikacija p("Tabernakul", 1992);
	  p.pecati(); // public - функција
	  Kniga *k = new Kniga("ProsvetnoDelo", 1900, 123);
	  k->pecati(); //pecati e public во Kniga		//dodeluvanjeto e public shto znaci pecati() e publik i moze da se akcesira vo dodelenata klasa
	  k->pecatiGodinaKniga(); // public - функција
	  // cout<<k->getNaziv(); // грешка! protected - функција
	  Vesnik *s = new Vesnik("Tea", 2013 ,30);
	  // s->pecati(); //грешка! protected - функција	//dodeluvanjeto e protected shto znaci ovva f-ja nemoze da se akcesira nadvor od hierarhijata
	  // cout<<s->getGodina(); // грешка! protected - функција
	  s->pecatiNazivVesnik(); // public - функција
	  DnevenVesnik d("Vest",2,3,2014,25);
	  d.pecati(); //public-функција
	  // d.pecatiNazivVesnik(); // грешка! private - функција
	  // cout<<d.getNaziv(); // грешка! private – функција
}
*/


class HotelskaRezervacija{
protected:
	int denovi;
	int broj_lica;
	char ime [50];
	char prezime [50];
public:
	HotelskaRezervacija(char * ime, char * prezime, int denovi, int broj_lica){
		strcpy(this->ime, ime);
		strcpy(this->prezime , prezime);
		this->denovi = denovi;
		this->broj_lica = broj_lica;
	}
	virtual int vratiCena(){
		return denovi*broj_lica*25;
	}
	virtual int vratiCena(int uplata){
		if(uplata >= vratiCena())
			return uplata - vratiCena();
		else{
			cout<<"Za vashata rezervacija treba da naplatite "<<vratiCena()<<endl;
			return -1;
		}
	}
};

class PolupansionskaHotelskaRezervacija : public HotelskaRezervacija{
public:
	PolupansionskaHotelskaRezervacija(char *ime, char* prezime, int denovi, int broj_lica) : HotelskaRezervacija(ime, prezime, denovi, broj_lica){
	}
	int vratiCena(int uplata){
		int cena = HotelskaRezervacija :: vratiCena() + broj_lica *5;
		if(uplata >= cena)
			return uplata - cena;
		else{
			cout<<"Za vashata rezervacija treba da naplatite "<<cena<<endl;
			return -1;
		}
	}
};

class Hotel{
private:
	char ime [50];
	int saldo;
public:
	Hotel(char* ime){
		strcpy(this->ime, ime);
		saldo = 0;
	}
	int uplatiZaRezervacija(HotelskaRezervacija &hr, int uplata){
		int kusur = hr.vratiCena(uplata);
		if(kusur != -1)
			saldo += uplata - kusur;
		return kusur;
	}
};

int main() {
  Hotel h("Bristol");
  HotelskaRezervacija *hr1=new HotelskaRezervacija("Petko","Petkovski",5,5);
  int cena = h.uplatiZaRezervacija(*hr1,1000);
  if (cena!=-1)
	cout<<"Kusur : "<<cena<<endl;
  PolupansionskaHotelskaRezervacija *hr2= new PolupansionskaHotelskaRezervacija("Risto","Ristovski",5,5);
  cena=h.uplatiZaRezervacija(*hr2,1000);
  if (cena!=-1)
	cout<<"Kusur : "<<cena<<endl;
  //покажувач кон основна класа покажува кон објект од изведена
  HotelskaRezervacija *hr3=new PolupansionskaHotelskaRezervacija("Ana","Anovska",4,2);
  cena=h.uplatiZaRezervacija(*hr3,100);
  if (cena!=-1)
	cout<<"Kusur : "<<cena<<endl;
  PolupansionskaHotelskaRezervacija hr4("Tome","Tomovski",5,3);
  cena=h.uplatiZaRezervacija(hr4,1000);
  if (cena!=-1)
	cout<<"Kusur : "<<cena<<endl;
}


/*
class GeomTelo{
protected:
	double visina;
public:
	GeomTelo(){
		visina = 0;
	}
	GeomTelo(int visina){
		this->visina = visina;
	}
	virtual void pecati(){
		cout << visina;
	}
	double getVisina(){
		return visina;
	}
	virtual double getVolumen() = 0; 	//chista  virtuelna f-ja
};

class Cilinder: public GeomTelo{
private:
	double radius;
public:
	Cilinder(double radius, double visina) : GeomTelo(visina){
		this->radius = radius;
	}
	void pecati(){
		cout<<"Cilinder so visina:";
		GeomTelo :: pecati();
		cout<<"i so radius na osnovata" << radius;
	}
	double getVolumen(){
		return M_PI * radius * radius * getVisina();
	}
	double getRadius(){
		return radius;
	}
};

class Konus: public GeomTelo{
private:
	double radius;
public:
	Konus(double radius, double visina) : GeomTelo(visina){
		this->radius = radius;
	}
	void pecati(){
		cout<<"Konus so visina:";
		GeomTelo :: pecati();
		cout<<"i so radius na osnovata" << radius;
	}
	double getVolumen(){
		return M_PI * radius * radius * getVisina() / 3.0;
	}
	double getRadius(){
		return radius;
	}
};

class Kvadar : public GeomTelo{
private:
	double a,b;
public:
	Kvadar(double a,double b, double visina) : GeomTelo(visina){
		this->a = a;
		this->b = b;
	}
	void pecati(){
		cout<<"Kvadar so visina:";
		GeomTelo :: pecati();
		cout<<"i so osnova" << a << " i " << b << endl;
	}
	double getVolumen(){
		return a*b*getVisina();
	}
};

void teloSoNajgolemVolumen(GeomTelo **niza, int n){
	int maxVolumen = 0;
	int maxIndex = 0;
	for(int i = 0; i<n;i++)
		if(niza[i]->getVolumen() > maxVolumen){
			maxVolumen = niza[i]->getVolumen();
			maxIndex = i;
		}
	cout<<"Teloto so najgolem volumen e:";
	niza[maxIndex]->pecati();
}

double getRadius(GeomTelo *g){
	Cilinder* c = dynamic_cast<Cilinder *>(g);
	if(c!=0)
		 return c->getRadius();
	Konus* k = dynamic_cast<Konus *>(g);
	if(k!=0)
		return k->getRadius();
	return -1;
}

int main(){
  GeomTelo** mnozestvoTela; //динамички алоцирано поле од покажувачи кон GeomTelo
  int n;
  cin>>n; //број на тела во множеството
  mnozestvoTela = new GeomTelo*[n]; //се алоцира меморија за полето од покажувачи
  for (int i = 0 ; i < n ; i++){
	  int r,a,b,h,type;
	  cout<<"Kakvo telo: 1-cilinder 2-konus 3-kvadar "<<endl;
	  cin >> type;
	  if (type==1) { //ако корисникот внесува цилиндер
		cin >> r >> h; mnozestvoTela[i]= new Cilinder(r,h); }
	  if (type==2) { //ако корисникот внесува конус
		cin >> r >> h; mnozestvoTela[i]= new Konus(r,h); }
	  if (type==3) { //ако корисникот внесува квадар
		cin >> a >> b >> h; mnozestvoTela[i]= new Kvadar(a,b,h); }
  }
  //барање 1
  teloSoNajgolemVolumen(mnozestvoTela,n);
  //барање 2
  int brojac=0;
  for (int i = 0 ; i < n ; i++)
	if (getRadius(mnozestvoTela[i]) == -1)
		brojac++;
  cout<<"Brojot na tela koi nemaat osnova krug e "<<brojac;
}
*/