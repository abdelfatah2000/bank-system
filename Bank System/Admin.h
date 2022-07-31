#pragma once
#include <iostream>
#include <string>
#include <vector>	
#include <iterator>
#include "Employee.h"

class Admin : public Employee
{
public:
	Admin() :Employee() {};
	Admin(std::string name, std::string password, float salary) :Employee(name, password, salary) {};

	//Methods
	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	void listEmployee() {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			eIt->Display();
		}
	}
	Employee* searchEmployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id) return eIt._Ptr;
		}
		return NULL;
	}
	void editEmployee(int id, std::string name, std::string password, float salary) {
		searchEmployee(id)->setUsername(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
};

static std::vector<Admin> allAdmins;
static std::vector<Admin>::iterator aIt;

