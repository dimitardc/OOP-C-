#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Igrachka {
public:
    virtual float getVolumen() = 0;
    virtual float getMasa() = 0;
    //дополнително барање 1
	virtual float getPlostina() = 0;
};

class Forma {
protected:
    char boja[100];
    int gustina;
public:
    // да се имплементираат потребните методи
	Forma(char* boja, int gustina){
		strcpy(this->boja, boja);
		this->gustina = gustina;
	}
};

class Kocka: public Forma, public Igrachka{
protected:
	int visina;
	int shirina;
	int dlabochina;
public:
	Kocka(char * boja, int gustina, int visina, int shirina, int dlabochina) : Forma(boja, gustina){
		this->visina = visina;
		this->shirina = shirina;
		this->dlabochina = dlabochina;
	}
	float getVolumen(){
		return visina*shirina*dlabochina;
	}
	float getMasa(){
		return visina*shirina*dlabochina*gustina;
	}
	float getPlostina(){
		return 6*visina*visina;
	}
};

class Topka: public Forma, public Igrachka{
protected:
	int radius;
public:
	Topka(char* boja, int gustina, int radius) : Forma(boja, gustina){
		this->radius = radius;
	}
	float getVolumen(){
		return 4.0/3*3.14*radius*radius*radius;
	}
	float getMasa(){
		return 4.0/3*3.14*radius*radius*radius*gustina;
	}
	float getPlostina(){
		return 4*3.14*radius*radius;
	}
};

void pecati(float masaPetra, Igrachka** niza, int n){
	float vkMasa = 0;
	for(int i = 0;i<n;i++)
		vkMasa += niza[i]->getMasa();
	if(vkMasa > masaPetra)
		cout<<"DA"<<endl;
	else
		cout<<"NE"<<endl;
}

float maxVolumen(Igrachka ** niza, int n){
	float max = 0;
	for(int i = 0;i<n;i++)
		if(niza[i]->getVolumen() > max)
			max = niza[i]->getVolumen();
	return max;
}

float minPlostina(Igrachka ** niza, int n){
	float min = 99999;
	for(int i = 0;i<n;i++)
		if(niza[i]->getPlostina() < min)
			min = niza[i]->getPlostina();
	return min;
}


int main(){
	int n, param;
	cin>>n;
	Igrachka **kupche = new Igrachka*[n];
	char boja[100];
	int gustina,radius,shirina,visina,dlabochina;
	for(int i = 0;i<n;i++){
		cin>>param;
		if(param == 1){ // vnesi topka
			cin>>boja>>gustina>>radius;
			kupche[i] = new Topka(boja,gustina,radius);
		}
		else{
			cin>>boja>>gustina>>visina>>shirina>>dlabochina;
			kupche[i]=new Kocka(boja,gustina,visina,shirina,dlabochina);
		}
	}
	cin>>boja>>gustina>>visina>>shirina>>dlabochina;
	Kocka petra(boja,gustina,visina,shirina,dlabochina);
	
	pecati(petra.getMasa(),kupche,n);
	
	cout<<"Razlikata e: "<<abs(petra.getMasa() - maxVolumen(kupche, n));
	
	cout<<"Razlikata e: "<<abs(petra.getPlostina() - minPlostina(kupche, n));
}
