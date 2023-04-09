#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


/*
class InvalidPassword{
public:
	char text[30];
	InvalidPassword(const char*text){
		strcpy(this->text, text);
	}
	void print(){
		cout<<text<<endl;
	}
};

class InvalidEmail{
public:
	char text[30];
	InvalidEmail(const char*text){
		strcpy(this->text, text);
	}
	void print(){
		cout<<text<<endl;
	}
};


class MaximumSizeLimit{
public:
	int n;
	MaximumSizeLimit(int n){
		this->n = n;
	}
	void print(){
		cout<<"you cant add more than "<<n<<" users."<<endl;
	}
};

class User{
private:
	char username [50];
	char password[50];
	char email[50];
public:
	User(char* username, char* password, char* email){
		int lower = 0,upper = 0,number = 0,special=0;
		for(int i = 0;i<strlen(password);i++){
			if(islower(password[i]))
				lower++;
			if(isupper(password[i]))
				upper++;
			if(isdigit(password[i]))
				number++;
		}
		for(int i = 0;i<strlen(email);i++)
			if(email[i] == '@')
				special++;
		if(lower == 0 || upper == 0 || number == 0)
			throw InvalidPassword("Password too weak");
		if(special != 1)
			throw InvalidEmail("Mail is not valid");
		
		strcpy(this->username, username);
		strcpy(this->password, password);
		strcpy(this->email, email);
	}
	virtual double popularity () = 0;
};

class FacebookUser : public User{
private:
	int likes;
	int friends;
	int comments;
public:
	FacebookUser(char * username, char * password, char * email, int friends, int likes, int comments) : User(username,password,email){
		this->friends = friends;
		this->likes=  likes;
		this->comments = comments;
	}
	double popularity(){
		return (double)friends + likes*0.1 + comments*0.5;
	}
};

class TwitterUser : public User{
private:
	int followers;
	int tweets;
public:
	TwitterUser(char * username, char * password, char * email, int followers, int tweets) : User(username,password,email){
		this->followers = followers;
		this->tweets = tweets;
	}
	double popularity(){
		return followers + tweets*0.5;
	}
};

class SocialNetwork{
private:
	User **niza;
	int elems;
	static int max;
public:
	SocialNetwork(){
		niza = new User*[0];
		elems = 0;
	}
	SocialNetwork(User **niza, int elems){
		this->elems = elems;
		this->niza = new User*[elems];
		for(int i =0;i<elems;i++)
			this->niza[i] = niza[i];
	}
	SocialNetwork& operator+=(User *k){
		if(elems < max){
			User** temp = new User*[elems+1];
			for(int i = 0;i<elems;i++)
				temp[i] = niza[i];
			temp[elems] = k;
			elems++;
			delete [] niza;
			niza = temp;
		}
		else 
			throw MaximumSizeLimit(max);
		return *this;
	}
	double avgPopularity(){
		double total = 0;
		for(int i=0;i<elems;i++)
			total += niza[i]->popularity();
		total /= elems;
		return total;
	}
	~SocialNetwork(){
		delete [] niza;
	}
	static void changeMaximumSize(int k){
		max = k;
	}
};

int SocialNetwork :: max = 5;

int main() {
  SocialNetwork network = SocialNetwork();
	int n;
	cin >> n;
	char username[50];
	char password[50];
	char email[50];
	int userType;
	for (int i=0; i < n; ++i) {
	  cin >> username;
	  cin >> password;
	  cin >> email;
	  cin >> userType;
	  if (userType == 1) {
		int friends;
		int likes;
		int comments;
		cin >> friends >> likes >> comments;
		  
		// TODO: Try-catch
		try{
			User * u = new FacebookUser(username,password,email,friends,likes,comments);
			network += u;
		}
		catch(InvalidPassword i){
			i.print();
		}
		catch(InvalidEmail i){
			i.print();
		}
		catch(MaximumSizeLimit i){
			i.print();
		}
	  }
	  else {
		int followers;
		int tweets;
		cin >> followers >> tweets;
		  
		// TODO: Try-catch
		try{
			User * u= new TwitterUser(username,password,email,followers,tweets);
			network += u;
		}
		catch(InvalidPassword i){
			i.print();
		}
		catch(InvalidEmail i){
			i.print();
		}
		catch(MaximumSizeLimit i){
			i.print();
		}
	  }

	}
	network.changeMaximumSize(6);
	cin >> username;
	cin >> password;
	cin >> email;
	int followers;
	int tweets;
	cin >> followers >> tweets;
	
	// TODO: Try-catch
	User * u= new TwitterUser(username,password,email,followers,tweets);
	network += u;
	
	cout << network.avgPopularity();
}
*/

 
class InvalidDateException {
private:
	int day;
	int month;
	int year;
public:
	InvalidDateException(int d, int m, int y) {
		day=d;
		month=m;
		year=y;
	}
	void message() {
		cout<<"Invalid Date "<<day<<"/"<<month<<"/"<<year<<endl;
	}
};
 
class NotSupportedCurrencyException {
private:
	char currency [3];
public:
	NotSupportedCurrencyException(char * c){
		strcpy(currency,c);
	}
	void message() {
		cout<<currency<<" is not a supported currency"<<endl;
	}
};
 
class Transakcija {
protected:
	int den;
	int mesec;
	int godina;
	double iznos;
	static double EUR;
	static double USD;
public:
	Transakcija(int den, int mesec, int godina, double iznos) {
		if (den<1 || den > 31 || mesec<1 || mesec > 12)
			throw InvalidDateException(den,mesec,godina);
		this->den=den;
		this->mesec=mesec;
		this->godina=godina;
		this->iznos=iznos;
	}
	Transakcija(const Transakcija &t){
		this->den=t.den;
		this->mesec=t.mesec;
		this->godina=t.godina;
		this->iznos=t.iznos;
	}
	static void setEUR(double eur) {
		EUR=eur;
	}
	static void setUSD(double usd){
		USD=usd;
	}
	static double getEUR() {
		return EUR;
	}
	static double getUSD() {
		return USD;
	}
	virtual double voDenari() = 0;
	virtual double voEvra() = 0;
	virtual double voDolari() = 0;
	virtual void pecati() = 0; 
};
 
double Transakcija::EUR = 61.0;
double Transakcija::USD = 50.0;
 
class DenarskaTransakcija : public Transakcija {
	public:
	DenarskaTransakcija(int den, int mesec, int godina, double iznos): Transakcija(den,mesec,godina,iznos){
		
	}
	double voDenari() {
		return iznos;
	}
	double voEvra() {
		return iznos/EUR;
	}
	double voDolari() {
		return iznos/USD;
	}
	void pecati() {
		cout<<this->den<<"/"<<this->mesec<<"/"<<this->godina<<" "<<this->iznos<<" MKD"<<endl;
	}
};
 
class DeviznaTransakcija : public Transakcija {
private:
	char valuta [4];
public:
	DeviznaTransakcija(int den, int mesec, int godina, double iznos, char * valuta): Transakcija(den,mesec,godina,iznos) {
		if (strcmp(valuta,"USD")==0 || strcmp(valuta,"EUR")==0)
			strcpy(this->valuta,valuta);
		else
			throw NotSupportedCurrencyException(valuta);
	}
	double voDenari() {
		if (strcmp(valuta,"EUR")==0)
			return this->iznos*EUR;
		else
			return this->iznos * USD;
	}
	double voEvra() {
		if (strcmp(valuta,"EUR")==0)
			return this->iznos;
		else
			return (this->iznos * USD) / EUR;
	}
	double voDolari() {
		if (strcmp(valuta,"USD")==0)
			return this->iznos;
		else
			return (this->iznos * EUR) / USD;
	}
	void pecati () {
		if (strcmp(valuta,"EUR")==0)
			cout<<this->den<<"/"<<this->mesec<<"/"<<this->godina<<" "<<this->iznos<<" EUR"<<endl;
		else
			cout<<this->den<<"/"<<this->mesec<<"/"<<this->godina<<" "<<this->iznos<<" USD"<<endl;
	}
};
 
class Smetka {
private:
	Transakcija ** transakcii;
	int brTr;
	double saldo;
	char brSmetka [15];
public:
	Smetka(char * brSmetka, int saldo){
		strcpy(this->brSmetka,brSmetka);
		this->saldo=saldo;
		transakcii = new Transakcija * [0];
		brTr=0;
	}
	Smetka &operator += (Transakcija * t) {
		Transakcija ** temp = new Transakcija * [brTr+1];
		for (int i=0;i<brTr;i++)
			temp[i]=transakcii[i];
		temp[brTr++]=t;
		delete [] transakcii;
		transakcii = temp;
		return *this;
	}
	~Smetka() {
		delete [] transakcii;
	}
	void izvestajVoDenari() {
		double sum = saldo;
		for (int i=0;i<brTr;i++)
			sum+=transakcii[i]->voDenari();
		cout<<"Korisnikot so smetka: "<<brSmetka<<" ima momentalno saldo od "<<sum<<" MKD"<<endl;
	}
	void izvestajVoEvra() {
		double sum = this->saldo / Transakcija::getEUR();
		for (int i=0;i<brTr;i++)
			sum+=transakcii[i]->voEvra();
		cout<<"Korisnikot so smetka: "<<brSmetka<<" ima momentalno saldo od "<<sum<<" EUR"<<endl;
	}
	void izvestajVoDolari() {
		double sum = this->saldo / Transakcija::getUSD();
		//cout<<Transakcija::getUSD();
		for (int i=0;i<brTr;i++)
			sum+=transakcii[i]->voDolari();
		cout<<"Korisnikot so smetka: "<<brSmetka<<" ima momentalno saldo od "<<sum<<" USD"<<endl;
	}
	void pecatiTransakcii() {
		for (int i=0;i<brTr;i++){
			transakcii[i]->pecati();
			//cout<<transakcii[i]->voDenari()<<" "<<transakcii[i]->voEvra()<<" "<<transakcii[i]->voDolari()<<endl;
		}
		   
	}
};
 
int main () {
   
	Smetka s ("300047024112789",1500);
   
	int n, den, mesec, godina, tip;
	double iznos;
	char valuta [3];
   
	cin>>n;
	cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos;
		try{
			if (tip==2){
				cin>>valuta;
				Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);
				s+=t;
				//delete t;
			}
			else {
				Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);
				s+=t;
				//delete t;
			}
		}
		catch (InvalidDateException &e){
			e.message();
		}
		catch (NotSupportedCurrencyException &e){
			e.message();
		}
	   
	   
	   
		//s.pecatiTransakcii();
		   
	}
	cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
	s.pecatiTransakcii();
	cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
	s.izvestajVoDenari();
	cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
	s.izvestajVoEvra();
	cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
	s.izvestajVoDolari();
   
	cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;
   
	   
	double newEUR, newUSD;
	cin>>newEUR>>newUSD;
	Transakcija::setEUR(newEUR);
	Transakcija::setUSD(newUSD);
	cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
	s.izvestajVoDenari();
	cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
	s.izvestajVoEvra();
	cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
	s.izvestajVoDolari();
   
   
   
	return 0;
}