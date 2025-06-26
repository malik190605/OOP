#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>   // для ispunct и tolower
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    string filename;
    cout << "Введите имя файла для анализа: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return 1;
    }

    map<string, int> freq; // частотная таблица: слово -> количество

    string line;
    while (getline(fin, line)) {
        size_t start = 0, end = 0;
        while (end <= line.size()) {
            if (end == line.size() || ispunct(static_cast<unsigned char>(line[end])) || isspace(static_cast<unsigned char>(line[end]))) {
                if (end > start) {
                    string word = line.substr(start, end - start);
                    // перевод в нижний регистр
                    for (char& c : word) {
                        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
                    }
                    freq[word]++;
                }
                start = end + 1;
            }
            end++;
        }
    }

    fin.close();

    cout << "\nЧастотная таблица слов:\n";
    for (const auto& p : freq) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
