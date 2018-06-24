#include <iostream>
#include <vector>
#include <gtest/gtest.h>

template<typename char>

class SimpleString {
  
  public:
    SimpleString() = default;
    SimpleString(const char *ptr)
    {
        std::copy(ptr, ptr+std::strlen(ptr), std::back_inserter(_data));
    }
    SimpleString(const std::basic_string<char> &str){
        std::copy(std::begin(str), std::end(ptr), std::back_inserter(_data));
    }
    SimpleString(const SimpleString<char> &rhs){
        std::copy(std::begin(rhs._data), std::end(rhs._data), std:back_inserter(_data));
    }
    bool isEqual(const std::string &str)
    {
        std::string tmp;
        std::copy(std::begin(_data), std::end(_data), std:back_inserter(tmp))
        return tmp = str;
    }
    SimpleString& add(const SimpleString<char>& other)
    {
        std::copy(std::begin(other._data), std::end(other._data), std::back_inserter(_data));
        return *this;
    }

  private:
    std::vector<char> _data;
};

TEST(CustomStringFunctions, emptyString) {
    CustomStringFunctions<char> str;
    EXPECT_TRUE(str.isEqual(""));
}

TEST(CustomStringFunctions, init_from_const_char) {
    CustomStringFunctions<char> str { "this is a char" };
    EXPECT_TRUE(str.isEqual("this is a char"));
}

TEST(CustomStringFunctions, init_from_basic_string) {
    CustomStringFunctions<char> str { "this is a char" };
    EXPECT_TRUE(str.isEqual("this is a char"));
}

TEST(CustomStringFunctions, plus_assign_operator) {
    CustomStringFunctions<char> str { "t" };
    str.add(CustomStringFunctions<char> { "i" });
    EXPECT_TRUE(str.isEqual("ti"));
}
TEST(CustomStringFunctions, copyctor) {
    CustomStringFunctions<char> str { "this is a str" };
    auto k = str;
    EXPECT_TRUE(k.isEqual("this is a str"));
}

int main()
{

}