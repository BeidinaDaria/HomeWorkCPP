#include "Garage.h"

int main(){
	srand(time(NULL));
	Garage g1(7);
	g1.show();
	Car c1;
	g1.addCar(c1);
	g1.show();
	g1.removeCarByIndex(2);
	g1.show();
}