#pragma once
#include <iostream>
#include <windows.h>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "FileManager.h"
#include "ClientManger.h"
#include "Validation.h"

class EmployeeManager
{
private:
	static void printEmployeeMenu() {
		std::system("CLS");
		std::cout << "1. Dispaly Personal Information\n";
		std::cout << "2. Change Password\n";
		std::cout << "3. Add New Client\n";
		std::cout << "4. Search For Client\n";
		std::cout << "5. List All Clients\n";
		std::cout << "6. Edit Client Information\n";
		std::cout << "7. Logout\n";
	}
public:
	static void newClient(Employee* employee) {
		Client client;
		client.setUsername(Validation::entryName());
		client.setPassword(Validation::entryPassword());
		client.setBalance(Validation::entryBalance());
		employee->addClient(client);
		FileManger::updateClientFile();
		std::cout << "\nClient is Added]n";
	}
	static void listAllClient(Employee* employee) {
		std::cout << "All Clients : \n" << std::endl;
		employee->listClient();
	}
	static void searchForClient(Employee* employee) {
		employee->searchClient(FileManger::entryid())->Display();
	}
	static void editClientInfo(Employee* employee) {
		employee->editClient(FileManger::entryid(), Validation::entryName(), Validation::entryPassword(), Validation::entryBalance());
		FileManger::updateClientFile();
		std::cout << "\nClient is Updated\n";
	}
	static Employee* login(int id, std::string password) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPassword() == password) {
				return eIt._Ptr;
			}
			std::cout << "\nInvalid Credentials\n";
			return NULL;
		}
	}
	static void back(Employee* employee) {
		std::cout << std::endl;
		system("pause");
		employeeOptions(employee);
	}
	static bool employeeOptions(Employee* employee) {
		int choice;
		printEmployeeMenu();
		std::cout << "Select a Choice : ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			employee->Display();
			break;
		case 2:
			system("cls");
			ClientManger::changePassword(employee);
			FileManger::updateEmployeeFile();
			break;
		case 3:
			system("cls");
			newClient(employee);
			break;
		case 4:
			system("cls");
			searchForClient(employee);
			break;
		case 5:
			system("cls");
			listAllClient(employee);
			break;
		case 6:
			system("cls");
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			employeeOptions(employee);
			return true;
		}
		back(employee);
		return true;
	}

};

