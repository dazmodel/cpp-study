#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  // Задаем параметры окружности
  int a, b, radius;

  cout << "     Vvedite koordinaty centra kryga (a, b):" << endl;
  cin >> a >> b;

  cout << "     Vvedite radius kryga:" << endl;
  cin >> radius;

  // --------- Обрабатываем пользовательскй ввод точек ---------
  int numberOfPoints = 5;
  // Массив для сохранения наборов сторон треугольника
  // введенных пользователем
  int userInput [numberOfPoints][2];

  cout << "     Vvedite " << numberOfPoints << " koordinat to4ek (x, y): " << endl;
  cout << endl;

  for (int i = 0; i < numberOfPoints; i++) {
    cout << "          Vvedite nabor to4ek #" << i + 1 << " (x, y)" << endl;
    cin >> userInput[i][0] >> userInput[i][1];
  }
  // -----------------------------------------------------

  // ---------- Вычисляем попадание точки в окружность

  for (int i = 0; i < numberOfPoints; i++) {
    bool bingo = (pow((userInput[i][0] - a), 2) + pow((userInput[i][1] - b), 2)) <= pow(radius, 2);

    if(bingo) {
      cout << "           Tochka (" << userInput[i][0] << ", " << userInput[i][1] << ") popadaiet v okryshnost" << endl;
    }
    else {
      cout << "           Tochka (" << userInput[i][0] << ", " << userInput[i][1] << ") NE popadaiet v okryshnost" << endl;
    }
  }
  // -----------------------------------------------------------------------
  return 0;
}