#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*
class myclass {
	int i;
public:
	myclass(int n){
		i = n;
		cout << "Constructing " << i << "\n";
	}
	~myclass(){
		cout << "Destroying " << i << "\n";
	}
	void set_i(int n){ 
		i=n;
	}
	int get_i(){
		return i; 
	}
};

void f(myclass ob) {
	ob.set_i(2);
	cout << "This is local i: " << ob.get_i() << endl;
}

int main() {
	myclass x(1);
	f(x);
	cout << "This is i in main: ";
	cout << x.get_i() << endl;
	return 0;
}
*/

/*
class X {
 int a;
 double b;
public:
	X(int j, double c){
		this->a = j; this->b = c;
	}
	void areTheSame(const X &y) {
		if(&y == this)
			cout << "It is the same object" << endl;
		else if(a==y.a && b==y.b)
			cout << "Objects have same values" << endl;
		else
			cout << "Objects are different" << endl;
	}
};

int main() {
	X A(1,2.3), B(4,5.6);
	X C(A), *p = &A;
	A.areTheSame(B);
	C.areTheSame(A);
	A.areTheSame(*p);
	return 0;
} 
*/

/*
class String 
{ 
private: 
    char *s; 
    int size; 
public: 
    String(const char *str = NULL){
		size = strlen(str); 
		s = new char[size+1]; 
		strcpy(s, str); 
	}
	String(const String& old_str){ 
		size = old_str.size; 
		s = new char[size+1]; 
		strcpy(s, old_str.s); 
	}
	~String(){
		delete [] s;
	}
    void print(){ 
		cout << s << endl;
	}
    void change(const char *str){
		delete [] s; 
		size = strlen(str); 
		s = new char[size+1]; 
		strcpy(s, str); 
	}
}; 
  
int main() 
{ 
    String str1("GeeksQuiz"); 
    String str2 = str1; 
  
    str1.print(); // what is printed ? 
    str2.print(); 
  
    str2.change("GeeksforGeeks"); 
  
    str1.print(); // what is printed now ? 
    str2.print(); 
    return 0; 
} 
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AUD

/*																1
class Momche{
private:
	char ime[20];
	char prezime [20];
	int godini;
public:
	Momche(char *name = "", char *lastname = "", int age = 0){
		godini = age;
		strcpy(ime, name);
		strcpy(prezime, lastname);
	}
	Momche(const Momche &m){
		godini = m.godini;
		strcpy(ime, m.ime);
		strcpy(prezime, m.prezime);
	}
	~Momche()   {}
	int getGodini(){
		return godini;
	}
	void print(){
		cout << "Momche: "<< ime << prezime << godini;
	}
};

class Devojche{
private:
	char ime[20];
	char prezime [20];
	int godini;
public:
	Devojche(char *name = "", char *lastname = "", int age = 0){
		godini = age;
		strcpy(ime, name);
		strcpy(prezime, lastname);
	}
	Devojche(const Devojche &d){
		godini = d.godini;
		strcpy(ime,d.ime);
		strcpy(prezime,d.prezime);
	}
	~Devojche()   {}
	int getGodini(){
		return godini;
	}
	void print(){
		cout << "  Devojche: "<< ime << prezime << godini;
	}
};

class Sredba{
private:
	Momche momche;
	Devojche devojche;
public:
	Sredba(const Momche m, const Devojche d){
		momche = m;
		devojche = d;
	}
	~Sredba()    {}
	void print(){
		cout << "sredba:   ";
		momche.print();
		devojche.print();
	}
	void DaliSiOdgovaraat(){
		if(fabs(momche.getGodini() - devojche.getGodini()) < 5)
			cout << "   si odgovaraat" << '\n';
		else
			cout << "   ne si odgovaraat" << '\n';
	}
};

int main(){
	int godini;
	char ime[20], prezime[20];
	//momche;
	cin >> ime >> prezime >> godini;
	Momche m(ime,prezime,godini);
	Momche momche = m; //Momche momche = m   eksplicitno povikuvanje na copy konstruktor za momche
	//devojche
	cin >> ime >> prezime >> godini;
	Devojche d(ime,prezime,godini);
	Devojche devojche = d; // Devojche devojche = d   eksplicitno povikuvanje na copy konstruktor za devojche
	Sredba s(momche,devojche); // implicitno povikuvanje na copy konstruktor za momche i devojche
	s.print();
	s.DaliSiOdgovaraat();
}
*/

/*																							2
class Ekipa{
private:
	int godina;
	char ime[20];
	char grad[20];
public:
	Ekipa(){
	}
	Ekipa(char* name , char* city, int year){
		godina = year;
		strcpy(ime,name);
		strcpy(grad,city);
	}
	~Ekipa()     {}
	const char* getIme(){
		return ime;
	}
};

class Natprevar{
private:
	Ekipa domakin, gostin;
	int GolDomakin,GolGostin;
public:
	Natprevar(){
	}
	Natprevar(const Ekipa &d, const Ekipa &g, int gDom , int gGost){
		domakin = d;
		gostin = g;
		GolDomakin = gDom;
		GolGostin = gGost;
	}
	~Natprevar()       {}
	Ekipa getDomakin(){
		return domakin;
	}
	Ekipa getGostin(){
		return gostin;
	}
	int getGoloviDomakin(){
		return GolDomakin;
	}
	int getGoloviGostin(){
		return GolGostin;
	}
};

bool revans(Natprevar n1, Natprevar n2){
	if( strcmp(n1.getDomakin().getIme() , n2.getGostin().getIme()) == 0  &&  strcmp(n1.getGostin().getIme() , n2.getDomakin().getIme()) == 0)
		return true;
	else
		return false;
}

void duel(Natprevar n1, Natprevar n2){
	if(revans(n1,n2)){
		int eGolovi1 = n1.getGoloviDomakin() + n2.getGoloviGostin();
		int eGolovi2 = n2.getGoloviDomakin() + n1.getGoloviGostin();
		if(eGolovi1 > eGolovi2)
			cout<< n1.getDomakin().getIme() << endl;
		else if (eGolovi1 < eGolovi2)
			cout<< n1.getGostin().getIme() << endl;
		else if(n1.getGoloviGostin() > n2.getGoloviGostin())
			cout<< n1.getGostin().getIme() << endl;
		else if(n1.getGoloviGostin() < n2.getGoloviGostin())
			cout<< n1.getDomakin().getIme() << endl;
		else 
			cout << "neresheno" << endl;
	}
	else{
		cout << "Ne se sovpagjaat." << endl;
	}
}

int main(){
	Ekipa e1("Real Madrid", "Madrid", 1880);
	Ekipa e2("FC Barcelona", "Barcelona", 1880);
	
	Natprevar n1(e1,e2,1,2);
	Natprevar n2(e2,e1,1,0);
	
	duel(n1,n2);
	return 0;
}
*/

/*																								3
class Datum{
private:
	int den,mesec,godina;
public:
	Datum(){
	}
	Datum(int day, int month, int year){
		den  = day;
		mesec = month;
		godina = year;
	}
	~Datum()		{}
	int getGodina(){
		return godina;
	}
	int getMesec(){
		return mesec;
	}
	int getDen(){
		return den;
	}
};

class Vraboten{
private:
	char ime[20];
	int plata;
	Datum raganje;
public:
	Vraboten(){
	}
	Vraboten(char *name, int pay,const Datum &d){
		raganje = d;
		strcpy(ime, name);
		plata = pay;
	}
	~Vraboten()			{}
	
	Datum getDataRaganje(){
		return raganje;
	}
	int getPlata(){
		return plata;
	}
	void print(){
		cout << "Ime: " << ime << endl;
		cout << "Plata: " << plata << endl;
		cout << "Datum na ragjanje: " << raganje.getDen() << "." << raganje.getMesec() << "." << raganje.getGodina() << endl;
	}
};

//0 = isto se   1 = d1 e pogolem od d2   2 = d2 3 pogolem od d1
int sporedba(Datum d1,Datum d2){
	if(d1.getGodina() > d2.getGodina())
		return 1;
	else if(d1.getGodina() < d2.getGodina())
		return 2;
	else if(d1.getMesec() > d2.getMesec())
		return 1;
	else if(d1.getMesec() < d2.getMesec())
		return 2;
	else if(d1.getDen() > d2.getDen())
		return 1;
	else if(d1.getDen() < d2.getDen())
		return 2;
	else
		return 0;
}

Vraboten najmlad(Vraboten v[], int n){
	int i,ind = 0;
	for(i=0 ; i<n ; i++)
		if(sporedba(v[i].getDataRaganje(), v[i+1].getDataRaganje()) == 1)
			ind = i;
	return v[ind];
}

Vraboten najplaten(Vraboten v[], int n){
	int i,ind = 0;
	int max = v[0].getPlata();
	for(i=1 ; i<n ; i++)
		if(v[i].getPlata() > max){
			max = v[i].getPlata();
			ind = i;
		}
	return v[ind];
}

int main(){
	Datum d1(1, 1, 1980);
	Datum d2(1, 2, 1983);
	Datum d3(11, 12, 1984);
	Vraboten v[3];
	Vraboten v1("Marjan", 40000, d1);
	Vraboten v2("Stefan", 30000, d2);
	Vraboten v3("Marko", 20000, d3);
	v[0] = v1;
	v[1] = v2;
	v[2] = v3;
	cout << "najmladiot vraboten: " << endl;
	najmlad(v,3).print();
	cout << "vraboten so najgolema plata: "<< endl;
	najplaten(v,3).print();
	return 0;
}
*/

/*																	1 so dinamicka alokacija
class Momche{
private:
	char* ime;
	char* prezime ;
	int godini;
	int sizeIme;
	int sizePrez;
public:
	Momche(){
	}
	Momche(char *name, char *lastname, int age){			//konst
		godini = age;
		sizeIme = strlen(name);
		ime = new char[sizeIme+1];
		strcpy(ime, name);
		sizePrez = strlen(lastname);
		prezime = new char[sizePrez+1];
		strcpy(prezime, lastname);
	}
	Momche(const Momche &m){			//copy konst
		godini = m.godini;
		sizeIme = m.sizeIme;
		ime = new char[sizeIme+1];
		strcpy(ime, m.ime);
		sizePrez = m.sizePrez;
		prezime = new char[sizePrez+1];
		strcpy(prezime, m.prezime);
	}
	Momche operator=(const Momche &m){		//asignment operator
		godini = m.godini;
		sizeIme = m.sizeIme;
		ime = new char[sizeIme+1];
		strcpy(ime, m.ime);
		sizePrez = m.sizePrez;
		prezime = new char[sizePrez+1];
		strcpy(prezime, m.prezime);
		return *this;
	}
	~Momche(){
		delete[] ime;
		delete[] prezime;
	}
	int getGodini(){
		return godini;
	}
	void print(){
		cout << "Momche: "<< ime << "  "<< prezime<< "  " << godini;
	}
};

class Devojche{
private:
	char* ime;
	char* prezime;
	int godini;
	int sizeIme;
	int sizePrez;
public:
	Devojche(){
	}
	Devojche(char *name, char *lastname, int age){		//konst
		godini = age;
		sizeIme = strlen(name);
		ime = new char[sizeIme+1];
		strcpy(ime, name);
		sizePrez = strlen(lastname);
		prezime = new char[sizePrez+1];
		strcpy(prezime, lastname);
	}
	Devojche(const Devojche &d){			//copy konst
		godini = d.godini;
		sizeIme = d.sizeIme;
		ime = new char[sizeIme+1];
		strcpy(ime, d.ime);
		sizePrez = d.sizePrez;
		prezime = new char[sizePrez+1];
		strcpy(prezime, d.prezime);
	}
	Devojche operator=(const Devojche &d){		//asignment operator
		godini = d.godini;
		sizeIme = d.sizeIme;
		ime = new char[sizeIme+1];
		strcpy(ime, d.ime);
		sizePrez = d.sizePrez;
		prezime = new char[sizePrez+1];
		strcpy(prezime, d.prezime);
		return *this;
	}
	~Devojche(){
		delete[] ime;
		delete[] prezime;
		}
	int getGodini(){
		return godini;
	}
	void print(){
		cout << "  Devojche: "<< ime << "  "<< prezime<< "  " << godini;
	}
};

class Sredba{
private:
	Momche momche;
	Devojche devojche;
public:
	Sredba(){
	}
	Sredba(const Momche m, const Devojche d){
		momche = m;
		devojche = d;
	}
	~Sredba()    {}
	void print(){
		cout << "sredba:   ";
		momche.print();
		devojche.print();
	}
	void DaliSiOdgovaraat(){
		if(fabs(momche.getGodini() - devojche.getGodini()) < 5)
			cout << "   si odgovaraat" << '\n';
		else
			cout << "   ne si odgovaraat" << '\n';
	}
};

int main(){
	int godini;
	char ime[20], prezime[20];
	//momche;
	cin >> ime >> prezime >> godini;
	Momche m(ime,prezime,godini);
	Momche momche = m; //Momche momche = m   eksplicitno povikuvanje na copy konstruktor za momche
	//devojche
	cin >> ime >> prezime >> godini;
	Devojche d(ime,prezime,godini);
	Devojche devojche = d; // Devojche devojche = d   eksplicitno povikuvanje na copy konstruktor za devojche
	Sredba s(momche,devojche); // implicitno povikuvanje na copy konstruktor za momche i devojche
	s.print();
	s.DaliSiOdgovaraat();
}
*/

/*																2 so dinamicka alokacija
class Ekipa{
private:
	int godina;
	char* ime;
	char* grad;
	int sizeIme;
	int sizeGrad;
public:
	Ekipa(){
	}
	Ekipa(char* ime , char* grad, int godina){
		this->godina = godina;
		sizeIme = strlen(ime);
		this->ime = new char[sizeIme + 1];
		strcpy(this->ime,ime);
		sizeGrad = strlen(grad);
		this->grad = new char[sizeGrad + 1];
		strcpy(this->grad,grad);
	}
	Ekipa(const Ekipa &e){
		this->godina = e.godina;
		sizeIme = e.sizeIme;
		this->ime = new char[sizeIme + 1];
		strcpy(this->ime,e.ime);
		sizeGrad = e.sizeGrad;
		this->grad = new char[sizeGrad + 1];
		strcpy(this->grad,e.grad);
	}
	Ekipa operator=(const Ekipa &e){
		this->godina = e.godina;
		sizeIme = e.sizeIme;
		this->ime = new char[sizeIme + 1];
		strcpy(this->ime,e.ime);
		sizeGrad = e.sizeGrad;
		this->grad = new char[sizeGrad + 1];
		strcpy(this->grad,e.grad);
		return *this;
	}
	~Ekipa(){
		delete[] ime;
		delete[] grad;
	}
	const char* getIme(){
		return ime;
	}
};

class Natprevar{
private:
	Ekipa domakin, gostin;
	int GolDomakin,GolGostin;
public:
	Natprevar(){
	}
	Natprevar(const Ekipa &d, const Ekipa &g, int gDom , int gGost){
		domakin = d;
		gostin = g;
		GolDomakin = gDom;
		GolGostin = gGost;
	}
	~Natprevar()       {}
	Ekipa getDomakin(){
		return domakin;
	}
	Ekipa getGostin(){
		return gostin;
	}
	int getGoloviDomakin(){
		return GolDomakin;
	}
	int getGoloviGostin(){
		return GolGostin;
	}
};

bool revans(Natprevar n1, Natprevar n2){
	if( strcmp(n1.getDomakin().getIme() , n2.getGostin().getIme()) == 0  &&  strcmp(n1.getGostin().getIme() , n2.getDomakin().getIme()) == 0)
		return true;
	else
		return false;
}

void duel(Natprevar n1, Natprevar n2){
	if(revans(n1,n2)){
		int eGolovi1 = n1.getGoloviDomakin() + n2.getGoloviGostin();
		int eGolovi2 = n2.getGoloviDomakin() + n1.getGoloviGostin();
		if(eGolovi1 > eGolovi2)
			cout<< n1.getDomakin().getIme() << endl;
		else if (eGolovi1 < eGolovi2)
			cout<< n1.getGostin().getIme() << endl;
		else if(n1.getGoloviGostin() > n2.getGoloviGostin())
			cout<< n1.getGostin().getIme() << endl;
		else if(n1.getGoloviGostin() < n2.getGoloviGostin())
			cout<< n1.getDomakin().getIme() << endl;
		else 
			cout << "neresheno" << endl;
	}
	else{
		cout << "Ne se sovpagjaat." << endl;
	}
}

int main(){
	Ekipa e1("Real Madrid", "Madrid", 1880);
	Ekipa e2("FC Barcelona", "Barcelona", 1880);
	
	Natprevar n1(e1,e2,1,2);
	Natprevar n2(e2,e1,1,0);
	
	duel(n1,n2);
	return 0;
}
*/

/*																			3 so dinamicka alokacija
class Datum{
private:
	int den,mesec,godina;
public:
	Datum(){
	}
	Datum(int day, int month, int year){
		den  = day;
		mesec = month;
		godina = year;
	}
	Datum(const Datum &d){
		den = d.den;
		mesec = d.mesec;
		godina = d.godina;
	}
	~Datum()		{}
	int getGodina(){
		return godina;
	}
	int getMesec(){
		return mesec;
	}
	int getDen(){
		return den;
	}
};

class Vraboten{
private:
	char* ime;
	int plata;
	Datum raganje;
	int size;
public:
	Vraboten(){
	}
	Vraboten(char *name, int pay,const Datum &d){
		plata = pay;
		size = strlen(name);
		ime = new char[size + 1];
		strcpy(ime, name);
		raganje = d;
	}
	Vraboten(const Vraboten &v){
		plata = v.plata;
		size = v.size;
		ime = new char[size + 1];
		strcpy(ime, v.ime);
		raganje = v.raganje;
	}
	Vraboten operator=(const Vraboten &v){
		plata = v.plata;
		size = v.size;
		ime = new char[size + 1];
		strcpy(ime, v.ime);
		raganje = v.raganje;
		return *this;
	}
	~Vraboten(){
		delete[] ime;
	}
	
	Datum getDataRaganje(){
		return raganje;
	}
	int getPlata(){
		return plata;
	}
	void print(){
		cout << "Ime: " << ime << endl;
		cout << "Plata: " << plata << endl;
		cout << "Datum na ragjanje: " << raganje.getDen() << "." << raganje.getMesec() << "." << raganje.getGodina() << endl;
	}
};

//0 = isto se   1 = d1 e pogolem od d2   2 = d2 3 pogolem od d1
int sporedba(Datum d1,Datum d2){
	if(d1.getGodina() > d2.getGodina())
		return 1;
	else if(d1.getGodina() < d2.getGodina())
		return 2;
	else if(d1.getMesec() > d2.getMesec())
		return 1;
	else if(d1.getMesec() < d2.getMesec())
		return 2;
	else if(d1.getDen() > d2.getDen())
		return 1;
	else if(d1.getDen() < d2.getDen())
		return 2;
	else
		return 0;
}

void najmlad(Vraboten v[], int n){
	int i,ind = 0;
	for(i=0 ; i<n ; i++)
		if(sporedba(v[i].getDataRaganje(), v[i+1].getDataRaganje()) == 1)
			ind = i;
	 v[ind].print();
}

void najplaten(Vraboten v[], int n){
	int i,ind = 0;
	int max = v[0].getPlata();
	for(i=1 ; i<n ; i++)
		if(v[i].getPlata() > max){
			max = v[i].getPlata();
			ind = i;
		}
	v[ind].print();
}

int main(){
	Datum d1(1, 1, 1980);
	Datum d2(1, 2, 1983);
	Datum d3(11, 12, 1984);
	Vraboten v[3];
	Vraboten v1("Marjan", 40000, d1);
	Vraboten v2("Stefan", 30000, d2);
	Vraboten v3("Marko", 20000, d3);
	v[0] = v1;
	v[1] = v2;
	v[2] = v3;
	cout << "najmladiot vraboten: " << endl;
	najmlad(v,3);
	cout << "vraboten so najgolema plata: "<< endl;
	najplaten(v,3);
	return 0;
}
*/

