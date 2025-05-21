#include <iostream>
using namespace std;

// Функција која проверава да ли број има две суседне нуле у бинарном запису
bool nemaDveNule(unsigned int x) {
    while (x > 0) {
        // Проверимо две последње цифре
        if ((x & 3) == 0)  // 3 у бинарном је 11 → провера последње две цифре
            return false;
        x >>= 1;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    unsigned int maxBroj = (1 << n);  // 2^n

    for (unsigned int i = 1; i < maxBroj; i++) {
        if (nemaDveNule(i))
            cout << i << endl;
    }

    return 0;
}
