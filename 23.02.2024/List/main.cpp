#include "List.h"

int main()
{
    int arr[]{ 1,2,3,4,5 };
    List<int> full(arr,5);
    std::cout << full;
    full.push_front(0);
    std::cout << full[0] << std::endl;
    std::cout << full[4] << std::endl;
    full.insert(3, -1);
    std::cout << full;
    full.erase(3);
    std::cout << full;
    full.reverse();
    std::cout << full;
}