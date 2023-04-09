#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

/*
class TennisPlayer{
private:
	char name[50];
	char surname[50];
	bool playsInLeague;
public:
	TennisPlayer(){
		
	}
	TennisPlayer(const char* name,const char* surname, bool playsInLeague){
		cout<<"Constructor: "<<endl;
		strcpy(this->name, name);
		strcpy(this->surname, surname);
		this->playsInLeague = playsInLeague;
	}
	TennisPlayer(const char* name,const char* surname){
		cout<<"Constructor: "<<endl;
		strcpy(this->name, name);
		strcpy(this->surname, surname);
		this->playsInLeague = false;
	}
	void Print(){
		cout<< surname << ","<<name;
	}
	void setPlaysInLeague(bool pl){
		playsInLeague = pl;
	}
	~TennisPlayer(){
		cout<<"Destructor TennisPlayer for: "<< name <<" "<<surname<<endl;
	}
	friend ostream& operator<<(ostream& out, const TennisPlayer &t){
		out << "-- Tennis Player --\n";
		out << t.name << " ";
		out << t.surname << " - " << t.playsInLeague << endl;
		return out;
	}
};

class RankedTennisPlayer : public TennisPlayer{
private:
	int rank;
public:
	RankedTennisPlayer(){
	}
	RankedTennisPlayer(const char* name,const  char* surname, bool playsInLeague, int rank) : TennisPlayer(name,surname,playsInLeague) {
		this->rank = rank;
		cout<<"Constructor RankedTennisPlayer"<<endl;
	}
	RankedTennisPlayer(const TennisPlayer &t, int rank) : TennisPlayer(t){  //default copy const za t
		this->rank = rank;
	}
	friend ostream& operator<<(ostream& out, const RankedTennisPlayer &tp){
		out << "-- RANKED TENNIS PLAYER --\n";
		out << TennisPlayer (tp);
		out << "Rank: " << tp.rank << endl;
		return out;
	}
	~RankedTennisPlayer() {
		cout << "Destructor RankedTennisPlayer\n" << endl;
	}

};

int main() {
	  TennisPlayer rf("Roger", "Federer");
	  TennisPlayer ng("Novak", "Djokovikj");
	  cout << rf;
	  cout << ng;
	  //TennisPlayer t;
	  RankedTennisPlayer rn("Rafael", "Nadal", true, 2750);
	  cout << rn;
	  TennisPlayer tp = rn;
	  cout << tp;
	  //RankedTennisPlayer copy(tp);
	  RankedTennisPlayer copy(ng, 3320);
	  cout << copy;
	  return 0;
}
*/


class DebitAccount{
private:
	char name[100];
	long number;
	double balance;
public:
	DebitAccount(){
		number = 0;
		balance = 0.0;
	}
	DebitAccount(const char* name , long number , double balance){
		strcpy(this->name, name);
		this->number = number;
		this->balance = balance;
	}
	void showInfo(){
		cout << name << '\n';
		cout << "\t Bank No: "<< number << '\n';
		cout << "\t Balance: "<< getBalance() << '\n';
	}
	void deposit(double amount){
		if (amount >=0 )
			balance += amount;
		else
			cout<< "You can not add negative amount to your balance!"<<endl;
	}
	void withdraw(double amount) {
		if (amount < 0) {
			cout<< "You can note withdraw negative amount from your account!"<<endl;
			return;
		}
		if (amount <= balance) {
			balance -= amount;
		}
		else {
			cout << "You can not withdraw more money than you have on your account.\n"
			<< "Please upgrade your debut account to credit account!"<<endl;
		}
	}
	double getBalance(){
		return balance;
	}
	~DebitAccount()		{}
};

class CreditAccount : public DebitAccount{
private:
	double limit;
	double interest;		//vo %
	double minus;
public:
	CreditAccount(){
	}
	CreditAccount(const char *name , long number , double balance , double limit) : DebitAccount(name,number,balance){
		//if DebitAccount members were protected (instead of private) we wouldnt need the : after this const and just directly pass the values into this const 
		//strcpy(this->name, name);
		//this->number = number;
		//this->balance = balance;
		this->limit = limit;
		this->interest = interest;
		this->minus = minus;
		interest = 0.05;
		minus = 0;
	}
	void withdraw(double amount){
		int balance = getBalance();
		if(amount <= balance){
			DebitAccount::withdraw(amount);
		}
		else if(amount <= balance + limit - minus){
			double advance = amount - balance;
			this->minus +=advance * (1.0 + interest);
			cout<<"Minus: " << advance <<"\n"<< "Minus with interest: " << advance*interest<<endl;
			deposit(advance);
			DebitAccount::withdraw(amount);
		}
		 else {
			cout << "The bank is not giving you that much money..." << endl;
			showInfo();
		}
	}
	void showInfo() {
	DebitAccount::showInfo();			//you can avoid this by naming the other showInfo (ex. Sinfo() ) and calling it as Sinfo()		its that simple
	cout<<"\t Limit: "<<this->limit << "\n"
	<<"\t In minus: " << this->minus << "\n"
	<<"\t Interest: " << this->interest << "%\n";
	}
	double getInterest() {
		return interest;;
	}
};

int main() {
	  DebitAccount d("Pero Perovski", 6, 100000);
	  CreditAccount ca("Mitko Mitkovski", 10, 5000, 1000);
	  d.showInfo();
	  d.deposit(50000);
	  d.withdraw(600000);
	  d.showInfo();
	  ca.showInfo();
	  ca.deposit(500);
	  ca.showInfo();
	  ca.withdraw(6200);
	  ca.showInfo();
	  return 0;
}
