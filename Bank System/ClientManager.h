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
	static void changePassword(Person* person, std::string password) {
		person->setPassword(password);
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
			std::system("cls");
			std::cout << "Entre New Password : ";
			std::cin >> password;
			while (!Validation::checkPassword(password)) {
				std::cout << "Entre New Password : ";
				std::cin >> password;
			}
			changePassword(client, password);
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
			break;
		case 5:
			std::system("cls");
			std::cout << "Enter Amount of Money : ";
			std::cin >> amount;
			client->withdraw(amount);
			break;
		case 6:
			std::system("cls");
			std::cout << "Enter Client Id : ";
			std::cin >> id;
			while (c.searchClient(id) == NULL) {
				std::system("cls");
				std::cout << "Invalid Id\n";
				std::cout << "Enter Client Id : ";
				std::cin >> id;
			}
			std::cout << "\nEnter Amount of Money : ";
			std::cin >> amount;
			client->transferTo(amount, *c.searchClient(id));
			FileManger::updateClientFile();
		}
	}
};

