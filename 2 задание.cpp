#include <iostream>
#include <cstring>    
#include <cctype>     

using namespace std;

class String {
private:
    char* str;  
public:
    // Конструктор по умолчанию
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    // Конструктор с параметром
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Деструктор
    ~String() {
        delete[] str;
    }
    void display() const {
        cout << str << endl;
    }

    void upit() {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]);  // переводим каждый символ
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Тестирование
    String s1("Hello, World!");
    cout << "Исходная строка: ";
    s1.display();

    s1.upit();

    cout << "В верхнем регистре: ";
    s1.display();

    return 0;
}
