#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*
int main(){
	cout << "Start..." << endl;
	for(int lineno = 0; lineno < 3; lineno++ ){
		cout << "This is line number " << lineno;
		int temp = 22;
		cout << " and temp is " << temp << endl;
	}
	int final = 33;
	cout << "... and final is " << final << endl;
}
*/

/*
enum answer {NE,DA,MOZEBI};

int main(){
	const int MAX = 5;
	answer cs[MAX];
	cout << "the size of cs is " << sizeof cs << endl;
	cs[0] = NE;
	cs[1] = DA;
	cs[2] = MOZEBI;
	cout << cs[0] << cs[1] << cs[2] << endl;
	return 0;
}
*/

/*
void list(int n, char **lt){
	void ruler(int n = 1, char c = '#', bool nl = 0);
	for(int i=0; i<n; i++){
		ruler();
		cout << i+1 << ' ' << lt[i] << endl;
	}
	ruler(15, '*', true);
	return;
}

void ruler(int n = 20, char c = '=', bool nl = 1){
	for(int i=0; i<n; i++)
		cout << c;
	if(nl) 
		cout << endl;
}

int main()
{
	const char naslov[]=" NASLOV ";
	const char podnaslov[]="Podnaslov";
	char *tocki[]={"Tocka eden", "Tocka dva", "Tocka tri"};
	//void ruler(int n = 20, char c = '=', bool nl = 1);					//definiranje na default vrednosti moze i na f-ii
	ruler(20,'=',1);
	cout << naslov << endl;			ruler(sizeof naslov - 1);
	cout << podnaslov << endl; 		ruler(sizeof podnaslov - 1, '-');
	void list(int n, char **lt);
	list(3, tocki);
	ruler();
}
*/

/*
void show( int = 1, float = 2.3, long = 4 );
int main()
{
show(); // All three arguments default
show( 5 ); // Provide 1st argument
show( 6, 7.8 ); // Provide 1st and 2nd
show( 9, 10.11, 12L ); // Provide all three arguments
// show( , 3.5, 7L); ** Error: cannot omit only first argument
}
void show( int first, float second, long third )
{
cout << "first = " << first;
cout << ", second = " << second;
cout << ", third = " << third;
cout << endl;
return;
}
*/

/*
struct bigone{
	int key;
	char text[1000];
};
// --- Pass by value
void valfunc(struct bigone vl){
	cout << endl << vl.key;
	cout << endl << vl.text;
}
// --- Pass by pointer
void ptrfunc(struct bigone *pl ){
	cout << endl << pl->key; // Pointer notation
	cout << endl << pl->text;
}
// --- Pass by reference
void reffunc(struct bigone &rl ){
	cout << endl << rl.key; // Reference notation
	cout << endl << rl.text;
	cout << endl;
}

int main(){
	struct bigone bo={ 123, "This is a big structure" };
	valfunc(bo); // Passing the variable itself
	ptrfunc(&bo); // Passing the address of the variable
	reffunc(bo); // Passing a reference to the variable
	return 0;
}
*/
/*
//alokacija na memorija
int main(){
	int *d=new int;
	cout << "dim="; 
	cin >> *d;
	int *p=0;
	p=new int[*d];
	for(int i=0; i<*d; i++)
		p[i]=i*i;
	for(int i=0; i<*d; i++)
		cout << "p[" << i << "]="<< p[i] << endl;
	delete [] p;
	delete d;
	return 0;
}
*/



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AUD

/*																			1
struct student{
	char name[50];
	char lastname[50];
	int number;
	int totalpoints;
	void print(){
		cout << name << "\t";
		cout << lastname << "\t";
		cout << number << "\t";
		cout << totalpoints << "\n";
	}
};

void norm(char *name, bool allup = false){
	*name = toupper(*name);
	name++;
	while(*name){
		if(allup)
			*name = toupper(*name);
		else
			*name = tolower(*name);
		name++;
	}
}

void read(student &s){
	int a,b,c,d;
	cin >> s.name;
	cin >> s.lastname;
	norm(s.name);
	norm(s.lastname);
	cin >> s.number;
	cin >> a >> b >> c >> d;
	s.totalpoints = a+b+c+d;
}

void sort(student s[], int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;i++)
			if(s[j].totalpoints > s[j+1].totalpoints){
				student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
}

int main(){
	student s[100];
	int n,i;
	cin >> n;
	for(i=0;i<n;i++)
		read(s[i]);
	sort(s,n);
	cout << "======== ORDERED ========" << endl;
	for(i=0;i<n;i++)
		s[i].print();
	return 0;
}
*/

/*																	2

struct city {
	char name[100];
	int population;
};

struct country {
	char name[100];
	char president[100];
	city capital;
	int population;
	void print() {
		cout << name << "\t" << president << "\t";
		cout << capital.name << "\t";
		cout << capital.population << "\t";
		cout << population << endl;
	}
};


void print(country &c) {
  cout << c.name << "\t" << c.president << "\t";
  cout << c.capital.name << "\t";
  cout << c.capital.population << "\t";
  cout << c.population << endl;
}


void read(int n, country c[]) {
	for (int i = 0; i < n; ++i) {
		cin >> c[i].name;
		cin >> c[i].president;
		cin >> c[i].capital.name;
		cin >> c[i].capital.population;
		cin >> c[i].population;
	}
}
void maxCapitalPopulation(int n, country c[]) {
	country max = c[0];
	for (int i = 1; i < n; ++i)
		if (c[i].capital.population > max.capital.population)
			max = c[i];
	cout << max.president << endl;
}


int main(){
	int n;
	country countries[100];
	cin >> n;
	read(n,countries);
	for (int i = 0; i < n; ++i){
		//print(countries[i]);
		countries[i].print();
	}
	maxCapitalPopulation(n, countries);
}
*/