#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
    void addTime(const Time &t1, const Time &t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + (seconds / 60);
        hours = t1.hours + t2.hours + (minutes / 60);
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
};

int main() {
    const Time t1(10, 12, 56);
    const Time t2(13, 15, 1);
    Time t3;
    t3.addTime(t1, t2);
    cout << "Sum of times: ";
    t3.display();
    return 0;
}

