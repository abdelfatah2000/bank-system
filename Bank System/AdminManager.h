#pragma once
#include <iostream>
#include <windows.h>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "FileManager.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "Validation.h"
class AdminManager
{
private:
	static void printAdminMenu(Admin* admin) {
		system("cls");
		std::cout << "1. Display Personal Information\n";
		std::cout << "2. Change Password\n";
		std::cout << "3. Add New Client\n";
		std::cout << "4. Search For Client\n";
		std::cout << "5. List All Clients\n";
		std::cout << "6. Edit Client Information\n";
		std::cout << "7. Add New Employee\n";
		std::cout << "8. Search For Employee\n";
		std::cout << "9. List All Employee\n";
		std::cout << "10. Edit Employee Information\n";
		std::cout << "11. Logout\n";
	}
public:
	static void newEmployee(Admin* admin) {
		Employee employee;
		employee.setUsername(Validation::entryName());
		employee.setPassword(Validation::entryPassword());
		employee.setSalary(Validation::entrySalary());
		admin->addEmployee(employee);
		FileManger::updateEmployeeFile();
		std::cout << "\nEmployee is Added\n";

	}
	static void searchForEmployee(Admin* admin) {
		admin->searchEmployee(FileManger::entryid())->Display();
	}
	static void listEmployee(Admin* admin) {
		std::cout << "All Employees : \n";
		admin->listEmployee();
	}
	static void editEmployee(Admin* admin) {
		admin->editEmployee(FileManger::entryid(), Validation::entryName(), Validation::entryPassword(), Validation::entrySalary());
		FileManger::updateEmployeeFile();
		std::cout << "\nEmployee is Updated\n";
	}
	static Admin* login(int id, std::string password) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id && aIt->getPassword() == password) {
				return aIt._Ptr;
			}
			std::cout << "\nInvalid Cerdentials\n";
			return NULL;
		}
	}
	static void back(Admin* admin) {
		std::cout << std::endl;
		system("pause");
		adminOptions(admin);
	}
	static bool adminOptions(Admin* admin) {
		printAdminMenu(admin);
		int choice;
		std::cout << "Enter a Choice : ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			admin->Display();
			break;
		case 2:
			system("cls");
			ClientManger::changePassword(admin);
			FileManger::updateAdminFile();
			break;
		case 3:
			system("cls");
			EmployeeManager::newClient(admin);
			break;
		case 4:
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			system("cls");
			EmployeeManager::listAllClient(admin);
			break;
		case 6:
			system("cls");
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			system("cls");
			newEmployee(admin);
			break;
		case 8:
			system("cls");
			searchForEmployee(admin);
			break;
		case 9:
			system("cls");
			listEmployee(admin);
			break;
		case 10:
			system("cls");
			editEmployee(admin);
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			adminOptions(admin);
			return true;
		}
		back(admin);
		return true;
	}
};

