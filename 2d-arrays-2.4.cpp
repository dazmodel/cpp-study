#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  
  // Задаем размеры матрицы
  const int rows = 5;
  const int columns = 5;

  // Входные данные для вычислений
  int M[rows][columns] = {
    { 5, -7, 0, 255, 34 },
    { -12, 35, -1, 10, 7 },
    { 100, 1, 2, -5, 0 },
    { 290, -57, 90, 3, 11 },
    { 22, -33, 44, -55, 66 }
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie M(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << M[i][j];
    }

    cout << endl; 
  }
  cout << endl;
  
  // Выше главной диагонали - номер столбца больше номера строки
  int numberOfNegatives = 0;

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(j > i) { // Мы выше главной диагонали матрицы
              if (M[i][j] < 0) { // Текущий элемент отрицательный?
                numberOfNegatives++; // Считаем его (+1)
              }
            } 
        }
    }
    
  //Печатаем результат
  cout << "Koli4estvo otricatelnih elementov vi6e glavnoi diagonali: " << numberOfNegatives;
  
  cout << endl;
  return 0;
}