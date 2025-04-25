#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    // ������������
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // ����������� �� float (��������, 7.5 �����)
    Distance(float dist) {
        feet = int(dist);
        inches = (dist - feet) * 12;
    }

    void getdist() {
        cout << "������� ����: "; cin >> feet;
        cout << "������� �����: "; cin >> inches;
    }

    void showdist() const {
        cout << feet << "\'-" << inches << '\"' << endl;
    }

    // ������������� ���������� ��������� *
    friend Distance operator * (Distance d1, Distance d2);
    friend Distance operator * (float val, Distance d);
};

// ���������� Distance * Distance
Distance operator * (Distance d1, Distance d2) {
    // ��������� �� � ����
    float dist1 = d1.feet + d1.inches / 12;
    float dist2 = d2.feet + d2.inches / 12;

    float result = dist1 * dist2; // ������� � ���������� �����

    return Distance(result); // ����������� �� float
}

// ���������� float * Distance
Distance operator * (float val, Distance d) {
    float dist = d.feet + d.inches / 12;
    float result = val * dist;
    return Distance(result); // ����������� �� float
}
int main() {
    setlocale(LC_ALL, "RU");
    Distance dist1, dist2, dist3;

    cout << "������� ������ ����������:\n";
    dist1.getdist();

    cout << "������� ������ ����������:\n";
    dist2.getdist();

    dist3 = dist1 * dist2;
    cout << "\n��������� ������������ ���������� (��� �������): ";
    dist3.showdist();

    Distance dist4 = 7.5 * dist2;
    cout << "\n��������� ��������� 7.5 * ����������: ";
    dist4.showdist();

    return 0;
}
