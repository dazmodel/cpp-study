#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std; 

int main() {
  
  // Задаем размеры матрицы
  const int rows = 4;
  const int columns = 4;

  // Входные данные для вычислений
  double P[rows][columns] = {
    { 5, -7, 0, 255 },
    { -12, 35, -1, 10 },
    { 100, 1, 2, -5 },
    { 92, 24, -42, 70 }
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie P(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << P[i][j];
    }

    cout << endl; 
  }
  cout << endl; 

  // Вычисляем сумму позитивных елементов на главной диагонали
  int sumOfMainDiagonalPositives =  0;

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(j == i) { // Мы на главной диагонали матрицы
              if (P[i][j] > 0) { // Позитивный элемент?
                sumOfMainDiagonalPositives += P[i][j]; // Считаем сумму
              }
            } 
        }
  }

  cout << "Summa positivnuh elementov glavnoi diagonali matrici P ravna: " << sumOfMainDiagonalPositives << endl;
  cout << endl;

  // Делим все элементы Р на сумму всех позитивных элементов главной диагонали
  for ( int i = 0; i < rows; i++ ) {
    for ( int j = 0; j < columns; j++ ) {
      P[i][j] = P[i][j]/sumOfMainDiagonalPositives;
    }
  }
    
  // Печатаем результат
  cout << "Rezultat deleniia vseh elementov matrici P na summy pozitivnuh elementov ee glavnoi diagonali: " << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << P[i][j];
    }

    cout << endl; 
  }
  cout << endl;
  
  cout << endl;
  return 0;
}