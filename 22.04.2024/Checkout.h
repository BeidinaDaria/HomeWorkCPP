#pragma once
#include "Product.h"
#include <vector>
#include <iostream>
class Checkout
{
	static float sum;
	std::vector<Product> sold;
	std::vector<Product> products;
	void delProduct(int i);
public:
	void show();
	void sell(std::string name);
	int categoryCount(std::string category);
	std::string mostProfitableCategory();
	std::string bestSellingProduct();
	void sortByCategory();
	void showSold();

	void addProduct(Product& pr) {
		products.push_back(pr);
	}
	float showSum() { return sum; }
	
};