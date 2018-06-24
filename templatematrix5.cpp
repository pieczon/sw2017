#include <iostream>
#include <array>
#include <vector>
#include <type_traits>
#include <gtest/gtest.h>
#include <exception>
#include <algorithm>

/* 
Matrix<M,N,T>
Napisać implementację:
-posiada operatory:
 dodawania macierzy (+)
 mnożenia macierzy (+)
 dodawania skalara do macierzy (+) 
 mnożenia macierzy przez skalar (+) 
-dostarcza konstruktory:
 domyślny
 kopiujący (+) 
 przesuwający*
Zadanie dodatkowe: gdzie występuje (+) implementacja ma działać dla typu T1, który jest konwertowalny do typu T
*/

/*
-jezeli jest cos konwertowalne, to static castem po elementach juz docelowo konwertujemy
-w dwóch postaciach operatory [], z const & operator[] const, oraz bez czyli & operator[]
-zadanie na koniec przedmiotu na zaliczenie, stworzyc macierz matrix M,N z dzis
-znajomosc algorytmow: find, copy, accumulate; kontenery, predykaty - funckje lambda
-na zaliczeniu zestaw zadan, np. Ring Buffer uzywajac alg. STL
-5 zadan, wybieramy sobie jedno, ale kazde jest dosyc zlozone
-np. zaimplementowac smart pointera mega trudny
-np. zrobic Serializacje Klasy to max na 3 lub 4, zapisac obiekt typu char to zapisac na dysku, zeby to sie dalo wczytac z dysku i odczytac/odtworzyc
-macierz Matrix<N,M,T> n wierszy, m kolumn i przechowuje dowolny typ danych T, z parametrami szablonowymi macierzy, bardzo punktowane, na 5 nawet z wieloma bledami
-to do zrobienia w chacie im szybciej tym lepiej
-lepiej jedno zadanie i sie na nim skupic
*/

template<std::size_t N, std::size_t M, typename T> 
class Macierz
{
    private:
    std::array<std::array<T,M>, N> nowa{};

    public:
    
    //konstruktor domyslny
    Macierz()
    {
        if(N==0 or M==0)
        {
            throw std::underflow_error{"Liczba wierszy oraz kolumn nie może być = 0"};
        }
    }

    //destruktor
    ~Macierz() { std::cout << "Potężny destruktor został wywołany!" << std::endl;};
 
    //przeciazenie operatora [], zwraca po uzyciu nawiasow klamrowych pozycje elementu zamiast wartosci
    std::array<T,M> &operator[](std::size_t index)
    {
        return nowa.at(index);
    }
    //to samo ale dla const elementow
    const std::array<T,M> &operator[](std::size_t index) const
    {
        return nowa.at(index);
    }

    //konstruktor kopiujacy
    template<std::size_t N1, std::size_t M1, typename T1>
    Macierz(const Macierz<N1,M1,T1>& kopiowana)
    {
        if(N1 > N)
        {
            throw std::range_error {"Number of rows error"};
        }
        else if(M1 > M)
        {
            throw std::range_error {"Number of cols error"};
        }
        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < M1; ++m) 
            {
                nowa[n][m] = kopiowana[n][m];
            }
        }
    }

    //macierz + macierz
    template<std::size_t N1, std::size_t M1, typename T1> 
    auto operator+(Macierz<N1,M1,T1>& dodawana)
    {
        static_assert(std::is_convertible<T1,T>::value, "Dodawanie macierzy: niezgodne/niekonwertowalne typy danych w macierzach");
        static_assert((N1 == N) && (M1 == M), "Dodawanie macierzy: niezgodne wymiary macierzy");
        
        Macierz<N,M,T> tablica;

        for(std::size_t i=0; i<N; ++i)
        {
            std::transform(nowa[i].begin(), nowa[i].end(), dodawana.nowa[i].begin(), tablica.nowa[i].begin(), std::plus<T1>());
        }
        return tablica;
    }

    //macierz + skalar
    template<typename T1>
    auto operator+(const T1& skalar)
    {
        static_assert(std::is_convertible<T1,T>::value, "Dodawanie skalara: niezgodne typy dodawanych elementów");
        Macierz<N,M,T1> tablica;
        for(auto& i : tablica.nowa)
        {
            //do każdego elementu tablicy dodajemy przyjety skalar
            i += skalar;
        }
        return tablica;
    }
    
    //macierz * macierz
    template<std::size_t N1, std::size_t M1, typename T1>
    auto operator*(Macierz<N1,M1,T1>& mnozona) //tablica przekazywana
    {
        static_assert(std::is_convertible<T1,T>::value, "Mnożenie macierzy: niezgodne/niekonwertowalne typy danych w macierzach");
        static_assert(N==M1, "Mnożenie macierzy: niezgodne wymiary macierzy");

        Macierz<N,M1,T> tablica; //tablica wynikowa
        for(std::size_t n=0; n<N; ++n)
        {
            for(std::size_t m=0; m<M1; ++m)
            {
                T sum = 0;
                for(std::size_t i=0; i<N1; ++i)
                {
                    sum += nowa[n][i] * mnozona.nowa[i][m];
                }
                tablica.nowa[n][m] = sum;
            }
        }
        return tablica;
    }

    //macierz * skalar
    template<typename T1>
    auto operator*(const T1& skalar)
    {
        static_assert(std::is_convertible<T1,T>::value, "Dodawanie skalara: niezgodne typy dodawanych elementów");
        Macierz<N,M,T1> tablica;
        for(auto& i : tablica.nowa)
        {
            //każdy element tablicy mnożymy przez przyjety skalar
            i *= skalar;
        }
        return tablica;
    }   
};

//specjalizacja szablonu, zabezpieczenie typ elementow macierzy musi byc inny niz bool, inaczej dajemy throw exception, to jest potrzebne do przeprowadzenia testu ponizej 
template<std::size_t N, std::size_t M>
struct Macierz<N,M,bool> 
{
    Macierz() 
    {
        throw std::bad_typeid { };
    }
};

//entry point programu, z deklaracją googlowych testow
int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//prosty test badajacy elementy macierzy i ich oczekiwane wartosci
TEST(MacierzTest, create) 
{
    Macierz<3,5,int> m;
    EXPECT_EQ(m[0][0], 0);
    m[2][1] = 1;
    EXPECT_EQ(m[2][1], 1);
    m[2][4] = 14;
    EXPECT_EQ(m[2][4], 14);
    EXPECT_EQ(m[2][2], 0);
}

//zabawa wymiarami macierzy, generalnie wymiary nie moga byc rowne 0
TEST(MacierzTest, createZero) 
{
    auto l = [](){ Macierz<0,3,int> m; };
    EXPECT_THROW(l(), std::underflow_error);
    auto l2 = [](){ Macierz<3,0,int> m; };
    EXPECT_THROW(l2(), std::underflow_error);
    auto l3 = [](){ Macierz<0,0,int> m; };
    EXPECT_THROW(l3(), std::underflow_error);
}

//macierz nie moze skladac sie z elementow typu bool, mamy na to wyjatek, funkcja lambda testuje ten warunek
TEST(MacierzTest, createBool) {
    auto l = [](){ Macierz<3,3,bool> m; };
    EXPECT_THROW(l(), std::bad_typeid);
}

//testowanie kopiowania macierzy, konstruktor kopiujacy dla macierzy o takich samych wymiarach
TEST(MacierzTest, copyCtor) {
    //okreslanie wymiarow macierzy
    int number = 0;
    const int I = 2;
    const int J = 3;
    //wypelnianie elementow macierzy kolejnymi cyframi
    Macierz<I,J,int> m;
    for(int i = 0; i < I; ++i) {
        for(int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    //kopiowanie macierzy, wywolanie konstruktora kopiujacego
    Macierz<I,J,int> n = m;
    for(int i = 0; i < I; ++i) {
        //sprawdzanie kolejno wartosci elementow w matrixach m i n
        for(int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}

//testowanie kopiowania macierzy, konstruktor kopiujacy dla macierzy o rozniacych sie wymiarach
TEST(MacierzTest, copyCtorSmallToBig) {
    int number = 0;
    const int I = 2;
    const int J = 2;
    //stworzenie i wypelnianie macierzy 2x2
    Macierz<I,J,int> m;
    for(int i = 0; i < I; ++i) {
        for(int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    //kopiujemy macierz o wymiarze mniejszym 2x2 do wiekszej 3x3
    Macierz<3,3,int> n = m;
    for(int i = 0; i < I; ++i) {
        for(int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
    //test czy elementy z wymiarow nie kopiowanych pozostaly 0
    EXPECT_EQ(n[2][0], 0);
    EXPECT_EQ(n[2][1], 0);
    EXPECT_EQ(n[2][2], 0);
    EXPECT_EQ(n[1][2], 0);
    EXPECT_EQ(n[0][2], 0);
}

//testowanie kopiowania macierzy, konstruktor kopiujacy wywolywany jest dla kopiowania elementow wiekszej macierzy do mniejszej, co spowoduje rzucenie wyjatku
TEST(MacierzTest, copyCtorBigToSmall) {
    auto l = [&]() { Macierz<3,3,int> m; m[1][1] = 5; Macierz<2,3,int> n = m; };
    EXPECT_THROW(l(), std::range_error);
    auto o = [&]() { Macierz<3,3,int> m; m[1][1] = 5; Macierz<3,2,int> n = m; };
    EXPECT_THROW(o(), std::range_error);
}