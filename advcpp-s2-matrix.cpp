#include <algorithm>
#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <functional>
#include <exception>

//http://slides.com/uczelnia_bt_kw/advanced-c#/14
// zadanko z Wilka na Matrix na 14.04.2018
// excercise
// Implement Matrix<N, M, T> (order is random here!)
// N - number of rows
// M - number of columns
// has templated copy ctor ( const Matrix<N1, M1, T1>& )
// ​N1 < N
// M1 < M
// T1 convertible to T 
// has operators:
// ​operator<<
// operator[]
// template operator+ (const Matrix<N1, M1, T1>)
// is specialized for N = 0 && M = 0 (cannot be created)
// is specialized for bools!! (std::vector<bool> is pure evil!)

template<std::size_t N, std::size_t M, typename T> 
struct Matrix 
{
    //konstruktor domyslny sprawdza wymiary
    Matrix() 
    {
        if ((N == 0) or (M == 0))
        {
            throw std::underflow_error { "number of rows or columns is 0" };
        }
    }
    //konstruktor kopiujacy, sprawdza wymiary i kopiuje elementy jednej macierzy do drugiej
    template<std::size_t N1,std::size_t M1,typename T1> 
    Matrix(const Matrix<N1,M1,T1>& kopiowana) 
    {
        if (N1 > N) 
        {
            throw std::range_error { "number of rows error" };
        }
        if (M1 > M) 
        {
            throw std::range_error { "number of columns error" };
        }
        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < M1; ++m) 
            {
                _array[n][m] = kopiowana[n][m];
            }
        }
    }
    //przeciazenie operatora, zwraca po uzyciu nawiasow klamrowych pozycje elementu zamiast wartosci
    std::array<T,M> &operator[](std::size_t index) 
    {
        return _array.at(index);
    }
    //to samo ale dla const elementow
    const std::array<T,M> &operator[](std::size_t index) const 
    {
        return _array.at(index);
    }
    //deklaracja zaprzyjaznionej funkcji do przeciazenia operatora strumieniowego
    template<std::size_t N1, std::size_t M1, typename T1>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<N1,M1,T1> &);

private:
    std::array<std::array<T,M>,N> _array{} ;
};
//to jest zaprzyjazniona funkcja do przeciazenia operatora strumienia
template<std::size_t N, std::size_t M, typename T> 
std::ostream &operator<<(std::ostream &os, const Matrix<N,M,T> &matrix) 
{
    for (const auto &element : matrix._array) 
    {
        for (const auto &e : element) 
        {
            os << e;
        }
        os << std::endl;
    }
    return os;
}
//specjalizacja szablonu, zabezpieczenie typ elementow macierzy musi byc inny niz bool, inaczej dajemy throw exception, to jest potrzebne do przeprowadzenia testu ponizej 
template<std::size_t N, std::size_t M>
struct Matrix<N, M, bool> 
{
    Matrix() 
    {
        throw std::bad_typeid { };
    }
};

/*
template<typename T>
struct Matrix<0, 0, T> {
    Matrix() = delete;
};
template<std::size_t N, typename T>
struct Matrix<N, 0, T> {
    Matrix()=delete;
};
template<std::size_t M, typename T>
struct Matrix<0, M, T> {
    Matrix()=delete;
};
*/

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//prosty test badajacy elementy macierzy i ich oczekiwane wartosci
TEST(TemplateMatrix1, create) 
{
    Matrix<3, 5, int> m;
    EXPECT_EQ(m[0][0], 0);
    m[2][1] = 1;
    EXPECT_EQ(m[2][1], 1);
    m[2][4] = 14;
    EXPECT_EQ(m[2][4], 14);
    EXPECT_EQ(m[2][2], 0);
}
//zabawa wymiarami macierzy, generalnie wymiary nie moga byc rowne 0
TEST(TemplateMatrix2, createZero) 
{
    auto l = [](){ Matrix<0,3,int> m; };
    EXPECT_THROW(l(), std::underflow_error);
    auto l2 = [](){ Matrix<3,0,int> m; };
    EXPECT_THROW(l2(), std::underflow_error);
    auto l3 = [](){ Matrix<0,0,int> m; };
    EXPECT_THROW(l3(), std::underflow_error);
}
//macierz nie moze skladac sie z elementow typu bool, mamy na to wyjatek, naszym statement jest wynik funkcji lambda
TEST(TemplateMatrix3, createBool) {
    auto l = []() { Matrix<3,3,bool> m; };
    EXPECT_THROW(l(), std::bad_typeid);
}
//testowanie kopiowania macierzy, konstruktor kopiujacy dla macierzy o takich samych wymiarach
TEST(TemplateMatrix4, copyCtor) {
    //okreslanie wymiarow macierzy
    int number = 0;
    const int I = 2;
    const int J = 3;
    //wypelnianie elementow macierzy kolejnymi cyframi
    Matrix<I,J,int> m;
    for(int i = 0; i < I; ++i) {
        for(int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    //kopiowanie macierzy, wywolanie konstruktora kopiujacego
    Matrix<I,J,int> n = m;
    for(int i = 0; i < I; ++i) {
        //sprawdzanie kolejno wartosci elementow w matrixach m i n
        for(int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}
//testowanie kopiowania macierzy, konstruktor kopiujacy dla macierzy o rozniacych sie wymiarach
TEST(TemplateMatrix5, copyCtorSmallToBig) {
    int number = 0;
    const int I = 2;
    const int J = 2;
    //stworzenie i wypelnianie macierzy 2x2
    Matrix<I,J,int> m;
    for(int i = 0; i < I; ++i) {
        for(int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    //kopiujemy macierz o wymiarze mniejszym 2x2 do wiekszej 3x3
    Matrix<3,3,int> n = m;
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
TEST(TemplateMatrix6, copyCtorBigToSmall) {
    auto l = [&]() { Matrix<3,3,int> m; m[1][1] = 5; Matrix<2,3,int> n = m; };
    EXPECT_THROW(l(), std::range_error);
    auto o = [&]() { Matrix<3,3,int> m; m[1][1] = 5; Matrix<3,2,int> n = m; };
    EXPECT_THROW(o(), std::range_error);
}