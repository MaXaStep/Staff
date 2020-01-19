#include <iostream>
#include<windows.h>
#include <fstream>
#include<ctime>
#include<iomanip>
#include<string>
#include<typeinfo>
#include<dos.h>
#include<conio.h>
using namespace std;

string waytostaff = "staff.txt";
string waytoshareholders = "shareholders.txt";
string waytoleadership = "leadership.txt";
string waytoworker = "worker.txt";
int counterstaff = 0;

class staff;
class shareholders;
class worker;
class leadership;


class staff {
private:
	
	
public:
	string name;
	
	string surname;
	int age;
	int id;
	char sex;

	staff():name("N/A"),surname("N/A"),age(0),id(00000),sex('n'){

	}
	staff(string na,string sur,int ag,char se):name(na),surname(sur),age(ag),sex(se) {
		counterstaff++;
		id = rand()%1000;
	}
	virtual void getdata()=0 {
		counterstaff++;
		cout << "Введите имя сотрудника..."; cin >> name;
		cout << "Введите фамилию сотрудника..."; cin >> surname;
		cout << "Введите возраст сотрудника в годах..."; cin >> age;
		cout << "Введите пол сотрудника... m/w "; cin >> sex;
		id = 1000 + counterstaff;
	}
	virtual void datainfile(int n) {

	}
	virtual void datainfile() {

	}
	string getnasur() {

		return name + surname;
	}
};
class shareholders :public staff {
private:
	int kof = 1;
	double perstocks;
	double capital;
	bool bigorsmall;
public:
	shareholders():staff(),perstocks(0),capital(0),bigorsmall(false){

	}
	shareholders(string na, string sur, int ag, char se,double pers,double cap):staff(na,sur,ag,se),perstocks(pers),capital(cap){
		if (perstocks>5.5) {
			bigorsmall = true;
		}
		else {
			bigorsmall = false;
		}
	}
	void getdata() {
		staff::getdata();
		cout << "Введите процент акций..."; cin >> perstocks;
		cout << "Введите капитал "; cin >> capital;
		if (perstocks > 5.5) {
			bigorsmall = true;
		}
		else {
			bigorsmall = false;
		}
	}
	void datainfile() {
		
		ofstream fin;
		fin.open(waytoshareholders, ofstream::app);
		fin <<"Name-"<<""<< this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Capital-" << this->capital << " BigOrSmall-" << this->bigorsmall << " Perstocks-" << this->perstocks << " kof" << kof << endl;
		fin.close();
	}
	void datainfile(int n) {
		ofstream fin;
		fin.open(waytoshareholders,ofstream::app);
		fin << "Name-" << "" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Capital-" << this->capital << " BigOrSmall-" << this->bigorsmall << " Perstocks-" << this->perstocks << " kof" << kof << endl;
		fin.close();
		ofstream fil;
		fil.open(waytostaff, ofstream::app);
		fil << "Name-" << "" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Capital-" << this->capital << " BigOrSmall-" << this->bigorsmall << " Perstocks-" << this->perstocks << " kof" << kof << endl;
		fil.close();
	}
};
class leadership : public staff {
private:
	string department;
	int kof = 2;
	double salary;
	int numbersubordinates;
public:
	leadership():staff(),department("N/A"),salary(0),numbersubordinates(0) {

	}
	leadership(string na, string sur, int ag, char se, double sala, string depar,int num) :staff(na, sur, ag, se), salary(sala), department(depar),numbersubordinates(num) {
	
	}
	void getdata() {
		staff::getdata();
		cout << "Введите название отдела сотрудника..."; cin >> department;
		cout << "Введите зарплату сотрудника..."; cin >> salary;
		cout << "Введите количество подчиненных у сотрудника..."; cin >> numbersubordinates;
	}
	void datainfile() {
		ofstream fin;
		fin.open(waytoleadership,ofstream::app);
		fin << "Name-" << "" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Department-" << department << " Salary-" << salary << " Number of subordinates-" << numbersubordinates << " kof" << kof << endl;
		fin.close();
	}
	void datainfile(int n) {
		ofstream fin;
		fin.open(waytoleadership, ofstream::app);
		fin << "Name-" << "" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Department-" << department << " Salary-" << salary << " Number of subordinates-" << numbersubordinates << " kof" << kof << endl;
		fin.close();
		ofstream fil;
		fil.open(waytostaff, ofstream::app);
		fil << "Name-" << "" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Department-" << department << " Salary-" << salary << " Number of subordinates-" << numbersubordinates << " kof" << kof << endl;
		fil.close();
	}
};
class worker : public staff {
private:
	string education;
	int kof = 3;
	double salary;
	int numberproject;
	double experience;
	int status;
public:
	worker() :staff(), education("N/A"), salary(0), numberproject(0), experience(0), status(0) {

	}
	worker(string na, string sur, int ag, char se, double sala, double exp, string educ, int num) :staff(na, sur, ag, se), salary(sala), experience(exp), education(educ), numberproject(num) {
		status = numberproject / 10;
		if (status>10) {
			status = 10;
		}
	}
	void getdata() {
		staff::getdata();
		cout << "Введите учреждение в котором учился сотрудник..."; cin >> education;
		cout << "Введите зарплату сотрудника..."; cin >> salary;
		cout << "Введите количество проектов сделанных данным сотрудником..."; cin >> numberproject;
		cout << "Введите количество лет проработанных в этой компании данным сотрудником..."; cin >> experience;
		status = numberproject / 10;
		if (status > 10) {
			status = 10;
		}
	}
	void datainfile(int n) {
		ofstream fin;
		fin.open(waytoworker, ofstream::app);
		fin << "Name" << "-" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Education-" << education << " Salaru-" << salary << " Numberproject-" << numberproject<<" Experience-"<<experience << " kof" << kof << endl;
		fin.close();
		ofstream fil;
		fil.open(waytostaff, ofstream::app);
		fil << "Name" << "-" << this->name << " Surname-" << this->surname << " Age-" << this->age << " ID-" << this->id << " Sex-" << this->sex << " Education-" << education << " Salaru-" << salary << " Numberproject-" << numberproject << " Experience-" << experience << " kof" << kof << endl;
		fil.close();
	}
	};
	void zagruzka() {

		for (int n = 0; n < 100; n++) {
			Sleep(1);
			system("cls");
			cout << "Loading... ";
			cout << n << "%";

		}system("cls");
	}
	void funcvivodall() {
		ifstream fin; fin.open(waytostaff);
		
		char ch;
		while (fin.get(ch)) {
			cout << ch;
		}
		fin.close();
	}
	void newstafftobase() {
		cout << "Введите 1, если это акционер,2 если руководитель,3 если простой работник...";
		char vib = _getch();
		switch (vib) {
		case '1': {
			staff *nowii = new shareholders; 
			nowii->getdata();
			nowii->datainfile(1);
			delete nowii;
			break; }
		case '2': {
			staff *nowii = new leadership;
			nowii->getdata();
			nowii->datainfile(1);
			delete nowii;
			break; }
		case '3': {
			staff * nowii = new worker;
			nowii->getdata();
			nowii->datainfile(1);
			delete nowii;
			break; }
		default: {
			cout << "Incorrect input!" << endl;
			break;
		}
		}
	}
	
	void menu() {
		char prova;
		do {
			cout << "\t\tНажмите: 1- для работы со всеми сотрудниками компании" << endl;
			cout << "\t\t\t 5- для выхода из программы " << endl << endl;
			prova = _getch();
			switch (prova) {
			case '1': {char proverka;
				do {
					cout << "\tНажмите: 1- для вывода сотрудников " << endl;
					cout << "\t\t 2- для добавления нового сотрудника в базу " << endl;
					cout << "\t\t 5- для выхода из области работы с даннными сотрудниками " << endl << endl;
					proverka = _getch();
					switch (proverka)
					{
					case '1': {
						funcvivodall();
						break; }
					case '2': {
						newstafftobase();
						break; }
					default: {
						break; }
					}
				} while (proverka != '5');
				break; }
			
			default: {break; }break;
			}

		} while (prova != '5');
	}
	int main() {

		srand(time(NULL));
		system("chcp 1251>null");
		zagruzka();
		menu();

		system("pause");
	}

