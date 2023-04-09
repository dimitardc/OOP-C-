#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*																								1
class Array{
private:
	int *x;
	int size;
	int capacity;
public:
	Array(){
		capacity = 5;
		size = 0;
		x = new int[capacity];
	}
	Array(const Array &a){								//copy const
		capacity = a.capacity;
		size = a.size;
		x = new int[capacity];
		for(int i = 0; i < size; i++)
			x[i] = a.x[i];
	}
	Array& operator=(const Array &a){					//assigment operator
		capacity = a.capacity;
		size = a.size;
		delete [] x;
		x = new int[capacity];
		for(int i = 0; i < size; i++)
			x[i] = a.x[i];
		return *this;
	}
	
	Array& operator +=(int n){							//add operator
		if(capacity == size){
			int *y = new int[2*capacity];
			for(int i = 0 ; i< size ; i++)
				y[i] = x[i];
			delete [] x;
			x = y;
			capacity = 2*capacity;
		}
		x[size] = n;
		size++;
		return *this;
	}
	Array& operator -=(int n){						//subtract operator
		int newsize = 0;
		for(int i = 0 , j = 0 ; i<size ; i++)
			if(x[i]!=n){
				x[j] = x[i];
				j++;
				newsize++;
			}
		size = newsize;
		return *this;
	}
	friend ostream& operator<<(ostream &out, Array &a);		//print operator
	~Array(){
		delete [] x;
	}
	int getSize(){
		return size;
	}
	int getCap(){
		return capacity;
	}
	int *getX(){
		return x;
	}
};

ostream& operator<<(ostream &out, Array &a){
	for(int i = 0 ; i<a.getSize() ; i++)
		out << a.getX()[i] << " ";
	for(int i = a.getSize() ; i<a.getCap() ; i++)
		out <<"- ";
	out<<endl;
	return out;
}


int main(){
	Array a;
	a += (6);
	a += (4);
	a += (3);
	a += (2);
	a += (1);
	Array b(a);
	b -= (2);
	b -= (3);
	cout << " a: " << a;
	cout << " b: " << b;
	return 0;
}
*/

/*																										2
class Array{
private:
	int *x;
	int size;
	int capacity;
public:
	Array(){
		capacity = 5;
		size = 0;
		x = new int[capacity];
	}
	Array(const Array &a){								//copy const
		capacity = a.capacity;
		size = a.size;
		x = new int[capacity];
		for(int i = 0; i < size; i++)
			x[i] = a.x[i];
	}
	Array& operator=(const Array &a){					//assigment operator
		capacity = a.capacity;
		size = a.size;
		delete [] x;
		x = new int[capacity];
		for(int i = 0; i < size; i++)
			x[i] = a.x[i];
		return *this;
	}
	
	Array& operator +=(int n){							//add operator
		if(capacity == size){
			int *y = new int[2*capacity];
			for(int i = 0 ; i< size ; i++)
				y[i] = x[i];
			delete [] x;
			x = y;
			capacity = 2*capacity;
		}
		x[size] = n;
		size++;
		return *this;
	}
	Array& operator -=(int n){						//subtract operator
		int newsize = 0;
		for(int i = 0 , j = 0 ; i<size ; i++)
			if(x[i]!=n){
				x[j] = x[i];
				j++;
				newsize++;
			}
		size = newsize;
		return *this;
	}
	
	int& operator[](int index){
		int pom = -1;
		if(index >=0 && index < size)
			return x[index];
		else{
			cout<<"Nadvor od opseg"<<endl;
			return pom;
		}
	}
	bool operator==(const Array &a){
		if(this->size != a.size)
			return false;
		for(int i = 0; i < size; i++)
			if(x[i]!=a.x[i])
				return false;
		return true;
	}
	friend ostream& operator<<(ostream &out, Array &a);		//print operator
	~Array(){
		delete [] x;
	}
	int getSize(){
		return size;
	}
	int getCap(){
		return capacity;
	}
	int *getX(){
		return x;
	}
};

ostream& operator<<(ostream &out, Array &a){
	for(int i = 0 ; i<a.getSize() ; i++)
		out << a.getX()[i] << " ";
	for(int i = a.getSize() ; i<a.getCap() ; i++)
		out <<"- ";
	out<<endl;
	return out;
}


int main(){
	Array a;
	a += (6);
	a += (4);
	a += (3);
	a += (2);
	a += (1);
	Array b(a);
	b -= (2);
	b -= (3);
	a[0] = 9; 							//primena na operatorot []
	cout << " a: " << a;
	cout << " b: " << b;
	if (a == b) cout << "Isti se";		//primena na operatorot ==
	else cout << "Ne se isti";
	return 0;
}
*/

/*																							3
class Complex{
private:
	float a;
	float b;
public:
	Complex(){
		a = 0;
		b = 0;
	}
	Complex(float a, float b){
		this->a = a;
		this->b = b;
	}
	Complex operator+(const Complex &c){		//c = c1+c2
		Complex res(a + c.a, b + c.b);
		return res;
	}
	Complex operator-(const Complex &c){
		Complex res(a - c.a, b - c.b);
		return res;
	}
	Complex operator*(const Complex &c){						//
		return Complex(a * c.a - b * c.b, b * c.a - a * c.b);
	}
	Complex operator/(const Complex &c){
		float m = c.a*c.a + c.b*c.b;
		float r = (a * c.a - b * c.b) / m;
		return Complex(r, (b * c.a + b * c.b) / m);
	}
	Complex &operator+=(const Complex &c){
		a += c.a;
		b += c.b;
		return *this;
	}
	Complex &operator-=(const Complex &c){
		a -= c.a;
		b -= c.b;
		return *this;
	}
	Complex &operator*=(const Complex &c){
		a = a * c.a - b * c.b;
		b = b * c.a - a * c.b;
		return *this;
	}
	Complex &operator/=(const Complex &c){
		*this = *this/c;
		return *this;
	}
	bool operator==(const Complex &c){
		return a == c.a && b == c.b;
	}
	float getA(){
		return a;
	}
	float getB(){
		return b;
	}
	Complex operator+(float n) {													//c = c1 + n
		Complex res(a + n, b);
		return res;
	}
	friend Complex operator+(float n,const Complex &c);			//global			c = n + c1

	friend ostream &operator<<(ostream &x, const Complex &c);		//global
};

Complex operator+(float n,const Complex &c){
		Complex res(c.a + n, c.b);
		return res;
}

ostream &operator<<(ostream &x, const Complex &c) {
	x << c.a;
	if(c.b >= 0)
		x << "+";
	x << c.b << "j";
	return x;
}



int main(){
	Complex c1(2, -6);
	Complex c2(3, 5);
	Complex c = c1 + c2;
	cout << c1 << " + " << c2 << " = " << c << endl;
	c = c1 - c2;
	cout << c1 << " - " << c2 << " = " << c << endl;
	c = c1 * c2;
	cout << c1 << " * " << c2 << " = " << c << endl;
	c = c1 / c2;
	cout << c1 << " / " << c2 << " = " << c << endl;
	if (c == c1) {
		cout << "Numbers are equal" << endl;
	}
	c = c1 + 2;							//se povikuva vnatreshnata f-ja
	cout << c1 << " + " << 2 << " = " << c << endl;
	c = 2 + c1;							//se povikuva globalnata f-ja
	cout << 2 << " + " << c1 << " = " << c << endl;
	return 0;

}
*/


/*
																						4
class Students{
private:
	char* name;
	float average;
	int year;
public:
	Students(){
		year = 0;
		average = 0;
		name = new char[0];
	}
	Students(const char *name, float average, int year){
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		this->average = average;
		this->year = year;
	}
	Students(const Students &s){								//copy const
		name = new char[strlen(s.name)+1];
		strcpy(this->name,s.name);
		this->average = s.average;
		this->year = s.year;
	}
	Students& operator=(const Students &s){						//= operator
		delete [] name;
		name = new char[strlen(s.name)+1];
		strcpy(this->name,s.name);
		this->average = s.average;
		this->year = s.year;
		return *this;
	}
	~Students(){
		delete [] name;
	}
	Students& operator++(){								//prefiks
		year++;
		return *this;
	}
	Students operator++(int){							//postfiks
		Students s(*this);
		year++;
		return s;
	}
	float getAverage(){
		return average;
	}
	friend ostream& operator<<(ostream& out, const Students &s){					//operator << stalno e friend
		out << "Ime:" << s.name << ", godina:" << s.year << ",prosek:" << s.average<< endl;
		return out;
	}
	bool operator>(const Students &s){
		return (average > s.average);
	}
};



class Paralelka{
private:
	Students* list;
	int total;
public:
	Paralelka(){
		total = 0;
		list = new Students[0];
	}
	Paralelka(int total){
		this->total = total;
		list = new Students[total];
	}
	Paralelka(const Paralelka &p){				//copy const
		this->total = p.total;
		list = new Students[total];
		for(int i = 0 ; i<total ; i++)
			list[i] = p.list[i];
	}
	Paralelka& operator+=(Students s){
		Students* tmp = new Students[total + 1];
		for(int i = 0 ; i<total ; i++)
			tmp[i] = list[i];
		tmp[total++] = s;
		delete [] list;
		list = tmp;
		return *this;
	}
	Paralelka& operator++(){						//prefiks
		for(int i = 0 ; i < total ; i++)
			++list[i];
		return *this;
	}
	Paralelka operator++(int){						//postfiks
		Paralelka p(*this);
		for(int i = 0 ; i < total ; i++)
			list[i]++;
		return p;
	}
	friend ostream& operator<<(ostream &out, const Paralelka &p){
		for(int i = 0 ; i <p.total ; i++)
			out << p.list[i];											//Students << operator called
		return out;
	}
	void nagradi(){
		for(int i = 0; i<total ; i++)
			if(list[i].getAverage() == 10.0)
				cout<<list[i];
	}
	void najvisokProsek(){
		float temp = list[0].getAverage();
		for(int i = 0 ; i < total ; i++){
			if(list[i].getAverage() > temp)
				temp = list[i].getAverage();
		}
		cout<<"Najvisokiot Prosek e: "<<temp;
	}
	~Paralelka(){
		delete [] list;
	}
};

int main (){
	Students u1("Martina Martinovska", 9.5, 3);
	Students u2("Darko Darkoski", 7.3, 2);
	Students u3("Angela Angelovska", 10, 3);
	Paralelka p;
	p += u1;
	p += u2;
	p += u3;
	cout << p;							//Paralelka << operator called
	cout << "Nagradeni:" << endl;
	p.nagradi();
	cout << endl;
	p.najvisokProsek();
	cout << endl;
	u2++;
	cout << p;
	cout << endl;
	p++;
	cout << p;
	return 0;
}

*/