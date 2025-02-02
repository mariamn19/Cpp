#include <iostream>
#include<string>

using namespace std;

class Employee {
private:
	int ID = 0;
	char* name = nullptr;
	char* hiringDate = nullptr;
	int salary = 0;
	int age = 18;
public:
	Employee() {

	}
	Employee(const char* name, const char* hiringDate, int salary, int age) {
		//this->ID = ID;
		/*if (name != nullptr) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
		this->hiringDate = new char[strlen(hiringDate)+1];
		strcpy(this->hiringDate, hiringDate);
		this->salary = salary;
		this->age = age;*/

		/*this->*/setName(name);
		/*this->*/setHiringDate(hiringDate);
		/*this->*/setSalary(salary);
		/*this->*/setAge(age);
	}
	Employee(Employee& e) {
		/*this->ID = e.ID;
		if (e.name != nullptr) {
			strcpy(this->name, e.name);
		}
		this->hiringDate = e.hiringDate;
		this->salary = e.salary;
		this->age = e.age;*/
		/*this->*/setName(e.getName());
		/*this->*/setHiringDate( e.gethiringDate());
		/*this->*/salary = e.salary;
	/*	this->*/age = e.age;
	}
	int getID() {
		return this->ID;
	}
	void setID(int Id) {
		this->ID = Id;
	}
	char* getName() {
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}		
	void setName(const char* newname) {
		/*if (this->name != NULL) {
			delete[] this->name;
		}
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);*/
		if (newname == nullptr ||
			strlen(newname) < 3) {
			throw "Invalid name";
		}
		int maxSize = strlen(newname) + 1;
		this->name = new char[maxSize];
		strcpy_s(this->name, maxSize, newname);
	}
	char* gethiringDate() {
		return this->hiringDate;
	}
	void setHiringDate(const char*newHD) {
		if (newHD) {
			delete[] hiringDate;
			hiringDate = new char[strlen(newHD) + 1];
			strcpy(this->hiringDate, newHD);
		}
	}
	int getSalary() {
		return this->salary;
	}
	void setSalary(int nsalary) {
		if (nsalary < 1500 || nsalary>20000) {
			throw invalid_argument("Wrong salary ?");
		}
		this->salary = nsalary;
	}
	int getAge() {
		return this->age;
	}
	void setAge(int newAge) {
		if (newAge < 18 || newAge>65) {
			throw invalid_argument("Not in age range");
		}
		this->age = newAge;
	}
	Employee& operator=(const Employee& e) {
		if (this != &e) {
			if (name != nullptr) {
				delete[] name;
			}
			if (e.name != nullptr) {
				this->name = new char[strlen(e.name) + 1];
				strcpy(this->name, e.name);
			}
			if (e.hiringDate != nullptr) {
				this->hiringDate = new char[strlen(e.hiringDate) + 1];
				strcpy(this->hiringDate,e.hiringDate);
			}
			this->salary = e.salary;
			this->age = e.age;
		}
		return *this;
	}

	void printInfo() {
		cout << "**********"<<endl;
		if (this->name != nullptr) {
			cout << "Name: " << this->name<<endl;
		}
		else {
			cout << "No name. ";
		}
		cout << "Hiring date: " << this->hiringDate<<endl;
		cout << "Salary: " << this->salary<<endl;
		cout << "Age: " << this->age <<endl;
	}
	//operator ++ preincrementare
	Employee operator++() {
		this->age++;
		return *this;
	}
	//operator ++ post incrementare
	Employee operator++(int) {
		Employee temp = *this;
		++(*this);
		return temp;
	}
	char operator[](int index) {
		return name[index];
	}
	Employee operator+=(int nsalary) {
		this->salary += nsalary;
		return *this;
	}
	~Employee() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
		if (hiringDate != nullptr) {
			delete[] hiringDate;
			hiringDate = nullptr;
		}	
	}
	friend ostream& operator<<(ostream& out, Employee e);
	friend istream& operator<<(istream& in, Employee e);//just to remind myself
};
ostream& operator<<(ostream& out, Employee e) {
	cout << "Ostream operator" <<endl;
	out << e.name<<endl;
	out << e.hiringDate<<endl;
	out <<e.salary<<endl;
	out << e.age<<endl;
	return out;
}
istream& operator<<(istream& in, Employee e) {
	cout << "Name: ";
	in >> e.name;
	cout << "hiring Date";
	in >> e.hiringDate;
	cout << "salary";
	in >> e.salary;
	cout << "age";
	in >> e.age;
	return in;
}

int main() {
	try {
		Employee e0;
		Employee e1("Popescu Andrei", "01122022", 3500, 30);
		cout << "Employee Name: " << e1.getName() << endl;
		cout << "Hiring Date: " << e1.gethiringDate() << endl;
		cout << "Salary: " << e1.getSalary() << endl;
		cout << "Age: " << e1.getAge() << endl;

		Employee e2("Popa Ioana", "15082020", 7200, 30);

		Employee e3("Popa Ioana", "15082020", 7500, 19);
		e1.getName();
		//e3.setSalary(1000);

		Employee e4("Stuparu Maria", "01032019", 6500, 25);
		Employee e5 = e4;
		e4 = e1;
		e5.printInfo();//just to see the values

		e2 = ++e1;
		cout << e3;
		cout << e4[0];
		e3.printInfo();
		e3 += 2000;
		e3.printInfo();
	}
	catch (const exception& e){
		cout << e.what();
	}

}