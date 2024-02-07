#include "MyString.h"

int main()
{
    MyString s1((char*)"Spanish");
    MyString s2 = s1;
    s2.show();
    std::cout << s2.empty() << std::endl;
    const char* s3="123";
    const char* s4 = "-123";
    std::cout << MyString::stoi(s3) << std::endl;
    std::cout << MyString::stoi(s4) << std::endl;
    std::cout << s1.find("pan") << std::endl;
    std::cout << s2.find("A") << std::endl;
}
