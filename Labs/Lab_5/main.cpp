#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>


using namespace std;

/*
class Matrica{
private:
	float a[10][10];
	int n;
public:
	Matrica()		{}
	friend ostream& operator<<(ostream& out, const Matrica &m){
		for(int i = 0; i < m.n ; i++){
			for(int j = 0 ; j < m.n ; j++)
				out << m.a[i][j] << "\t";
			out<<endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Matrica &m){
		m.n= 4;
		for(int i = 0; i < m.n ; i++)
			for(int j = 0 ; j < m.n ; j++)
				m.a[i][j] = i+j;
		return in;
	}
	Matrica& operator+(int x){
		for(int i = 0; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				a[i][j] = a[i][j] + x;
		return *this;
	}
	Matrica& operator-(Matrica &m){
		for(int i = 0; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				a[i][j] = a[i][j] - m.a[i][j];
		return *this;
	}
	Matrica operator*(const Matrica &m){
		Matrica mNew;
		mNew.n = n;
		for(int i = 0; i < mNew.n ; i++)
			for(int j = 0 ; j < mNew.n ; j++){
				mNew.a[i][j] = 0;
				mNew.a[i][j] = a[i][j] * m.a[i][j];
		}
		return mNew;
	}
	// does the same as above operator
	Matrica& operator*(const Matrica &m){
		for(int i = 0; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				a[i][j] = a[i][j] * m.a[i][j];
		return *this;
	}
	
};



//Matrica operator*(const Matrica &m1, const Matrica &m2){
	Matrica m;
	m.n = m1.n;
	for(int i = 0; i < m.n ; i++)
		for(int j = 0 ; j < m.n ; j++){
			m.a[i][j] = 0;
			m.a[i][j] = m1.a[i][j] * m2.a[i][j];
		}
	return m;
}


int main(){
	Matrica A,B,C;
	cin>>A>>B>>C;
    Matrica D=B*C;
    Matrica R=A-D+2;
    cout<<R;
}
*/

/*
class ComplexNumber{
private:
	float real;
	float imag;
public:
	ComplexNumber(){
		real = 0;
		imag = 0;
	}
	ComplexNumber(float real, float imag){
		this->real = real;
		this->imag = imag;
	}
	float module(){
		return sqrt((real * real) + (imag *imag));
	}
	ComplexNumber(const ComplexNumber &c){
		real = c.real;
		imag = c.imag;
	}
	ComplexNumber& operator=(const ComplexNumber &c){
		real = c.real;
		imag = c.imag;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const ComplexNumber &c){
		if(c.real == 0)
			out <<"" << c.imag<<"i";
		else if(c.imag == 0)
			out << "" << c.real << "";
		else
			out << "" << c.real << " + " << c.imag<<"i";
		return out;
	}
	ComplexNumber& operator+(const ComplexNumber &c){
		ComplexNumber CN;
		CN.real = real + c.real;
		CN.imag = imag + c.imag;
		return CN;
	}
	
	//same works the same as above
	//ComplexNumber& operator+(const ComplexNumber &c){
	//	real = real+ c.real;
	//	imag = imag + c.imag;
	//	return *this;
	//}
	ComplexNumber operator-(const ComplexNumber &c){
		ComplexNumber CN;
		CN.real = real - c.real;
		CN.imag = imag - c.imag;
		return CN;
	}
	ComplexNumber operator*(const ComplexNumber &c){
		ComplexNumber CN;
		CN.real = real * c.real;
		CN.imag = imag * c.imag;
		return CN;
	}
	ComplexNumber operator/(const ComplexNumber &c){
		ComplexNumber CN;
		CN.real = real / c.real;
		CN.imag = imag / c.imag;
		return CN;
	}
	bool operator == (const ComplexNumber &c){
		return real == c.real && imag == c.imag;
	}
	bool operator > (const ComplexNumber &c){
		if(real != c.real)
			return real>c.real;
		else
			return imag > c.imag;
	}
	bool operator < (const ComplexNumber &c){
		if(real != c.real)
			return real<c.real;
		else
			return imag < c.imag;
	}
};


class Equation{
private:
	ComplexNumber* numbers;
	char * znaci;
	int n;
public:
	Equation(){
		numbers = new ComplexNumber[0];
		znaci = new char[0];
		n = 0;
	}
	friend istream& operator>>(istream& in, Equation &e){
		float real,imag;
		char znak;
		while(1){
			in>>real>>imag>>znak;
			ComplexNumber CN(real,imag);						//napravi eden comp broj
			ComplexNumber *temp = new ComplexNumber[e.n+1];		//napravi nova lista od comp broevi so +1 golemina od predhodno
			char *temp2 = new char[e.n+1];						//napravi nova niza od znaci --||--
			for(int i = 0 ; i<e.n ; i++){
				temp2[i] = e.znaci[i];							//dodeli predhodni znaci vo nova lista
				temp[i] = e.numbers[i];							//dodeli predhodni Comp broevi vo nova lista
			}
			temp[e.n] = CN;										//dodaj go posledniot broj vo listata
			temp2[e.n] = znak;									//dodaj go posledniot nak vo listata
			e.n++;												//zgolemi go "counter-ot"
			delete [] e.numbers;
			delete [] e.znaci;
			e.numbers = temp;
			e.znaci = temp2;
			if(znak == '=')
				break;
		}
		return in;
	}
	ComplexNumber result() {
		ComplexNumber res(numbers[0]);
		for(int i=1; i<n; i++) {
			if(znaci[i-1] == '+') {
				res = res + numbers[i];
			}
			if(znaci[i-1] == '-') {
				res = res - numbers[i];
			}
			if(znaci[i-1] == '*') {
				res = res * numbers[i];
			}
			if(znaci[i-1] == '/') {
				res = res / numbers[i];
			}
		}
		return res;
	}
	float sumModules(){
		float sum = 0;
		for(int i = 0 ; i < n; i++){
			sum+=numbers[i].module();
		}
		return sum;
	}
	~Equation(){
		delete [] numbers;
		delete [] znaci;
	}
};


int main() {
	int testCase;
	float real, imaginary;
	ComplexNumber first, second, result;

	cin >> testCase;

	if (testCase <= 8) {
		cin >> real;
		cin >> imaginary;
		first = ComplexNumber(real, imaginary);
		cin >> real;
		cin >> imaginary;
		second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		cout << "===== OPERATOR + =====" << endl;
		result = first + second;
		cout << result;
	}
	else if (testCase == 2) {
		cout << "===== OPERATOR - =====" << endl;
		result = first - second;
		cout << result;
	}
	else if (testCase == 3) {
		cout << "===== OPERATOR * =====" << endl;
		result = first * second;
		cout << result;
	}
	else if (testCase == 4) {
		cout << "===== OPERATOR / =====" << endl;
		result = first / second;
		cout << result;
	}
	else if (testCase == 5) {
		cout << "===== OPERATOR == =====" << endl;
		cout << first;
		cout << second;
		if (first == second)
			cout << "EQUAL" << endl;
		else
			cout << "NOT EQUAL" << endl;
	}
	else if (testCase == 6) {
		cout << "===== OPERATOR > =====" << endl;
		cout << first;
		cout << second;
		if (first > second)
			cout << "FIRST GREATER THAN SECOND" << endl;
		else
			cout << "FIRST LESSER THAN SECOND" << endl;
	}
	else if (testCase == 7) {
		cout << "===== OPERATOR < =====" << endl;
		cout << first;
		cout << second;
		if (first < second)
			cout << "FIRST LESSER THAN SECOND" << endl;
		else
			cout << "FIRST GREATER THAN SECOND" << endl;
	}
	else if (testCase == 8) {
		cout << "===== MODULE =====" << endl;
		double module = first.module();
		cout << first;
		cout << "Module: " << module << endl;
		cout << second;
		module = second.module();
		cout << "Module: " << module << endl;
	}
	else if (testCase == 9) {
		cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
		Equation equation;
		cin >> equation;
		cout << equation.sumModules();
	}
	else if (testCase == 10) {
		cout << "===== EQUATION RESULT =====" << endl;
		Equation equation;
		cin >> equation;
		result = equation.result();
		cout << result;
	}
	return 0;
}
*/

/*
class Group{
private:
	char* name;
	int rounds;
	int people;
public:
	Group(){
		name = new char[0];
		rounds = 0;
		people = 0;
	}
	Group(const char* name, int rounds, int people){
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->rounds = rounds;
		this->people = people;
	}
	Group(const Group &g){															//copy const
		this->name = new char[strlen(g.name)+1];
		strcpy(this->name, name);
		this->rounds = g.rounds;
		this->people = g.people;
	}
	Group& operator=(const Group &g){												// = operator
		delete[] name;
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->rounds = rounds;
		this->people = people;
		return *this;
	}
	Group operator+(const Group &g){
		Group temp;
		temp.people = people + g.people;
		if(people > g.people){
			temp.name = new char[strlen(name) +1];
			strcpy(temp.name, name);
			temp.rounds = rounds;
		}
		else{
			temp.name = new char[strlen(g.name) +1];
			strcpy(temp.name, g.name);
			temp.rounds = g.rounds;
		}
		return temp;
	}
	bool operator > (const Group &g){
		return people > g.people;
	}
	bool operator < (const Group &g){
		return people < g.people;
	}
	friend ostream& operator<<(ostream& out, const Group &g){
		out << "Ime: " << g.name << "Turi: " << g.rounds << "Clenovi: " << g.people;
		return out;
	}
	int getPeople(){
		return people;
	}
	int getRounds(){
		return rounds;
	}
	char *getName(){
		return name;
	}
	~Group(){
		delete [] name;
	}
	friend void najmnoguClenovi(Group g[] , int n);
};


void najmnoguClenovi(Group g[] , int n){
		int temp = 0;
		for(int i = 0; i < n ; i++)
			if(g[i].people > g[temp].people)
				temp = i;
		cout << "Najmnogu clenovi ima planinarskoto drustvo: " << g[temp];
}


int main(){
    Group drustva[3];
    Group pl;
    for (int i=0;i<3;i++){
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	Group p(ime,brTuri,brClenovi);
        drustva[i] = p;
   	}
    pl = drustva[0] + drustva[1];
    cout<<pl;
    najmnoguClenovi(drustva, 3);
    return 0;
}
*/

/*
class Automobile{
private:
	char* marka;
	int registracija[5];
	int brzina;
public:
	Automobile(){
		marka = new char[0];
		brzina = 0;
	}
	Automobile(const char* marka, const int* registracija, int brzina){
		this->marka = new char[strlen(marka)+1];
		strcpy(this->marka, marka);
		for(int i = 0 ; i< 5 ; i++)
			this->registracija[i] = registracija[i];
		this->brzina = brzina;
	}
	Automobile(const Automobile &a){
		this->marka = new char[strlen(a.marka)+1];
		strcpy(this->marka, marka);
		for(int i = 0 ; i< 5 ; i++)
			this->registracija[i] = a.registracija[i];
		this->brzina = a.brzina;
	}
	Automobile & operator=(const Automobile &a){
		delete [] marka;
		this->marka = new char[strlen(a.marka)+1];
		strcpy(this->marka, marka);
		for(int i = 0 ; i< 5 ; i++)
			this->registracija[i] = a.registracija[i];
		this->brzina = a.brzina;
		return *this;
	}
	bool operator==(const Automobile &a){
		for(int i = 0; i < 5 ; i ++)
			if(registracija[i] != a.registracija[i])
				return false;
		return true;
	}
	friend ostream & operator<<(ostream& out, const Automobile &a){
		out<<"marka: " << a.marka << " registracija: ";
		for(int i = 0 ; i< 5 ; i++)
			out<<a.registracija[i]<<" ";
		return out;
	}
	int getBrzina(){
		return brzina;
	}
	~Automobile(){
		delete[] marka;
	}
};

class Rentacar{
private:
	char agencija[100];
	Automobile* niza;
	int count;
public:
	Rentacar(){
		niza = new Automobile[0];
		count = 0;
	}
	Rentacar(char agencija[], Automobile niza[], int count){
		strcpy(this->agencija, agencija);
		this->count = count;
		this->niza = new Automobile[count+1];
		for(int i = 0 ; i< count ; i++)
			this->niza[i] = niza[i];
		
	}
	Rentacar(const char agencija[]){
		strcpy(this->agencija, agencija);
		niza = new Automobile[0];
		count = 0;
	}
	Rentacar(const Rentacar &r){
		strcpy(agencija, r.agencija);
		for(int i = 0 ; i < 5 ; i++){
			niza[i] = r.niza[i];
		}
		count = r.count;
	}
	Rentacar& operator=(const Rentacar &r){
		strcpy(agencija, r.agencija);
		for(int i = 0 ; i < 5 ; i++){
			niza[i] = r.niza[i];
		}
		count = r.count;
		return *this;
	}
	Rentacar& operator+=(const Automobile &a){
		Automobile *temp = new Automobile[count+1];
		for(int i = 0 ; i < count ; i++)
			niza[i] = temp[i];
		delete [] temp;
		niza[count] = a;
		count++;
		return *this;
	}
	Rentacar& operator-=(const Automobile &a){
		Automobile *temp = new Automobile[count];
		int newCount = 0;
		for(int i = 0; i < count ; i++){
			if(!(niza[i]==a)){
				temp[newCount] = niza[i];
				newCount++;
			}
		}
		delete [] niza;
		niza = temp;
		count = newCount;
		return *this;
	}
	~Rentacar(){
		delete [] niza;
	}
	void pecatiNadBrzina(int maxBrzina){
		for(int i=0;i<count;i++){
			if(niza[i].getBrzina() > maxBrzina)
				cout<<niza[i];
		}
	}
};



int main(){
   Rentacar agencija("FINKI-Car");
   int n;
   cin>>n;
    
   for (int i=0;i<n;i++)
   {
    	char marka[100];
    	int regisracija[5];
    	int maximumBrzina;
    
       	cin>>marka;
    
       	for (int i=0;i<5;i++)
    		cin>>regisracija[i];
    
    	cin>>maximumBrzina;
    
       	Automobile nov=Automobile(marka,regisracija,maximumBrzina);
       
    	//dodavanje na avtomobil
       	agencija+=nov;   
       
   }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0;i<5;i++)
    cin>>regisracija[i];
    cin>>maximumBrzina;
    
    Automobile greshka=Automobile(marka,regisracija,maximumBrzina);
    
    //brishenje na avtomobil
    agencija-=greshka;
    
    agencija.pecatiNadBrzina(150);
    
    return 0;
}
*/