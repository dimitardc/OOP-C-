#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


/*
class Kartichka{
private:
	double saldo;
	char id[16];
public:
	Kartichka(double saldo, char * id){
		this->saldo = saldo;
		strcpy(this->id, id);
	}
	void prikaziSaldo(){
		cout << id<<" : " << saldo<<endl;
	}
	void uplati(double suma){
		saldo += suma;
	}
	virtual double isplati(double suma){
		if(saldo > suma){
			saldo -= suma;
			return suma;
		}
		else
			return 0;
	}
	virtual double isplati(double suma, double limit){
		if(saldo + limit > suma){
			saldo -= suma;
			return suma;
		}
		else
			return 0;
	}
};

class Maestro : public Kartichka{
private:
	char lozinka[10];
	const static double  popust;
public:
	Maestro(char * lozinka, char * id, double saldo) : Kartichka(saldo, id){
		strcpy(this->lozinka, lozinka);
	}
	static double getPopust(){
		return popust;
	}
	double isplati(double cena){
		double suma = cena*(1-popust);
		return Kartichka::isplati(suma);
	}
};

const double Maestro::popust = 0.05;


class Master : public Kartichka{
private:
	double limit;
	const static double popust1;		//fiksen
	static double popust2;				//can be changed
public:
	Master(double limit, char * id, double saldo) : Kartichka(saldo, id){
		this->limit = limit;
	}
	static double getPopust1(){
		return popust1;
	}
	static double getPopust2(){
		return popust2;
	}
	static void setPopust2(double popust2){
		Master::popust2 = popust2;
	}
	double isplati(double cena){
		if(limit<6000){
			double suma = cena*(1-popust1);
			return Kartichka::isplati(suma, limit);
		}
		else{
			double suma = cena*(1 - popust2);
			return Kartichka::isplati(suma, limit);
		}
	}
};

const double Master::popust1 = 0.03; //pri inicijalizacija ne se pisuva klucniot zbor static
double Master::popust2 = 0.1;


class Kasa {
private:
	double sumaVoKasa;
	double sumaOdKartica;
	int den,mesec,godina;
public:
	Kasa(double sumaVoKasa, int den, int mesec, int godina){
		this->sumaVoKasa = sumaVoKasa;
		this->den = den;
		this->mesec = mesec;
		this->godina = godina;
	}
	void kasaPrimi(double smetka){
		sumaVoKasa +=smetka;
	}
	void kasaPrimi(double smetka, Kartichka &k){
		sumaOdKartica = k.isplati(smetka);
	}
	void prikaziKasa(){
		cout << "Den: \t" << den << endl;
		cout << "Mesec: \t" << mesec << endl;
		cout << "Godina: " << godina << endl;
		cout << "Prihod-vkupno: " <<vratiPrihod() << endl;
		cout << endl;
	}
	double vratiPrihod(){
		return sumaOdKartica + sumaVoKasa;
	}
};


int main(){
	Kasa deneshna(10000, 22, 4, 2014);
	Kartichka *k;
	deneshna.prikaziKasa();
	cout << "Primam vo gotovo!" << endl;
	deneshna.kasaPrimi(5000);
	deneshna.prikaziKasa();
	k = new Master(10000.00, "1234567890123456", 54000.00);
	cout << "Primam so kartichka!" << endl;
	deneshna.kasaPrimi(10000.00, *k);
	deneshna.prikaziKasa();
	k = new Maestro("lozinka", "1234567890123456", 54000.00);
	cout << "Primam so kartichka!" << endl;
	deneshna.kasaPrimi(10000, *k);
	deneshna.prikaziKasa();
	Master::setPopust2(0.07);
	k = new Master(10000, "4567891234567890", 3000);
	cout << "Primam so kartichka!" << endl;
	deneshna.kasaPrimi(10000, *k);
	deneshna.prikaziKasa();
	return 0;
}
*/


//klasa za iskluchokot
class NegativeValueException{
private:
	char text[50];
public:
	  NegativeValueException(char *text){
		strcpy(this->text, text);
	  }
	  void print(){
		  cout << text;
	  }
};

class Discount {
public:
	  static float euro;
	  static float dollar;
	  virtual float discount_price() = 0;
	  virtual float price() = 0;
	  virtual void print_rule() = 0;
};

float Discount::euro = 61.7;
float Discount::dollar = 44.5;

class Product {
protected:
	  char name[100];
	  float price;
public:
	Product(const char *name, const float price) {
		strcpy(this->name, name);
		this->price = price;
	}
	float getPrice() {
		return price;
	}
	void print() {
		cout << "Product{ name=" << name << ", price=" << price << "}" << endl;
	}
	void changePrice(float price){
		if (price < 0) 
			throw NegativeValueException("Vnesena e negativna vrednost za cena!\n");
		this->price = price;
	}
};

class Cosmetics : public Product, public Discount {
private:
	int weight;
public:
	Cosmetics(const char *name, const float price,const int weight ) :Product(name, price){
		this->weight = weight;
	}
	float discount_price() {
		if (getPrice() / Discount::dollar > 20)
			return 0.86 * getPrice();
		if (getPrice() / Discount::euro > 5)
			return 0.88 * getPrice();
		return getPrice();
	}
	float price() {
		return getPrice();
	}
	void print_rule(){
		cout << "Site kozmeticki proizvodi poskapi od 5 evra imaat popust od 12%,";
		cout<<"dodeka pak onie koi se poskapi od 20 dolari imaat popust 14%" << endl;
	}
};
class FoodProduct : public Product, public Discount{
private:
	float callories;
public:
	FoodProduct(const char *name , const float price ,const float callories ) : Product(name, price) {
		this->callories = callories;
	}
	float discount_price() {
		return getPrice();
	}
	float price() {
		return getPrice();
	}
	void print_rule(){
		cout << "Nema popust za proizvodite od tip na hrana" << endl;
	}
};

class Drinks : public Product, public Discount {
private:
	char brand[100];
	bool alcoholic;
public:
	Drinks(const char *name , const float price,const char *brand , const bool alcoholic ) : Product(name, price) {
		strcpy(this->brand, brand);
		this->alcoholic = alcoholic;
	}
	float discount_price() {
		if (this->alcoholic && (getPrice() / Discount::euro > 20))
			return 0.95 * getPrice();
		if (!this->alcoholic && (strcmp(this->brand, "Coca-Cola") == 0))
			return 0.90 * getPrice();
		return getPrice();
	}
	float price(){ 
		return getPrice(); 
	}
	void print_rule(){
		cout << "Site alkoholni pijaloci poskapi od 20 evra imaat popust od 5 % ,";
		cout<<"dodekapak nealkoholnite od brendot Coca - Cola imaat popust od 10 % "<<endl;
  }
};

float total_discount(Discount **d, int n) {
	float discount = 0;
	for (int i = 0; i < n; ++i) {
		discount += d[i]->discount_price();
		cout << "Prvicna cena: " << d[i]->price() << endl;
		cout << "So popust: " << d[i]->discount_price() << endl;
		d[i]->print_rule();
	}
	return discount;
}



int main() {
  int n = 0;
  float newPrice;
  Discount **d = new Discount*[10];
  d[n++] = new FoodProduct("leb", 30);
  d[n++] = new Drinks("viski", 1350, "Jack Daniel's", true);
  d[n++] = new FoodProduct("sirenje", 390, 105);
  d[n++] = new Drinks("votka", 850, "Finlandia", true);
  d[n++] = new Cosmetics("krema", 720, 100);
  d[n++] = new Drinks("sok", 50, "Coca-Cola", false);
  d[n++] = new Cosmetics("parfem", 3500, 50);
  cout << "Vkupnata cena na site proizvodi e: " << total_discount(d, n) << endl;
  //se menuva cenata na site Kozmeticki proizvodi
  cout << "Promena na cenata na kozmetickite proizvodi " << endl;
  for (int i = 0; i < n; ++i) {
	Cosmetics* c = dynamic_cast<Cosmetics *>(d[i]);
	if (c != 0){
		c->print();
		cin >> newPrice;
		try{
			c->changePrice(newPrice);
		}
		catch (NegativeValueException i){
			i.print();
		}
	}
  }
  for (int i = 0; i < n; ++i) {
	delete d[i];
  }
  delete[] d;
  return 0;
}