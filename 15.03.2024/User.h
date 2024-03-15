#pragma once
#include <iostream>
class User
{
	friend class DB;
	friend class AppManager;
	int uniqueId;
	std::string firstName = "", lastName = "";
	std::string email;
	std::string password;
	std::string toString();
	void show();
public:
	User(int id, std::string first, std::string last,
		std::string mail, std::string pass) :
		uniqueId(id), firstName(first), lastName(last), email(mail), password(pass) {}
};


