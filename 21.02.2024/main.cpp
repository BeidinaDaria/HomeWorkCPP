#include "Deque.h"

int main(){
    //Deque()
    Deque<char> q1;

    //Deque(arr)
    int arr[]{ 1,2,3,4,5 };
    Deque<int> q2(arr, 5);

    //ostream
    std::cout << q1;
    std::cout << q2;

    std::cout << q1.size()<<std::endl;
    std::cout << q2.size()<<std::endl;

    std::cout << q1.front() << std::endl;
    std::cout << q2.front() << std::endl;

    std::cout << q1.back() << std::endl;
    std::cout << q2.back() << std::endl;

    q1.push_front('^');
    std::cout << q1;
    q1.pop_front();
    std::cout << q1;
    q1.push_back('$');
    std::cout << q1;
    q1.pop_back();
    std::cout << q1;

    q2.push_back(6);
    q2.push_front(0);
    std::cout << q2;
    q2.pop_back();
    q2.pop_front();
    std::cout << q2;

    q1.clear();
    q2.clear();
    std::cout << q2;
}