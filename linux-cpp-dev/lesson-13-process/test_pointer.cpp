#include <iostream>

int main()
{
    char *pc = new char();
    int *pi = new int();
    double *pd = new double();

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(pc) << std::endl;
    std::cout << sizeof(pi) << std::endl;
    std::cout << sizeof(pd) << std::endl;

    return 0;
}