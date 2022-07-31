#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"
#include "Employee.h"

class FilesHandler
{
public:
	static void saveClient(Client c) {
		std::ofstream file;
		file.open("Clients.txt", std::ios::app);
		file << c.getId() << " " << c.getName() << " " << c.getPassword() << " " << c.getBalance() << "\n";
		file.close();
	}
	
	static void saveEmployee(std::string fileName, Employee e) {
		std::ofstream file;
		file.open(fileName, std::ios::app);
		file << e.getId() << " " << e.getName() << " " << e.getPassword() << " " << e.getSalary() << "\n";
		file.close();
	}
	static void getData(std::string fileName) {
		std::ifstream file(fileName);
		std::string name;
		int id;
		float balance;
		while (file >> id >> name >> balance) {
			std::cout << id << " " << name << " " << balance << std::endl;
		}
		file.close();
	}
	static void clearFile(std::string fileName) {
		std::ofstream file;
		file.open(fileName, std::ios::app, std::ios::trunc);
		file.close();
	}

};

