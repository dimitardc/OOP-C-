#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cmath>

using namespace std;

/*														1
class ParkingPlac{
private:
	char adresa [20];
	char *id;
	int cena;
	int profit;
public:
	ParkingPlac(){
		id = new char[0];
	}
	ParkingPlac(char* adresa, char*id, int cena){
		strcpy(this->adresa, adresa);
		this->id = new char[strlen(id) + 1];
		strcpy(this->id, id);
		this->cena = cena;
		this->profit = 0;
	}
	ParkingPlac(const ParkingPlac &p){
		strcpy(this->adresa, p.adresa);
		this->id = new char[strlen(p.id) + 1];
		strcpy(this->id, p.id);
		this->cena = p.cena;
		this->profit = p.profit;
	}
	ParkingPlac& operator=(const ParkingPlac &p){
		if(this==&p)
			return *this;
		strcpy(this->adresa, p.adresa);
		this->id = new char[strlen(p.id) + 1];
		strcpy(this->id, p.id);
		this->cena = p.cena;
		this->profit = p.profit;
		return *this;
	} 
	void pecati(){
		cout<<id<<" "<<adresa;
		if(profit!=0) cout<<" - "<<profit<<" denari"<<endl;
	}
	void platiCasovi(int casovi){
		profit += cena*casovi;
	}
	bool daliIstaAdresa(const ParkingPlac &p){
		if(strcmp(adresa,p.adresa)==0) 
			return true;
		else 
			return false;
	}
	const char* getId(){
		return id;
	}
	~ParkingPlac(){
		delete[] id;
	}
};

int main(){
    ParkingPlac p[100];
    int n,m;
    char adresa[50],id[50];
    int brojcasovi,cenacas;
    cin>>n;
    for (int i=0;i<n;i++){
        cin.get();
        cin.getline(adresa,50);
        cin>>id>>cenacas;
        ParkingPlac edna(adresa,id,cenacas);
        //povik na operatorot =
        p[i]=edna;
    }
    //plakjanje
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>id>>brojcasovi;
        int findId=false;
        for (int j=0;j<n;j++){
            if (strcmp(p[j].getId(),id)==0){
                p[j].platiCasovi(brojcasovi);
                findId=true;
            }
        }
        if (!findId)
			cout<<"Ne e platen parking. Greshen ID."<<endl;
    }
    cout<<"========="<<endl;
    ParkingPlac pCentar("Cvetan Dimov","C10",80);
    for (int i=0;i<n;i++)
        if (p[i].daliIstaAdresa(pCentar))
            p[i].pecati();
}
*/
/*															2
enum zanr{action,comedy,drama};

class Film{
private:
	char* ime;
	int size;
	zanr genre;
public:
	Film()		{}
	Film(char* ime, int size,zanr genre){
		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);
		this->size = size;
		this->genre = genre;
	}
	Film(const Film &f){
		this->ime = new char[strlen(f.ime) + 1];
		strcpy(this->ime, f.ime);
		this->size = f.size;
		this->genre = f.genre;
	}
	Film& operator=(const Film &f){
		if(this==&f)
			return *this;
		delete[] ime;
		this->ime = new char[strlen(f.ime) + 1];
		strcpy(this->ime, f.ime);
		this->size = f.size;
		this->genre = f.genre;
		return *this;
	}
	void pecati(){
		cout<<size<<"MB" << "-\"" <<ime<<"\""<<endl;
	}
	~Film(){
		delete[] ime;
	}
	int getSize(){
		return size;
	}
	zanr getZanr(){
		return genre;
	}
};

class DVD{
private:
	Film f[5];
	int brojFilmovi;
	int size;
public:
	DVD()		{}
	DVD(Film *f, int brojFilmovi, int size){
		this->brojFilmovi = brojFilmovi;
		this->size = size;
		for(int i = 0; i<5 ; i++)
			this->f[i] = f[i];
	}
	DVD(const DVD &d){
		this->brojFilmovi = d.brojFilmovi;
		this->size = d.size;
		for(int i = 0; i<5 ; i++)
			this->f[i] = d.f[i];
	}
	 DVD(int size){
		this->size=size;
		brojFilmovi=0;
 }
	void dodadiFilm(Film f){
		if(brojFilmovi<5)
			if(size>=f.getSize()){
				this->f[brojFilmovi] = f;
				brojFilmovi++;
				size-=f.getSize();
			}
	}
	void pecatiFilmoviDrugZanr(zanr z){
		for(int i = 0;i<brojFilmovi ; i++)
			if(z!=f[i].getZanr())
				f[i].pecati();
	}
	Film getFilm(int i){
		return f[i];
	}
	int getBroj(){
		return brojFilmovi;
	}
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;
    int n, memorija, kojzanr;
    char ime[50];
    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } 
	else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } 
	else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } 
	else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } 
	else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } 
    return 0;
}
*/

/*																								3
class Pica{
private:
	char ime[15];
	int cena;
	char* sostojki;
	int popust;
public:
	Pica(){
		sostojki = new char[0];
	}
	Pica(char *ime, int cena, char* sostojki, int popust){
		strcpy(this->ime, ime);
		this->cena = cena;
		this->sostojki = new char[strlen(sostojki) + 1];
		strcpy(this->sostojki, sostojki);
		this->popust = popust;
	}
	Pica(const Pica &p){
		strcpy(this->ime, p.ime);
		this->cena = p.cena;
		this->sostojki = new char[strlen(p.sostojki) + 1];
		strcpy(this->sostojki, p.sostojki);
		this->popust = p.popust;
	}
	Pica& operator=(const Pica &p){
		strcpy(this->ime, p.ime);
		this->cena = p.cena;
		delete [] sostojki;
		this->sostojki = new char[strlen(p.sostojki) + 1];
		strcpy(this->sostojki, p.sostojki);
		this->popust = p.popust;
		return *this;
	}
	void pecati(){
		cout<<ime<<"-"<<sostojki<<", "<<cena;
	}
	bool istiSe(const Pica &p){
		if(strcmp(sostojki, p.sostojki)==0)
			return true;
		else
			return false;
	}
	int getPrice(){
		return cena;
	}
	int getPop(){
		return popust;
	}
	~Pica(){
		delete[] sostojki;
	}
};

class Picerija{
private:
	char ime[15];
	Pica *pc;
	int brPici;
public:
	Picerija(){
		pc = new Pica[0];
	}
	Picerija(char* ime){
		strcpy(this->ime, ime);
		this->brPici = 0;
	}
	Picerija(const Picerija &p){
		strcpy(ime, p.ime);
		brPici = p.brPici;
		delete[] pc;
		pc = new Pica[brPici];
		for(int i = 0 ; i<brPici ; i++)
			pc[i] = p.pc[i];		//= operator called
	}
	Picerija& operator=(const Picerija &p){
		strcpy(ime, p.ime);
		brPici = p.brPici;
		delete[] pc;
		pc = new Pica[brPici];
		for(int i = 0 ; i<brPici ; i++)
			pc[i] = p.pc[i];		//= operator called
		return *this;
	}
	~Picerija(){
		delete[] pc;
	}
	void dodadi(Pica p){
		int flag = 1;
		for(int i = 0 ;i< brPici ; i++)
			if(pc[i].istiSe(p)){
				flag = 0;
				break;
			}
		if(flag){
			Pica *tmp = new Pica[brPici + 1];
			for(int i = 0; i<brPici ;i++)
				tmp[i] = pc[i];
			if(brPici>0)
				delete[] pc;
				pc = tmp;
				pc[brPici++] = p;
		}
	}
	void setIme(const char* ime){
		strcpy(this->ime, ime);
	}
	char *getIme(){
		return ime;
	}
	void piciNaPromocija(){
		for(int i = 0; i<brPici ; i++)
			if(pc[i].getPop()){
				pc[i].pecati();
				cout<<" "<<pc[i].getPrice()-(pc[i].getPrice()*pc[i].getPop())/100<<endl;
			}
	}
};

int main () {
    int n;
    char ime[15];
    cin >> ime;
    cin >> n;
    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }
    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);
    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();
    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();
	return 0;
}
*/

/*																										4
enum tip{linux, unix, windows};

class OperativniSistemi{
private:
	char *name;
	float version;
	tip type;
	float size;
public:
	OperativniSistemi(){
		name = new char[0];
	 }
	OperativniSistemi(char *name, float version, tip type, float size){
		this-> name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->version = version;
		this->type = type;
		this->size = size;
	}
	OperativniSistemi(const OperativniSistemi &o){
		this-> name = new char[strlen(o.name)+1];
		strcpy(this->name, o.name);
		this->version = o.version;
		this->type = o.type;
		this->size = o.size;
	}
	OperativniSistemi& operator=(const OperativniSistemi &o){
		delete[] name;
		this-> name = new char[strlen(o.name)+1];
		strcpy(this->name, o.name);
		this->version = o.version;
		this->type = o.type;
		this->size = o.size;
		return *this;
	}
	void pecati(){
		cout<<"Ime: "<<name<<": "<<" Verzija: "<<version<<" Tip: "<<type<<" Golemina"<<size<<endl;
	}
	bool ednakviSe(const OperativniSistemi &o){
		if((strcmp(name, o.name)==0) && type == o.type && size==o.size && version == o.version)
			return true;
		else
			return false;
	}
	int sporediVerzija(const OperativniSistemi &o){
		if(version == o.version)
			return 0;
		else if(o.version > version)
			return -1;
		else
			return 1;
	}
	bool istaFamilija(const OperativniSistemi &o){
		if((strcmp(name, o.name)==0) && type == o.type)
			return true;
		else
			return false;
	}
	~OperativniSistemi(){
		delete[] name;
	}
};

class Repozitorium{
private:
	char name[20];
	OperativniSistemi* ops;
	int count;
public:
	Repozitorium(){
		ops = new OperativniSistemi[0];
		count = 0;
	}
	Repozitorium(const char *name){
		strcpy(this->name, name);
		this->count = 0;
	}
	Repozitorium(const Repozitorium &r){
		strcpy(name, r.name);
		count = r.count;
		ops = new OperativniSistemi[count];
		for(int i = 0; i<count ; i++)
			ops[i] = r.ops[i];
	}
	Repozitorium& operator=(const Repozitorium &r){
		strcpy(name, r.name);
		count = r.count;
		delete[] ops;
		ops = new OperativniSistemi[count];
		for(int i = 0; i<count ; i++)
			ops[i] = r.ops[i];
		return *this;
	}
	void pecatiOperativniSistemi(){
		for(int i = 0; i<count ; i++){
			ops[i].pecati();
		}
	}
	void izbrishi(const OperativniSistemi &operativenSistem){
		int ind = -1;
		for(int i = 0; i<count ; i++){
			if(!ops[i].ednakviSe(operativenSistem)){
				ind = i;
			}
		}
		if(ind != -1){
			OperativniSistemi *temp = new OperativniSistemi[count-1];
			for(int i = 0, j = 0; i<count ; i++){
				if(i != ind){
					temp[j] = ops[i];
					j++;
				}
			}
			delete [] ops;
			ops = temp;
			count--;
		}
		
	}
	void dodadi(const OperativniSistemi &nov){
		int flag = 0;
		for(int i = 0 ; i<count ; i++){
			if(ops[i].istaFamilija(nov) && ops[i].sporediVerzija(nov) == -1){
				ops[i] = nov;
				flag++;
				break;
			}
		}
		if(flag == 0){
			count++;
			OperativniSistemi* temp = new OperativniSistemi[count];
			for(int i = 0; i<count ; i++)
				temp[i] = ops[i];
			temp[count-1] = nov;
			delete[] ops;
			ops = temp;
		}
	}
	~Repozitorium(){
		delete[] ops;
	}
};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int type;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>type;
        cin>>golemina;
        OperativniSistemi os = OperativniSistemi(ime, verzija, (tip)type, golemina);
        repozitorium.dodadi(os);
    }
    repozitorium.pecatiOperativniSistemi();
	cin>>ime;
    cin>>verzija;
    cin>>type;
    cin>>golemina;
    OperativniSistemi os = OperativniSistemi(ime, verzija, (tip)type, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
*/

/*																										5
class List{
private:
	int *nums;
	int count;
public:
	List(){
		nums = new int[0];
		count = 0;
	}
	List(int* nums, int count){
		this->count = count;
		nums = new int[count];
		for(int i = 0 ; i<count ; i++)
			this->nums[i] = nums[i];
	}
	List(const List &l){
		this->count = l.count;
		nums = new int[count];
		for(int i = 0 ; i<count ; i++)
			this->nums[i] = l.nums[i];
	}
	List& operator=(const List &l){
		this->count = l.count;
		delete[] nums;
		nums = new int[count];
		for(int i = 0 ; i<count ; i++)
			this->nums[i] = l.nums[i];
		return *this;
	}
	~List(){
		delete[] nums;
	}
	void pecati(){
		cout<<count<<": ";
		for(int i = 0; i< count ; i ++)
			cout<<" "<<nums[i];
		cout<<" sum: "<<sum();
		cout<<" average: "<<average()<<endl;
	}
	int sum(){
		int sum = 0;
		for(int i = 0 ; i <count ; i++)
			sum+=nums[i];
		return sum;
	}
	float average(){
		return (1.0 * sum() )/count;
	}
	int getCount(){
		return count;
	}
};

class ListContainer{
private:
	List* lists;
	int elems;
	int tries;
public:
	ListContainer(){
		lists = new List[0];
		tries = 0;
		elems = 0;
	}
	ListContainer(const ListContainer &l){
		this->tries = l.tries;
		this->elems = l.elems;
		lists = new List[elems];
		for(int i = 0 ; i < elems ; i++){
			lists[i] = l.lists[i];				//copy const called
		}
	}
	ListContainer& operator=(const ListContainer &l){
		this->tries = l.tries;
		this->elems = l.elems;
		delete [] lists;
		lists = new List[elems];
		for(int i = 0 ; i < elems ; i++){
			this->lists[i] = l.lists[i];
		}
		return *this;
	}
	~ListContainer(){
		delete[] lists;
	}
	int sum(){
		int sum = 0;
		for(int i = 0; i<elems ; i++){
			sum+=lists[i].sum();				//suma od sumi
		}
		return sum;
	}
	float average(){
		int suma = sum();
		float vkelements = 0;
		for(int i = 0; i<elems ; i++)
			vkelements+=lists[i].getCount();
		return 1.0 * suma / vkelements;
	}
	void print(){
		if(elems == 0){
			cout<<"the list is empty";
			return;
		}
		else{
			for(int i = 0; i < elems; i ++){
				cout<<"List number: "<< i + 1 << " List info: ";
				lists[i].pecati();
				cout<<endl;
			}
		}
		cout<<"Sum: " << sum();
		cout<<" Average: " <<average() << endl;
		cout << "Successful attempts: " << elems << " Failed attempts: " << tries - elems<< endl;
	}
	void addNewList(List l){
		tries++;
		for(int i = 0; i<elems ; i++)
			if(l.sum() == lists[i].sum())
				return;
		List* temp = new List[elems+1];
		for(int i = 0 ; i<elems ; i++)
			temp[i] = lists[i];
		temp[elems++] = l;
		delete[] lists;
		lists = temp;
	}
};

int main() {
	ListContainer lc;
	int N;
	cin>>N;
	for (int i=0;i<N;i++) {
		int n;
		int niza[100];
		cin>>n;
		for (int j=0;j<n;j++){
			cin>>niza[j];
		}
		List l=List(niza,n);
		lc.addNewList(l);
	}
    int testCase;
    cin>>testCase;
    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();
    }
    else {
        lc.print();
    }
}
*/

/*																													6
enum Extension{txt = 0,pdf,exe};

class File{
private:
	char *name;					//file name
	Extension type;
	char *owner;
	int size;
public:
	File(){
		name = new char[0];
		owner = new char[0];
	}
	File(char* name, char* owner, int size, Extension type){
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);
		this->owner = new char[strlen(owner) + 1];
		strcpy(this->owner,owner);
		this->size = size;
		this->type = type;
	}
	File(const File &f){
		name = new char[strlen(f.name) + 1];
		strcpy(this->name,f.name);
		owner = new char[strlen(f.owner) + 1];
		strcpy(this->owner,f.owner);
		size = f.size;
		type = f.type;
	}
	File& operator=(const File &f){
		delete [] name;
		name = new char[strlen(f.name) + 1];
		strcpy(this->name,f.name);
		delete[] owner;
		owner = new char[strlen(f.owner) + 1];
		strcpy(this->owner,f.owner);
		size = f.size;
		type = f.type;
		return *this;
	}
	void print(){
		
	}
	bool equals(const File &that){
		if((strcmp(name,that.name) == 0) && (strcmp(owner,that.owner) == 0) && (type == that.type))
			return true;
		else
			return false;
	}
	bool equalsType(const File & that){
		if((strcmp(name,that.name) == 0) && (type == that.type))
			return true;
		else
			return false;
	}
	~File(){
		delete[] name;
		delete[] owner;
	}
};

class Folder{
private:
	char* name;							//folder name
	int numFiles;
	File* files;
public:
	Folder(const char *name){
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->numFiles = 0;
		files = new File[0];
	}
	Folder(const Folder &f){
		name = new char[strlen(f.name)+1];
		strcpy(this->name, f.name);
		numFiles = f.numFiles;
		files = new File[numFiles];
		for (int i = 0 ; i <numFiles ; i ++)
			files[i] = f.files[i];
	}
	Folder& operator=(const Folder &f){
		delete [] name;
		name = new char[strlen(f.name)+1];
		strcpy(this->name, f.name);
		numFiles = f.numFiles;
		delete [] files;
		files = new File[numFiles];
		for (int i = 0 ; i <numFiles ; i ++)
			files[i] = f.files[i];
		return *this;
	}
	void print(){
		
	}
	void remove(const File & file){
		int flag = -1;
		for(int i = 0 ; i<numFiles ; i++){
			if(files[i].equals(file)){
				flag = i;
			}
		}
		if(flag != -1){
			File *temp = new File[numFiles - 1];
			for(int i = 0 , j = 0; i <numFiles ; i++){
				if( i != flag){
					temp[j] = files[i];							//=operator
					j++;
				}
			}
			delete[] files;
			files = temp;
			numFiles--;
		}
	}
	void add(const File & file){
		File *temp = new File[numFiles+1];
		for(int i = 0 ; i<numFiles ; i++)
			temp[i] = files[i];
		temp[numFiles++] = file;
		delete[] files;
		files = temp;
	}
	~Folder(){
		delete[] name;
		delete [] files;
	}
};

int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;
	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;
		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;
		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;
		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;	
		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;
		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();
		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();
	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);
		int iter;
		cin >> iter;
		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;
			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);
		int iter;
		cin >> iter;
		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;
			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;
		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
*/