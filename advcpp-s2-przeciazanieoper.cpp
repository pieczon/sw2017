#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <cstring>

class C {
public:
    C(const char* text) 
    {
        table = new char[strlen(text) + 1];
        strcpy(table, text);
    }

    ~C() 
    {
        delete [] table;
    }

    char* getStr() 
    {
        return table;
    }

    C& operator=(const C& other) //przeciazanie operatora przypisania, kopiujemy tablice do tablicy
    {
        if (table != other.table) //(this != &other)
        {
            if (strlen(table) != strlen(other.table))
            {
                delete [] table;
                table = new char[strlen(other.table)+1];        
            }
            for(size_t i=0; i < strlen(other.table)+1; ++i)
            {
                table[i] = other.table[i];
            }
        } 
        return *this;
    }

    C& operator=(C&& other) //przeciazanie operatora przypisania, ktory przenosi zamiast kopiowania, przepisuje wskaznik nowy na wartosci ktore chcemy miec skopiowane, to jest przeladowanie funkcji
    {
        table = other.table;
        other.table = nullptr;
        return *this;
    }

private:
    char* table;
};

int main()
{
    char c1[6] = {1,2,3,4,5,6};
    char c2[6] = {6,5,4,3,2,1};
    c1[6] = std::move(c2);
}