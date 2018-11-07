#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

// Вычисляем Y
double calculateY(double a, double x) {
  return (pow(a, 2) * pow((x - 1), 1.0/3))/(x + 1);
}

int main() {
  // Задаем края интервала
  int xmin = -2, xmax = 2; 

  // Задаем шаг вычисления
  double hx = 0.25;

  // Задаем значение а
  double a = 1.02;

  cout << "Vhodnie dannue:" << endl;
  cout << "        x in [" << xmin << ", " << xmax << "]" << endl;
  cout << "        Hx = " << hx << endl;
  cout << "        a = " << hx << endl;
  cout << endl;

  cout << "Rezultat: " << endl;

  //Текущее значение Х
  double currentX = xmin;
  // Количество итераций цикла, в рассчетах не участвует, только для отображения
  int iterationsCount = 0;
  while(currentX <= xmax) {
    double currentY = calculateY(a, currentX);

    // Проверяем, была ли ошибка в вычислениях (NaN)
    // если была, то
    if (isnan(currentY)) {
      cout << "        Nevozmozhno vi4islit Y pri x = " << currentX << " and a = " << a << " !!! (otricatelnoe pod kornem v chislitele)" << endl;
    } else {
      cout << "        Pri X=" << currentX << " and a = " << a << ", Y=" << currentY << endl;
    }

    currentX+=hx;
    iterationsCount++;
  }

  cout << endl;
  cout << "Gotovo! Koli4estvo proidennux iteracii: " << iterationsCount << endl;

  return 0;
}