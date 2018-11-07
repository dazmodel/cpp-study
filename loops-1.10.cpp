#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Вычисляем значение Y на интервале,
// где x^2 + y^2 <= a^2
double calculateYwhenXlessOrEqual (double x) {
  return x/(15 * pow(x, 2));
} 

// Вычисляем значение Y на интервале,
// где x^2 + y^2 > a^2
double calculateYwhenMore (double x) {
  return pow(x, 2) + exp(x);
}

double pow2XY(double x, double y) {
  return pow(x, 2) + pow(y, 2);
}

// Вычисляем Y
double calculateY (double a, double x, double y) {
  // Если x^2 + y^2 <= a^2, то 
  if (pow2XY(x, y) <= pow(a, 2)) {
    return calculateYwhenXlessOrEqual(x);
  }
  
  // В противном случае справедливо x^2 + y^2 > a^2
  return calculateYwhenMore(x);
}

int main() {
  // Задаем края интервала для Х
  int xmin = -3, xmax = 3; 

  // Задаем края интервала для a
  double amin = -0.1, amax = -1.4;

  // Задаем шаг X
  double hx = 0.5;

  // Задаем a
  double a = 5.3;

  // Задаем y
  double y = 1.1;

  cout << "Vhodnie dannue:" << endl;
  cout << "        x in [" << xmin << ", " << xmax << "]" << endl;
  cout << "        Hx = " << hx << endl;
  cout << "        a = " << a << endl;
  cout << "        y = " << y << endl;
  cout << endl;

  cout << "Rezultat: " << endl;

  //Текущее значение Х
  double currentX = xmin;

  // Количество итераций цикла, в рассчетах не участвует, только для отображения
  int iterationsCount = 0;

  while(currentX <= xmax) {
    double currentY = calculateY(a, currentX, y);

    // Проверяем, была ли ошибка в вычислениях (NaN)
    // если была, то
    if (isnan(currentY)) {
      cout << "        Nevozmozhno vi4islit Y pri x = " << currentX << ", a = " << a << ", and y = " << y << " !!! (delenie na 0)" << endl;
    } else {
      cout << "        Pri x = " << currentX << ", a = " << a << " and y = " << y << ", Y = " << currentY << endl;
    }

    currentX += hx;

    iterationsCount++;
  }

  cout << endl;
  cout << "Gotovo! Koli4estvo proidennux iteracii: " << iterationsCount << endl;
  cout << "                            Teku6ee X = " << currentX << endl;
  return 0;
}