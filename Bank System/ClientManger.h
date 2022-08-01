#pragma once
#include <iostream>
#include <windows.h>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "FileManager.h"
#include "Validation.h"

class ClientManger
{
	static void printClientMenu() {
		std::system("Color 80");
		std::cout << "1. Display Personal Information\n";
		std::cout << "2. Change Password\n";
		std::cout << "3. Check Balance\n";
		std::cout << "4. Deposit\n";
		std::cout << "5. Withdraw\n";
		std::cout << "6. Transfer Money\n";
		std::cout << "7. Logout\n";
	}
public:
	static void changePassword(Person* person) {
		person->setPassword(Validation::entryPassword());
		std::cout << "\nPassword is Changed\n";
	}
	static Client* login(int id, std::string password) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id && clIt->getPassword() == password) {
				return clIt._Ptr;
			}
			std::cout << "\nInvalid Credentials\n";
			return NULL;
		}
	}
	static void back(Client* client) {
		std::cout << std::endl;
		system("pause");
		clientOptions(client);
	}
	static bool clientOptions(Client* client) {
		printClientMenu();
		std::cout << "Select a Choice : ";
		int choice, id;
		float amount;
		std::string password;
		Employee c;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::system("cls");
			client->Display();
			break;
		case 2:
			system("cls");
			changePassword(client);
			FileManger::updateClientFile();
			break;
		case 3:
			std::system("cls");
			client->getBalance();
			break;
		case 4:
			std::system("cls");
			std::cout << "Enter Amount of Money : ";
			std::cin >> amount;
			client->deposit(amount);
			FileManger::updateClientFile();
			break;
		case 5:
			std::system("cls");
			std::cout << "Enter Amount of Money : ";
			std::cin >> amount;
			client->withdraw(amount);
			FileManger::updateClientFile();
			break;
		case 6:
			std::cout << "\nEnter Amount of Money : ";
			std::cin >> amount;
			client->transferTo(amount, *c.searchClient(FileManger::entryid()));
			FileManger::updateClientFile();
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
		}
		back(client);
		return true;
	}
};

