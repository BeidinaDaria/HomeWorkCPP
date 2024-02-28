#include "Tree.h"

int main()
{
    Tree<int> tr;
    tr.insert(8);
    tr.insert(9);
    tr.insert(5);
    tr.insert(5);
    tr.insert(2);
    tr.insert(0);
    tr.insert(4);
    tr.insert(57);
    tr.insert(28);
    tr.show();
    std::cout << std::endl;
    tr.del(28);
    tr.show();
    std::cout << std::endl;
    tr.del(9);
    tr.show();
    std::cout << std::endl;
    tr.del(2);
    tr.show();
    std::cout << std::endl;
    tr.del(8);
    tr.show();
    std::cout << std::endl;
}