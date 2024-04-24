#pragma once
#include <string>
class Product
{
	std::string name, category;
	float price;
public:
	Product(std::string name, std::string category, float price) :name(name), category(category), price(price) {}
	void show();
	float Price() { return price; }
	std::string Category() { return category; }
	std::string Name() { return name; }
};