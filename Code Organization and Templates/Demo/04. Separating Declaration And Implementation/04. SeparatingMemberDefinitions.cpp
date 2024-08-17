#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

class Company {
private:
	int id;
	string name;
	vector<pair<char, char> > employees;

public:
	Company(int id, string name, vector<pair<char, char> > employees);

	int getId() const;

	string getName() const;

	vector<pair<char, char> > getEmployees() const;

	string toString() const;

	bool operator==(const Company& other) const;

	string operator+(const string& s);

	Company& operator+=(const pair<char, char>& employee);
};

Company::Company(int id, string name, vector<pair<char, char> > employees)
	: id(id)
	, name(name)
	, employees(employees) {}

int Company::getId() const {
	return this->id;
}

string Company::getName() const {
	return this->name;
}

vector<pair<char, char> > Company::getEmployees() const {
	return this->employees;
}

string Company::toString() const {
	ostringstream stream;
	stream << id << " " << name << " ";

	for (int i = 0; i < employees.size(); i++) {
		auto initials = employees[i];
		stream << initials.first << initials.second;
		if (i < employees.size() - 1) {
			stream << " ";
		}
	}

	return stream.str();
}

bool Company::operator==(const Company& other) const {
	return this->id == other.id;
}

string Company::operator+(const string& s) {
	return this->toString() + s;
}

Company& Company::operator += (const pair<char, char>& employee) {
	this->employees.push_back(employee);

	return *this;
}

int main() {
	Company c(42, "TheAnswer Inc.", {
        { 'G', 'L' },
        { 'H', 'F' },
        { 'G', 'G' }
    });

	c += { 'W', 'P' };

	cout << c + " <- this is a cool company" << endl;

	return 0;
}