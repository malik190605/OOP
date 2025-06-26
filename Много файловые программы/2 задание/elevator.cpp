#include "elevator.h"
#include <limits>

elevator::elevator() : current_floor(0), current_dir(STOP), loading_timer(0), unloading_timer(0), destination(false) {
    // ������������� ����� �� ������ ����� (0)
}

void elevator::tick() {
    display(); // ����� ���������

    // ��������� ��������
    if (loading_timer > 0) --loading_timer;
    if (unloading_timer > 0) --unloading_timer;

    // ���� ���� ���������� � ���� �� �����
    if (destination && loading_timer == 0 && unloading_timer == 0) {
        if (current_floor < NUM_FLOORS - 1 && current_dir == UP) {
            current_floor++;
        }
        else if (current_floor > 0 && current_dir == DN) {
            current_floor--;
        }
        else if (current_floor == NUM_FLOORS - 1 || current_floor == 0) {
            current_dir = STOP;
        }
        if (current_floor == (destination ? NUM_FLOORS - 1 : 0)) {
            unloading_timer = LOAD_TIME;
            destination = false;
        }
    }
}

void elevator::display() const {
    cout << "���� �� �����: " << current_floor + 1 << endl;
    cout << "�����������: ";
    switch (current_dir) {
    case UP: cout << "�����" << endl; break;
    case DN: cout << "����" << endl; break;
    case STOP: cout << "����������" << endl; break;
    }
    cout << "���������: ";
    if (loading_timer > 0) cout << "�������� (" << loading_timer << ")" << endl;
    else if (unloading_timer > 0) cout << "�������� (" << unloading_timer << ")" << endl;
    else cout << "�����" << endl;
}

void elevator::set_destination(int floor) {
    if (floor > 0 && floor <= NUM_FLOORS) {
        destination = true;
        current_dir = (floor > current_floor + 1) ? UP : DN;
    }
    else {
        cout << "�������� ����! ������� ����� �� 1 �� " << NUM_FLOORS << endl;
    }
}

void elevator::get_destination() {
    int floor;
    cout << "������� ���� ���������� (1-" << NUM_FLOORS << ", 0 ��� ������): ";
    cin >> floor;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������
    if (floor == 0) return;
    set_destination(floor - 1); // �������� �� 0-based ������
}

int elevator::get_floor() const {
    return current_floor;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "��������� ���������� ����� ������" << endl;

    elevator lift;
    while (true) {
        lift.tick();
        lift.get_destination();
        if (cin.eof()) break; // ����� ��� Ctrl+Z ��� Ctrl+D
    }
    return 0;
}