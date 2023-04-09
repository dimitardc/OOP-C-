#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


/*															kompjuterska igra
struct Igrac{
	char korisnickoIme[15];
	int nivo;
	int poeni;
};

struct KompjuterskaIgra{
	char ime[20];
	Igrac lista [30];
	int n;		//igraci
};

void najdobarIgrac(KompjuterskaIgra igri[], int n){
	int popularnost = 0;
	for(int i = 0 ; i < n ; i++)
		if(igri[i].n > igri[popularnost].n)
			popularnost = i;
	KompjuterskaIgra biggest = igri[popularnost];
	int index = 0;
	for(int i = 0 ; i < biggest.n ; i++){
		if(biggest.lista[i].poeni > biggest.lista[index].poeni)
			index = i;
		else if(biggest.lista[i].poeni == biggest.lista[index].poeni)
			if(biggest.lista[i].nivo > biggest.lista[index].nivo)
				index = i;
	}
	cout<<"Najdobar igrac e igracot so korisnicko ime " << biggest.lista[index].korisnickoIme
	<<" koj ja igra igrata "<<biggest.ime;
}

int main() {
	int n;
	cin>>n;
	KompjuterskaIgra poleigri[100];
	for (int i=0; i<n; i++) {
		KompjuterskaIgra nova;
		cin>>nova.ime>>nova.n;
		for (int j=0; j<nova.n; j++) {
			Igrac nov;
			cin>>nov.korisnickoIme>>nov.nivo>>nov.poeni;
			nova.lista[j]=nov;
		}
		poleigri[i]=nova;
	}

	najdobarIgrac(poleigri,n);
	return 0;
}
*/

/*																CD

enum tip{pop = 0, rap, rok};

class Pesna{
private:
	char *name;
	int mins;
	tip type;
public:
	Pesna(){
		name = new char[0];
	}
	Pesna(char *name, int mins, tip type){
		this->name = new char[strlen(name)+1];
		strcpy(this->name , name);
		this->mins = mins;
		this->type = type;    
	}
	Pesna(const Pesna &p){
		this->name = new char[strlen(p.name)+1];
		strcpy(this->name , p.name);
		this->mins = p.mins;
		this->type = p.type;
	}
	Pesna& operator = (const Pesna &p){
		delete [] name;
		this->name = new char[strlen(p.name)+1];
		strcpy(this->name , p.name);
		this->mins = p.mins;
		this->type = p.type;
		return *this;
	}
	~Pesna(){
		delete [] name;
	}
	void pecati(){
		cout << "\"" << name << "\"-" << mins << "min"<<endl;  
	}
	int getMins(){
		return mins;
	}
	tip getType(){
		return type;
	}
	char *getName(){
		return name;
	}
};

class CD{
private:
	Pesna niza[10];
	int brojNaPesni;
	int maxVreme;
public:
	CD(){
	}
	CD(int maxVreme){
		this->maxVreme = maxVreme;
		brojNaPesni = 0;
	}
	CD(const CD &c){
		maxVreme = c.maxVreme;
		brojNaPesni = c.brojNaPesni;
		for(int i = 0 ; i <brojNaPesni ; i++)
			niza[i] = c.niza[i];
	}
	CD& operator =(const CD &c){
		maxVreme = c.maxVreme;
		brojNaPesni = c.brojNaPesni;
		for(int i = 0 ; i <brojNaPesni ; i++)
			niza[i] = c.niza[i];
		return *this;
	}
	void dodadiPesna(Pesna p){
		if(p.getMins() < maxVreme && brojNaPesni < 10){
			maxVreme -= p.getMins();
			niza[brojNaPesni++] = p;
		}
	}
	void pecatiPesniPoTip(tip t){
		for( int i = 0 ; i < brojNaPesni ; i++)
			if(niza[i].getType() == t)
				niza[i].pecati();
	}
	Pesna getPesna(int i){
		return niza[i];
	}
	int getBroj(){
		return brojNaPesni;
	}
};




int main() {
	// se testira zadacata modularno
	int testCase;
	cin >> testCase;
	
	int n, minuti, kojtip;
	char ime[50];
	
	if(testCase == 1) {
		cout << "===== Testiranje na klasata Pesna ======" << endl;
		cin >> ime;
		cin >> minuti;
		cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
		Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
	} else if(testCase == 2) {
		cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
			for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
	else if(testCase == 3) {
		cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
			for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
	}
	else if(testCase == 4) {
		cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
		cin>>kojtip;
		omileno.pecatiPesniPoTip((tip)kojtip);
			
	}
	else if(testCase == 5) {
		cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
		cin>>kojtip;
		omileno.pecatiPesniPoTip((tip)kojtip);
			
	}
	
return 0;
}
*/

/*																	ZHELEZNICKA STANICA
struct Voz{
	char relacija [50];
	int km;
	int patnici;
};

struct ZeleznickaStanica{
	char grad[20];
	Voz niza[30];
	int trainCount;
};


void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){
	int temp = 999999, index_i, index_j;
	for(int i = 0;  i < n ; i++){
		if(strcmp(zs[i].grad , grad)==0){
			for(int j = 0 ; j < zs[i].trainCount ; j++){
				if(zs[i].niza[j].km <= temp){
					index_i = i;
					index_j = j;
					temp = zs[i].niza[j].km;
				}
			}
		}
	}
	cout<<"Najkratka relacija: "<<zs[index_i].niza[index_j].relacija << " (" << zs[index_i].niza[index_j].km <<" km)"<<endl;
}


int main(){
	int n;
	cin>>n; //se cita brojot na zelezlnichki stanici
	ZeleznickaStanica zStanica[100];
	for (int i=0;i<n;i++){
		cin>>zStanica[i].grad >> zStanica[i].trainCount;
		for(int j = 0 ; j < zStanica[i].trainCount ; j++){
			cin >> zStanica[i].niza[j].relacija >>zStanica[i].niza[j].km >> zStanica[i].niza[j].patnici;
		}
	}
	char grad[25];
	cin>>grad;
	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
*/

/*																		PICERIJA
class Pica{
private:
	char name [15];
	int cena;
	char* sostojki;
	int popust;
public:
	Pica(){
		sostojki = new char[0];
		cena = 0;
		popust = 0;
	}
	Pica(char *name, int cena, char* sostojki, int popust){
		strcpy(this->name, name);
		this->cena = cena;
		this->popust =popust;
		this->sostojki = new char[strlen(sostojki)+1];
		strcpy(this->sostojki, sostojki);
	}
	Pica(const Pica &p){
		strcpy(this->name, p.name);
		this->cena = p.cena;
		this->sostojki = new char[strlen(p.sostojki)+1];
		strcpy(this->sostojki, p.sostojki);
		this->popust =p.popust;
	}
	Pica& operator=(const Pica &p){
		delete [] sostojki;
		strcpy(this->name, p.name);
		this->cena = p.cena;
		this->sostojki = new char[strlen(p.sostojki)+1];
		strcpy(this->sostojki, p.sostojki);
		this->popust =p.popust;
		return *this;
	}
	~Pica(){
		delete[] sostojki;
	}
	void pecati(){
		cout << name << " - " << sostojki << ", " << cena;
	}
	bool istiSe(Pica p){
		return (strcmp(sostojki, p.sostojki) == 0);
	}
	int getPopust(){
		return popust;
	}
	int getCena(){
		return cena;
	}
};

class Picerija{
private:
	char ime[15];
	Pica *niza;
	int picaCount;
public:
	Picerija(){
	}
	Picerija(char* ime){
		strcpy(this->ime, ime);
		niza = new Pica[0];
		picaCount = 0;
	}
	Picerija(const Picerija &p){
		strcpy(this->ime, p.ime);
		picaCount = p.picaCount;
		this->niza = new Pica[picaCount];
		for(int i=  0; i < picaCount ; i++)
			niza[i] = p.niza[i];
	}
	Picerija& operator=(const Picerija &p){
		delete [] niza;
		picaCount = p.picaCount;
		strcpy(this->ime, p.ime);
		this->niza = new Pica[picaCount];
		for(int i=  0; i < picaCount ; i++)
			niza[i] = p.niza[i];
		return *this;
	}
	~Picerija(){
		delete [] niza;
	}
	void dodadi(Pica p){
		int flag = 0;
		for(int i = 0 ; i < picaCount ; i++)
			if(niza[i].istiSe(p))
				flag = 1;
		if(!flag){
			Pica *temp = new Pica[picaCount+1];
			for(int i = 0 ; i< picaCount ; i++)						//u fucked here last time remember this
				temp[i] = niza[i];
			temp[picaCount] = p;
			picaCount++;
			delete [] niza;
			niza = temp;
		}
	}
	void piciNaPromocija(){
		for(int i = 0 ; i < picaCount ; i++)
			if(niza[i].getPopust() != 0){
				niza[i].pecati();
				cout << " " << niza[i].getCena() * (1 - niza[i].getPopust() / 100.0) << endl;
			}
		}
	void setIme(char *ime){
		strcpy(this->ime, ime);
	}
	char* getIme(){
		return ime;
	}
};


int main() {

	int n;
	char ime[15];
	cin >> ime;
	cin >> n;

	Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100];
		cin.get();
		cin.getline(imp, 100);
		int cena;
		cin >> cena;
		char sostojki[100];
		cin.get();
		cin.getline(sostojki, 100);
		int popust;
		cin >> popust;
		Pica p(imp, cena, sostojki, popust);
		p1.dodadi(p);
	}
	
	Picerija p2 = p1;
	cin >> ime;
	p2.setIme(ime);
	char imp[100];
	cin.get();
	cin.getline(imp, 100);
	int cena;
	cin >> cena;
	char sostojki[100];
	cin.get();
	cin.getline(sostojki, 100);
	int popust;
	cin >> popust;
	Pica p(imp, cena, sostojki, popust);
	p2.dodadi(p);
	cout << p1.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p1.piciNaPromocija();
	cout << p2.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p2.piciNaPromocija();
	return 0;
}
*/

/*																					Marathon
class Ucesnik{
private:
	char * ime;
	bool pol;
	int vozrast;
public:
	Ucesnik(){
		ime = new char[0];
	}
	Ucesnik(char *ime, bool pol, int vozrast){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		this->pol = pol;
		this->vozrast = vozrast;
	}
	Ucesnik(const Ucesnik &u){
		ime = new char[strlen(u.ime)+1];
		strcpy(ime, u.ime);
		pol = u.pol;
		vozrast = u.vozrast;
	}
	Ucesnik& operator=(const Ucesnik &u){
		delete [] ime;
		ime = new char[strlen(u.ime)+1];
		strcpy(ime, u.ime);
		pol = u.pol;
		vozrast = u.vozrast;
		return *this;
	}
	bool operator>(const Ucesnik &u){
		return vozrast > u.vozrast;
	}
	friend ostream& operator<<(ostream& out, const Ucesnik &u){
		out<<u.ime<<" ";
		if(u.pol == 0)
			out<<"zhenski ";
		else
			out<<"mashki ";
		out<<u.vozrast<<endl;
		return out;
	}
	int getVozrast(){
		return vozrast;
	}
};

class Marathon{
private:
	char lokacija[100];
	Ucesnik* niza;
	int brojUcesnici;
public:
	Marathon()		{}
	Marathon(char *lokacija){
		strcpy(this->lokacija, lokacija);
		brojUcesnici = 0;
		niza = new Ucesnik[0];
	}
	Marathon(const Marathon &m){
		strcpy(this->lokacija, m.lokacija);
		brojUcesnici = m.brojUcesnici;
		niza = new Ucesnik[brojUcesnici];
		for(int i = 0 ; i<brojUcesnici;i++)
			niza[i] = m.niza[i];
	}
	Marathon& operator=(const Marathon &m){
		strcpy(this->lokacija, m.lokacija);
		brojUcesnici = m.brojUcesnici;
		delete [] niza;
		niza = new Ucesnik[brojUcesnici];
		for(int i = 0 ; i<brojUcesnici;i++)
			niza[i] = m.niza[i];
		return *this;
	}
	Marathon& operator+=(const Ucesnik &u){
		Ucesnik *temp = new Ucesnik[brojUcesnici+1];
		for(int i=0;i<brojUcesnici;i++)
			temp[i] = niza[i];
		temp[brojUcesnici] = u;
		brojUcesnici++;
		delete [] niza;
		niza = temp;
		return *this;
	}
	float prosecnoVozrast(){
		float sum = 0;
		for(int i=0;i<brojUcesnici;i++)
			sum+=niza[i].getVozrast();
		return 1.0*sum/brojUcesnici;
	}
	void pecatiPomladi(Ucesnik &u){
		for(int i=0;i<brojUcesnici;i++)
			if(niza[i].getVozrast() < u.getVozrast())
				cout<<niza[i];
	}
};


int main() {
	char ime[100];
	bool maski;
	int vozrast, n;
	cin >> n;
	char lokacija[100];
	cin >> lokacija;
	Marathon m(lokacija);
	Ucesnik **u = new Ucesnik*[n];
	for(int i = 0; i < n; ++i) {
		cin >> ime >> maski >> vozrast;
		u[i] = new Ucesnik(ime, maski, vozrast);
		m += *u[i];
	}
	m.pecatiPomladi(*u[n - 1]);
	cout << m.prosecnoVozrast() << endl;
	for(int i = 0; i < n; ++i) {
		delete u[i];
	}
	delete [] u;
	return 0;
}
*/


/*																					Repozitorium
enum tip{LINUS, UNIX, WINDOWS};

class OperativenSistem{
private:
	char* ime;
	float verzija;
	tip type;
	float golemina;
public:
	OperativenSistem(){
		ime = new char[0];
		verzija = 0.0;
		golemina = 0.0;
		type = (tip) 0;
	}
	OperativenSistem(char *ime, float verzija, tip type, float golemina){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		this->verzija = verzija;
		this->type = type;
		this->golemina = golemina;
	}
	OperativenSistem(const OperativenSistem &os){
		this->ime = new char[strlen(os.ime)+1];
		strcpy(this->ime, os.ime);
		this->verzija = os.verzija;
		this->type = os.type;
		this->golemina = os.golemina;
	}
	OperativenSistem& operator=(const OperativenSistem &os){
		delete [] ime;
		this->ime = new char[strlen(os.ime)+1];
		strcpy(this->ime, os.ime);
		this->verzija = os.verzija;
		this->type = os.type;
		this->golemina = os.golemina;
		return *this;
	}
	~OperativenSistem(){
		delete [] ime;
	}
	void pecati(){
		cout<<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<type<<" Golemina:"<<golemina<<"GB"<<endl;
	}
	bool ednakviSe(const OperativenSistem &os){
		if((strcmp(ime, os.ime) == 0) && verzija == os.verzija && golemina == os.golemina && type == os.type)
			return true;
		else
			return false;
	}
	int sporediVerzija(const OperativenSistem &os){
		if(verzija == os.verzija)
			return 0;
		else if(os.verzija > verzija)
			return -1;
		else
			return 1;
	}
	bool istaFamilija(const OperativenSistem &sporedba){
		if((strcmp(sporedba.ime, ime) == 0) && sporedba.type == type)
			return true;
		else
			return false;
	}
	float getVerzija(){
		return verzija;
	}
};

class Repozitorium{
private:
	char ime[20];
	OperativenSistem * niza;
	int sistemCount;
public:
	Repozitorium(){
		niza = new OperativenSistem[0];
		sistemCount = 0;
	}
	Repozitorium(const char *ime){
		strcpy(this->ime, ime);
		niza =new OperativenSistem[0];
		sistemCount = 0;
	}
	Repozitorium(const Repozitorium &r){
		strcpy(this->ime, r.ime);
		sistemCount = r.sistemCount;
		for(int i=0 ; i<sistemCount ; i++)
			niza[i] = r.niza[i];
	}
	Repozitorium& operator=(const Repozitorium &r){
		strcpy(this->ime, r.ime);
		sistemCount = r.sistemCount;
		delete [] niza;
		for(int i=0 ; i<sistemCount ; i++)
			niza[i] = r.niza[i];
		return *this;
	}
	~Repozitorium(){
		delete [] niza;
	}
	void pecatiOperativniSistemi(){
		cout<<"Repozitorium: "<<ime<<endl;
		for(int i=0 ; i<sistemCount ; i++)
			niza[i].pecati();
	}
	void izbrishi(const OperativenSistem &operativenSistem){
		int flag = 0;
		int index = 0;
		for(int i=0 ; i<sistemCount ; i++)
			if(niza[i].ednakviSe(operativenSistem) == true){
				flag = 1;
				index = i;
			}
		if(flag){
			OperativenSistem *temp = new OperativenSistem[sistemCount-1];
			for(int i=0 ; i<sistemCount ; i++)
				if(index != i)
					temp[i] = niza[i];
			sistemCount--;
			delete [] niza;
			niza = temp;
		}
	}
	void dodadi(const OperativenSistem &nov){
		int flag = 0;
		for(int i=0 ; i<sistemCount ; i++){
			if(niza[i].istaFamilija(nov) == true && niza[i].sporediVerzija(nov) == -1){
				niza[i] = nov;
				flag = 1;
			}
		}
		if(flag == 0){
			OperativenSistem *temp = new OperativenSistem[sistemCount+1];
			for(int i = 0; i<sistemCount ; i++)
				temp[i] = niza[i];
			temp[sistemCount++] = nov;
			delete [] niza;
			niza = temp;
		}
	}
};

int main() {
	char repoName[20];
	cin>>repoName;
	Repozitorium repozitorium=Repozitorium(repoName);
	int brojOperativniSistemi = 0;
	cin>>brojOperativniSistemi;
	char ime[20];
	float verzija;
	int kojtip;
	float golemina;
	for (int i = 0; i<brojOperativniSistemi; i++){
		cin>>ime;
		cin>>verzija;
		cin>>kojtip;
		cin>>golemina;
		OperativenSistem os = OperativenSistem(ime, verzija, (tip)kojtip, golemina);
		repozitorium.dodadi(os);
	}
	repozitorium.pecatiOperativniSistemi();
	cin>>ime;
	cin>>verzija;
	cin>>kojtip;
	cin>>golemina;
	OperativenSistem os = OperativenSistem(ime, verzija, (tip)kojtip, golemina);
	cout<<"=====Brishenje na operativen sistem====="<<endl;
	repozitorium.izbrishi(os);
	repozitorium.pecatiOperativniSistemi();
	return 0;
}
*/

/*																									Sladoled
class IceCream{
private:
	char *ime;
	char sostav[100];
	float cena;
	int popust;
public:
	IceCream(){
		ime = new char[0];
	}
	IceCream(const char *ime,const char *sostav , float cena){
		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);
		strcpy(this->sostav , sostav);
		this->cena = cena;
		popust = 0;
	}
	IceCream(const IceCream& ic){
		this->ime = new char[strlen(ic.ime) + 1];
		strcpy(this->ime, ic.ime);
		strcpy(this->sostav , ic.sostav);
		this->cena = ic.cena;
		this->popust = ic.popust;
	}
	IceCream& operator=(const IceCream &ic){
		delete [] ime;
		this->ime = new char[strlen(ic.ime) + 1];
		strcpy(this->ime, ic.ime);
		strcpy(this->sostav , ic.sostav);
		this->cena = ic.cena;
		this->popust = ic.popust;
		return *this;
	}
	~IceCream(){
		delete [] ime;
	}
	friend ostream& operator<<(ostream &out, const IceCream &ic){
		out<<ic.ime<<": "<<ic.sostav<<" "<<ic.cena<<" ";
		if(ic.popust)
			out<<"("<<ic.cena-(ic.cena*ic.popust)/100<<")";
		return out;
	}
	IceCream& operator++(){
		popust+=5;
		return *this;
	}
	IceCream& operator+(const char *dodaj){
		char *temp = new char[strlen(ime)+1];
		strcpy(temp, ime);
		delete [] ime;
		ime  = new char[strlen(temp) + 3 + strlen(dodaj) + 1];
		strcpy(ime, temp);
		strcat(ime, " + ");
		strcat(ime, dodaj);
		cena+=10;
		delete [] temp;
		return *this;
	}
	void setDiscount(int discount){
		if(discount >=0 && discount <=100)
			popust = discount;
	}
	void setName(const char* name){
		this->ime = new char[strlen(name)+1];
		strcpy(this->ime, name);
	}
};

class IceCreamShop{
private:
	char ime [50];
	IceCream* niza;
	int iceCreamCount;
public:
	IceCreamShop(){
		niza = new IceCream[0];
		iceCreamCount = 0;
	}
	IceCreamShop(char* ime){
		strcpy(this->ime , ime);
		niza = new IceCream[0];
		iceCreamCount = 0;
	}
	IceCreamShop(const IceCreamShop &cs){
		strcpy(this->ime , cs.ime);
		iceCreamCount = cs.iceCreamCount;
		niza = new IceCream[iceCreamCount];							//DONT FORGET THIS SHIT(zaboravi da alocirash i ne ti raboteshe programata)
		for(int i = 0 ; i<iceCreamCount ; i++)
			niza[i] = cs.niza[i];
	}
	IceCreamShop& operator=(const IceCreamShop &cs){
		strcpy(this->ime , cs.ime);
		iceCreamCount = cs.iceCreamCount;
		delete [] niza;
		niza = new IceCream[iceCreamCount];							////DONT FORGET THIS SHIT(zaboravi da alocirash i ne ti raboteshe programata)
		for(int i = 0 ; i<iceCreamCount ; i++)
			niza[i] = cs.niza[i];
		return *this;
	}
	~IceCreamShop(){
		delete [] niza;
	}
	IceCreamShop & operator+=(const IceCream &cs){
		IceCream *temp = new IceCream[iceCreamCount + 1];
		for(int i = 0 ; i<iceCreamCount ; i++)
			temp[i] = niza[i];
		temp[iceCreamCount++] = cs;
		delete [] niza;
		niza = temp;
		return *this;
	}
	friend ostream& operator<<(ostream &out, const IceCreamShop &cs){
		out << cs.ime<<endl;
		for(int i = 0 ; i<cs.iceCreamCount ; i++)
			out<<cs.niza[i]<<endl;
		return out;
	}
};


int main() {
	char name[100];
	char ingr[100];
	float price;
	int discount;
	int testCase;
	cin >> testCase;
	cin.get();
	if(testCase == 1) {
		cout << "====== TESTING IceCream CLASS ======" << endl;
		cin.getline(name,100);
		cin.getline(ingr,100);
		cin >> price;
		cin >> discount;
		cout << "CONSTRUCTOR" << endl;
		IceCream ic1(name, ingr, price);
		ic1.setDiscount(discount);
		cin.get();
		cin.getline(name,100);
		cin.getline(ingr,100);
		cin >> price;
		cin >> discount;
		IceCream ic2(name, ingr, price);
		ic2.setDiscount(discount);
		cout << "OPERATOR <<" << endl;
		cout << ic1 << endl;
		cout << ic2 << endl;
		cout << "OPERATOR ++" << endl;
		++ic1;
		cout << ic1 << endl;
		cout << "OPERATOR +" << endl;
		IceCream ic3 = ic2 + "chocolate";
		cout << ic3 << endl;
	} else if(testCase == 2) {
		cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
		cin.getline(name,100);
		cin.getline(ingr,100);
		cin >> price;
		//cin >> discount;
		cout << "CONSTRUCTOR" << endl;
		IceCream ic1(name, ingr, price);
		cout << ic1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		IceCream ic2(ic1);
		cin.get();
		cin.getline(name,100);
		ic2.setName(name);
		cout << ic1 << endl;
		cout << ic2 << endl;
		cout << "OPERATOR =" << endl;
		ic1 = ic2;
		cin.getline(name,100);
		ic2.setName(name);
		cout << ic1 << endl;
		cout << ic2 << endl;
		
		cin >> discount;
		ic1.setDiscount(discount);
 

	} else if(testCase == 3) {
		cout << "====== TESTING IceCreamShop ======" << endl;
		char icsName[50];
		cin.getline(icsName,100);
		cout << "CONSTRUCTOR" << endl;
		IceCreamShop ics(icsName);
		int n;
		cin >> n;
		cout << "OPERATOR +=" << endl;
		for(int i = 0; i < n; ++i) {
			cin.get();
			cin.getline(name,100);
			cin.getline(ingr,100);
			cin >> price;
			IceCream ic(name, ingr, price);
			ics += ic;
		}
		cout << ics;
	} else if(testCase == 4) {
		cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
		char icsName[50];
		cin.getline(icsName,100);
		IceCreamShop ics(icsName);
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin.get();
			cin.getline(name,100);
			cin.getline(ingr,100);
			cin >> price;
			IceCream ic(name, ingr, price);
			ics += ic;
		}
		IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
		IceCreamShop icp = ics;
		ics+=x;
		cout << ics << endl;
		cout << icp << endl;
	}
	return 0;
}
*/

/*																							ListContainer 
class List{
private:
	int* lista;
	int numCount;
public:
	List(){
		lista = new int[0];
		numCount = 0;
	}
	List(int* lista, int numCount){
		this->numCount = numCount;
		this->lista = new int[numCount];
		for(int i = 0; i < numCount; i++)
			this->lista[i] = lista[i];
	}
	List(const List &l){
		numCount = l.numCount;
		lista = new int[numCount];
		for(int i = 0; i < numCount; i++)
			lista[i] = l.lista[i];
	}
	List& operator=(const List &l){
		numCount = l.numCount;
		delete [] lista;
		lista = new int[numCount];
		for(int i = 0; i < numCount; i++)
			lista[i] = l.lista[i];
		return *this;
	}
	~List(){
		delete [] lista;
	}
	void pecati(){
		cout<<numCount<<": ";
		int sum = 0;
		for(int i = 0 ; i<numCount;i++){
			cout<<lista[i]<<" ";
			sum+=lista[i];
		}
		cout<<"sum: "<<sum<<" average: "<<1.0*sum/numCount<<endl;
	}
	int sum(){
		int sum = 0;
		for(int i = 0 ; i<numCount;i++)
			sum+=lista[i];
		return sum;
	}
	float average(){
		return 1.0*sum()/numCount;
	}
	int getCount(){
		return numCount;
	}
};


class ListContainer{
private:
	List *niza;
	int listCount;
	int attempts;
public:
	ListContainer(){
		niza = new List[0];
		listCount = 0;
		attempts = 0;
	}
	ListContainer(const ListContainer& lc){
		listCount = lc.listCount;
		attempts = lc.attempts;
		niza = new List[listCount];
		for(int i=0;i<listCount;i++)
			niza[i] = lc.niza[i];
	}
	ListContainer& operator=(const ListContainer& lc){
		listCount = lc.listCount;
		attempts = lc.attempts;
		delete [] niza;
		niza = new List[listCount];
		for(int i=0;i<listCount;i++)
			niza[i] = lc.niza[i];
		return *this;
	}
	~ListContainer(){
		delete [] niza;
	}
	void print(){
		if(!listCount){
			cout<<"The list is empty"<<endl;
			return;
		}
		else{
			for(int i=0;i<listCount;i++){
				cout<<"List number: " << i+1 <<" List info: ";
				niza[i].pecati();
			}
			cout<<"Sum: "<< sum() << " Average: " << average()<<endl;
			cout<<"Successful attempts: "<<listCount<<" Failed attempts: " << attempts - listCount<<endl;
		}
	}
	void addNewList(List l){
		attempts++;
		int flag = 1;
		for(int i = 0 ;i<listCount ; i++)
			if(niza[i].sum() == l.sum())
				flag = 0;
		if(flag){
			List *temp = new List[listCount + 1];
			for(int i = 0; i<listCount;i++)
				temp[i] = niza[i];
			temp[listCount] = l;
			listCount++;
			delete [] niza;
			niza = temp;
		}
	}
	int sum(){
		int suma = 0;
		for(int i =0 ;i<listCount;i++)
			suma+=niza[i].sum();
		return suma;
	}
	float average(){
		int suma = sum();
		float prosek = 0;
		for(int i =0 ;i<listCount;i++)
			prosek+=niza[i].getCount();
		return suma/prosek*1.0;
	}
};

int main() {
	ListContainer lc;
	int N;
	cin>>N;
	for (int i=0;i<N;i++) {
		int n;
		int niza[100];
		cin>>n;
		for (int j=0;j<n;j++){
			cin>>niza[j];
		}
		List l=List(niza,n);
		lc.addNewList(l);
	}
	int testCase;
	cin>>testCase;
	if (testCase==1) {
		cout<<"Test case for operator ="<<endl;
		ListContainer lc1;
		lc1.print();
		cout<<lc1.sum()<<" "<<lc.sum()<<endl;
		lc1=lc;
		lc1.print();
		cout<<lc1.sum()<<" "<<lc.sum()<<endl;
		lc1.sum();
		lc1.average();
	}
	else {
		lc.print();
	}
}
*/

/*																									Планинарски дом
class Zichara{
private:
	char * mesto;
	int cena;
public:
	Zichara(){
		mesto = new char[0];
		cena = 0;
	}
	Zichara(char *mesto, int cena){
		this->mesto = new char[strlen(mesto)+1];
		strcpy(this->mesto, mesto);
		this->cena = cena;
	}
	Zichara(const Zichara &z){
		mesto = new char[strlen(z.mesto)+1];
		strcpy(mesto, z.mesto);
		cena = z.cena;
	}
	Zichara& operator=(const Zichara &z){
		delete [] mesto;
		mesto = new char[strlen(z.mesto)+1];
		strcpy(mesto, z.mesto);
		cena = z.cena;
		return *this;
	}
	~Zichara(){
		delete [] mesto;
	}
	int getCena(){
		return cena;
	}
};

class PlaninarskiDom{
private:
	char ime[15];
	int cenaSezoni [2];
	char klasa;
	bool daliZicara;
	Zichara obj;
public:
	PlaninarskiDom(){
		daliZicara = false;
	}
	PlaninarskiDom(char* ime,int *cenaSezoni, char klasa){
		strcpy(this->ime, ime);
		for(int i=0;i<2;i++)
			this->cenaSezoni[i] = cenaSezoni[i];
		this->klasa = klasa;
	}
	PlaninarskiDom(const PlaninarskiDom &p){
		strcpy(ime, p.ime);
		for(int i=0;i<2;i++)
			cenaSezoni[i] = p.cenaSezoni[i];
		klasa = p.klasa;
		daliZicara = p.daliZicara;
		obj = p.obj;
	}
	PlaninarskiDom &operator=(const PlaninarskiDom &p){
		strcpy(ime, p.ime);
		for(int i=0;i<2;i++)
			cenaSezoni[i] = p.cenaSezoni[i];
		klasa = p.klasa;
		daliZicara = p.daliZicara;
		obj = p.obj;
		return *this;
	}
	PlaninarskiDom& operator--(){
		if(klasa != 'F')
			++klasa;
		return *this;
	}
	~PlaninarskiDom()	{}
	bool operator<=(char znak){
		return klasa > znak;
	}
	void setZichara(Zichara z){
		obj = z;
		daliZicara = true;
	}
	friend ostream& operator<<(ostream &out, const PlaninarskiDom &p){
		out<<p.ime<<" klasa:"<<p.klasa;
		if(p.daliZicara)
			out<<" so Zichara"<<endl;
		else
			out<<endl;
		return out;
	}
	void presmetajDnevenPrestoj(int den, int mesec, int &cena){
		if(den < 1 || den > 31 || mesec < 1 || mesec > 12) {
			throw 5;
		}
		if (daliZicara)
			cena += obj.getCena();
		if ((den >= 1&&mesec >= 4&&mesec < 9) || (mesec == 9 && den == 1)) {
			cena += cenaSezoni[0];
		}
		else {
			cena += cenaSezoni[1];
		}
	}
};


int main(){

   PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

   //во следниот дел се вчитуваат информации за планинарскиот дом
   char imePlaninarskiDom[15],mestoZichara[30],klasa;
   int ceni[12];
   int dnevnakartaZichara;
   bool daliZichara;
   cin>>imePlaninarskiDom;
   for (int i=0;i<2;i++) cin>>ceni[i];
   cin>>klasa;
   cin>>daliZichara;

   //во следниот дел се внесуваат информации и за жичарата ако постои
   if (daliZichara) {
	  cin>>mestoZichara>>dnevnakartaZichara;
	  PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
	  Zichara r(mestoZichara,dnevnakartaZichara);
	  pom.setZichara(r);
	  p=pom;
   }
   else{
	  PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
	  p=*pok;
   }
   //се намалува класата на планинарскиот дом за 2
   --p;
   --p;
   int cena;
   int den,mesec;
   cin>>den>>mesec;
   try{
	   p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
	   cout<<"Informacii za PlaninarskiDomot:"<<endl;
	   cout<<p;
	   if (p<='D') 
		   cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";
	   cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
   }
   catch (int){
	  cout<<"Mesecot ili denot e greshno vnesen!";
   }
}
*/
/*

enum Extension{pdf,txt,exe};

class File{
private:
	char *ime;
	Extension tip;
	char *owner;
	int size;
public:
	File(){
		ime  = new char[0];
		owner = new char[0];
		size = 0;
		tip = (Extension) 0;
	}
	File(char *ime, char* owner, int size, Extension tip){
		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);
		this->owner = new char[strlen(owner) + 1];
		strcpy(this->owner, owner);
		this->size = size;
		this->tip = tip;
	}
	File(const File &f){
		ime = new char[strlen(f.ime) + 1];
		strcpy(ime, f.ime);
		owner = new char[strlen(f.owner) + 1];
		strcpy(owner, f.owner);
		size = f.size;
		tip = f.tip;
	}
	File& operator=(const File &f){
		delete [] ime;
		ime = new char[strlen(f.ime) + 1];
		strcpy(ime, f.ime);
		delete [] owner;
		owner = new char[strlen(f.owner) + 1];
		strcpy(owner, f.owner);
		size = f.size;
		tip = f.tip;
		return *this;
	}
	~File(){
		delete [] ime;
		delete [] owner;
	}
	void print(){
		cout <<"File name: "<<ime<<".";
		if(tip == 0)
			cout<<"pdf"<<endl;
		else if(tip == 1)
			cout<<"txt"<<endl;
		else
			cout<<"exe"<<endl;
		cout <<"File owner: "<<owner<<endl;
		cout <<"File size: "<<size<<endl;
	}
	bool equals(const File &that){
		if( strcmp(ime, that.ime)==0 && tip==that.tip && strcmp(owner, that.owner)==0 )
			return true;
		else
			return false;
	}
	bool equalsType(const File &that){
		if(strcmp(ime, that.ime)==0 && tip==that.tip)
			return true;
		else
			return false;
	}
};

class Folder{
private:
	char *ime;
	int brojElems;
	File *niza;
public:
	Folder(){
		ime = new char[0];
		brojElems = 0;
		niza = new File[0];
	}
	Folder(const char * ime){
		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);
		brojElems = 0;
		niza = new File[0];
	}
	Folder(const Folder &f){
		this->ime = new char[strlen(f.ime) + 1];
		strcpy(this->ime, f.ime);
		brojElems = f.brojElems;
		niza = new File[brojElems];
		for(int i = 0; i<brojElems ; i++)
			niza[i] = f.niza[i];
	}
	Folder& operator=(const Folder &f){
		delete [] ime;
		this->ime = new char[strlen(f.ime) + 1];
		strcpy(this->ime, f.ime);
		brojElems = f.brojElems;
		delete [] niza;
		niza = new File[brojElems];
		for(int i = 0; i<brojElems ; i++)
			niza[i] = f.niza[i];
		return *this;
	}
	~Folder(){
		delete [] ime;
		delete [] niza;
	}
	void print(){
		cout<<"Folder name: "<<ime<<endl;
		for(int i = 0;i<brojElems;i++)
			niza[i].print();
	}
	void remove(const File &f){
		int index = -1;
		for(int i = 0;i<brojElems;i++)
			if(niza[i].equals(f)){
				index = i;
				break;
			}
		if(index > -1){
			File *temp = new File[brojElems - 1];
			for(int i=0;i<brojElems;i++)
				if(index != i)
					temp[i] = niza[i];
			brojElems--;
			delete [] niza;
			niza = temp;
		}
	}
	void add(const File &f){
		File *temp = new File[brojElems+1];
		for(int i=0;i<brojElems;i++)
			temp[i] = niza[i];
		temp[brojElems] = f;
		brojElems++;
		delete [] niza;
		niza = temp;
	}
};


int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
		cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
		cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;	

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
*/

/*
class Patnik{
private:
	char ime [100];
	int vagonKlasa;
	bool velosiped;
public:
	Patnik(){
		
	}
	Patnik(char *ime, int vagonKlasa, bool velosiped){
		strcpy(this->ime, ime);
		this->vagonKlasa = vagonKlasa;
		this->velosiped = velosiped;
	}
	Patnik(const Patnik &p){
		strcpy(ime, p.ime);
		vagonKlasa = p.vagonKlasa;
		velosiped = p.velosiped;
	}
	Patnik& operator=(const Patnik& p){
		strcpy(ime, p.ime);
		vagonKlasa = p.vagonKlasa;
		velosiped = p.velosiped;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Patnik &p){
		out<<p.ime<<endl<<p.vagonKlasa<<endl<<p.velosiped<<endl;
		return out;
	}
	bool getVelosiped(){
		return velosiped;
	}
	int getKlasa(){
		return vagonKlasa;
	}
};

class Voz{
private:
	char dest[100];
	Patnik* niza;
	int passCount;
	int maxVelosipedi;
public:
	Voz(){
		niza = new Patnik[0];
		passCount = 0;
	}
	Voz(char* dest, int maxVelosipedi){
		strcpy(this->dest, dest);
		this->maxVelosipedi = maxVelosipedi;
		niza = new Patnik[0];
		passCount = 0;
	}
	Voz& operator+=(Patnik &p){
		if((!p.getVelosiped() && maxVelosipedi == 0) || maxVelosipedi != 0){
			Patnik *temp = new Patnik[passCount + 1];
			for(int i = 0; i<passCount;i++)
				temp[i] = niza[i];
			temp[passCount] = p;
			passCount++;
			delete [] niza;
			niza = temp;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Voz &v){
		out<<v.dest<<endl;
		for(int i = 0; i<v.passCount;i++)
			out<<v.niza[i]<<endl;
		return out;
	}
	void patniciNemaMesto(){
		int prvaKlasa = 0, vtoraKlasa = 0;
		for (int i = 0; i < passCount; i++) {
			if (niza[i].getKlasa() == 1 && niza[i].getVelosiped() == true) {
				prvaKlasa++;
			}
			else if (niza[i].getKlasa() == 2 && niza[i].getVelosiped() == true) {
				vtoraKlasa++;
			}
		}
		if (prvaKlasa >= maxVelosipedi) {
			prvaKlasa -= maxVelosipedi;
		}
		else if (prvaKlasa < maxVelosipedi) {
			maxVelosipedi -= prvaKlasa;
			prvaKlasa = 0;
			if (vtoraKlasa >= maxVelosipedi) {
				vtoraKlasa -= maxVelosipedi;
			}
			else if (vtoraKlasa < maxVelosipedi) {
				vtoraKlasa = 0;
			}
		}
		cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << prvaKlasa << endl;
		cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << vtoraKlasa << endl;
	}
};



int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n;
	bool velosiped;
	int klasa;
	int maxv;
	cin >> destinacija >> maxv;
	cin >> n;
	Voz v(destinacija, maxv);
	//cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		//cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}
*/

/*
struct Tanc{
	char ime[15];
	char zemja[15];
};

struct Tancer{
	char ime[20];
	char prezime[20];
	Tanc niza[5];
};

void tancuvanje(Tancer *t, int n, char *zemja){
	for(int i = 0; i<n;i++)
		for(int j = 0 ; j<n;j++)
			if(strcmp(t[i].niza[j].zemja, zemja)==0){
				cout<<t[i].ime<<" "<<t[i].prezime<<", "<<t[i].niza[j].ime<<endl;
				break;
			}
}

int main()
{
	int i, j, n;
	char zemja[15];
	Tancer tanceri[5];
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> tanceri[i].ime;
		cin >> tanceri[i].prezime;
		for(j = 0; j < 3; j++){
			cin >> tanceri[i].niza[j].ime;
			cin >> tanceri[i].niza[j].zemja;
		}
	}
	cin >> zemja;
	tancuvanje(tanceri, n, zemja);
	return 0;
}
*/
/*

class StockRecord{
private:
	char id [12];
	char ime [50];
	double kupenaCena;
	double momentalnaCena;
	int numAkcii;
public:
	StockRecord(){
		kupenaCena = 0.0;
		momentalnaCena = 0.0;
		numAkcii = 0;
	}
	StockRecord(const char *id, const char* ime, double kupenaCena, int numAkcii){
		strcpy(this->id, id);
		strcpy(this->ime, ime);
		this->kupenaCena = kupenaCena;
		this->numAkcii = numAkcii;
		momentalnaCena = 0.0;
	}
	StockRecord(const StockRecord &s){
		strcpy(this->id, s.id);
		strcpy(this->ime, s.ime);
		this->kupenaCena = s.kupenaCena;
		this->numAkcii = s.numAkcii;
		this->momentalnaCena = s.momentalnaCena;
	}
	void setNewPrice(double c){
		momentalnaCena = c;
	}
	double value(){
		return numAkcii*momentalnaCena;
	}
	double profit(){
		return numAkcii*(momentalnaCena - kupenaCena);
	}
	friend ostream& operator<<(ostream& out, StockRecord &s){
		out<<s.ime<<" "<<s.numAkcii<<" "<<s.kupenaCena<<" "<<s.momentalnaCena<<" "<<s.profit()<<endl;
		return out;
	}
};

class Client{
private:
	char ime[60];
	int id;
	StockRecord* niza;
	int objCount;
public:
	Client(){
		niza = new StockRecord[0];
		id = 0;
		objCount = 0;
	}
	Client(char *ime, int id){
		strcpy(this->ime, ime);
		this->id = id;
		niza = new StockRecord[0];
		objCount = 0;
	}
	Client(const Client &c){
		strcpy(ime, c.ime);
		id = c.id;
		objCount = c.objCount;
		niza = new StockRecord[objCount];
	}
	Client& operator=(const Client &c){
		delete [] niza;
		strcpy(ime, c.ime);
		id = c.id;
		objCount = c.objCount;
		niza = new StockRecord[objCount];
		return *this;
	}
	~Client(){
		delete [] niza;
	}
	double totalValue(){
		double sum = 0.0;
		for(int i = 0;i<objCount;i++)
			sum+=niza[i].value();
		return sum;
	}
	Client& operator+=(const StockRecord &s){
		StockRecord *temp = new StockRecord[objCount+1];
		for(int i = 0;i<objCount;i++)
			temp[i] = niza[i];
		temp[objCount] = s;
		objCount++;
		delete [] niza;
		niza = temp;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Client &c){
		out<<c.id<<" "<<c.totalValue()<<endl;
		for(int i = 0;i<c.objCount;i++)
			out<<c.niza[i];
		return out;
	}
};


int main(){
	
	int test;
	cin >> test;
	
	if(test == 1){
		double price;
		cout << "=====TEST NA KLASATA StockRecord=====" << endl;
		StockRecord sr("1", "Microsoft", 60.0, 100);
		cout << "Konstruktor OK" << endl;
		cin >> price;
		sr.setNewPrice(price);
		cout << "SET metoda OK" << endl;
	}
	else if(test == 2){
		cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
		char id[12], company[50];
		double price, newPrice;
		int n, shares;
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> id;
			cin >> company;
			cin >> price;
			cin >> newPrice;
			cin >> shares;
			StockRecord sr(id, company, price, shares);
			sr.setNewPrice(newPrice);
			cout << sr.value() << endl;
			cout << sr;
		}
	}
	else if(test == 3){
		cout << "=====TEST NA KLASATA Client=====" << endl;
		char companyID[12], companyName[50], clientName[50];
		int clientID, n, shares;
		double oldPrice, newPrice;
		bool flag = true;
		cin >> clientName;
		cin >> clientID;
		cin >> n;
		Client c(clientName, clientID);
		cout << "Konstruktor OK" << endl;
		for(int i = 0; i < n; ++i){
			cin >> companyID;
			cin >> companyName;
			cin >> oldPrice;
			cin >> newPrice;
			cin >> shares;
			StockRecord sr(companyID, companyName, oldPrice, shares);
			sr.setNewPrice(newPrice);
			c += sr;
			if(flag){
				cout << "Operator += OK" << endl;
				flag = false;
			}
		}
		cout << c;
		cout << "Operator << OK" << endl;
	} 
	return 0;

}
*/

class Gitara{
private:
	char srBroj [20];
	double cena;
	int godina;
	char tip [40];
public:
	Gitara(){
		cena = 0.0;
		godina = 0;
	}
	Gitara(char *tip, char* srBroj, int godina, double cena){
		strcpy(this->tip, tip);
		strcpy(this->srBroj, srBroj);
		this->godina = godina;
		this->cena = cena;
	}
	Gitara(const Gitara &g){
		strcpy(this->tip, g.tip);
		strcpy(this->srBroj, g.srBroj);
		this->godina = g.godina;
		this->cena = g.cena;
	}
	Gitara& operator=(const Gitara &g){
		strcpy(this->tip, g.tip);
		strcpy(this->srBroj, g.srBroj);
		this->godina = g.godina;
		this->cena = g.cena;
		return *this;
	}
	bool daliIsti(const Gitara &g){
		return (strcmp(srBroj, g.srBroj) == 0);
	}
	void pecati(){
		cout<<srBroj<<" "<<tip<<" "<<cena<<endl;
	}
	int getGodina(){
		return godina;
	}
	char *getTip(){
		return tip;
	}
	char *getSeriski(){
		return srBroj;
	}
	double getNabavna(){
		return cena;
	}
};

class Magacin{
private:
	char ime[30];
	char loc[60];
	Gitara* niza;
	int elemCount;
	int year;
public:
	Magacin(){
		niza = new Gitara[0];
		elemCount = 0;
		year = 0;
	}
	Magacin(const char* ime, const char* loc, int year){
		strcpy(this->ime, ime);
		strcpy(this->loc, loc);
		this->year = year;
		niza = new Gitara[0];
		elemCount = 0;
	}
	Magacin(const char* ime, const char* loc){
		strcpy(this->ime, ime);
		strcpy(this->loc, loc);
		this->year = 0;
		niza = new Gitara[0];
		elemCount = 0;
	}
	Magacin(const Magacin &m){
		strcpy(this->ime, m.ime);
		strcpy(this->loc, m.loc);
		this->year = m.year;
		elemCount = m.elemCount;
		niza = new Gitara[elemCount];
		for(int i=0;i<elemCount;i++)
			niza[i] = m.niza[i];
	}
	Magacin& operator=(const Magacin &m){
		delete [] niza;
		strcpy(this->ime, m.ime);
		strcpy(this->loc, m.loc);
		this->year = m.year;
		elemCount = m.elemCount;
		niza = new Gitara[elemCount];
		for(int i=0;i<elemCount;i++)
			niza[i] = m.niza[i];
		return *this;
	}
	~Magacin(){
		delete [] niza;
	}
	double vrednost(){
		double sum;
		for(int i=0;i<elemCount;i++)
			sum+=niza[i].getNabavna();
		return sum;
	}
	void dodadi(Gitara &g){
		Gitara *temp = new Gitara[elemCount+1];
		for(int i=0;i<elemCount;i++)
			temp[i] = niza[i];
		temp[elemCount] = g;
		elemCount++;
		delete [] niza;
		niza = temp;
	}
	void prodadi(Gitara g){
		int counter = 0;
		for(int i=0;i<elemCount;i++)
			if(niza[i].daliIsti(g) == false){
				counter++;
			}
		if(counter > 0){
			Gitara *temp = new Gitara[counter];
			for(int i=0,j=0;i<elemCount;i++)
				if(niza[i].daliIsti(g) == false){
					temp[j] = niza[i];
					j++;
				}
				elemCount = counter;
				delete [] niza;
				niza = temp;
		}
	}
	void pecati(bool daliNovi){
		cout<<ime<<" "<<loc<<endl;
		if(daliNovi == true){
			for(int i=0;i<elemCount;i++)
				if(niza[i].getGodina() > year)
					niza[i].pecati();
		}
		else{
			for(int i=0;i<elemCount;i++)
				niza[i].pecati();
		}
	}
};


int main() {
	// se testira zadacata modularno
	int testCase;
	cin >> testCase;

	int n, godina;
	float cena;
	char seriski[50],tip[50];

	if(testCase == 1) {
		cout << "===== Testiranje na klasata Gitara ======" << endl;
		cin>>tip;
		cin>>seriski;
		cin >> godina;
		cin >> cena;
		Gitara g(tip,seriski, godina,cena);
		cout<<g.getTip()<<endl;
		cout<<g.getSeriski()<<endl;
		cout<<g.getGodina()<<endl;
		cout<<g.getNabavna()<<endl;
	} else if(testCase == 2){
		cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
		Magacin kb("Magacin1","Lokacija1");
		kb.pecati(false);
	}
	else if(testCase == 3) {
		cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
		Magacin kb("Magacin1","Lokacija1",2005);
		cin>>n;
			for (int i=0;i<n;i++){
				cin>>tip;
				cin>>seriski;
				cin >> godina;
				cin >> cena;
				Gitara g(tip,seriski, godina,cena);
				cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
		kb.pecati(true);
	}

	else if(testCase == 4) {
		cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
		Magacin kb("Magacin1","Lokacija1",2012);
			cin>>n;
			Gitara brisi;
			for (int i=0;i<n;i++){
				cin>>tip;
				cin>>seriski;
				cin >> godina;
				cin >> cena;

				Gitara g(tip,seriski, godina,cena);
				if(i==2)
					brisi=g;
				cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
		kb.pecati(false);
		kb.prodadi(brisi);
		kb.pecati(false);
	}
	else if(testCase == 5) {
		cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
		Magacin kb("Magacin1","Lokacija1",2011);
			cin>>n;
			Gitara brisi;
			for (int i=0;i<n;i++){
				cin>>tip;
				cin>>seriski;
				cin >> godina;
				cin >> cena;

				Gitara g(tip,seriski, godina,cena);
				if(i==2)
					brisi=g;
				cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
		kb.pecati(true);
		kb.prodadi(brisi);
		cout<<"Po brisenje:"<<endl;
		Magacin kb3;
		kb3=kb;
		kb3.pecati(true);
	}
   else if(testCase ==6)
		{
		cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
		Magacin kb("Magacin1","Lokacija1",2011);
			cin>>n;
			Gitara brisi;
			for (int i=0;i<n;i++){
				cin>>tip;
				cin>>seriski;
				cin >> godina;
				cin >> cena;

				Gitara g(tip,seriski, godina,cena);
				if(i==2)
					brisi=g;
				kb.dodadi(g);
			}
		cout<<kb.vrednost()<<endl;
		kb.prodadi(brisi);
		cout<<"Po brisenje:"<<endl;
		cout<<kb.vrednost();
		Magacin kb3;
		kb3=kb;
		}
	return 0;
}
