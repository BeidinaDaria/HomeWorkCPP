#pragma once
#include "XmlManager.h"
#include "DB.h"
class AppManager
{
	DB memory;
	XmlManager xmlMan;
public:
	AppManager(std::string path) :xmlMan(XmlManager(path)), memory(DB(xmlMan.readFile())) {}
	void addUser(User u);
	void removeUserById(int id);
	void showAll();
};



