#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

// Вычисляем p
double calculateP (int a, int b, int c) {
  return (a + b + c)/2;
}

double calculateHeight (int a, int b, int c) {
  return ((2/a) * sqrt(calculateP(a, b, c) * (calculateP(a, b, c) - a) * (calculateP(a, b, c) - c)));
}

int main() {
  // Задаем количество наборов сторон треугольника
  int numberOfSideSets = 2;

  // Количество сторон треугольника
  int numberOfTriangleSides = 3;

  // --------- Обрабатываем пользовательскй ввод ---------
  // Массив для сохранения наборов сторон треугольника
  // введенных пользователем
  int userInput [numberOfSideSets][numberOfTriangleSides];

  cout << "     Vvedite " << numberOfSideSets << " naborov storon treygolnika: " << endl;
  cout << endl;

  for (int i = 0; i < numberOfSideSets; i++) {
    cout << "          Vvedite nabor #" << i + 1 << " (a, b, c)" << endl;
    cin >> userInput[i][0] >> userInput[i][1] >> userInput[i][2];
  }
  // -----------------------------------------------------

  // ---------- Вычисляем высоты для введенных наборов сторон треугольников
  srand(static_cast<unsigned int>(time(NULL)));
  // Массив для высчитанных высот
  double triangleHeights[numberOfSideSets];

  // Заполняем массив результатами рассчетов
  // и вычисляем максимальную высоту

  for (int i = 0; i < numberOfSideSets; i++) {
    double h = calculateHeight(userInput[i][0], userInput[i][1], userInput[i][2]);
    triangleHeights[i] = h;
  }
  // -----------------------------------------------------------------------
  
  // ----------- Ищем максимальную высоту ----------------------------------
  double maxTriangleHeight = 0;
  int maxTriangleSidesIndex = 0;
  for (int i = 0; i< numberOfSideSets; i++) {
    if (triangleHeights[i] > maxTriangleHeight) {
      maxTriangleHeight = triangleHeights[i];
      maxTriangleSidesIndex = i;
    }
  }
  // -----------------------------------------------------------------------
  
  // ----------- Выводим результат -----------------------------------------

  cout << "     Maksimalnaya vusota h = " << maxTriangleHeight << 
          ", vu4islena dlia nabora #" << maxTriangleSidesIndex << 
          ", gde a = " << userInput[maxTriangleSidesIndex][0] << 
          ", b = " << userInput[maxTriangleSidesIndex][1] << 
          ", c = " << userInput[maxTriangleSidesIndex][2] << endl;

  // -----------------------------------------------------------------------
  system("PAUSE");
  return 0;
}