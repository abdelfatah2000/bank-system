#ifndef Client_HEADER
#define Client_HEADER

#include <iostream>
#include "Person.h"
#include "Validation.h"
class Client :public Person
{
private:
	float balance;
public:
	Client() {
		balance = 0;
	}
	Client(std::string name, std::string password, float balance) :Person(name, password) {
		this->balance = balance;
	}

	//Setters
	void setBalance(float balance) {
		this->balance = balance;
	}

	//Getters
	float getBalance() {
		return balance;
	}
	void withdraw(float amount) {
		if (Validation::checkBalance((balance - amount))) {
			balance -= amount;
		}
	}
	void deposit(float amount) {
		balance += amount;
	}
	void transferTo(float amount, Client& recipient) {
		withdraw(amount);
		recipient.deposit(amount);
	}
	void Display() {
		std::cout << "ID : " << id << std::endl;
		std::cout << "Username : " << name << std::endl;
		std::cout << "Password : " << password << std::endl;
		std::cout << "Balance : " << balance << std::endl;
	}
};
#endif // !Client_HEADER
