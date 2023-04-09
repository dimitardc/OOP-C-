#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*
class Agol{
private:
	int stepeni;
	int minuti;
	int sekundi;
public:
	Agol()		{}
	Agol(int stepeni, int minuti, int sekundi){
		this->stepeni = stepeni;
		this->minuti = minuti;
		this->sekundi = sekundi;
	}
	void setStepeni(int stepeni){
		this->stepeni = stepeni;
	}
	void setMinuti(int minuti){
		this->minuti = minuti;
	}
	void setSekundi(int sekundi){
		this->sekundi = sekundi;
	}
	int getStepeni(){
		return stepeni;
	}
	int getMinuti(){
		return minuti;
	}
	int getSekundi(){
		return stepeni*3600+minuti*60+sekundi;
	}
};

bool proveri(int a, int b, int c){
	if(a<360 && b>0 && b<60 && b>0 && c<60 && c>=0){
		return 1;
	}
	else
		return 0;
}

int main(){
	Agol a;
	int deg,min,sec;
	cin>>deg>>min>>sec;
	if(proveri(deg,min,sec)){
		a.setStepeni(deg);
		a.setMinuti(min);
		a.setSekundi(sec);
	}
	return 0;
}
*/

/*
class Krug{
private:
	float radius;
	static const float PI = 3.15;
public:
	Krug()		{}
	Krug(float radius){
		this->radius = radius;
	}
	float plostina(){
		return radius*radius*PI;
	}
	float perimetar(){
		return 2*radius*PI;
	}
	bool comp(){
		if(plostina() == perimetar())
			return true;
		else
			return false;
	}
};

int main(){
	float r;
	cin >> r;
	Krug k(r);
	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.comp() << endl;
}
*/

/*
class Film{
private:
	char name[100];
	char director[50];
	char genre[50];
	int year;
public:
	Film()		{}
	Film(char* name, char* director, char* genre,  int year){
		strcpy(this->name, name);
		strcpy(this->director, director);
		strcpy(this->genre, genre);
		this->year  = year;
	}
	void setName(char* name){
		strcpy(this->name, name);
	}
	void setDir(char* director){
		strcpy(this->director, director);
	}
	void setGen(char* genre){
		strcpy(this->genre, genre);
	}
	void setYear(int year){
		this->year  = year;
	}
	int getYear(){
		return year;
	}
	char *getName(){
		return name;
	}
};

void pecati_po_godina(Film f[], int n, int godina){
	for(int i = 0; i<n;i++)
		if(godina == f[i].getYear())
			cout<<f[i].getName();
}

int main(){
	Film f[50];
	int n;
	cin>>n;
	for(int i = 0; i<n;i++){
		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
		f[i].setName(ime);
		f[i].setDir(reziser);
		f[i].setGen(zanr);
		f[i].setYear(godina);
	}
	int godina;
	cin>>godina;
	pecati_po_godina(f,n,godina);
	return 0;
}
*/