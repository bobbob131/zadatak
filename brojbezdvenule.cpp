#include <iostream>
#include <vector>

using namespace std;

int binUDekadni(const vector<bool>& b) {
  int d = 0;
  for (bool x : b)
    d = 2 * d + (x ? 1 : 0);
  return d;
}
/* rekurzvino stablo zbog kojeg radi ceo zadatak poz 0 = 1
                       |
              +--------+---------+
              |                  |
          poz 1 = 0          poz 1 = 1
              |                  |
              |              +---+---+
          poz 2 = 1      poz 2 = 0  poz 2 = 1
              |              |         |
           [101]           [110]     [111]
              |
           [102] (ovaj ne postoji jer iza 0 ne sme 0) */
void generisi_(vector<bool>& tekuci, int poz) {
  if (poz == tekuci.size()) {
    cout << binUDekadni(tekuci) << endl;
    return;
  }
  if (poz > 0 && tekuci[poz-1] != false) {
    tekuci[poz] = false;
    generisi_(tekuci, poz + 1);
  }
  tekuci[poz] = true;
  generisi_(tekuci, poz + 1);
}

void generisi(int n) {
  for (int brojBinCifara = 1; brojBinCifara <= n; brojBinCifara++) {
    vector<bool> tekuci(brojBinCifara);
    generisi_(tekuci, 0);
  }
}

int main() {
  int n;
  cin >> n;
  generisi(n);
  return 0;
}
