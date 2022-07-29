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
	static bool checkBalance(int balance) {
		if (balance < 1500) {
			std::cout << "Balance should not be less than 1500\n";
			return false;
		}
		return true;
	}
	
};

#endif