#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Вычисляем значение Y на интервале,
// где x > 2
float calculateYwhenXmoreThan2 (float a, float x) {
  return cos(a * x + 2);
} 

// Вычисляем значение Y на интервале,
// где x <= 2
float calculateYwhenXlessOrEqualTo2 (float a, float x) {
  return tan(abs(x - 2 * a));
}

// Вычисляем Y
float calculateY (float a, float x) {
  // Если x <= 2, то вычисляем значение Y на интервале,
  // где x <= 2
  if (x <= 2) {
    calculateYwhenXlessOrEqualTo2(a, x);
  } 
  // В противном случае x > 2, вычисляем значение Y на интервале,
  // где x > 2
  return calculateYwhenXmoreThan2(a, x);
  
}

int main() {
  // Задаем края интервала для Х
  float xmin = 0.5, xmax = 3.1; 

  // Задаем минимальное значение для a
  float amin = 0.1;

  // Задаем шаг X
  float hx = 0.2;

  // Задаем шаг a
  float ha = 0.3;

  cout << "Vhodnie dannue:" << endl;
  cout << "        x in [" << xmin << ", " << xmax << "]" << endl;
  cout << "        Hx = " << hx << endl;
  cout << "        a >= " << amin << endl;
  cout << "        Ha = " << ha << endl;
  cout << endl;

  cout << "Rezultat: " << endl;

  //Текущее значение Х
  float currentX = xmin;
  float currentA = amin;

  // Количество итераций цикла, в рассчетах не участвует, только для отображения
  int iterationsCount = 0;

  while(currentX >= xmin && currentX <= xmax && currentA >=amin) {
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