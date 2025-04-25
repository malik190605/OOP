#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    // Конструкторы
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Конструктор из float (например, 7.5 футов)
    Distance(float dist) {
        feet = int(dist);
        inches = (dist - feet) * 12;
    }

    void getdist() {
        cout << "Введите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }

    void showdist() const {
        cout << feet << "\'-" << inches << '\"' << endl;
    }

    // Дружественная перегрузка оператора *
    friend Distance operator * (Distance d1, Distance d2);
    friend Distance operator * (float val, Distance d);
};

// Перегрузка Distance * Distance
Distance operator * (Distance d1, Distance d2) {
    // Переводим всё в футы
    float dist1 = d1.feet + d1.inches / 12;
    float dist2 = d2.feet + d2.inches / 12;

    float result = dist1 * dist2; // Площадь в квадратных футах

    return Distance(result); // Конструктор из float
}

// Перегрузка float * Distance
Distance operator * (float val, Distance d) {
    float dist = d.feet + d.inches / 12;
    float result = val * dist;
    return Distance(result); // Конструктор из float
}
int main() {
    setlocale(LC_ALL, "RU");
    Distance dist1, dist2, dist3;

    cout << "Введите первое расстояние:\n";
    dist1.getdist();

    cout << "Введите второе расстояние:\n";
    dist2.getdist();

    dist3 = dist1 * dist2;
    cout << "\nРезультат перемножения расстояний (как площадь): ";
    dist3.showdist();

    Distance dist4 = 7.5 * dist2;
    cout << "\nРезультат умножения 7.5 * расстояние: ";
    dist4.showdist();

    return 0;
}
