#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;
    bool isPM;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours >= 24) {
            isPM = hours != 24;
            hours %= 12;
            if (hours == 0) hours = 12;
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0), isPM(false) {}
    Time(int h, int m, int s, bool ap = false) : hours(h), minutes(m), seconds(s), isPM(ap) {
        normalize();
    }

    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ':' << (minutes < 10 ? "0" : "") << minutes << ':' << (seconds < 10 ? "0" : "") << seconds;
        if (isPM) cout << " p.m.";
        else cout << " a.m.";
    }

    Time(const Time& t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds), isPM(t.isPM) {}

    Time(const Time& t, bool ap) : hours(t.hours), minutes(t.minutes), seconds(t.seconds), isPM(ap) {
        normalize();
    }
};

int main() {
    int h, m, s;
    while (true) {
        cout << "Enter 24-hour time:\n";
        cout << "   Hours (0 to 23): "; cin >> h;
        if (h > 23)
            return 1;
        cout << "   Minutes: "; cin >> m;
        cout << "   Seconds: "; cin >> s;
        Time t(h, m, s);
        cout << "You entered: "; t.display();
        Time t12(t, h >= 12);
        cout << "\n12-hour time: "; t12.display();
        cout << "\n\n";
    }
    return 0;
}