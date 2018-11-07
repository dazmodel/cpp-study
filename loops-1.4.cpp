#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Вычисляем значение Y на интервале,
// где x < b
double calculateYwhenXlessThanB (double a, double b, double x) {
  return sin(abs(a * x + pow(b, a)));
} 

// Вычисляем значение Y на интервале,
// где x >= b
double calculateYwhenXmoreOrEqualToB (double a, double b, double x) {
  return cos(abs(a * x - pow(b, a)));
}

// Вычисляем Y
double calculateY (double a, double b, double x) {
  // Если x < b, то вычисляем значение Y на интервале,
  // где x < b
  if (x < b) return calculateYwhenXlessThanB(a, b, x);

  // Если x >= b, то вычисляем значение Y на интервале,
  // где x >= b
  if (x >= b) return calculateYwhenXmoreOrEqualToB(a, b, x);
}

int main() {
  // Задаем края интервала для Х
  double xmin = 0.5, xmax = 3.1; 

  // Задаем минимальное значение для a
  double amin = 0.1;

  // Задаем шаг X
  double hx = 0.2;

  // Задаем шаг a
  double ha = 0.3;

  cout << "Vhodnie dannue:" << endl;
  cout << "        x in [" << xmin << ", " << xmax << "]" << endl;
  cout << "        Hx = " << hx << endl;
  cout << "        a >= " << amin << endl;
  cout << "        Ha = " << ha << endl;
  cout << endl;

  cout << "Rezultat: " << endl;

  //Текущее значение Х
  double currentX = xmin;
  double currentA = amin;

  // Количество итераций цикла, в рассчетах не участвует, только для отображения
  int iterationsCount = 0;

  while(currentX <= xmax || currentA >= amax) {
    cout << "        Pri x = " << currentX << ", a = " << currentA << " and b = " << b << ", Y = " << calculateY(currentA, b, currentX) << endl;

    // a и x меняются одновременно
    currentX += hx;
    currentA += -ha;

    iterationsCount++;
  }

  cout << endl;
  cout << "Gotovo! Koli4estvo proidennux iteracii: " << iterationsCount << endl;
  cout << "                            Teku6ee X = " << currentX << endl;
  cout << "                            Teku6ee A = " << currentA << endl;
  return 0;
}