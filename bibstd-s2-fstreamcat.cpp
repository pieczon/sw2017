#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>

void copy(std::istream& is, std::ostream& os)
{
    auto old_flags = is.flags();
    std::noskipws(is);
    std::copy(std::istream_iterator<char>(is), std::istream_iterator<char>(), std::ostream_iterator<char>(os,""));
    is.flags(old_flags);
}

int main(int argc, char* argv[])
{
    std::fstream plik{argv[1]};
    //{"bibstd-s2-fstreamcat.cpp"};
    //std::ofstream oPlik { plik.c_str() };
    std::string buff;

    std::cout << "Zawartosc pliku:" << std::endl;
    while( !plik.eof() )
    {
        std::getline(plik, buff);
        std::cout << buff << std::endl;
    }

    //main() BT
    // if(argc == 1){
    //     copy(std::cin, std::cout);
    // }
    // else {
    //     std::fstream file{argv[1]}
    //     copy(file, std::cout);
    //     std::cout << std::endl;
    // }

    return 0;
}