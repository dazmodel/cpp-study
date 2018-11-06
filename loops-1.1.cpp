#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

// Вычисляем Z=|x| + x^3
double calculateZ(double x) {
  return abs(x) + pow(x,3);
} 

// Вычисляем Y
double calculateY(double x) {
  return calculateZ(x) * ((pow(sin(2+x), 2)/(2 + x)));
}

int main() {
  // Задаем края интервала
  int xmin = 1, xmax = 4; 

  // Задаем шаг вычисления
  double hx = 0.5;

  cout << "Vhodnie dannue:" << endl;
  cout << "        x => [" << xmin << ", " << xmax << "]" << endl;
  cout << "        Hx = " << hx << endl;
  cout << endl;

  cout << "Rezultat: " << endl;

  //Текущее значение Х
  double currentX = xmin;
  // Количество итераций цикла, в рассчетах не участвует, только для отображения
  int iterationsCount = 0;
  while(currentX <= xmax) {
    cout << "        Pri X=" << currentX << ", Y=" << calculateY(currentX) << endl;
    currentX+=hx;
    iterationsCount++;
  }

  cout << endl;
  cout << "Gotovo! Koli4estvo proidennux iteracii: " << iterationsCount << endl;

  return 0;
}