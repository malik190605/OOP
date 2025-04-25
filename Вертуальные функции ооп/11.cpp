#include <iostream>
#include <cstring>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
using namespace std;

// Абстрактный базовый класс
class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual bool isNumber() = 0;
    virtual ~Token() {}
};

// Класс для чисел
class Number : public Token {
private:
    float fnum;
public:
    Number(float n) : fnum(n) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return '\0'; }
    bool isNumber() override { return true; }
};

// Класс для операторов
class Operator : public Token {
private:
    char oper;
public:
    Operator(char c) : oper(c) {}
    float getNumber() override { return 0.0f; } // Не используется
    char getOperator() override { return oper; }
    bool isNumber() override { return false; }
};

// Функция приоритетов
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Вычисление одного действия
float applyOp(float a, float b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0.0f ? a / b : 0.0f;
    default: return 0;
    }
}

// Основной парсинг
float evaluate(const char* expr) {
    stack<Token*> tokens;

    const char* p = expr;
    while (*p) {
        if (isspace(*p)) {
            p++;
            continue;
        }

        if (isdigit(*p) || *p == '.') {
            char* end;
            float val = strtof(p, &end);
            tokens.push(new Number(val));
            p = end;
        }
        else if (strchr("+-*/", *p)) {
            while (!tokens.empty() && !tokens.top()->isNumber() &&
                precedence(tokens.top()->getOperator()) >= precedence(*p)) {
                // Вычисление
                Token* op2 = tokens.top(); tokens.pop();
                Token* num2 = tokens.top(); tokens.pop();
                Token* op1 = tokens.top(); tokens.pop();
                Token* num1 = tokens.top(); tokens.pop();

                float res = applyOp(num1->getNumber(), num2->getNumber(), op1->getOperator());
                tokens.push(new Number(res));

                delete num1; delete num2; delete op1; delete op2;
            }

            tokens.push(new Operator(*p));
            p++;
        }
        else {
            cout << "Ошибка: недопустимый символ '" << *p << "'" << endl;
            return 0.0f;
        }
    }

    // Последние вычисления
    while (tokens.size() >= 3) {
        Token* num2 = tokens.top(); tokens.pop();
        Token* op = tokens.top(); tokens.pop();
        Token* num1 = tokens.top(); tokens.pop();

        float res = applyOp(num1->getNumber(), num2->getNumber(), op->getOperator());
        tokens.push(new Number(res));

        delete num1; delete num2; delete op;
    }

    float result = 0.0f;
    if (!tokens.empty()) {
        result = tokens.top()->getNumber();
        delete tokens.top();
        tokens.pop();
    }

    return result;
}

int main() {
    char input[100];
    cout << "Введите выражение (например: 3.5 + 2.1 * 4.0): ";
    cin.getline(input, 100);

    float result = evaluate(input);
    cout << "Результат: " << result << endl;

    return 0;
}
