#include <iostream>
using namespace std;

const int MEMORY_SIZE = 100;

float fmemory[MEMORY_SIZE];
int pmemory[MEMORY_SIZE];

int fmem_top = 0;
int pmem_top = 0;

class Float {
public:
    int addr;

    Float(float value) {
        addr = fmem_top;
        fmemory[fmem_top++] = value;
    }

    int operator&() {
        return addr;
    }
};

class ptrFloat {
public:
    int addr;

    ptrFloat(int* ptr) {
        addr = pmem_top;
        pmemory[pmem_top++] = *ptr;
    }

    float& operator*() {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    Float var1 = 1.234;
    Float var2 = 5.678;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << " *ptr1 = " << *ptr1 << endl;
    cout << " *ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123;
    *ptr2 = 8.456;

    cout << " *ptr1 = " << *ptr1 << endl;
    cout << " *ptr2 = " << *ptr2 << endl;
    return 0;
}
