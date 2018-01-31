#include <iostream>
#include <istream>
#include <ctime>

using namespace std;

struct Clock
{
    Clock() = delete;
    Clock(const Clock&) = default;
    Clock(int h, int m, int s): _hour(h), _minute(m), _second(s) {}
    
    int hours() const noexcept {return _hour;}
    int minutes() const noexcept {return _minute;}
    int seconds() const noexcept {return _second;}

    static Clock now() noexcept { return Clock{10,05,03}; }

    private:
    int8_t _hour;
    int8_t _minute;
    int8_t _second;
};

int main()
{
    Clock c{Clock::now()};
    cout << c.hours() << endl;
    // c.minutes() <<c.seconds()<<endl;

    //cout<<c.timeStr()<<endl;
    Clock g{10,15,20};
}