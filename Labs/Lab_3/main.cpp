#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*																					1
class Masa{
private:
	int dolzina;
	int shirina;
public:
	Masa()		{}
	Masa(int shirina, int dolzina){
		this->dolzina = dolzina;
		this->shirina = shirina;
	}
	void pecati(){
		cout<<"Masa: "<<shirina<<" "<<dolzina<<endl;
	}
};

class Soba{
private:
	Masa table;
	int dolzina;
	int shirina;
public:
	Soba()		{}
	Soba(int shirina, int dolzina, const Masa &m){
		this->dolzina = dolzina;
		this->shirina = shirina;
		table = m;
	}
	void pecati(){
		cout<<"Soba: " << shirina<<" "<< dolzina<<" ";
		table.pecati();
	}
};

class Kukja{
private:
	Soba room;
	char adresa[50];
public:
	Kukja()		{}
	Kukja(const Soba &s, char* adresa){
		room = s;
		strcpy(this->adresa, adresa);
	}
	void pecati(){
		cout << "Adresa: " << adresa <<" ";
		room.pecati();
	}
};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}
    return 0;
}
*/

/*																				2
class Potpisuvac{
private:
	char ime[20];
	char prezime[20];
	char EMBG[14];
public:
	Potpisuvac()		{}
	Potpisuvac(char* ime, char* prezime, char* EMBG){
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		strcpy(this->EMBG, EMBG);
	}
	Potpisuvac(const Potpisuvac &p){
		strcpy(this->ime, p.ime);
		strcpy(this->prezime, p.prezime);
		strcpy(this->EMBG, p.EMBG);
	}
	char* getEMBG(){
		return EMBG;
	}
	~Potpisuvac()		{}
};

class Dogovor{
private:
	int brDogovor;
	char kategorija[50];
	Potpisuvac pot[3];
public:
	Dogovor()		{}
	Dogovor(int brDogovor, char* kategorija,const Potpisuvac p[]){
		this->brDogovor = brDogovor;
		strcpy(this->kategorija, kategorija);
		for(int i = 0; i<3 ; i++)
			pot[i] = p[i];
	}
	bool proverka(){
		if(strcmp(pot[0].getEMBG(),pot[1].getEMBG())==0)
			return 1;
		else if(strcmp(pot[0].getEMBG(),pot[2].getEMBG())==0)
			return 1;
		else if(strcmp(pot[1].getEMBG(),pot[2].getEMBG())==0)
			return 1;
		else 
			return 0;
	}
	~Dogovor()		{}
};

int main(){
    char embg[13], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl; 
    	if(d.proverka() == true)
			cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
			cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}
*/

/*																			3
class Rabotnik{
private:
	char ime[30];
	char prezime[30];
	int plata;
public:
	Rabotnik()		{}
	Rabotnik(char* ime, char* prezime, int plata){
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		this->plata = plata;
	}
	int getPlata(){
		return plata;
	}
	void pecati(){
		cout<<ime<<" "<<prezime<<" "<<plata<<endl;
	}
};

class Fabrika{
private:
	Rabotnik rabotnik[100];
	int brojVraboteni;
public:
	Fabrika()		{}
	Fabrika(int brojVraboteni, const Rabotnik r[]){
		this->brojVraboteni = brojVraboteni;
		for(int i = 0 ; i< brojVraboteni ;i++)
			rabotnik[i] = r[i];
	}
	void pevatiVraboteni(){
		for(int i = 0; i < brojVraboteni ; i++)
			rabotnik[i].pecati();
	}
	void pecatiSoPlata(int minPlata){
		for(int i = 0; i < brojVraboteni ; i++)
			if(rabotnik[i].getPlata() > minPlata)
				rabotnik[i].pecati();
	}
};

int main(){
	int n,plata,minPlata;
	char ime[30], prezime[30];
	Rabotnik r[100];
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>ime>>prezime>>plata;
		r[i]= Rabotnik(ime,prezime,plata);
	}
	cin>>minPlata;
	Fabrika f(n,r);
	cout<<"Site vraboteni: "<<endl;
	f.pevatiVraboteni();
	cout<<"Vraboteni so plata povisoka od " << minPlata<<endl;
	f.pecatiSoPlata(minPlata);
}
*/

/*																4
class NewsArticle;
class Category;

class Category{
private:
	char name[20] = "unnamed";
public:
	Category()		{}
	Category(char* name){
		strcpy(this->name, name);
	}
	void print(){
		cout<<"Category: " << name;
	}
};

class NewsArticle{
private:
	Category cat;
	char title[30] = "untitled";
public:
	NewsArticle()		{}
	NewsArticle(Category cat, char* title=""){
		this->cat = cat;
		strcpy(this->title, title);
	}
	void print(){
		cout<<"Title: "<<title;
		cat.print();
	}
};

class FrontPage{
	NewsArticle na;
	float price=0;
	int editionNumber=0;
public:
	FrontPage()		{}
	FrontPage(NewsArticle na,float price = 0, int editionNumber = 0){
		this->na = na;
		this->price = price;
		this->editionNumber = editionNumber;
	}
	void print(){
		cout<<"Price: "<<price<<", "<<"Edition number: "<<editionNumber;
		na.print();
	}
};

int main() {
	char categoryName[20];
	char articleTitle[30];
	float price;
	int editionNumber;
	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		int iter;
		cin >> iter;
		while (iter > 0) {
			cin >> categoryName;
			cin >> articleTitle;
			cin >> price;
			cin >> editionNumber;
			Category category(categoryName);
			NewsArticle article(category, articleTitle);
			FrontPage frontPage(article, price, editionNumber);
			frontPage.print();
			iter--;
		}
	}
	else if (testCase == 2) {
		cin >> categoryName;
		cin >> price;
		cin >> editionNumber;
		Category category(categoryName);
		NewsArticle article(category);
		FrontPage frontPage(article, price, editionNumber);
		frontPage.print();
	}// test case 3
	else if (testCase == 3) {
		cin >> categoryName;
		cin >> articleTitle;
		cin >> price;
		Category category(categoryName);
		NewsArticle article(category, articleTitle);
		FrontPage frontPage(article, price);
		frontPage.print();
	}
    else {
    	FrontPage frontPage = FrontPage();
        frontPage.print();
    }
	return 0;
}
*/

/*																	5
class Date{
private:
	int year,month,day;
public:
	Date()		{}
	Date(int year, int month, int day){
		this->year = year;
		this->month = month;
		this->day = day;
	}
	void print(){
		cout<<year<<"."<<month<<"."<<day<<endl;
	}
};

class Person{
private:
	char ime[20] = "not specified";
	char prez[20] = "not specified";
public:
	Person()		{}
	Person(char* ime, char* prez){
		strcpy(this->ime, ime);
		strcpy(this->prez, prez);
	}
	void print(){
		cout<<ime<<" "<<prez<<endl;
	}
};
class Car{
private:
	Person p1;//sopstvenik
	Date d1;//data na kupucanje
	float price = 0;
public:
	Car()		{}
	Car(Person p1, Date d1, float price){
		this->p1 = p1;
		this->d1 = d1;
		this->price = price;
	}
	float getPrice(){
		return price;
	}
	void print(){
		p1.print();
		d1.print();
		cout<<price;
	}
};

void cheaperThan(Car* cars, int numCars, float pricelim){
	for(int i = 0; i<numCars ; i++){
		if(cars[i].getPrice() < pricelim)
			cars[i].print();
	}
}

int main() {
	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;
	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);
		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);
		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);
		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));
		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;
		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);
			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);
			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}
	return 0;
}
*/


/*																		6
class Planeta{
private:
	char ime[30];
	int dijametar;
	int oddalacenost;
	float masa;
public:
	Planeta()		{}
	Planeta(char* ime, int dijametar, int oddalacenost, float masa){
		this->dijametar = dijametar;
		strcpy(this->ime, ime);
		this->oddalacenost = oddalacenost;
		this->masa = masa;
	}
	void pecati(){
		cout<<ime<<" so dijametar "<<dijametar<<"km"<<endl;
	}
	int getDalec(){
		return oddalacenost;
	}
	char *getIme(){
		return ime;
	}
	int getDija(){
		return dijametar;
	}
	float getMasa(){
		return masa;
	}
};

class SonchevSistem{
private:
	Planeta najbliskaPlaneta;
	Planeta planeti[50];
	int brojPlaneti;
public:
	SonchevSistem()		{}
	SonchevSistem(Planeta p[],int brojPlaneti){
		this->brojPlaneti = brojPlaneti;
		for(int i = 0; i< brojPlaneti ; i++)
			planeti[i] = p[i];
	}
	void pechatiPlaneti(){
		najbliskaPlaneta = planeti[0];
		for(int i = 0 ; i<brojPlaneti ; i++){
			planeti[i].pecati();
			if(planeti[i].getDalec() < najbliskaPlaneta.getDalec())
				najbliskaPlaneta = planeti[i];
		}
		cout<< "Najbliska planeta e " << najbliskaPlaneta.getIme()<<"so dijametar "<<najbliskaPlaneta.getDija();
		cout<<endl;
	}
	void pechatiSoMasa(float brMasa){
		for(int i = 0; i<brojPlaneti ; i++)
			if(planeti[i].getMasa()>brMasa)
				planeti[i].pecati();
	}
};


int main() {
    Planeta planeti[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ime[100];
        int dijametar;
        int oddalechenost;
        float masa;
        cin >> ime >> dijametar >> oddalechenost >> masa;
        Planeta p(ime, dijametar, oddalechenost, masa);
        planeti[i] = p;
    }
    SonchevSistem ss(planeti, n);
    float masa;
    cin >> masa;
    cout << "Site planeti:"<<endl;
    ss.pechatiPlaneti();
    cout<<endl;
    cout << "Planeti so masa pogolema od " << masa << "kg:"<<endl;
    ss.pechatiSoMasa(masa);
    return 0;
}
*/