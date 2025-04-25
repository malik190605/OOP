#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

// === Абстрактный базовый класс ===
class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

// === Класс числа ===
class Number : public Token {
private:
    float fnum;
public:
    Number(float f) : fnum(f) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return '\0'; } // фиктивный
};

// === Класс оператора ===
class Operator : public Token {
private:
    char oper;
public:
    Operator(char c) : oper(c) {}
    float getNumber() override { return 0.0; } // фиктивный
    char getOperator() override { return oper; }
};

// === Стек для Token* ===
class Stack {
private:
    Token* arr[100];
    int top;
public:
    Stack() : top(0) {}
    void push(Token* t) {
        if (top < 100)
            arr[top++] = t;
        else
            cout << "Стек переполнен\n";
    }

    Token* pop() {
        if (top > 0)
            return arr[--top];
        else {
            cout << "Стек пуст\n";
            return nullptr;
        }
    }

    bool isEmpty() {
        return top == 0;
    }

    ~Stack() {
        while (!isEmpty())
            delete pop();
    }
};

// === Простая функция вычисления выражения ===
// Например: "3.0 + 4.0 * 2.0"
float evaluate(const string& expr) {
    istringstream iss(expr);
    string token;
    Stack stack;

    while (iss >> token) {
        if (isdigit(token[0]) || token[0] == '.') {
            float num = stof(token);
            stack.push(new Number(num));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            stack.push(new Operator(token[0]));
        }
    }

    // Перебор стека в обратном порядке — простой подход (без приоритета)
    vector<Token*> rev;
    while (!stack.isEmpty()) {
        rev.push_back(stack.pop());
    }

    reverse(rev.begin(), rev.end());

    // Выполняем вычисления (упрощённо: без учёта приоритета операций)
    float result = 0.0f;
    if (rev.size() >= 3) {
        result = rev[0]->getNumber();
        for (size_t i = 1; i < rev.size(); i += 2) {
            char op = rev[i]->getOperator();
            float next = rev[i + 1]->getNumber();

            switch (op) {
            case '+': result += next; break;
            case '-': result -= next; break;
            case '*': result *= next; break;
            case '/': result /= next; break;
            }
        }
    }

    for (auto ptr : rev)
        delete ptr;

    return result;
}

// === main() ===
int main() {
    string expr;

    cout << "Введите выражение через пробелы (например: 3.5 + 4.2 * 2.0):\n";
    getline(cin, expr);

    float result = evaluate(expr);
    cout << "Результат: " << result << endl;

    return 0;
}
