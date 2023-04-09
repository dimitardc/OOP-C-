#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

/*
class Vehicle{
protected:
	double acceleration;
public:
	Vehicle(){
		cout<<"Vehicle Constructor"<<endl;
	}
	virtual ~Vehicle(){
		cout<<"Vehicle Destructor"<<endl;
	}
	virtual void accelerate() const{
		cout<<"Vehicle Accelerating"<<endl;
	}
	void setAcceleration(double a) {
		acceleration = a;
	}
	double getAcceleration() const {
		return acceleration;
	}
};

class Car :virtual public Vehicle {
public:
	Car(){
		cout << "Car Constructor" << endl;
	}
	virtual void accelerate() const {
		cout << "Car Accelerating" << endl;
	}
	virtual void drive() const {
		cout << "Car Driving" << endl;
	}
	virtual ~Car() {
		cout << "Car Destructor" << endl;
	}
};

class Jet :virtual public Vehicle {
public:
	Jet() {
		cout << "Jet Constructor" << endl;
	}
	virtual ~Jet() {
		cout << "Jet Destructor" << endl;
	}
	virtual void fly() const {
		cout << "Jet flying" << endl;
	}
};

class JetCar: public Car, public Jet{
public:
	JetCar(){
		cout << "JetCar Constructor" << endl;
	}
	virtual ~JetCar(){
		cout<< "JetCar Destructor"<<endl;
	}
	virtual void drive() const {
		cout << "JetCar driving" << endl;
	}
	virtual void fly() const {
		cout << "JetCar flying" << endl;
	}

};

void analyzeCarPerformance(Car *testVehicle) {
  testVehicle->drive();
  //функцијата drive() може да се повика и со покажувач кон основната и
  //кон изведената класа. Oваа функција е дефинирана и во двете класи
}
void analyzeJetPerformance(Jet *testVehicle) {
  testVehicle->fly();
  //fly() е дефинирана и во основната и во изведената класа (Јет и JetCar)
}

int main() {
  Car myCar;
  Jet myJet;
  JetCar myJetCar;
  cout << endl << endl;
  cout << "Car testing in progress" << endl;
  analyzeCarPerformance(&myCar);
  analyzeCarPerformance(&myJetCar);
  cout << "Jet testing in progress" << endl;
  analyzeJetPerformance(&myJet);
  analyzeJetPerformance(&myJetCar);
  cout << endl << endl;
  return 0;
}
*/



class Discount{
public:
	virtual float getDiscount_price() = 0;
	virtual float getPrice() = 0;
	virtual ~Discount()		{}
};

class Product{
protected:
	char name[100];
	float price;
public:
	Product(const char * name, float price){
		strcpy(this->name, name);
		this->price = price;
	}
	float getPrice(){
		return price;
	}
};

class DigitalProduct: public Product, public Discount{
protected:
	float size;
public:
	DigitalProduct(const char *name, float price, float size) : Product(name,price){
		this->size = size;
	}
	float getDiscount_price(){
		return 0.9*getPrice();
	}
	float getPrice(){
		return Product::getPrice();
	}
};

class FoodProduct: public Product, public Discount{
protected:
	float callories;
public:
	FoodProduct(const char* name, float price, float callories)  : Product(name,price){
		this->callories = callories;
	}
	float getDiscount_price(){
		return 0.8*getPrice();
	}
	float getPrice(){
		return Product::getPrice();
	}
};

float total_discount(Discount **d,int n){
	float price = 0;
	for(int i = 0; i<n;i++){
		price+= d[i]->getPrice();
	}
	float discount = 0;
	for(int i =0;i<n;i++)
		discount+=d[i]->getDiscount_price();
	return price - discount;
}


int main() {
  Discount **d = new Discount*[3];
  d[0] = new FoodProduct("Cheese", 450, 1200);
  d[1] = new FoodProduct("Wine", 780, 250);
  d[2] = new DigitalProduct("WOW", 380, 400);
  cout << "Difference: " << total_discount(d, 3) << endl;
  for (int i = 0; i < 3; ++i) {
  delete d[i];
  }
  delete[] d;
  return 0;
}
