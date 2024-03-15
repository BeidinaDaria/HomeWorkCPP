#include "AppManager.h"

void AppManager::addUser(User u){
	memory.addUser(u);
	std::vector<std::string> users;
	std::vector<User> arr = memory.getUsers();
	for (int i = 0; i < arr.size(); i++)
		users.push_back(arr[i].toString());
	xmlMan.writeFile(users);
}

void AppManager::removeUserById(int id)
{
	memory.removeUser(id);
	std::vector<std::string> users;
	std::vector<User> arr = memory.getUsers();
	for (int i = 0; i < arr.size(); i++)
		users.push_back(arr[i].toString());
	xmlMan.writeFile(users);
}

void AppManager::showAll()
{
	memory.showAll();
}