#include "Checkout.h"
#include <map>
#include <set>

float Checkout::sum = 0;

void Checkout::show() {
	for (int i = 0; i < products.size(); i++) {
		products[i].show();
	}
}

void Checkout::delProduct(int i) {
	products.erase(products.begin() + i);
}

void Checkout::sell(std::string name) {
	for (int i = 0; i < products.size(); i++) {
		if (products[i].Name() == name) {
			sum += products[i].Price();
			std::cout << name << " sold!" << std::endl;
			sold.push_back(products[i]);
			delProduct(i);
			return;
		}
	}
}

int Checkout::categoryCount(std::string category) {
	int c = 0;
	for (auto el : products) {
		if (el.Category() == category)
			c++;
	}
	return c;
}

std::string Checkout::mostProfitableCategory() {
	std::map<std::string, float> store;
	for (int i = 0; i < products.size(); i++) {
		store[products[i].Category()] += products[i].Price();
	}
	for (auto it = store.begin(); it != store.end(); ++it)
		it->second /= categoryCount(it->first);
	float max = 0;
	std::string res;
	for (auto it = store.begin(); it != store.end(); ++it)
		if (it->second > max) {
			max = it->second;
			res = it->first;
		}
	return res;
}

std::string Checkout::bestSellingProduct() {
	std::map<std::string, int> store;
	for (int i = 0; i < sold.size(); i++) {
		store[sold[i].Name()]++;
	}
	int max = 0;
	std::string res;
	for (auto it = store.begin(); it != store.end(); ++it)
		if (it->second > max) {
			max = it->second;
			res = it->first;
		}
	return res;
}

void Checkout::sortByCategory() {
	std::set<std::string> categories;
	for (int i = 0; i < sold.size(); i++) {
		if (categories.find(sold[i].Category()) == categories.end())
			categories.insert(sold[i].Category());
	}
	int i = 0;
	for (auto el : categories) {
		for (int j = i; j < products.size(); j++) {
			if (products[j].Category() == el) {
				std::swap(products[i], products[j]);
				i++;
			}
		}
	}
}

void Checkout::showSold() {
	for (int i = 0; i < sold.size(); i++) {
		sold[i].show();
	}
}