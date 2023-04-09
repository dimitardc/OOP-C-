#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*
class String{
private:
	char *cptr = NULL;
public:
	String(){
	}
	String(const char* a){
		cptr = new char[strlen(a)+1];
		strcpy(cptr, a);
	}
	~String(){
		delete [] cptr;
	}
	void print(){
		cout << cptr << endl;
	}
};

int main(){
	char a[20];
	cin >> a;
	String idk(a);
	idk.print();
	return 0;
}
*/

/*
int main(){
	int *p = new int(6);
	if (!p){
		cout << "Memory allocation failed\n";
	}
	cout<< *p;
}
*/


//																						AUD

/*																		1
class Ekipa{
private:
	char ime[20];
	char grad[20];
	char stadion[20];
public:
	Ekipa(){
	}
	Ekipa(char* name, char* city, char* stadium){
		strcpy(ime,name);
		strcpy(grad,city);
		strcpy(stadion,stadium);
	}
	Ekipa(const Ekipa &e){
		strcpy(ime, e.ime);
		strcpy(grad, e.grad);
		strcpy(stadion, e.stadion);
	}
	~Ekipa()		{}
	const char *getIme(){
		return ime;
	}
	const char *getGrad(){
		return grad;
	}
	const char *getStadion(){
		return stadion;
	}
	void setIme(char* name){
		strcpy(ime, name);
	}
};

int main(){
	Ekipa *e1 = new Ekipa("Real Madrid", "Madrid", "Santiago Bernabeu");
	Ekipa *e2 = new Ekipa(*e1);
	cout << "Ekipite se: ";
	cout << e1->getIme() << "-" << e2->getIme();
	e1->setIme("Barcelona");
	cout << "\nPo promenata na ekipite se: " << e1->getIme() << "-" << e2->getIme() << endl;
	
	delete e1;
	delete e2;
	return 0;
	
}
*/

/*																					2
class Ekipa{
private:
	char ime[20];
	char grad[20];
	char stadion[20];
public:
	Ekipa(){
	}
	Ekipa(char* name, char* city, char* stadium){
		strcpy(ime,name);
		strcpy(grad,city);
		strcpy(stadion,stadium);
	}
	Ekipa(const Ekipa &e) {
		strcpy(ime, e.ime);
		strcpy(grad, e.grad);
		strcpy(stadion, e.stadion);
	}
	const char *getIme()const{
		return ime;
	}
	const char *getGrad()const{
		return grad;
	}
	const char *getStadion()const{
		return stadion;
	}
	void setIme(char* name){
		strcpy(ime, name);
	}
	~Ekipa()		{}
};

class Natprevar{
private:
	Ekipa *domakin, *gostin;
	int golDomakin,golGostin;
public:
	Natprevar(){
	}
	Natprevar(const Ekipa &d, const Ekipa &g, int gDom, int gGos){
		domakin = new Ekipa(d);
		gostin = new Ekipa(g);
		golDomakin = gDom;
		golGostin = gGos;
	}
	Natprevar(const Natprevar& n) {
		domakin = new Ekipa(*n.domakin);
		gostin = new Ekipa(*n.gostin);
		golDomakin = n.golDomakin;
		golGostin = n.golGostin;
	}
	Ekipa* getDomakin(){
		return domakin;
	}
	Ekipa* getGostin(){
		return gostin;
	}
	int getGoloviDomakin(){
		return golDomakin;
	}
	int getGoloviGostin(){
		return golGostin;
	}
	~Natprevar(){
		delete gostin;
		delete domakin;
	}
	friend bool isTip(Natprevar n, char tip);
};

bool isTip(Natprevar n, char tip){
	if (n.golDomakin == n.golGostin && tip == 'X') 
		return true;
	else if (n.golDomakin > n.golGostin && tip == '1') 
		return true;
	else if (n.golDomakin < n.golGostin && tip == '2') 
		return true;
	else 
		return false;
}


int main(){
	Ekipa e1("Real Madrid", "Madrid", "Santiago Bernabeu");
	Ekipa e2("FC Barcelona", "Barcelona", "Camp Nou");
	Natprevar first(e1,e2,1,3);
	cout << "Vnesi tip za natprevarot: "<< first.getDomakin()->getIme() << "-" << first.getGostin()->getIme() << endl;
	char tip; // 1,2,x
	cin >> tip;
	if(isTip(first,tip))
		cout <<"Tipot e pogoden" <<  endl;
	else
		cout <<"Tipot ne e pogoden" << endl;
	first.getDomakin()->setIme("RLM");
	first.getGostin()->setIme("BAR");
	cout << "Natprevarot beshe megju: "<< first.getDomakin()->getIme() << "-" << first.getGostin()->getIme() << endl;
	return 0;
}
*/
//																			2 my version
/*
class Ekipa{
private:
	char ime[20];
	char grad[20];
	char stadion[20];
public:
	Ekipa(){
	}
	Ekipa(char* name, char* city, char* stadium){
		strcpy(ime,name);
		strcpy(grad,city);
		strcpy(stadion,stadium);
	}
	const char *getIme()const{
		return ime;
	}
	const char *getGrad()const{
		return grad;
	}
	const char *getStadion()const{
		return stadion;
	}
	void setIme(char* name){
		strcpy(ime, name);
	}
	~Ekipa()		{}
};

class Natprevar{
private:
	Ekipa domakin, gostin;
	int golDomakin,golGostin;
public:
	Natprevar(){
	}
	Natprevar(const Ekipa &d, const Ekipa &g, int gDom, int gGos){
		domakin = d;
		gostin = g;
		golDomakin = gDom;
		golGostin = gGos;
	}
	Ekipa& getDomakin(){
		return domakin;
	}
	Ekipa& getGostin(){
		return gostin;
	}
	int getGoloviDomakin(){
		return golDomakin;
	}
	int getGoloviGostin(){
		return golGostin;
	}
	~Natprevar(){
	}
	friend bool isTip(Natprevar n, char tip);
};

bool isTip(Natprevar n, char tip){
	if (n.golDomakin == n.golGostin && tip == 'X') 
		return true;
	else if (n.golDomakin > n.golGostin && tip == '1') 
		return true;
	else if (n.golDomakin < n.golGostin && tip == '2') 
		return true;
	else 
		return false;
}

int main(){
	Ekipa e1("Real Madrid", "Madrid", "Santiago Bernabeu");
	Ekipa e2("FC Barcelona", "Barcelona", "Camp Nou");
	Natprevar first(e1,e2,1,3);
	cout << "Vnesi tip za natprevarot: "<< first.getDomakin().getIme() << "-" << first.getGostin().getIme() << endl;
	char tip; // 1,2,x
	cin >> tip;
	if(isTip(first,tip))
		cout <<"Tipot e pogoden" <<  endl;
	else
		cout <<"Tipot ne e pogoden" << endl;
	first.getDomakin().setIme("RLM");
	first.getGostin().setIme("BAR");
	cout << "Natprevarot beshe megju: "<< first.getDomakin().getIme() << "-" << first.getGostin().getIme() << endl;
	return 0;
}
*/

/*																							3
class Ekipa{
private:
	char ime[20];
	char grad[20];
	char stadion[30];
public:
	Ekipa(){
	}
	Ekipa(char* name, char* city, char* stadium){
		strcpy(ime,name);
		strcpy(grad,city);
		strcpy(stadion,stadium);
	}
	Ekipa(const Ekipa &e) {
		strcpy(ime, e.ime);
		strcpy(grad, e.grad);
		strcpy(stadion, e.stadion);
	}
	const char *getIme(){
		return ime;
	}
	const char *getGrad(){
		return grad;
	}
	const char *getStadion(){
		return stadion;
	}
	void setIme(char* name){
		strcpy(ime, name);
	}
	~Ekipa()		{}
};

void sort(Ekipa *p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(p[i].getIme(), p[j].getIme()) > 0) {
				Ekipa pom = p[i];
				p[i] = p[j];
				p[j] = pom;
			}
		}
	}
}

int main(){
	int n,i;
	char ime[20],grad[20],stadion[30];
	cin >> n;
	Ekipa* prvenstvo = new Ekipa[n];	//pokazuvac kon dinamicko alocirano pole od objekt od Ekipa
	for(i=0;i<n;i++){
		cin >> ime >> grad >> stadion;
		prvenstvo[i] = Ekipa(ime, grad, stadion);
	}
	sort(prvenstvo, n);
	cout << "Ekipite od prvenstvoto se:\n";
	for (int i = 0; i < n; i++)
		cout << i + 1 << " " << prvenstvo[i].getIme() << " (" << prvenstvo[i].getGrad() << ", " << prvenstvo[i].getStadion() << ")" << endl;
	delete[] prvenstvo;
	return 0;
}
*/


//																		Zadaci




//																		1
/*
class Array{
private:
	int size;
	int capacity;
	int* x;
public:
	Array(const int capacity = 5){					//konst
		x = new int[capacity];
		size = 0;
		this->capacity = capacity;
	}
	Array(const Array &a){			//copy konst
		size = a.size;
		capacity = a.capacity;
		x = new int [capacity];
		for(int i = 0 ; i<size ; i++)
			x[i] = a.x[i];
	}
	Array operator=(const Array &a){
		if (this == &a) 
			return *this;
		size = a.size;
		capacity = a.capacity;
		delete [] x;
		x = new int[capacity];
		for (int i = 0; i < size; ++i)
			x[i] = a.x[i];
		return *this;
	}
	void print () {
		for (int i = 0; i < size; ++i) {
			cout <<x[i] <<" ";
		}
		for (int i = size; i < capacity; ++i) {
			cout <<"- ";
		}
		cout << endl;
	}
	void change(int n, int m){
		for(int i=0;i<size;i++)
			if(x[i]==n)
				x[i] = m;
	}
	void deleteAll(int n){
		int newSize = 0;
		for(int i=0,j=0 ; i<size ; i++)
			if(x[i] != n){
				x[j] = x[i];
				j++;
				newSize++;
			}
		size = newSize;
	}
	void add(int n){
		if(capacity == size){
			int *y = new int [2 * capacity];
			for(int i = 0 ; i<size ; i++)
				y[i] = x[i];
			delete[] x;
			x = y;
			capacity = capacity * 2;
		}
		x[size] = n;
		size++;
	}
	~Array(){
		delete[] x;
	}
};


int main(){
	Array a;
	a.add(6);
	a.add(4);
	a.add(3);
	a.add(2);
	a.add(1);
	Array b(a);			//copy konst called
	Array c;
	c = a;				//asingment operator called
	b.add(2);
	b.change(2, 6);
	c.deleteAll(6);
	cout << "a: ";
	a.print();
	cout << "b: ";
	b.print();
	cout << "c: ";
	c.print();
	return 0;
}
*/

/*
class WebPage {
private :
	char url [100];
	char* sodrzina;
public:
	WebPage (char* url = "", char* sodrzina = ""){
		strcpy(this -> url, url);
		this -> sodrzina = new char [strlen(sodrzina) + 1];
		strcpy(this -> sodrzina, sodrzina);
	}
	WebPage (const WebPage& wp) {
		strcpy(this->url , wp.url );
		this-> sodrzina = new char [strlen (wp.sodrzina) + 1];
		strcpy(this->sodrzina, wp.sodrzina );
	}
	~WebPage () {
		delete [] sodrzina ;
	}
	bool daliIsti(WebPage& wp){
		return strcmp(url, wp.url) == 0;
	}
	WebPage& operator= (WebPage& wp) {
		if (this != &wp) {
			strcpy (this -> url , wp.url);
			delete [] sodrzina ;
			this -> sodrzina = new char [strlen(wp.sodrzina) + 1];
			strcpy(this -> sodrzina, wp.sodrzina);
		}
		return *this ;
	}
	friend class WebServer; //prijatelska klasa
};

class WebServer {
private:
	char ime [30];
	int count ;
	WebPage* wp;
public:
	WebServer (char * ime = "", int count = 0, WebPage *wp = 0) {
		strcpy(this ->ime, ime);
		this-> count = count ;
		this->wp = new WebPage [count];
		for (int i = 0; i < count ; i++)
			this->wp[i] = wp[i];
	}
	WebServer(const WebServer &ws) {
		strcpy (this->ime, ws.ime );
		this -> count = ws.count ;
		this -> wp = new WebPage[count];
		for (int i = 0; i < count ; i++)
			this -> wp[i] = ws.wp[i];
	}
	WebServer& operator= (const WebServer &ws) {
		if (this != &ws) {
			strcpy (this ->ime, ws.ime );
			this -> count = ws.count ;
			delete [] this -> wp;
			this -> wp = new WebPage[count];
			for (int i = 0; i < count; i++)
				this ->wp[i] = ws.wp[i];
		}
		return *this ;
	}
	~WebServer(){
		delete [] wp;
	}
	WebServer& addPage(WebPage webPage){
		WebPage * tmp = new WebPage [count + 1]; //alociraj nova memorija so kapacitet za eden povekje od prethodno
		for (int i = 0; i < count; i++)
			tmp [i] = wp[i];
		tmp[count] = webPage ; //vmetni ja novata veb strana (webPage)
		count++;
		delete [] wp;
		wp = tmp;
		return *this ;				//?????
	}
	WebServer& deletePage(WebPage webPage){
		int newCount = 0;
		for (int i = 0; i < count; i++)
			if (!wp[i].daliIsti(webPage))
				newCount++;
		WebPage* tmp = new WebPage[newCount];//po brishenjeto kje ima newCount elementi
		newCount = 0;
		for (int i = 0; i < count; i++)
			if (!wp[i].daliIsti(webPage))
				tmp[newCount++] = wp[i];
		delete [] wp;
		wp = tmp;
		count = newCount ;
		return *this;				//?????
	}
	void listPages(){
		cout << "Number: " << count << endl;
		for (int i = 0; i < count; i++)
			cout << wp[i].sodrzina << "- " << wp[i].url << endl ; //direkten pristap do sodrzina i url
	}
};


int main () {
	WebPage wp1 ("http://www.google.com", "The search engine");
	WebPage wp2 ("http://www.finki.ukim.mk", "FINKI");
	WebPage wp3 ("http://www.time.mk", "Site vesti");
	WebServer ws;
	ws.addPage(wp1);
	ws.addPage(wp2);
	ws.addPage(wp3);
	ws.listPages();
	cout << "\nAfter delete: \n";
	ws.deletePage(wp3);
	ws.listPages();
	return 0;
}
*/
