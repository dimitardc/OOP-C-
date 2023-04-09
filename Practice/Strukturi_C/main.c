#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

/*
struct a{
	int i;
	char niza[80];
}s,*p;

int main(){
	//struct a s;
	//struct a *p;
	p = &s;
	s.i = 10;
	p->i = 30;
	strcpy(p->niza, "Mnogu sakam strukturi");
	printf("%d %d %s\n", s.i, p->i, p->niza);
}
*/

/*
//definicija na struktura karta

struct karta{
	char *brojka;
	char *boja;
};

int main(){
	struct karta aCard;
	struct karta *cardPtr;
	
	aCard.brojka = "As";
	aCard.boja = "Detelina";
	cardPtr = &aCard;
	
	printf("%s%s%s\n", aCard.brojka," ",aCard.boja);
	printf("%s%s%s\n", cardPtr->brojka," ",cardPtr->boja);
	printf("%s%s%s\n", (*cardPtr).brojka," ",(*cardPtr).boja);
	//they all do the same
}
*/

//~~~~~~~~~~~~~~~~~~~~~~AUD 
/*																1
struct date{
	int year;
	int month;
	int day;
};
typedef struct date date;

int compare(date d1, date d2){
	if(d1.year > d2.year)
		return 1;
	else if(d1.year < d2.year)
		return -1;
	else{
		if(d1.month > d2.month)
			return 1;
		else if(d1.month < d2.month)
			return -1;
		else{
			if(d1.day > d2.day)
				return 1;
			else if(d1.day < d2.day)
				return -1;
			else
				return 0;
		}
	}
}

int days(date d1, date d2){
	int days = d1.day - d2.day;
	days += (d1.month - d2.month) *30;
	days += (d1.year - d2.year) *365;
	return days;
}

void read(date *d){
	scanf("%d%d%d", &d->day, &d->month,&d->year);
}	

int main(){
	date d1,d2;
	read(&d1);
	read(&d2);
	int res = compare(d1,d2);
	if(res == 0)
		printf("dates are equal\n");
	else if(res>0)
		printf("the difference in days is %d days\n",days(d1,d2));
	else
		printf("the difference in days is %d days\n",-days(d1,d2));
	return 0;
}
*/

/*																	1.1
struct date{
	int year;
	int month;
	int day;
};
//typedef struct date date; // namesto 'struct date' mozeme da koristime samo 'date'

int compare(struct date d1,struct  date d2){
	if(d1.year > d2.year)
		return 1;
	else if(d1.year < d2.year)
		return -1;
	else{
		if(d1.month > d2.month)
			return 1;
		else if(d1.month < d2.month)
			return -1;
		else{
			if(d1.day > d2.day)
				return 1;
			else if(d1.day < d2.day)
				return -1;
			else
				return 0;
		}
	}
}

int days(struct date d1,struct date d2){
	int days = d1.day - d2.day;
	days += (d1.month - d2.month) *30;
	days += (d1.year - d2.year) *365;
	return days;
}

int main(){
	struct date d1;
	struct date d2;
	scanf("%d%d%d", &d1.day, &d1.month, &d1.year);
	scanf("%d%d%d", &d2.day, &d2.month, &d2.year);
	int res = compare(d1,d2);
	if(res == 0)
		printf("dates are equal\n");
	else if(res>0)
		printf("the difference in days is %d days\n",days(d1,d2));
	else
		printf("the difference in days is %d days\n",-days(d1,d2));
	return 0;
}
*/

/*													2
struct vector{
	float x,y,z;
};
//typedef struct vector vector;

float scalar_product(struct vector v1,struct vector v2) {
	return v1.x * v2.x + v1.y + v2.y + v1.z * v2.z;
}

struct vector vec_prod(struct vector v1,struct vector v2){
	struct vector v;
	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return v;
}

int main(){
	struct vector v1 = {2,4,6};
	struct vector v2 = {3,5,9};
	struct vector v = vec_prod(v1,v2);
	printf("v1 * v2 = %.2f\n", scalar_product(v1, v2));
	printf("v1 x v2 = [%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
}
*/

/*													2.1
struct vector{
	float x,y,z;
};
//typedef struct vector vector;

float scalar_product(struct vector v1,struct vector v2) {
	return v1.x * v2.x + v1.y + v2.y + v1.z * v2.z;
}

void vec_prod(struct vector v1,struct vector v2, struct vector *v){
	//struct vector v;
	v->x = v1.y * v2.z - v1.z * v2.y;
	v->y = v1.z * v2.x - v1.x * v2.z;
	v->z = v1.x * v2.y - v1.y * v2.x;
}

int main(){
	struct vector v1 = {2,4,6};
	struct vector v2 = {3,5,9};
	struct vector v;
	vec_prod(v1,v2,&v);
	printf("v1 * v2 = %.2f\n", scalar_product(v1, v2));
	printf("v1 x v2 = [%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
}
*/

/*															3
struct comp{
	float real;
	float imag;
};

struct comp add(struct comp a, struct comp b){
	struct comp c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

struct comp subb(struct comp a, struct comp b){
	struct comp c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;  
}

void mult(struct comp a, struct comp b, struct comp *c){
	c->real = a.real * b.real - a.imag * b.imag;
	c->imag = a.real * b.imag + a.imag * b.real;
}

void Pecati(struct comp *pok){
	printf("%.2f", pok->real);
	if(pok->imag>=0)
		printf("+j%.2f\n", pok->imag);
	else
		printf("-j%.2f\n", fabs(pok->imag));
}

int main(){
	struct comp a,b,c;
	scanf("%f%f", &a.real, &a.imag);
	scanf("%f%f", &b.real, &b.imag);
	Pecati(&a);
	Pecati(&b);
	printf("a+b\n");
	c = add(a,b);
	Pecati(&c);
	printf("a-b\n");
	c = subb(a,b);
	Pecati(&c);
	printf("a*b\n");
	mult(a,b,&c);
	Pecati(&c);
	return 0;
}
*/

/*																4
struct student{
	char ime[15];
	char prezime[20];
	int index;
	int poeni;
};

void norm(char *a){
	int i=1;
	a[0] = toupper(a[0]);
	while(a[i] != '\0'){
		a[i] = tolower(a[i]);
		i++;
	}
}

void sort(struct student a[],int n){
	int i,j;
	struct student s;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j].poeni > a[j+1].poeni){
				s = a[j];
				a[j] = a[j+1];
				a[j+1] = s;
			}
}

int main(){
	struct student st[50];
	int i,n;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", st[i].ime);
		scanf("%s", st[i].prezime);
		scanf("%d", &st[i].index);
		int j,zadaca;
		for(j=0;j<4;j++){
			scanf("%d", &zadaca);
			st[i].poeni += zadaca;
		}
		norm(st[i].ime);
		norm(st[i].prezime);
	}
	sort(st,n);
	for(i=0;i<n;i++)
		printf("%d. %s %s\t%d\t%d\n",i+1,st[i].ime, st[i].prezime, st[i].index, st[i].poeni);
	return 0;
}
*/
/*																	5
struct city{
	char name [30];
	int population;
};

struct president{
	char name [20];
	char party [20];
};

struct country{
	char name [30];
	struct president pres;
	int population;
	struct city capital;
};

int main(){
	struct country d[20];
	int n,i,maxi=0,max;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%s", d[i].name);
		printf("president:\n");
		scanf("%s", d[i].pres.name);
		scanf("%s", d[i].pres.party);
		scanf("%d", &d[i].population);
		scanf("%s", d[i].capital.name);
		scanf("%d", &d[i].capital.population);
	}
	max = d[maxi].capital.population;
	for (i = 0; i < n; i++)
		if (d[i].capital.population > max) {
			max = d[i].capital.population;
			maxi = i;
		}
	printf("Name of the president of the country with the largest capital is: %s\n",d[maxi].pres.name);
	return 0;
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ZBIRKA

/*
#define MAX 50

struct stan{
	int stanNo;
	int roomNo;
	int floor;
	char Eq;
	int sqf;
};

struct zgrada{
	char name [20];
	char adresa [30];
	int apartNum;
	struct stan apart[MAX];
};

int apartPrice(struct stan c){
	int res = (c.floor)*1000;
	switch(c.floor){
		case 1: res+=20; break;
		case 2: res+=15; break;
		case 3: res+=10; break;
		case 4: res+=5; break;
		default: res=res; 
	}
	if (c.Eq=='+') res+=2000;
		return res;
}

void func(struct zgrada z){
	int i;
	printf("zgrada %s\n", z.name);
	printf("adresa %s\n", z.adresa);
	for(i=0 ; i<z.apartNum ; i++){
		printf("%d %d %d %dm/2\t", i+1, z.apart[i].stanNo, z.apart[i].roomNo, z.apart[i].sqf);
		if(z.apart[i].Eq == '+')
			printf("opremen\t%d\n",apartPrice(z.apart[i]));
		else
			printf("ne e opremen\t%d\n",apartPrice(z.apart[i]));
	}
}

int main(){
	struct zgrada flat;
	int i;
	printf("ime na zgrada");  		scanf("%s", flat.name);
	printf("adresa na zgrada");  	scanf("%s", flat.adresa);
	printf("broj na stanovi");  	scanf("%d", &flat.apartNum);
	printf("\n\n");
	for(i=0 ; i<flat.apartNum ; i++){
		printf("Br. na stan");		scanf("%d", &flat.apart[i].stanNo);
		printf("Br. na sobi");		scanf("%d", &flat.apart[i].roomNo);
		printf("kat");				scanf("%d", &flat.apart[i].floor);
		printf("povrshina");		scanf("%d", &flat.apart[i].sqf);
		printf("oprema");			scanf("%c", &flat.apart[i].Eq);
	}
	printf("\n\n");
	func(flat);
}
*/


/*
struct uni{
	char ime[20];
	char adresa [30];
};


struct faks{
	char ime [20];
	char adresa[30];
	struct uni univerz;
};


struct student{
	char ime[20];
	char prezime[20];
	int index;
	struct faks fakultet;
};

void func(struct student me[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d %s %s %s %s \t",i+1, me[i].ime, me[i].prezime, me[i].fakultet.ime, me[i].fakultet.univerz.ime);
}

int main(){
	struct student me[50];
	int i,n;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", me[i].ime);
		scanf("%s", me[i].prezime);
		scanf("%d", &me[i].index);
		scanf("%s", me[i].fakultet.ime);
		scanf("%s", me[i].fakultet.univerz.ime);
	}
	func(me,n);
	return 0;
}
*/
