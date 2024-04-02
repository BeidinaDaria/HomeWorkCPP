#include "Proxy.h"

int main()
{
    Proxy p("text.txt");
    std::cout << p.read(2) << std::endl;
    p.write("Input ended");
    std::cout << p.read(2) << std::endl;
}

