#pragma once
#include "User.h"
#include <vector>
#include <string>
class DB
{
	friend class AppManager;
	std::vector<User> users;
	DB(std::vector<std::string> arr);
public:
	void addUser(User u);
	User findUserById(int id);
	int getCountUsers();
	void showAll();
	std::vector<User> getUsers();
	void removeUser(int id);
private:
	void clear();
};


