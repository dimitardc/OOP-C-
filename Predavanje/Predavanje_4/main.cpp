#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*
using namespace std;

class circle{
public:
	float radius;
	float area(){
		return radius*radius*3.14;
	}
};

int main(){
	circle c1;
	cin >> c1.radius;
	float a;
	a=c1.area();
	cout << a;
	return 0;
}
*/
/*
class krug{
private:
	double radius;
public:
	double get_r (){ 
		return radius; 
	}
	void set_r(double r);
};

void krug::set_r(double r){ 
	if (r>=0) 
		radius = r;
	else 
		radius = 0; 
}

int main(){
	krug c;
	c.set_r(5.0);
	cout << "Radiusot na krugot c e " << c.get_r() << endl;
}
*/

/*
class Log{
public:
int LogLevelError = 0;
int LogLevelWarning = 1;
int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo;
public:
	void SetLevel(int level){
		m_LogLevel = level;
	}
	
	void Error (char* message){
		if(m_LogLevel >= LogLevelError)
			cout << "error: " <<  message << endl;
	}
	void Warn (char* message){
		if(m_LogLevel >= LogLevelWarning)
			cout << "warning: " <<  message << endl;
	}
	void Info (char* message){
		if(m_LogLevel >= LogLevelInfo)
			cout << "info: " <<  message << endl;
	}
};


int main(){
	Log log;
	log.SetLevel(log.LogLevelError); // take the value from log.LogLevelWarning and sent it to log.SetLevel
	log.Error("Hello!");
	log.Warn("Hello!");
	log.Info("Hello!");
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AUD

/*													1
class triagolnik{
private:
	int a,b,c;
public:
	triagolnik(int x, int y, int z){
		a = x;
		b = y;
		c = z;
	}
	~triagolnik(){
	}
	float perimetar(){
		return a+b+c;
	}
	float ploshtina(){
		float s = (a+b+c)/2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
};

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	triagolnik trig(a,b,c);
	cout << "ploshtina: " << trig.ploshtina() << endl;
	cout << "perimetar: " << trig.perimetar() << endl;
	return  0;
}
*/

/*														2
enum position{
	employee,manager,owner
};

class worker{
private:
	char name[100];
	int salary;
	position pos; 
public:
	worker(){
	}
	worker(char *n, int s, position p){
		strcpy(name, n);
		salary = s;
		pos = p;
	}
	~worker(){
	}
	void setName(char *n){
		strcpy(name, n);
	}
	void setSalary(int s){
		salary = s;
	}
	void setPosition(position p){
		pos = p;
	}
	char *getName(){
		return name;
	}
	int getSalary(){
		return salary;
	}
	position getPosition(){
		return pos;
	}
};

void sort(worker a[], int n){
	int i,j;
	worker b;
	for(i=0 ; i<n-1 ; i++)
		for(j=i ; j<n ; j++)
			if(a[i].getSalary() < a[j].getSalary()){
				b = a[j];
				a[j] = a[i];
				a[i] = b;
			}
}

int main(){
	worker vraboteni[100];
	char name [100];
	float salary;
	int pos;
	int n,i;
	cin >> n;
	for(i = 0 ;i<n;i++){
		cin >> name;
		cin >> salary;
		cin >> pos;
		vraboteni[i].setName(name);
		vraboteni[i].setSalary(salary);
		vraboteni[i].setPosition((position) pos);
	}
	sort(vraboteni , n);
	for(i=0;i<n;i++)
		cout << i + 1 << ". " << vraboteni[i].getName() << "\t" << vraboteni[i].getSalary() << "\t" << vraboteni[i].getPosition() << endl;
	return 0;
}
*/

/*
const int AddrLen = 100, SubLen = 200, BodyLen = 1000;

class Email{
private:
	char to[AddrLen];
	char from[AddrLen];
	char subject[SubLen];
	char body[BodyLen];
public:
	Email(char * _to, char * _from, char* _subject, char* _body){
		strncpy(to, _to, AddrLen - 1);
		strncpy(from, _from, AddrLen - 1);
		strncpy(subject, _subject, SubLen - 1);
		strncpy(body, _body, BodyLen);
		//to[AddrLen - 1] = from[AddrLen - 1] = subject[SubLen - 1] = body[BodyLen - 1] = 0;
	}
	~Email(){
	}
	void print() {
		cout << "To: " << to << endl;
		cout << "From: " << from << endl;
		cout << "Subject: " << subject << endl;
	}
};


bool checkEmail(char *adresa){
	int count = 0;
	while(*adresa){
		if(*adresa == '@')
			count++;
		adresa++;
	}
	return count;
}

int main(){
	char to[100], from[100], subject[200], body[1000];
	cout << "To:" << endl;
	cin >> to;
	if(checkEmail(to)){
		cout << "From: " << endl;
		cin >> from;
		cout << "Subject: " << endl;
		cin >> subject;	
		cout << "Body: " << endl;
		cin >> body;
		Email poraka(to, from, subject, body);
		cout << "Sent:" << endl;
		poraka.print();
		cout << "Body: " <<  body << endl;
	}
	else
		cout << "no mail nigga" << endl;
}

*/