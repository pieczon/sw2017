#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

std::string help() { return R"(Test)"; }

void printAll(const std::vector<std::string>& args)
{
    for(const std::string& arg : args) std::cout << arg << std::endl;
}

int main(int argc, char* argv[])
{
    const std::vector<std::string> args{argv+1, argv+argc};
    
    for(const std::string& arg : args)
    {
        if(arg == "-h" || arg == "--help")
        {
            std::cout << help() << std::endl;
            return EXIT_SUCCESS;
        }
        else if(arg == "-v" || arg == "--verbose")
        {
            printAll(args);
            return EXIT_SUCCESS;
        }
        else
        {
            int position = arg.find("-f=");
            std::string subStr = arg.substr(position +3, arg.size());
            int number = std::atoi(subStr.c_str());
            std::cout << number * number << std::endl;
        }
    }

}