#ifndef Validation_HEADER
#define Validation_HEADER

#include <iostream>
#include <string>
class Validation
{
public:
	static bool checkUsername(std::string name) {
		if (name.length() > 20 || name.length() < 5) {
			std::cout << "Invalid Username\n";
			return false;
		}
		return true;
	}
	static bool checkPassword(std::string password) {
		if (password.length() < 8 || password.length() > 20) {
			std::cout << "Invalid Password\n";
			return false;
		}
		return true;
	}
	static bool checkBalance(float balance) {
		if (balance < 1500) {
			std::cout << "Balance should not be less than 1500\n";
			return false;
		}
		return true;
	}
	static bool checkSalary(float salary) {
		if (salary < 5000) {
			std::cout << "Salary must be more than 5000\n";
			return false;
		}
		return true;
	}

	static std::string entryName(){
		system("CLS");
		std::string name;
		std::cout << "Enter Name : ";
		std::cin >> name;
		while (!checkUsername(name)) {
			system("CLS");
			std::cout << "Invalid Username\n";
			std::cout << "Enter Name : ";
			std::cin >> name;
		}
		return name;
	}
	static std::string entryPassword() {
		system("cls");
		std::string password;
		std::cout << "Entere Password : ";
		std::cin >> password;
		while (!checkPassword(password)) {
			system("cls");
			std::cout << "Invalid Password\n";
			std::cout << "Enter Password : ";
			std::cin >> password;
		}
		return password;
	}
	static float entryBalance() {
		system("cls");
		float balance;
		std::cout << "Enter Balance : ";
		std::cin >> balance;
		while (!checkBalance(balance)) {
			system("cls");
			std::cout << "Invalid Balance\n";
			std::cout << "Enter Balance : ";
			std::cin >> balance;
		}
		return balance;
	}

	static float entrySalary() {
		system("cls");
		float salary;
		std::cout << "Enter Salary : ";
		std::cin >> salary;
		while (!checkBalance(salary)) {
			system("cls");
			std::cout << "Invalid Salary\n";
			std::cout << "Enter Salary : ";
			std::cin >> salary;
		}
		return salary;
	}

};

#endif