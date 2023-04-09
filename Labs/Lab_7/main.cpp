#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


/*
class Employee{
protected:
	char name [50];
	int age;
	int experience;
public:
	Employee(const char * name, int age, int experience){
		strcpy(this->name, name);
		this->age = age;
		this->experience = experience;
	}
	virtual double plata() = 0;
	virtual double bonus() = 0;
	virtual int getType() = 0;
	int getAge(){
		return age;
	}
	virtual ~Employee()		{}
};

class SalaryEmployee : public Employee{
protected:
	int BasicSalary;
public:
	SalaryEmployee(const char* name, int age, int experience, int BasicSalary) : Employee(name,age,experience){
		this->BasicSalary = BasicSalary;
	}
	double bonus(){
		return (BasicSalary / experience) * 1.0;
	}
	double plata(){
		return bonus() + BasicSalary; 
	}
	int getType(){
		return 1;
	}
};

class HourlyEmployee : public Employee{
protected:
	int hoursWorked;
	int hourlyPay;
public:
	HourlyEmployee(const char* name, int age, int experience, int hoursWorked, int hourlyPay) : Employee(name,age,experience){
		this->hoursWorked = hoursWorked;
		this->hourlyPay = hourlyPay;
	}
	double plata(){
		return (hoursWorked * hourlyPay) + bonus();
	}
	double bonus(){
		int i = 0;
		int temp = hoursWorked;
		while(temp%320 > 0){
			i++;
			temp = temp%320;
		}
		return i *(hourlyPay / 2) * 1.0;
	}
	int getType(){
		return 2;
	}
};

class Freelancer : public Employee{
protected:
	int numProjects;
	double * projects;
public:
	Freelancer(char* name, int age, int experience, int numProjects, double * projects) : Employee(name,age,experience){
		this->numProjects = numProjects;
		this->projects = new double[numProjects];
		for(int i = 0 ; i <numProjects;i++)
			this->projects[i] = projects[i];
	}
	double bonus(){
		int counter = 0;
		for(int i = 0, j = 0; j < numProjects ;j++){
			i++;
			if(i == 5){
				counter++;
				i = 0;
			}
		}
		return counter * 1000.0;
	}
	double plata(){
		double sum = 0;
		for(int i = 0; i<numProjects;i++)
			sum+=projects[i];
		return sum + bonus();
	}
	int getType(){
		return 3;
	}
};

bool operator==(Employee &e1, Employee &e2){
	if(e1.getAge() == e2.getAge() && e1.bonus() == e2.bonus())
		return true;
	else
		return false;
}

class Company{
private:
	int counter1,counter2,counter3;
	char name [50];
	int numWorkers;
	Employee** niza;
public:
	Company(char * name){
		strcpy(this->name , name);
		numWorkers = 0;
		niza = new Employee*[0];
		counter1 = 0;
		counter2 = 0;
		counter3 = 0;
	}
	Company(const Company &c){
		numWorkers = c.numWorkers;
		niza = new Employee*[numWorkers];
		for(int i = 0; i<numWorkers;i++)
			niza[i] = c.niza[i];
	}
	Company& operator=(const Company &c){
		delete [] niza;
		numWorkers = c.numWorkers;
		niza = new Employee*[numWorkers];
		for(int i = 0; i<numWorkers;i++)
			niza[i] = c.niza[i];
		return *this;
	}
	~Company(){
		delete [] niza;
	}
	Company& operator+=(Employee *e){
		Employee** temp = new Employee*[numWorkers+1];
		for(int i = 0; i<numWorkers;i++)
			temp[i] = niza[i];
		temp[numWorkers] = e;
		numWorkers++;
		delete [] niza;
		niza = temp;
		return *this;
	}
	double filtriranaPlata(Employee *emp){
		for(int i = 0; i<numWorkers;i++){
			if(*emp == *niza[i]){
				return niza[i]->plata();
			}
		}
		return 0;
	}
	double vkupnaPlata(){
		double sum = 0;
		for(int i = 0;i<numWorkers;i++)
			sum+=niza[i]->plata();
		return sum;
	}
	void pecatiRabotnici(){
		int counter1=0;counter2 = 0; counter3 = 0;
		cout<<"Vo kompanijata "<<name<<" rabotat:"<<endl;
		for(int i = 0;i<numWorkers;i++){
			SalaryEmployee *se = dynamic_cast<SalaryEmployee*>(niza[i]);
			if(se){
				counter1++;
				continue;
			}
			HourlyEmployee *he = dynamic_cast<HourlyEmployee*>(niza[i]);
			if(he){
				counter2++;
				continue;
			}
			Freelancer *fe = dynamic_cast<Freelancer*>(niza[i]);
			if(fe){
				counter2++;
				continue;
			}
		}
		cout<<"Salary employees: "<<counter1<<endl;
		cout<<"Hourly employees: "<<counter2<<endl;
		cout<<"Freelancers: "<<counter3<<endl;
	}
};



int main() {
	char name[50];
	cin >> name;
	Company c(name);

	int n;
	cin >> n;

	char employeeName[50];
	int age;
	int experience;
	int type;

	for (int i=0; i <n; ++i) {
	  cin >> type;
	  cin >> employeeName >> age >> experience;

	  if (type == 1) {
		int basicSalary;
		cin >> basicSalary;
		c += new SalaryEmployee(employeeName, age, experience, basicSalary);
	  }

	  else if (type == 2) {
		int hoursWorked;
		int hourlyPay;
		cin >> hoursWorked >> hourlyPay;
		c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
	  }

	  else {
		int numProjects;
		cin >> numProjects;
		double projects[10];
		for (int i=0; i < numProjects; ++i) {
		  cin >> projects[i];
		}
		c += new Freelancer(employeeName, age, experience, numProjects, projects);
	  }
	}

	c.pecatiRabotnici();
	cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
	Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
	cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);
	delete emp;
}
*/


/*			Жичани инструменти
class ZicanInstrument {
protected:
	char ime[20];
	int brojZici;
	int osnovnaCena;
public:
	ZicanInstrument(){
		brojZici = 0;
		osnovnaCena = 0;
	}
	ZicanInstrument (const char *ime,int brojZici,int osnovnaCena){
		strcpy(this->ime,ime);
		this->brojZici = brojZici;
		this->osnovnaCena = osnovnaCena;
	}
	virtual ~ZicanInstrument() {}
	bool operator== (ZicanInstrument &z1){
		if (z1.brojZici == brojZici)
			return true;
		else
			return false;
	}
	virtual int cena ()=0;		//cista virtuelna funkcija
};
 
class Mandolina : public ZicanInstrument {
protected:
	char forma[20];
public:
	Mandolina (const char *ime,int brojZici,int osnovnaCena,const char *forma) : ZicanInstrument (ime,brojZici,osnovnaCena){
		strcpy(this->forma,forma);
	}
	~Mandolina() {}
	int cena (){
		if (!strcmp(forma,"Neapolitan")){
			return osnovnaCena + osnovnaCena * 0.15;
		}
		else
			return osnovnaCena;
	}
	friend ostream &operator<< (ostream &o,const Mandolina &m){
		o<<m.ime<<" "<<m.brojZici<<" "<<m.osnovnaCena<<" "<<m.forma<<endl;
		return o;
	}
};
 
 
class Violina: public ZicanInstrument {
protected:
	float golemina;
public:
	Violina (const char *ime,int brojZici,int osnovnaCena,float golemina) : ZicanInstrument (ime,brojZici,osnovnaCena){
		this->golemina = golemina;
	}
	~Violina() {}
	int cena (){
		if (golemina == 0.25)
			return osnovnaCena + osnovnaCena * 0.1;
		else if (golemina == 1.00)
			return osnovnaCena + osnovnaCena * 0.2;
		else
			return osnovnaCena;
	}
	friend ostream &operator<< (ostream &o,const Violina &v){
		o<<v.ime<<" "<<v.brojZici<<" "<<v.osnovnaCena<<" "<<v.golemina<<endl;
		return o;
	}
};
 
 
void pecatiInstrumenti (ZicanInstrument &zi,ZicanInstrument **i,int n){
	for (int k=0;k<n;k++){
		if (zi == *i[k]){
			cout<< i[k] -> cena() << endl;
		}
	}
}
 
 
int main() {
		char ime[20];
		int brojZici;
		float cena;
		char forma[20];
		cin >> ime >> brojZici >> cena >> forma;
		Mandolina m(ime, brojZici, cena, forma);
		int n;
		cin >> n;
		ZicanInstrument **zi = new ZicanInstrument*[2 * n];
		for(int i = 0; i < n; ++i) {
				cin >> ime >> brojZici >> cena >> forma;
				zi[i] = new Mandolina(ime, brojZici, cena, forma);
		}
		for(int i = 0; i < n; ++i) {
				float golemina;
				cin >> ime >> brojZici >> cena >> golemina;
				zi[n + i] = new Violina(ime, brojZici, cena, golemina);
		}
		pecatiInstrumenti(m, zi, 2 * n);
		for(int i = 0; i < 2 * n; ++i) {
				delete zi[i];
		}
		delete [] zi;
		return 0;
}

*/
 

//		2. Numbers

/*
class Number {
public:
	//TODO da se deklariraat trite cisto virtuelni metodi
	virtual double doubleValue() = 0;
	virtual int intValue() = 0;
	virtual void print() = 0;
	bool operator==(Number& n){
		return doubleValue() == n.doubleValue();
	}
}; 

//ТODO preoptovaruvanje na operatorot == 

class Integer : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
	private:
		int broj;
	public:
	//TODO konstruktor so eden argument
	Integer(int broj){
		this->broj = broj;
	}
	//TODO da se prepokrijat metodite od klasata Number
	int intValue(){
		return broj;
	}
	double doubleValue(){
		return double(broj);
	}
	void print(){
		cout << broj;
	}
};

class Double : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
	private:
		double broj;
	public:
	//TODO konstruktor so eden argument
	Double(double broj){
		this->broj = broj;
	}
	//TODO da se prepokrijat metodite od klasata Number
	int intValue(){
		return int(broj);
	}
	double doubleValue(){
		return broj;
	}
	void print(){
		cout << broj;
	}
	
};

class Numbers{
private:
		Number** niza;
		int brElem;
public:
	//TODO default konstruktor
	Numbers(){
		niza = new Number*[0];
		brElem = 0;
	}
	//TODO copy konstruktor
	Numbers(const Numbers& n){
		brElem = n.brElem;
		niza = new Number*[brElem];
		for (int i = 0; i < n.brElem; i++){
			niza[i] = n.niza[i];
		}
	}
	//TODO operator =
	Numbers& operator=(const Numbers& n){
		brElem = n.brElem;
		niza = new Number*[brElem];
		for (int i = 0; i < n.brElem; i++){
			niza[i] = n.niza[i];
		}
		return *this;
	}
	//TODO destruktor
	~Numbers(){
		delete[] niza;
	}
	//TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
	Numbers& operator+=(Number* n){
		bool add = true;
		for (int i = 0; i < brElem; i++){
			if (*niza[i] == *n){
				add = false;
			}
		}
		if (add){
			Number** nova = new Number*[brElem + 1];
			for (int i = 0; i < brElem; i++){
				nova[i] = niza[i];
			}
			nova[brElem] = n;
			brElem++;
			delete[] niza;
			niza = nova;
		}
		return *this;
	}
	//TODO void statistics()
	void statistics(){
		cout << "Count of numbers: " << brElem << endl;
		double allSum = 0;
		for (int i = 0; i < brElem; i++){
			allSum += niza[i]->doubleValue();
		}
		cout << "Sum of all numbers: " << allSum << endl;
		int countIntegers = 0;
		int intSum = 0;
		for (int i = 0; i < brElem; i++){
			if (dynamic_cast<Integer*>(niza[i])){
				countIntegers++;
				intSum += niza[i]->intValue();
			}
		}
		cout << "Count of integer numbers: " << countIntegers << endl;
		cout << "Sum of integer numbers: " << intSum << endl;
		int countDoubles = 0;
		double doubleSum = 0;
		for (int i = 0; i < brElem; i++){
			if (dynamic_cast<Double*>(niza[i])){
				countDoubles++;
				doubleSum += niza[i]->doubleValue();
			}
		}
		cout <<"Count of double numbers: " << countDoubles << endl;
		cout <<"Sum of double numbers: " << doubleSum << endl;
	}
	//TODO void integersLessThan (Integer n)
	void integersLessThan(Integer n){
		bool none = true;
		for (int i = 0; i < brElem; i++){
			if (dynamic_cast<Integer*>(niza[i])){
				if (niza[i]->intValue() < n.intValue()){
					none = false;
					cout << "Integer: " << niza[i]->intValue() << end	l;
				}
			}
		}
		if (none) 
			cout << "None" << endl;
	}
	//TODO void doublesBiggerThan (Double n)
	void doublesBiggerThan(Double n){
		bool none = true;
		for (int i = 0; i < brElem; i++){
			if (dynamic_cast<Double*>(niza[i])){
				if (niza[i]->doubleValue()  > n.doubleValue()){
					none = false;
					cout << "Double: " << niza[i]->doubleValue() << endl;
				}
			}
		}
		if (none) 
			cout << "None" << endl;
	}
};

int main() {
	
	int n;
	cin>>n;
	Numbers numbers;
	for (int i=0;i<n;i++){
		int type;
		double number;
		cin>>type>>number;
		if (type==0){//Integer object
			Integer * integer = new Integer((int) number);
			numbers+=integer;
		}
		else {
			Double * doublee = new Double(number);
			numbers+=doublee;
		}
	}
	
	int lessThan;
	double biggerThan;
	
	cin>>lessThan;
	cin>>biggerThan;		
	
	cout<<"STATISTICS FOR THE NUMBERS\n";
	numbers.statistics();
	cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
	numbers.integersLessThan(Integer(lessThan));
	cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
	numbers.doublesBiggerThan(Double(biggerThan));
	
	return 0;

}
*/


// 3.  Тајни пораки

/*
class Secret{
public:
	virtual double simpleEntropy() = 0;
	virtual int total() = 0;
};

class DigitSecret : public Secret{
private:
	int cifri[100];
	int n;
public:
	DigitSecret(int * cifri, int n){
		this->n = n;
		for(int i = 0;i<n;i++)
			this->cifri[i] = cifri[i];
	}
	int total(){
		return n;
	}
	double simpleEntropy(){
		double different = 0.0;
		int count = 0;
		for(int i = 0;i<n;i++){
			count = 0;
			for(int j= 0;j<n;i++)
				if(i != j && cifri[i] == cifri[j])
					count++;
			if(count==0)
				different += 1.0;
		}
		return different/total();
	}
	friend ostream &operator << (ostream &out, DigitSecret &ds){
		for(int i = 0; i<ds.total() ; i++)
			out<<ds.cifri[i];
		out<<"Simple entropy: " << ds.simpleEntropy() << " Total: "<<ds.total();
		return out;
	}
};


bool operator ==(Secret &s1, Secret &s2){
	return s1.total() == s2.total() && s1.simpleEntropy() == s2.simpleEntropy();
}

bool operator !=(Secret &s1, Secret &s2){
	return s1.total() != s2.total() || s1.simpleEntropy() != s2.simpleEntropy();
}


class CharSecret : public Secret
{
private:
	char ch[100];
	int n;
public:
	CharSecret(char * ch){
		strcpy(this->ch , ch);
		n = strlen(ch);
	}
	int total(){
		return n;
	}
	double simpleEntropy() {
		double different = 0.0;
		int count = 0;
		for (int i = 0;i < n; i++){
			count = 0;
			for (int j = 0; j < n; j++){
				if ((i!=j) && (ch[i] == ch[j]))
					count++;
			}
			if (count == 0)
				different += 1.0;
		}
		return different/total();
	}
	friend ostream &operator << (ostream &o,  CharSecret &cs){
		for (int i = 0; i < cs.total(); i++)
			o << cs.ch[i];
		o<<" Simple entropy: " << cs.simpleEntropy() << " Total: "<< cs.total();
		return o;
	}
};

void process(Secret **secrets, int n){
	int max = 0;
	int j = 0;
	for(int i = 0;i<n;i++){
		if(max < secrets[i]->simpleEntropy()){
			max = secrets[i]->simpleEntropy();
			j = i;
		}
	}
	DigitSecret *ds = dynamic_cast<DigitSecret *>(secrets[j]);
	if(ds){
		cout<< *ds;
	}
	CharSecret *cs = dynamic_cast<CharSecret *>(secrets[j]);
	if(cs){
		cout<< *cs;
	}
}

void printAll(Secret **secrets, int n){
	for(int i = 0 ;i<n;i++){
		DigitSecret *ds = dynamic_cast<DigitSecret *>(secrets[i]);
		if(ds){
			cout<< *ds;
		}
		CharSecret *cs = dynamic_cast<CharSecret *>(secrets[i]);
		if(cs){
			cout<< *cs;
		}
	}
}

int main() {
	int n;
	cin >> n;
	if(n == 0) {
		cout << "Constructors" << endl;
		int numbers [] = {1,2,3,4,5};
		DigitSecret ds(numbers,5);
		CharSecret cs("abcabc");
		cout << "OK" << endl;
	} else if(n == 1) {
		cout << "operator <<" << endl;
		int numbers [] = {1,2,3,4,5};
		DigitSecret ds(numbers,5);
		CharSecret cs("abcabc");
		cout << ds << endl;
		cout << cs << endl;
	}  else if(n == 2) {
		cout << "== and !=" << endl;
		int numbers [] = {1,2,3,4,5};
		DigitSecret ds(numbers,5);
		CharSecret cs("abcabc");
		CharSecret css("abcabc");
		cout << (ds == cs) << endl;
		cout << (cs != ds) << endl;
		cout << (cs == css) << endl;
		cout << (cs != css) << endl;
	} else if(n == 3) {
		cout << "Secret processor" << endl;
		int numbers1 [] = {1,2,3,4,5,6,4,3,2,1,1,2,3,4,5};
		DigitSecret ds1(numbers1,15);
		int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
		DigitSecret ds2(numbers2,15);
		int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
		DigitSecret ds3(numbers3,20);
		CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
		CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
		CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
		Secret** s = new Secret*[6];
		s[0] = &ds1;
		s[1] = &ds2;
		s[2] = &ds3;
		s[3] = &cs1;
		s[4] = &cs2;
		s[5] = &cs3;
		process(s,6);
		delete [] s;
	}
	else if (n==4){
		cout << "Print all secrets" << endl;
		int numbers1 [] = {1,2,3,4,5,5,4,3,2,1,1,2,3,4,5};
		DigitSecret ds1(numbers1,15);
		int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
		DigitSecret ds2(numbers2,15);
		int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
		DigitSecret ds3(numbers3,20);
		CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
		CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
		CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
		Secret** s = new Secret*[6];
		s[0] = &ds1;
		s[1] = &ds2;
		s[2] = &ds3;
		s[3] = &cs1;
		s[4] = &cs2;
		s[5] = &cs3;
		printAll(s,6);
		delete [] s;
	}
 
	return 0;
}
*/

/*
// 4. Shapes

//TODO: konstruiraj ja abstraknata klasa Shape
class Shape{
protected:
	int a;
public:
	virtual double plostina()=0;
	virtual void pecati()=0;
	virtual int getType() =0;
};
//TODO: konstruiraj ja klasata Kvadrat
class Square : public Shape{
public:
	Square(int a){
		this->a=a;
	}
	double plostina(){
		return (double)a*a;
	}
	void pecati(){
		cout<<"Kvadrat so plostina = "<<plostina()<<endl;
	}
	int getType(){
		return 1;
	}
};
//TODO: konstruiraj ja klasata Krug
class Krug : public Shape{
public:
	Krug(int a){
		this->a=a;
	}
	double plostina(){
		return 3.14 * a * a;
	}
	void pecati(){
		cout<<"Krug so plostina = "<<plostina()<<endl;
	}
	int getType(){
		return 2;
	}
};
//TODO: konstruiraj ja klasata Triagolnik
class Triagolnik : public Shape{
public:
	Triagolnik(int a){
		this->a=a;
	}
	double plostina(){
		return (sqrt(3)/4) * (double)a * a;
	}
	void pecati(){
		cout<<"Triagolnik so plostina = "<<plostina()<<endl;
	}
	int getType(){
		return 3;
	}
};
 
//TODO: definiraj go metodot void checkNumTypes(Shape** niza, int n)
void checkNumTypes(Shape** niza, int n){
	int square=0, krug=0, triagolnik=0;
	for(int i=0;i<n;++i){
		if(niza[i]->getType()==1)
			square++;
		if(niza[i]->getType()==2)
			krug++;
		if(niza[i]->getType()==3)
			triagolnik++;
	}
	cout<<"Broj na kvadrati vo nizata = "<<square<<endl;
	cout<<"Broj na krugovi vo nizata = "<<krug<<endl;
	cout<<"Broj na triagolnici vo nizata = "<<triagolnik<<endl;
}
 
int main(){
	int n;
	cin >> n;
	//TODO: inicijaliziraj niza od pokazuvachi kon klasata Shape
	Shape **niza;
	//TODO: alociraj memorija so golemina n za prethodno navedenata niza
	niza=new Shape*[50];
	int classType;
	int side;
	//TODO: konstruiraj for ciklus so chija pomosh ke ja popolnish nizata
	for(int i = 0; i < n; ++i){
		cin >> classType;
		cin >> side;
		if(classType==1)
		niza[i]=new Square(side);
		if(classType==2)
		   niza[i]=new Krug(side);
		if(classType==3)
			niza[i]=new Triagolnik(side);
	}
	for(int i = 0; i < n; ++i){
		niza[i]->pecati();
	}
	checkNumTypes(niza, n);
	return 0;
}
*/


/*		Распоредувач на задачи
class Task{
protected:
	char id[5];
public:
	Task(const char *id){
		strcpy(this->id, id);
	}
	
	virtual int getOrder() = 0;
	virtual void print() = 0;
	
	char *getID(){
		return id;
	}
};
 
class TimedTask : public Task{
private:
	int time;
public:
	TimedTask(const char *id, int time) : Task(id){
		this->time = time;
	}
	int getOrder(){
		return time;
	}
	void print(){
		cout << "TT->" <<id << ":" << time << endl;
	}
};
 
class  PriorityTask : public Task{
private:
	int priority;
public:
	PriorityTask(const char *id, int priority)  : Task(id){
		this->priority = priority;
	}
	int getOrder(){
		return priority;
	}
	void print(){
		cout << "PT->" << this->id << ":" << priority << endl;
	}
};
 
void scheduleTimedTasks (Task ** tasks, int n, int t){
	for(int i = 0; i < n-1; ++i){
		for(int k = i+1; i < n; ++i){
			if(tasks[i]->getOrder() > tasks[k]->getOrder()){
				Task *pom = tasks[i];
				tasks[i] = tasks[k];
				tasks[k] = pom;
			}
		}
	}
	for(int i = 0; i < n; i++){
		TimedTask *tt = dynamic_cast <TimedTask *>(tasks[i]);
		if(tt !=0 && tasks[i] ->getOrder() < t )
			tasks[i] ->print();
		}
}
 
void schedulePriorityTasks(Task ** tasks, int n, int p){
	for(int i = 0; i < n-1; ++i){
		for(int k = i+1; i < n; ++i){
			if(tasks[i]->getOrder() > tasks[k]->getOrder()){
				Task *pom = tasks[i];
				tasks[i] = tasks[k];
				tasks[k] = pom;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		PriorityTask *pt = dynamic_cast <PriorityTask *>(tasks[i]);
		if(pt !=0 && tasks[i] ->getOrder() < p )
			tasks[i] ->print();
	}
}

bool operator == (Task *t1, Task &t2){
	return strcmp(t1 ->getID(), t2.getID()) == 0 && t1 ->getOrder()== t2.getOrder();
}

int main () {
	int testCase;
	int n;
	cin>>testCase;
 
	if (testCase==0){
		cin>>n;
		Task ** tasks;
		tasks = new Task * [n];
		for (int i=0;i<n;i++){
		char id [5];
		int timeOrPriority;
		int type; //0 za timed, 1 za priority
		cin >> type >>id >> timeOrPriority;
		if (type==0)
			tasks[i] = new TimedTask(id,timeOrPriority);
		else
			tasks[i] = new PriorityTask(id,timeOrPriority);
		//tasks[i]->print();
		}
 
		cout<<"SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10"<<endl;
		schedulePriorityTasks(tasks,n,10);
 
	}
	else if (testCase==1) {
		cin>>n;
		Task ** tasks;
		tasks = new Task * [n];
		for (int i=0;i<n;i++){
		char id [5];
		int timeOrPriority;
		int type; //0 za timed, 1 za priority
		cin >> type >>id >> timeOrPriority;
		if (type==0)
			tasks[i] = new TimedTask(id,timeOrPriority);
		else
			tasks[i] = new PriorityTask(id,timeOrPriority);
		//tasks[i]->print();
		}
 
 
		cout<<"SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50"<<endl;
		scheduleTimedTasks(tasks,n,50);
	}
	else {
		TimedTask * tt1 = new TimedTask("11",10);
		TimedTask * tt2 = new TimedTask("11",11);
		TimedTask * tt3 = new TimedTask("11",11);
		PriorityTask * pp1 = new PriorityTask("aa",10);
		PriorityTask * pp2 = new PriorityTask("11",10);
 
		cout << (tt1==(*tt2))<<endl;
		cout << (tt2==(*tt3))<<endl;
		cout << (pp1==(*pp2))<<endl;
		cout << (pp2==(*tt1))<<endl;
	}
 
	return 0;
}
*/