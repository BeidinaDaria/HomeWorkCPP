#include "User.h"
#include <string>

std::string User::toString() {
	return std::to_string(uniqueId) + ";" + firstName + ";" + lastName + ";" + email + ";" + password;
}

void User::show() {
	std::cout << "Id: " + std::to_string(uniqueId) + "; first name: " + firstName + "; last name: " + lastName
		+ "; email: " + email + "; password: " + password;
}