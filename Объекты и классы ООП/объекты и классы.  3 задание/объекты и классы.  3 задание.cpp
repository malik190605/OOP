// объекты и классы.  3 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>

class Time {
private:
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void displayTime() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }

    Time addTime(const Time& t) const {
        int totalSeconds = seconds + t.seconds;
        int totalMinutes = minutes + t.minutes + totalSeconds / 60;
        int totalHours = hours + t.hours + totalMinutes / 60;
        return Time(totalHours % 24, totalMinutes % 60, totalSeconds % 60);
    }
};

int main() {
    
    Time t1(11, 59, 59);
    Time t2(1, 0, 1);

    Time t3 = t1.addTime(t2);

    std::cout << "Time 1: "; t1.displayTime();
    std::cout << "Time 2: "; t2.displayTime();
    std::cout << "Sum: "; t3.displayTime();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
