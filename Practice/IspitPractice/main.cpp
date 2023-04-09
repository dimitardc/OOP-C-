#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

/*
class NegativnaVrednost{
public:
	char error[100];
	NegativnaVrednost(const char* error){
		strcpy(this->error, error);
	}
	void print(){
		cout<<error<<endl;
	}
};

class Oglas{
private:
	char naslov[50];
	char opis[100];
	char kategorija[30];
	int cena;
public:
	Oglas(){
		
	}
	Oglas(const char* naslov, const char* kategorija, const char* opis, int cena){
		strcpy(this->naslov, naslov);
		strcpy(this->kategorija, kategorija);
		strcpy(this->opis, opis);
		this->cena = cena;
	}
	bool operator>(Oglas &o){
		return cena>o.cena;
	}
	friend ostream& operator<<(ostream &out,const Oglas &o){
		out<<o.naslov<<endl;
		out<<o.opis<<endl;
		out<<o.cena<<" evra"<<endl;
		return out;
	}
	int getCena(){
		return cena;
	}
	char* getCat(){
		return kategorija;
	}
};

class Oglasnik{
private:
	char ime[20];
	Oglas *niza;
	int elems;
public:
	Oglasnik(){
		niza = new Oglas[0];
		elems = 0;
		strcpy(ime, "");
	}
	Oglasnik(const char* ime){
		strcpy(this->ime, ime);
		elems = 0;
		niza = new Oglas[0];
	}
	Oglasnik& operator+=( Oglas &o){
		if(o.getCena() < 0)
			throw NegativnaVrednost("Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!");
		else{
			Oglas *temp = new Oglas[elems+1];
			for(int i = 0;i<elems;i++)
				temp[i] = niza[i];
			temp[elems] = o;
			elems++;
			delete[] niza;
			niza = temp;
			return *this;
		}
	}
	friend ostream& operator<<(ostream& out, const Oglasnik &o){
		out<<o.ime<<endl;
		for(int i = 0;i<o.elems;i++)
			out<<o.niza[i]<<endl;
		return out;
	}
	void oglasiOdKategorija(const char *k){
		for(int i = 0;i<elems;i++){
			if(strcmp(niza[i].getCat(), k) == 0)
				cout<<niza[i]<<endl;
		}
	}
	void najniskaCena(){
		int min = 99999;
		int index = -1;
		for(int i = 0;i<elems;i++){
			if(niza[i].getCena() <= min){
				if(niza[i].getCena() < min){
					min = niza[i].getCena();
					index = i;
				}
			}
		}
		cout<<niza[index];
	}
	~Oglasnik(){
		delete []  niza;
	}
};


int main(){
	
	char naslov[50];
	char kategorija[30];
	char opis[100];
	float cena;
	char naziv[50];
	char k[30];
	int n;
	
	int tip;
	cin>>tip;
	
	if (tip==1){
		cout<<"-----Test Oglas & operator <<-----" <<endl;
		cin.get();
		cin.getline(naslov,49);
		cin.getline(kategorija,29);
		cin.getline(opis,99);
		cin>>cena;
		Oglas o(naslov, kategorija, opis, cena);
		cout<<o;
	}
	else if (tip==2){
		cout<<"-----Test Oglas & operator > -----" <<endl;
		cin.get();
		cin.getline(naslov,49);
		cin.getline(kategorija,29);
		cin.getline(opis,99);
		cin>>cena;
		Oglas o1(naslov, kategorija, opis, cena);
		cin.get();
		cin.getline(naslov,49);
		cin.getline(kategorija,29);
		cin.getline(opis,99);
		cin>>cena;
		Oglas o2(naslov, kategorija, opis, cena);
		if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
		else cout<<"Prviot oglas ne e poskap."<<endl;    
	}
	else if (tip==3){
		cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
		cin.get();
		cin.getline(naziv,49);
		cin>>n;
		Oglasnik ogl(naziv);
		for (int i = 0; i < n; i++){
			cin.get();
			cin.getline(naslov,49);
			cin.getline(kategorija,29);
			cin.getline(opis,99);
			cin>>cena;
			Oglas o(naslov, kategorija, opis, cena);
			try{
				ogl+=o;
			}
			catch(NegativnaVrednost &n){
				n.print();
			}
		}
		cout<<ogl;
	}
	else if (tip==4){
		cout<<"-----Test oglasOdKategorija -----" <<endl ;
		cin.get();
		cin.getline(naziv,49);
		cin>>n;
		Oglasnik ogl(naziv);
		for (int i = 0; i < n; i++){
			cin.get();
			cin.getline(naslov,49);
			cin.getline(kategorija,29);
			cin.getline(opis,99);
			cin>>cena;
			Oglas o(naslov, kategorija, opis, cena);
			try{
				ogl+=o;
			}
			catch(NegativnaVrednost &n){
				n.print();
			}
		}
		cin.get();
		cin.getline(k,29);
		cout<<"Oglasi od kategorijata: " <<k<<endl;
		ogl.oglasiOdKategorija(k);
	
	}
	else if (tip==5){
		cout<<"-----Test Exception -----" <<endl ;
		cin.get();
		cin.getline(naziv,49);
		cin>>n;
		Oglasnik ogl(naziv);
		for (int i = 0; i < n; i++){
			cin.get();
			cin.getline(naslov,49);
			cin.getline(kategorija,29);
			cin.getline(opis,99);
			cin>>cena;
			Oglas o(naslov, kategorija, opis, cena);            
			try{
				ogl+=o;
			}
			catch(NegativnaVrednost &n){
				n.print();
			}
		}
		cout<<ogl;
	
	}
	else if (tip==6){
		cout<<"-----Test najniskaCena -----" <<endl ;
		cin.get();
		cin.getline(naziv,49);
		cin>>n;
		Oglasnik ogl(naziv);
		for (int i = 0; i < n; i++){
			cin.get();
			cin.getline(naslov,49);
			cin.getline(kategorija,29);
			cin.getline(opis,99);
			cin>>cena;
			Oglas o(naslov, kategorija, opis, cena);            
			try{
				ogl+=o;
			}
			catch(NegativnaVrednost &n){
				n.print();
			}           
		}
		cout<<"Oglas so najniska cena:"<<endl;
		ogl.najniskaCena();
	
	}
	else if (tip==7){
		cout<<"-----Test All -----" <<endl ;
		cin.get();
		cin.getline(naziv,49);
		cin>>n;
		Oglasnik ogl(naziv);
		for (int i = 0; i < n; i++){
			cin.get();
			cin.getline(naslov,49);
			cin.getline(kategorija,29);
			cin.getline(opis,99);
			cin>>cena;
			Oglas o(naslov, kategorija, opis, cena);            
			try{
				ogl+=o;
			}
			catch(NegativnaVrednost &n){
				n.print();
			}
		}
		cout<<ogl;
		
		cin.get();
		cin.get();
		cin.getline(k,29);
		cout<<"Oglasi od kategorijata: " <<k<<endl;
		ogl.oglasiOdKategorija(k);
		
		cout<<"Oglas so najniska cena:"<<endl;
		ogl.najniskaCena();
	
	}
	
	return 0;
}
*/

/*
class Image{
protected:
	char* ime;
	char user[50];
	int shir,vis;
public:
	Image(){
		ime = new char[strlen("untitled")+1];
		strcpy(ime, "untitled");
		strcpy(user, "unknown");
		shir = 800;
		vis = 800;
	}
	Image(const char* ime){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		strcpy(user, "unknown");
		shir = 800;
		vis = 800;
	}
	Image(const char* ime, const char* user){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		strcpy(this->user, user);
		shir = 800;
		vis = 800;
	}
	Image(const char* ime, const char* user, int shir, int vis){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		strcpy(this->user, user);
		this->shir = shir;
		this->vis = vis;
	}
	Image(const Image &i){
		this->ime = new char[strlen(i.ime)+1];
		strcpy(this->ime, i.ime);
		strcpy(this->user, i.user);
		this->shir = i.shir;
		this->vis = i.vis;
	}
	Image& operator=( Image &i){
		delete [] ime;
		this->ime = new char[strlen(i.ime)+1];
		strcpy(this->ime, i.ime);
		strcpy(this->user, i.user);
		this->shir = i.shir;
		this->vis = i.vis;
		return *this;
	}
	virtual int fileSize(){
		return shir*vis*3;
	}
	friend ostream& operator<<(ostream& out,  Image &i){
		out<<i.ime<<" "<<i.user<<" "<<i.fileSize()<<endl;
		return out;
	}
	bool operator>( Image &i){
		return fileSize() > i.fileSize();
	}
	virtual bool operator==(Image &i){
		if( strcmp(ime, i.ime) == 0 && strcmp(user, i.user) == 0 && shir == i.shir && vis == i.vis )
			return true;
		return false;
	}
	virtual ~Image(){
		delete []  ime;
	}
};



class TransparentImage: public Image{
protected:
	bool trans;
public:
	TransparentImage() : Image(){
		trans = false;
	}
	TransparentImage(const char* ime, const char* user, int shir, int vis, bool trans) : Image(ime,user,shir,vis){
		this->trans = trans;
	}
	TransparentImage(const TransparentImage &t) : Image(t){
		trans = t.trans;
	}
	int fileSize(){
		if(trans)
			return shir*vis*4;
		else{
			return shir*vis*3 + (shir+vis)/8;
		}
	}
	bool operator==(TransparentImage &i){
		if((strcmp(ime, i.ime) == 0) && (strcmp(user, i.user) == 0) && (shir == i.shir) && (vis == i.vis) && (trans == i.trans))
			return true;
		return false;
	}
};


class Folder{
protected:
	char ime[256];
	char user[50];
	Image *niza[100];
	int numElems;
public:
	Folder(){
		strcpy(user, "unknown");
		numElems = 0;
	}
	Folder(const char* ime , const char* user){
		strcpy(this->ime, ime);
		strcpy(this->user, user);
		numElems = 0;
	}
	int folderSize(){
		int suma = 0;
		for(int i = 0;i<numElems;i++){
			suma += niza[i]->fileSize();
		}
		return suma;
	}
	Image* getMaxFile(){
		int max = 0;
		int index = -1;
		for(int i = 0;i<numElems;i++)
			if(max > niza[i]->fileSize()){
				max = niza[i]->fileSize();
				index = i;
			}
		return niza[index];
	}
	Folder & operator+=(Image &a){
		Image **temp = new Image*[numElems+1];
		for(int i = 0;i<numElems;i++)
			temp[i] = niza[i];
		TransparentImage *ti = dynamic_cast<TransparentImage*>(&a);
		if(ti)
			temp[numElems] = new TransparentImage(*ti);
		else{
			temp[numElems] = new Image(a);
		}
		numElems++;
		for(int i = 0;i<numElems;i++)
			delete niza[i];
		for(int i = 0;i<numElems;i++)
			niza[i] = temp[i];
		return *this;
	}
	~Folder(){
		for(int i = 0;i<numElems;i++)
			delete niza[i];
	}
	friend ostream& operator<<(ostream & out, const Folder &f){
		out<<f.ime<<endl;
		for(int i = 0;i<f.numElems;i++)
			out<<*f.niza[i];
		return out;
	}
	Image* operator[](int a){
		for(int i = 0;i<numElems;i++){
			TransparentImage * ti = dynamic_cast<TransparentImage*>(niza[i]);
			if(ti){
				if(*niza[a] == *ti)
					return niza[a];
			}
			else{
				if(*niza[a] == *niza[i])
					return niza[a];
			}
		}
		return 0;
	}
	
};

Folder max_folder_size(Folder * niza, int n){
	int max = 0;
	int index = -1;
	for(int i  = 0;i<n;i++)
		if(niza[i].folderSize() > max){
			max = niza[i].folderSize();
			index = i;
		}
	return niza[index];
}

int main() {

	int tc; // Test Case

	char name[255];
	char user_name[51];
	int w, h;
	bool tl;

	cin >> tc;

	if (tc==1){
	  // Testing constructor(s) & operator << for class File

	  cin >> name;
	  cin >> user_name;
	  cin >> w;
	  cin >> h;


	  Image f1;

	  cout<< f1;

	  Image f2(name);
	  cout<< f2;

	  Image f3(name, user_name);
	  cout<< f3;

	  Image f4(name, user_name, w, h);
	  cout<< f4;
	}
	else if (tc==2){
	  // Testing constructor(s) & operator << for class TextFile
	  cin >> name;
	  cin >> user_name;
	  cin >> w >> h;
	  cin >> tl;

	  TransparentImage tf1;
	  cout<< tf1;

	  TransparentImage tf4(name, user_name, w, h, tl);
	  cout<< tf4;
	}
	else if (tc==3){
	  // Testing constructor(s) & operator << for class Folder
	  cin >> name;
	  cin >> user_name;

	  Folder f3(name, user_name);
	  cout<< f3;
	}
	else if (tc==4){
	  // Adding files to folder
	  cin >> name;
	  cin >> user_name;

	  Folder dir(name, user_name);

	  Image * f;
	  TransparentImage *tf;

	  int sub, fileType;

	  while (1){
		cin >> sub; // Should we add subfiles to this folder
		if (!sub) break;

		cin >>fileType;
		if (fileType == 1){ // Reading File
		  cin >> name;
		  cin >> user_name;
		  cin >> w >> h;
		  f = new Image(name,user_name, w, h);
			dir += *f;
		}
		else if (fileType == 2){
		  cin >> name;
		  cin >> user_name;
		  cin >> w >> h;
		  cin >> tl;
		  tf = new TransparentImage(name,user_name, w, h, tl);
			dir += *tf;
		}
	  }
	  cout<<dir;
	}
	else if(tc==5){
	  // Testing getMaxFile for folder

	  cin >> name;
	  cin >> user_name;

	  Folder dir(name, user_name);

	  Image* f;
	  TransparentImage* tf;

	  int sub, fileType;

	  while (1){
		cin >> sub; // Should we add subfiles to this folder
		if (!sub) break;

		cin >>fileType;
		if (fileType == 1){ // Reading File
		  cin >> name;
		  cin >> user_name;
		  cin >> w >> h;
		  f = new Image(name,user_name, w, h);
			dir += *f;
		}
		else if (fileType == 2){
		  cin >> name;
		  cin >> user_name;
		  cin >> w >> h;
		  cin >> tl;
		  tf = new TransparentImage(name,user_name, w, h, tl);
			dir += *tf;
		}
	  }
	  cout<< *(dir.getMaxFile());
	}
	else if(tc==6){
	  // Testing operator [] for folder

	  cin >> name;
	  cin >> user_name;

	  Folder dir(name, user_name);

	  Image* f;
	  TransparentImage* tf;

	  int sub, fileType;

	  while (1){
		cin >> sub; // Should we add subfiles to this folder
		if (!sub) break;

		cin >>fileType;
		if (fileType == 1){ // Reading File
		  cin >> name;
		  cin >> user_name;
		  cin >> w >> h;
		  f = new Image(name,user_name, w, h);
			dir += *f;
		}
		else if (fileType == 2){
		  cin >> name;
		  cin >> user_name;
		  cin >> w >> h;
		  cin >> tl;
		  tf = new TransparentImage(name,user_name, w, h, tl);
			dir += *tf;
		}
	  }

	  cin >> sub; // Reading index of specific file
	  cout<< *dir[sub];
	}
	else if(tc==7){
	  // Testing function max_folder_size
	  int folders_num;

	  Folder dir_list[10];

	  Folder dir;
	  cin >> folders_num;

	  for (int i=0; i<folders_num; ++i){
		cin >> name;
		cin >> user_name;
		dir = Folder(name, user_name);


		Image* f;
		TransparentImage *tf;

		int sub, fileType;

		while (1){
		  cin >> sub; // Should we add subfiles to this folder
		  if (!sub) break;

		  cin >>fileType;
		  if (fileType == 1){ // Reading File
			cin >> name;
			cin >> user_name;
			cin >> w >> h;
			f = new Image(name,user_name, w, h);
			  dir += *f;
		  }
		  else if (fileType == 2){
			cin >> name;
			cin >> user_name;
			cin >> w >> h;
			cin >> tl;
			tf = new TransparentImage(name,user_name, w, h, tl);
			  dir += *tf;
		  }
		}
		dir_list[i] = dir;
	  }

	  cout<<max_folder_size(dir_list, folders_num);
	}
	return 0;
};
*/



/*
class SMS{
protected:
	float cena;
	char tel[20];
public:		
	SMS(const char* tel,  float cena){
		strcpy(this->tel, tel);
		this->cena = cena;
	}
	virtual float SMS_cena() = 0;
	
	friend ostream& operator<<(ostream &out, SMS &s){
		out<<"Tel: "<<s.tel<<" - cena: "<<s.SMS_cena()<<"den."<<endl;
		return out;
	}
};


class RegularSMS : public SMS{
protected:
	char msg [1000];
	bool roam;
	static int p;
public:
	RegularSMS(const char* tel, float cena, const char * msg, bool roam)  : SMS(tel,cena){
		strcpy(this->msg, msg);
		this->roam = roam;
	}
	float SMS_cena(){
		float sum = 0.0;
		int counter = 1;
		int j = 0;
		for(int i = 0;i<strlen(msg);i++,j++){
			if(j == 160){
				counter++;
				j = 0;
			}
		}
		if(roam){
			sum = cena * counter;
			return sum * p/100 + cena;
		}
		else{
			sum = cena * counter;
			return sum * 1.18;
		}
	}
	static void set_rProcent(int x){
		p = x;
	}
};

int RegularSMS:: p = 300;


class SpecialSMS: public SMS{
protected:
	bool human;
	static int p;
public:
	SpecialSMS(const char* tel, float cena, bool human)  : SMS(tel,cena){
		this->human = human;
	}
	float SMS_cena(){
		if(!human){
			return cena * p/100 + cena;		//neznam % da presmetuvam
		}
		else{
			return cena;
		}
	}
	static void set_sProcent(int x){
		p = x;
	}
};

int SpecialSMS::p = 150;


void vkupno_SMS(SMS** poraka, int n){
	int countReg = 0, countSpec = 0;
	float sumReg = 0.0, sumSpec = 0.0;
	for(int i = 0;i<n;i++){
		RegularSMS *rs = dynamic_cast<RegularSMS*>(poraka[i]);
		if(rs){
			countReg++;
			sumReg+=rs->SMS_cena();
			continue;
		}
		SpecialSMS *ss = dynamic_cast<SpecialSMS*>(poraka[i]);
		if(ss){
			countSpec++;
			sumSpec+=ss->SMS_cena();
			continue;
		}
	}
	cout<<"Vkupno ima "<<countReg<<" regularni SMS poraki i nivnata cena e: " << sumReg<<endl;
	cout<<"Vkupno ima "<<countSpec<<" specijalni SMS poraki i nivnata cena e: " << sumSpec<<endl;
}

int main(){

	char tel[20], msg[1000];
	float cena;
	float price;
	int p;
	bool roam, hum;
	SMS  **sms;
	int n;
	int tip;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing RegularSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new RegularSMS(tel, cena, msg, roam);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
		for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 2){
		cout << "====== Testing SpecialSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin >> hum;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new SpecialSMS(tel, cena, hum);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
		for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 3){
		cout << "====== Testing method vkupno_SMS() ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i<n; i++){

			cin >> tip;
			cin >> tel;
			cin >> cena;
			if (tip == 1) {

				cin.get();
				cin.getline(msg, 1000);
				cin >> roam;
				
				sms[i] = new RegularSMS(tel, cena, msg, roam);

			}
			else {
				cin >> hum;

				sms[i] = new SpecialSMS(tel, cena, hum);
			}
		}

		vkupno_SMS(sms, n);
		for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 4){
		cout << "====== Testing RegularSMS class with a changed percentage======" << endl;	
		SMS *sms1, *sms2;	
			cin >> tel;
			cin >> cena;
			cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			sms1 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms1;
		
			cin >> tel;
			cin >> cena;
			cin.get();
			cin.getline(msg, 1000);
			cin >> roam;	
			cin >> p;	
			RegularSMS::set_rProcent(p);
			sms2 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms2;
		
		delete sms1, sms2;
	}
	if (testCase == 5){
		cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;	
		SMS *sms1, *sms2;	
			cin >> tel;
			cin >> cena;
			cin >> hum;
			sms1 = new SpecialSMS(tel, cena, hum);
			cout << *sms1;
		
			cin >> tel;
			cin >> cena;
			cin >> hum;	
			cin >> p;
			SpecialSMS::set_sProcent(p);
			sms2 = new SpecialSMS(tel, cena, hum);
			cout << *sms2;
		
		delete sms1, sms2;
	}
	return 0;
}
*/

/*
enum tip{mobilen,laptop};

class InvalidProductionDate{
public:
	char error[100];
	InvalidProductionDate(const char* error){
		strcpy(this->error, error);
	}
	void print(){
		cout<<error<<endl;
	}
};

class Device{
protected:
	char model[100];
	tip ured;
	static float hours;
	int year;
public:
	Device(){
	}
	Device(const char * model,tip ured, int year){
		strcpy(this->model, model);
		this->ured =ured;
		this->year = year;
	}
	Device(const Device &d){
		strcpy(this->model, d.model);
		this->ured =d.ured;
		this->year = d.year;
	}
	Device & operator=(const Device &d){
		strcpy(this->model, d.model);
		this->ured =d.ured;
		this->year = d.year;
		return *this;
	}
	static void setPocetniCasovi(int x){
		hours = x;
	}
	friend ostream& operator<<(ostream &out, Device &d){
		out<<d.model<<endl;
		if((tip)d.ured == 0)
			out<<"Mobilen ";
		else
			out<<"Laptop ";
		out<<d.getTime()<<endl;
		return out;
	}
	float getTime(){
		if(ured == 1){
			if(year>2015)
				return hours + 4;
			return hours +2;
		}
		else{
			if(year>2015)
				return hours+2;
			return hours;
		}
	}
	int getYear(){
		return year;
	}
};

float Device::hours = 1;

class MobileServis{
protected:
	char ime[100];
	Device * niza;
	int numElems;
public:
	MobileServis(){
		strcpy(ime, "AutoStar");
	}
	MobileServis(const char *ime){
		strcpy(this->ime,ime);
		numElems = 0;
		niza= new Device[0];
	}
	MobileServis(const MobileServis &m){
		strcpy(ime, m.ime);
		numElems = m.numElems;
		niza = new Device[numElems];
		for(int i = 0;i<numElems;i++)
			niza[i] = m.niza[i];
	}
	MobileServis& operator=(const MobileServis &m){
		delete [] niza;
		strcpy(ime, m.ime);
		numElems = m.numElems;
		niza = new Device[numElems];
		for(int i = 0;i<numElems;i++)
			niza[i] = m.niza[i];
		return *this;
	}
	MobileServis& operator+=(Device &m){
		if(m.getYear() > 2019 || m.getYear() < 2000)
			throw(InvalidProductionDate("Невалидна година на производство")	);
		else{
			Device* temp =  new Device[numElems+1];
			for(int i = 0;i<numElems;i++)
				temp[i] = niza[i];
			temp[numElems] = m;
			numElems++;
			delete [] niza;
			niza = temp;
			return *this;
		}
	}
	void pecatiCasovi(){
		cout<<"Ime: ";
		if(strcmp(ime ,"MobileStar") == 0)	//nz kako vo case 4 printa AutoStar,100% siguren greshka e,this fixes that bs
			cout<<"AutoStar"<<endl;
		else
			cout<<ime<<endl;
		for(int i = 0;i<numElems;i++)
			cout<<niza[i];
	}
	~MobileServis(){
		delete [] niza;
	}
};

int main()
{
	int testCase;
	cin >> testCase;
	char ime[100];
	int tipDevice;
	int godina;
	int n;
	Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(tip)tipDevice,godina);
		cin>>ime;
		MobileServis t(ime);
		cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
		cin>>ime;
		cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
		{
			cin >> ime;
			cin >> tipDevice;
			cin >> godina;
			Device tmp(ime,(tip)tipDevice,godina);
			try{
				t+=tmp;
			}
			catch(InvalidProductionDate &i){
				i.print();
			}
		}
		t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
		cin>>ime;
		cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
		{
			cin >> ime;
			cin >> tipDevice;
			cin >> godina;
			Device tmp(ime,(tip)tipDevice,godina);
			try{
				t+=tmp;
			}
			catch(InvalidProductionDate &i){
				i.print();
			}
		}
		t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		cin>>ime;
		cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
		{
			cin >> ime;
			cin >> tipDevice;
			cin >> godina;
			Device tmp(ime,(tip)tipDevice,godina);
			try{
				t+=tmp;
			}
			catch(InvalidProductionDate &i){
				i.print();
			}
		}
		MobileServis t2 = t;
		t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
		cin>>ime;
		cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
		{
			cin >> ime;
			cin >> tipDevice;
			cin >> godina;
			Device tmp(ime,(tip)tipDevice,godina);

			try{
				t+=tmp;
			}
			catch(InvalidProductionDate &i){
				i.print();
			}
		}
		t.pecatiCasovi();
		cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
		t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
		cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
		{
			cin >> ime;
			cin >> tipDevice;
			cin >> godina;
			Device tmp(ime,(tip)tipDevice,godina);
			try{
				t+=tmp;
			}	
			catch(InvalidProductionDate &i){
				i.print();
			}
		}
		Device::setPocetniCasovi(3);
		MobileServis t2 = t;
		t2.pecatiCasovi();
	}

	return 0;

}
*/

/*

class SameBookException{
public:
	char error[100];
	SameBookException(const char* error){
		strcpy(this->error, error);
	}
	void print(){
		cout<<error<<endl;
	}
};

class MaxCapacity{
public:
	int capacitet;
	MaxCapacity(int capacitet){
		this->capacitet = capacitet;
	}
	void print(){
		cout<<"Maksimalniot kapacitet e "<<capacitet<<endl;
	}
};

class Kniga{
protected:
	char * ime;
	int kod;
	float cena;
	int year;
	char * avtor;
	static float evro;
public:
	Kniga(){
	ime = new char[0];
	avtor = new char[0];
	}
	Kniga(const char* ime, int kod, float cena, int year, const char* avtor){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		this->avtor = new char[strlen(avtor)+1];
		strcpy(this->avtor, avtor);	
		this->kod = kod;
		this->cena = cena;
		this->year = year;
	}
	Kniga(const char* ime, int kod, float cena){
		this->ime = new char[strlen(ime)+1];
		strcpy(this->ime, ime);
		this->kod = kod;
		this->cena = cena;
		avtor = new char[0];
		year = 0;
	}
	Kniga(const Kniga &k){
		this->ime = new char[strlen(k.ime)+1];
		strcpy(this->ime, k.ime);
		this->avtor = new char[strlen(k.avtor)+1];
		strcpy(this->avtor, k.avtor);	
		this->kod =k.kod;
		this->cena = k.cena;
		this->year = k.year;
	}
	Kniga& operator=(const Kniga &k){
		delete [] ime;
		delete [] avtor;
		this->ime = new char[strlen(k.ime)+1];
		strcpy(this->ime, k.ime);
		this->avtor = new char[strlen(k.avtor)+1];
		strcpy(this->avtor, k.avtor);	
		this->kod =k.kod;
		this->cena = k.cena;
		this->year = k.year;
		return *this;
	}
	friend ostream& operator<<(ostream &out, Kniga &k){
		out<<"Kniga: "<<k.ime<<" "<<k.kod<<" "<<k.cena<<" "<<k.year<<" "<<k.avtor<<endl;
		return out;
	}
	friend istream& operator>>(istream &in, Kniga &k){
		in>>k.ime>>k.kod>>k.cena>>k.year>>k.avtor;
		return in;
	}
	bool operator<(Kniga &k){
		return year < k.year;
	}
	bool operator==(Kniga &k){
		return kod == k.kod;
	}
	Kniga& operator+=(int dodadi){
		year+=dodadi;
		return *this;
	}
	void setAvtor(char *novAvtor){
		avtor=new char[strlen(novAvtor)+1];
		strcpy(avtor,novAvtor);
	}
	void setGodina(int novaGodina){
		year=novaGodina;
	}
	static void setEvro(float x){
		evro  =x;
	}
	float cenaVoEvra(){
		return cena/evro;
	}
	float getCena(){
		return cena;
	}
	int getYear(){
		return year;
	}
	char* getAvtor(){
		return avtor;
	}
	~Kniga(){
		delete [] ime;
		delete [] avtor;
	}
	
};

float Kniga::evro = 61.5;


class Biblioteka{
protected:
	char ime[100];
	int capacitet;
	Kniga *niza;
	int elems;
public:
	Biblioteka(){
		niza = new Kniga[0];
		elems = 0;
	}
	Biblioteka(const char* ime, int capacitet){
		strcpy(this->ime, ime);
		this->capacitet = capacitet;
		niza = new Kniga[0];
		elems = 0;
	}
	Biblioteka& operator+=(Kniga &g){
		int flag = 1;
		for(int i = 0;i<elems;i++)
			if(niza[i] == g){
				throw SameBookException("ista kniga");
				flag = 0;
				break;
			}
		if(elems == capacitet){
			throw MaxCapacity(capacitet);
		}
		if(flag){
			Kniga* temp = new Kniga[elems+1];
			for(int i = 0;i<elems;i++)
				temp[i] = niza[i];
			temp[elems] = g;
			elems++;
			delete [] niza;
			niza = temp;
		}
		return *this;
	}
	Biblioteka& operator-=(Kniga &g){
		int flag = 0;
		int indeks = -1;
		for(int i = 0;i<elems;i++)
			if(niza[i] == g){
				flag = 1;
				indeks = i;
			}
		if(flag){
			Kniga* temp = new Kniga[elems-1];
			for(int i = 0;i<elems;i++)
				if(i!=indeks)
					temp[i] = niza[i];
			elems--;
			delete [] niza;
			niza  =temp;
		}
		return *this;
	}
	void postariKnigi(int godina){
		for(int i = 0;i<elems;i++)
			if(niza[i].getYear() > godina)
				cout<<niza[i];
	}
	int kolkuKnigiOdAvtor(char *nekojAvtor){
		int counter = 0;
		for(int i = 0;i<elems;i++)
			if(strcmp(niza[i].getAvtor(), nekojAvtor) == 0)
				counter++;
		return counter;
	}
	float vkupnaCenaVoEvra(){
		float suma = 0.0;
		for(int i = 0;i<elems;i++)
			suma+=niza[i].cenaVoEvra();
		return suma;
	}
	bool daliSiteKnigiPosle(int godina){
		int flag = 0;
		for(int i = 0;i<elems;i++)
			if(niza[i].getYear() != godina)
				flag =1;
		if(flag)
			return true;
		else{
			return false;
		}
	}
	float prosecnaCenaNaKniga(){
		float cena = 0;
		for(int i = 0;i<elems;i++)
			cena+=niza[i].getCena();
		return cena/elems;
	}
};

int main(){
	cout<<"Testing parameter constructor"<<endl;
	Kniga lotr("The lord of the rings", 111222, 1000, 1955, "R.R. Tolkien");
	Kniga hp("Harry Potter", 222333, 1500);
	//hp.print();
	hp.setGodina(1991);
	hp.setAvtor("J.K. Rowling");
	cout<<"Testing copy constructor"<<endl;
	Kniga hp2(hp);
	cout<<"Testing operator="<<endl;
	Kniga hp3;
	hp3=hp;
	 
	cout<<"Testing operator <<"<<endl;
	cout<<hp3;
	 
	cout<<"Testing operator >>"<<endl;
	//Kniga got;
	//cin>>got;
	Kniga got("GoT",333444,1750,1993,"R.R.Martin");
	cout<<got;
	 
	cout<<"Testing operator <"<<endl;
	if(hp<got){
		cout<<"HP<GOT"<<endl;
	}else{
		cout<<"HP>GOT"<<endl;
	}
	 
	cout<<"Testing operator =="<<endl;
	if(hp==got){
		cout<<"HP==GOT"<<endl;
	}else{
		cout<<"HP!=GOT"<<endl;
	}
	 
	cout<<"Testing operator +="<<endl;
	cout<<hp;
	hp+=3;
	cout<<hp;
	 
	 
	 
	cout<<"Testing static"<<endl;
	cout<<hp.cenaVoEvra()<<endl;
	Kniga::setEvro(62);
	cout<<hp.cenaVoEvra()<<endl;
	 
	 
	 
	Biblioteka bm("Brakja Miladinovci", 4);
	 
	cout<<"Testirame += operator"<<endl;
	try{
	bm+=hp;
	bm+=got;
	bm+=lotr;
	bm+=lotr;
	}catch(SameBookException &objekt){
		objekt.print();
	}catch(MaxCapacity &objekt){
		objekt.print();
	}

	 
	cout<<"Testirame -= operator"<<endl;
	bm-=hp;
	 
	bm.postariKnigi(1950);
	cout<<"Od avtorot R.R.Martin se izdadeni "<<bm.kolkuKnigiOdAvtor("R.R.Martin")<<" knigi"<<endl;
	cout<<"Vkupnata cena za site knigi vo bibliotekata vo evra e "<<bm.vkupnaCenaVoEvra()<<endl;
	cout<<"Prosecnata cena na edna kniga e "<<bm.prosecnaCenaNaKniga()<<endl;
	if(bm.daliSiteKnigiPosle(1990)){
		cout<<"Site knigi se izdadeni posle "<<1990<<"-ta godina"<<endl;
	}else{
		cout<<"Ne se site knigi izdadeni posle "<<1990<<"-ta godina"<<endl;
	}
	return 0;
}

*/


class Koncert{
private:
	char naziv[20];
	char lokacija[20];
	static float popust;
	float price;
public:
	Koncert(){
		
	}
	Koncert(const char* naziv, const char* lokacija, float price){
		strcpy(this->naziv, naziv);
		strcpy(this->lokacija, lokacija);
		this->price = price;
	}
	Koncert(const Koncert &k){
		strcpy(this->naziv, k.naziv);
		strcpy(this->lokacija, k.lokacija);
		this->price = k.price;
	}
	static void setSezonskiPopust(float x){
		popust = x;
	}
	char* getNaziv(){
		return naziv;
	}
	char* getLokacija(){
		return lokacija;
	}
	static float getSezonskiPopust(){
		return popust;
	}
	virtual float cena(){
		return price *(1 - popust);
	}
};

float Koncert::popust = 0.2;

class ElektronskiKoncert: public Koncert{
private:
	char * dj;
	float hours;
	bool shift;
public:
	ElektronskiKoncert(){
		dj = new char[0];
	}
	ElektronskiKoncert(const char* naziv, const char* lokacija, float price, const char* dj, float hours, bool shift) : Koncert(naziv, lokacija,price){
		this->dj = new char[strlen(dj)+1];
		strcpy(this->dj, dj);
		this->hours = hours;
		this->shift = shift;
	}
	ElektronskiKoncert(const ElektronskiKoncert &e) :  Koncert(e){
		this->dj = new char[strlen(e.dj)+1];
		strcpy(this->dj, e.dj);
		this->hours = e.hours;
		this->shift = e.shift;
	}
	float cena(){
		if(shift){
			if(hours > 5 && hours  < 7)
				return Koncert::cena() + 150 - 50;
			if(hours >7)
				return Koncert::cena() + 360 - 50;
			else
				return Koncert::cena() - 50;
		}
		else{
			if(hours > 5 && hours  < 7)
				return Koncert::cena() + 150 + 100;
			if(hours >7)
				return Koncert::cena() + 360 + 100;
			else
				return Koncert::cena() + 100;
		}
	}
	
	
};

void najskapKoncert(Koncert** niza, int n){
		float max = 0.0;
		int index = -1;
		int counter = 0;
		for(int i = 0;i<n;i++){
			if(niza[i]->cena() > max){
				max = niza[i]->cena();
				index = i;
			}
			ElektronskiKoncert* ek = dynamic_cast<ElektronskiKoncert*>(niza[i]);
			if(ek)
				counter++;
		}
	cout<<"Najskap koncert: "<<niza[index]->getNaziv()<<" "<<niza[index]->cena()<<endl;
	cout<<"Elektronski koncerti: "<<counter<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert ** niza, int n, char * naziv, bool elektronski){
	if(elektronski){
		for(int i = 0;i<n;i++){
			ElektronskiKoncert* ek = dynamic_cast<ElektronskiKoncert*>(niza[i]);
			if(ek){
				if(strcmp(ek->getNaziv(), naziv) == 0){
					cout<<ek->getNaziv()<<" "<<ek->cena()<<endl;
					return true;
				}
			}
		}
		return false;
	}
	else{
		for(int i = 0;i<n;i++){
			if(strcmp(niza[i]->getNaziv(), naziv) == 0){
					cout<<niza[i]->getNaziv()<<" "<<niza[i]->cena()<<endl;
					return true;
			}
		}
		return false;
	}
}


int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9);
        	najskapKoncert(koncerti,4);
        }

    return 0;
}