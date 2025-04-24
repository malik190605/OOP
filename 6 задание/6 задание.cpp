#include <iostream>
using namespace std;

// Функция сравнения двух строк через указатели
int compstr(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 < *s2)
            return -1;
        else if (*s1 > *s2)
            return 1;

        s1++; 
        s2++;
    }

  
    if (*s1 == '\0' && *s2 == '\0')
        return 0;          
    else if (*s1 == '\0')
        return -1;          
    else
        return 1;          
}

int main() {
    setlocale(LC_ALL, "Russian");

    const char* str1 = "абрикос";
    const char* str2 = "апельсин";
    const char* str3 = "абрикос";

    // Тест 1
    cout << "Сравнение \"" << str1 << "\" и \"" << str2 << "\": ";
    cout << compstr(str1, str2) << endl;

    // Тест 2
    cout << "Сравнение \"" << str2 << "\" и \"" << str1 << "\": ";
    cout << compstr(str2, str1) << endl;

    // Тест 3
    cout << "Сравнение \"" << str1 << "\" и \"" << str3 << "\": ";
    cout << compstr(str1, str3) << endl;

    return 0;
}
