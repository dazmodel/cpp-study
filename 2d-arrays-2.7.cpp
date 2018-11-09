#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  
  // Задаем размеры матрицы
  const int rows = 5;
  const int columns = 5;

  // Входные данные для вычислений
  int D[rows][columns] = {
    { 5, -7, 0, 255, 34 },
    { -12, 35, -1, 10, 7 },
    { 100, 1, 2, -5, 0 },
    { 290, -57, 90, 3, 11 },
    { 22, -33, 44, -55, 66 }
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie D(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << D[i][j];
    }

    cout << endl; 
  }
  cout << endl;
  
  // Выше главной диагонали - номер столбца больше номера строки
  int minEl = D[0][1];
  int minElementRow = 0;
  int minElementColumn = 1;

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(j > i) { // Мы выше главной диагонали матрицы
              if (D[i][j] < minEl) { // Ищем минимальный елемент
                minEl = D[i][j];
                minElementRow = i;
                minElementColumn = j;
              }
            } 
        }
    }
    
  //Печатаем результат
  cout << "Minimalnii element matrici D(" << rows << ", " << columns << ") raven " << minEl << endl;
  cout << "Ego index [" << minElementRow << ", " << minElementColumn << "]" << endl;
  
  cout << endl;
  return 0;
}