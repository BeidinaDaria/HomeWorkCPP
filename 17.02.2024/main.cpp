#include "Journal.h"

int main(){
    Journal j(10);
    j.show();
    j.addRecord(2);
    j.showByIndex(2);
    int idP, idR;
    std::cout << "Enter the page and the record id: ";
    std::cin >> idP;
    std::cin >> idR;
    j.delRecord(idP, idR);
    j.showByIndex(idP);
}