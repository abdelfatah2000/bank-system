#pragma once
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"

class Screens
{
	static void welcome() {
		std::cout << "\n\n\n\n\n\n\t    ##       ##   #######   ##      #######  ########    ####    ####   #######\n";
		std::cout << "\t    ##   #   ##   ##        ##      ##       ##    ##    ##  #  #  ##   ##\n";
		std::cout << "\t    ##  ###  ##   ######    ##      ##       ##    ##    ##   ##   ##   #######\n";
		std::cout << "\t    ## ## ## ##   ##        ##      ##       ##    ##    ##        ##   ##\n";
		std::cout << "\t    ###     ###   #######   ######  #######  ########    ##        ##   #######\n\n\n";
		Sleep(3000);
		system("cls");
	}
	static void loginOptions() {
		std::cout << "1. Admin.\n";
		std::cout << "2. Employee\n";
		std::cout << "3. Client\n";
		std::cout << "Login as : \n";
	}
	static int loginAs() {
		loginOptions();
		int choice;
		std::cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		system("cls");
		loginAs();

	}
	static void loginScreen(int choice) {
		int x = choice, id;
		std::string password;
		std::cout << "Enter Id : ";
		std::cin >> id;
		std::cout << "Enter Password : ";
		std::cin >> password;
		switch (x)
		{
		case 1:
			if (AdminManager::login(id, password) != NULL) {
				while (AdminManager::adminOptions(AdminManager::login(id, password)) != false);
				logout();
			}
			else invalid(1);
			break;
		case 2:
			if (EmployeeManager::login(id, password) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)) != false);
				logout();
			}
			else invalid(2);
			break;
		case 3:
			if (ClientManger::login(id, password) != NULL)
			{
				while (ClientManger::clientOptions(ClientManger::login(id, password)) != false);
				logout();
			}
			else invalid(3);
			break;
		default:
			system("cls");
			loginOptions();
		}
	}
	static void invalid(int c) {
		system("cls");
		std::cout << "Invalid Cerdentials.\n" << std::endl;
		loginScreen(c);
	}
	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}
public:
	static void runApp() {
		welcome();
		loginScreen(loginAs());
	}
};

