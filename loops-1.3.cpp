#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Вычисляем Z
// Поскольку формула содержит квадратный корень sqrt,
// функция может вернуть NaN
double calculateZ (double a, double x) {
  return (sqrt(x - 1.5) + pow(x, a))/(pow((x - 2), 1/3));
}

int main() {
  // Задаем края интервала для Х
  double xmin = 1, xmax = 4; 

  // Задаем минимальное значение для a
  double amin = 0.5;

  // Задаем шаг X
  double hx = 0.5;

  // Задаем шаг a
  double ha = 0.2;

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

  while(currentX >= xmin && currentX <= xmax && currentA >=amin) {
    double currentZ = calculateZ(currentA, currentX);

    // Проверяем, была ли ошибка в вычислениях (NaN)
    // если была, то
    if (isnan(currentZ)) {
      cout << "        Nevozmozhno vi4islit Z pri x = " << currentX << ", a = " << currentA << "!!!" << endl;
    }
    // если нет - печатаем результат
    else {
      cout << "        Pri x = " << currentX << ", a = " << currentA << ", Z = " << currentZ << endl;
    }

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