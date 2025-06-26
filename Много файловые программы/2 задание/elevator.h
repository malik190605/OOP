#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
using namespace std;

const int NUM_FLOORS = 20; // ����� ������
const int LOAD_TIME = 3;   // ����� �������/������� (� �������� ������)

enum direction { UP, DN, STOP }; // ����������� ��������

class elevator {
private:
    int current_floor;      // ������� ���� (�� 0 �� NUM_FLOORS-1)
    direction current_dir;  // ������� �����������
    int loading_timer;      // ������ �������
    int unloading_timer;    // ������ �������
    bool destination;       // ���� ���������� (��� ������ ���������)

public:
    elevator();             // �����������
    void tick();            // ���� �������� ��� ���������� ������
    void display() const;   // ����� ��������� �����
    void set_destination(int floor); // ��������� ����� ����������
    void get_destination(); // ��������� ����� ���������� �� ���������
    int get_floor() const;  // ��������� �������� �����
};

#endif