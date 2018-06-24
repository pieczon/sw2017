#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl;

int main()
{
    int var = 8;
    auto* ptr = &var;
    *ptr = 10;
    LOG(var);
    LOG(&var);
    LOG(&ptr); LOG("-->"); LOG(ptr);

    char* bufor = new char[8];
    memset(bufor, 0, 8);

    char** dptr = &bufor;
    LOG(&bufor);
    LOG(&dptr); LOG("-->"); LOG(dptr);
    delete[] bufor;
    //std::cin.get();
} 