#include <iostream>
using namespace std;

class ArrayOfArrays {
private:
    static const int NUMARRAYS = 10;  
    static const int MAXSIZE = 10;   
    int* ap[NUMARRAYS];              

public:
    ArrayOfArrays() {
        for (int j = 0; j < NUMARRAYS; j++) {
            ap[j] = new int[MAXSIZE];
        }
    }
    int& operator[](int index) {
       
        int row = index / MAXSIZE;   
        int col = index % MAXSIZE;    
        return *(ap[row] + col);     
    }

    void fillData() {
        for (int j = 0; j < NUMARRAYS; j++) {
            for (int k = 0; k < MAXSIZE; k++) {
                ap[j][k] = j * MAXSIZE + k;  
            }
        }
    }

    
    void printData() const {
        for (int j = 0; j < NUMARRAYS; j++) {
            for (int k = 0; k < MAXSIZE; k++) {
                cout << ap[j][k] << "\t";
            }
            cout << endl;
        }
    }

    ~ArrayOfArrays() {
        for (int j = 0; j < NUMARRAYS; j++) {
            delete[] ap[j];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    ArrayOfArrays arr;  
    arr.fillData();    
    arr.printData();    

    cout << "Доступ через оператор []: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << "\t";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}
