#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int nHorses = 5;
const float finishLine = 5.0f; // длина дистанции в форлонгах

class Horse {
protected:
    static Horse* hArray[nHorses];
    static int totalHorses;
    float fDist;
    int horseNum;

public:
    Horse() : fDist(0.0f) {
        horseNum = totalHorses;
        hArray[totalHorses++] = this;
    }

    virtual void horse_tick() {
        fDist += static_cast<float>(rand() % 10) / 10.0f;
    }

    float getDist() const {
        return fDist;
    }

    int getNum() const {
        return horseNum;
    }

    virtual ~Horse() = default;

    static void raceTickAll() {
        for (int i = 0; i < totalHorses; i++) {
            hArray[i]->horse_tick();
        }
    }

    static void showRace() {
        for (int i = 0; i < totalHorses; i++) {
            int pos = static_cast<int>(hArray[i]->getDist() * 10);
            for (int j = 0; j < pos; j++) cout << ".";
            cout << i << endl;
        }
    }

    static bool raceFinished() {
        for (int i = 0; i < totalHorses; i++) {
            if (hArray[i]->getDist() >= finishLine) return true;
        }
        return false;
    }
};

Horse* Horse::hArray[nHorses];
int Horse::totalHorses = 0;

// -------------------------------------------------

class ComHorse : public Horse {
public:
    void horse_tick() override {
        // Найти лидера
        float maxDist = 0.0f;
        for (int i = 0; i < totalHorses; i++) {
            if (hArray[i]->getDist() > maxDist) {
                maxDist = hArray[i]->getDist();
            }
        }

        // Проверка: я ли лидер?
        if (fDist >= maxDist - 0.0001f) {
            bool rivalsClose = false;
            for (int i = 0; i < totalHorses; i++) {
                if (i != horseNum) {
                    if (abs(hArray[i]->getDist() - fDist) < 0.1f) {
                        rivalsClose = true;
                        break;
                    }
                }
            }

            if (rivalsClose) {
                fDist += static_cast<float>((rand() % 10) + 5) / 10.0f; // ускорение
                return;
            }
        }

        // обычное движение
        fDist += static_cast<float>(rand() % 10) / 10.0f;
    }
};

// -------------------------------------------------

int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned>(time(0)));

    // создаем обычных и "конкурентных" лошадей
    Horse h1, h2;
    ComHorse ch1, ch2, ch3;

    cout << "Начало скачек!\n";

    while (!Horse::raceFinished()) {
        Horse::raceTickAll();
        Horse::showRace();
        cout << "----------------\n";
        _sleep(500); // задержка для визуализации (Windows). На Linux: usleep(500000);
    }

    cout << "Финиш!\n";
    return 0;
}
