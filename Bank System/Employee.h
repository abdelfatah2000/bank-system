#ifndef Employee_HEADER
#define Employee_HEADER
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Validation.h"
class Employee :public Person
{
private:
	float salary;
public:
	Employee() {
		salary = 0;
	}
	Employee(std::string name, std::string password, float salary) :Person(name, password) {
		if (Validation::checkSalary(salary)) {
			this->salary = salary;
		}
	}

	// Setters
	void setSalary(float salary) {
		this->salary = salary;
	}

	// Getters
	float getSalary() {
		return salary;
	}
	void Display() {
		std::cout << "ID : " << id << std::endl;
		std::cout << "Username : " << name << std::endl;
		std::cout << "Password : " << password << std::endl;
		std::cout << "Salary : " << salary << std::endl;
		std::cout << "================================================" << std::endl;

	}

	void addClient(Client& client) {
		allClients.push_back(client);
	}
	Client* searchClient(int id) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) return clIt._Ptr;
		}
		return NULL;
	}
	void listClient() {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			clIt->Display();
		}
	}
	void editClient(int id, std::string name, std::string password, float balance) {
		searchClient(id)->setUsername(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
};

static std::vector<Employee> allEmployees;
static std::vector<Employee>::iterator eIt;

#endif // !Employee_HEADER
