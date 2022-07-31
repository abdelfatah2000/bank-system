#ifndef Person_HEADER
#define Person_HEADER

#include <string>
#include "Validation.h"
class Person
{
protected:
	int id;
	std::string name;
	std::string password;
public:
	static int ID;
	Person() {
		id = ID++;
		name = " ";
		password = " ";
	}
	Person(std::string name, std::string password) {
		this->id = ID++;
		this->name = name;
		this->password = password;
	}

	//Setters
	void setUsername(std::string name) {
		if (Validation::checkUsername(name)) {
			this->name = name;
		}
	}
	void setPassword(std::string password) {
		if (Validation::checkPassword(password)) {
			this->password = password;
		}
	}

	//Getters
	int getId() {
		return id;
	}
	std::string getName() {
		return name;
	}
	std::string getPassword() {
		return password;
	}
	virtual void Display() = 0;
};

#endif