#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    string inputFile, outputFile;
    cout << "Введите имя входного файла: ";
    cin >> inputFile;
    cout << "Введите имя выходного файла: ";
    cin >> outputFile;

    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin) {
        cerr << "Не удалось открыть файл: " << inputFile << "\n";
        return 1;
    }
    if (!fout) {
        cerr << "Не удалось создать файл: " << outputFile << "\n";
        return 1;
    }

    istream_iterator<int> in(fin), in_end;
    ostream_iterator<int> out(fout, " ");

    while (in != in_end) {
        *out = *in;
        ++in;
        ++out;
    }

    cout << "Копирование завершено.\n";

    return 0;
}
