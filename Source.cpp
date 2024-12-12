#include <iostream>

class Triad {
protected:
    int a, b, c;

public:
    Triad(int x, int y, int z) : a(x), b(y), c(z) {}

    bool operator==(const Triad& other) const {
        return (a == other.a && b == other.b && c == other.c);
    }

    bool operator<(const Triad& other) const {
        return (a < other.a) || (a == other.a && b < other.b) || (a == other.a && b == other.b && c < other.c);
    }

    virtual void display() const {
        std::cout << "Triad: (" << a << ", " << b << ", " << c << ")\n";
    }
};

class Time : public Triad {
private:
    int hour, minute, second;

public:
    Time(int h, int m, int s) : Triad(h, m, s), hour(h), minute(m), second(s) {}

    bool operator==(const Time& other) const {
        return (hour == other.hour && minute == other.minute && second == other.second);
    }

    bool operator<(const Time& other) const {
        return (hour < other.hour) || (hour == other.hour && minute < other.minute) || (hour == other.hour && minute == other.minute && second < other.second);
    }

    void display() const override {
        std::cout << "Time: " << hour << ":" << minute << ":" << second << "\n";
    }
};

int main() {
    Triad triad1(1, 2, 3);
    Triad triad2(1, 2, 3);
    Time time1(12, 30, 45);
    Time time2(12, 30, 50);

    triad1.display();
    triad2.display();
    time1.display();
    time2.display();

    std::cout << "Triads equal: " << (triad1 == triad2) << "\n";
    std::cout << "Time1 < Time2: " << (time1 < time2) << "\n";

    return 0;
}
