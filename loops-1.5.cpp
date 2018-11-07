#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Вычисляем значение Y на интервале,
// где a < x
float calculateYwhenAlessThanX (float a, float x) {
  return pow(a, 2) - x;
}

// Вычисляем значение Y при a = x
float calculateYwhenAEqualToX (float a, float x) {
  return pow(a, 2);
}

// Вычисляем значение Y на интервале,
// где a > x
float calculateYwhenAmoreThanX (float a, float x) {
  return pow(a, 2) + x;
} 

// Вычисляем Y
float calculateY (float a, float x) {
  // Если a < x, то 
  if (a < x) {
    return calculateYwhenAlessThanX(a, x);
  } 

  // Если a = x, то
  if (a == x) {
    return calculateYwhenAEqualToX(a, x);
  }

  // В противном случае a > x
  return calculateYwhenAmoreThanX(a, x);
}

int main() {
  // Задаем края интервала для Х
  int xmin = 1, xmax = 8; 

  // Задаем края интервала для a
  int amin = 2, amax = 10;

  // Задаем шаг X
  float hx = 0.5;

  // Задаем шаг a
  int ha = 1;

  cout << "Vhodnie dannue:" << endl;
  cout << "        x in [" << xmin << ", " << xmax << "]" << endl;
  cout << "        Hx = " << hx << endl;
  cout << "        a in [" << amin << ", " << amax << "]" << endl;
  cout << "        Ha = " << ha << endl;
  cout << endl;

  cout << "Rezultat: " << endl;

  //Текущее значение Х
  float currentX = xmin;
  float currentA = amin;

  // Количество итераций цикла, в рассчетах не участвует, только для отображения
  int iterationsCount = 0;

  while(currentX <= xmax && currentA <= amax) {
    cout << "        Pri x = " << currentX << ", a = " << currentA << ", Y = " << calculateY(currentA, currentX) << endl;

    // a и x меняются одновременно
    currentX += hx;
    currentA += ha;

    iterationsCount++;
  }

  cout << endl;
  cout << "Gotovo! Koli4estvo proidennux iteracii: " << iterationsCount << endl;
  cout << "                            Teku6ee X = " << currentX << endl;
  cout << "                            Teku6ee A = " << currentA << endl;
  return 0;
}