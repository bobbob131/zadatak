#include <iostream>
using namespace std;


void generisi_(unsigned tekuci, int preostaloCifara) {
  
  // Bazični slučaj: ako nema više cifara za dodavanje
  if (preostaloCifara == 0) {
    cout << tekuci << endl;  // ispiši broj
    return;
  }

  // Ako je poslednji bit trenutnog broja 1
  if ((tekuci & 1) != 0)
    // Možeš da dodaš 0 na kraj broja
    // (pomeri sve bitove ulevo za jedno mesto — dodaj 0 na kraj)
    generisi_(tekuci << 1, preostaloCifara - 1);
  
  // Pomeri sve bitove ulevo i postavi poslednji bit na 1 pomoću | 1
  generisi_((tekuci << 1) | 1, preostaloCifara - 1);
}

// Funkcija koja pokreće generisanje binarnih brojeva dužine od 1 do n
void generisi(int n) {
  // Za svaku dužinu od 1 do n
  for (int brojBinCifara = 1; brojBinCifara <= n; brojBinCifara++)
    // Pokreni rekurziju sa početnom vrednošću 0 i brojem preostalih cifara
    generisi_(0, brojBinCifara);
}

int main() {
  int n;
  cin >> n;
  generisi(n);
  return 0;
}
