#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std; 

int main() {
  
  // Задаем размеры матрицы
  const int rows = 5;
  const int columns = 5;

  // Входные данные для вычислений
  double M[rows][columns] = {
    { 5, -7, 0, 255, 78 },
    { -12, 35, -1, 10, 99 },
    { 100, 1, 2, -5, -43 },
    { 92, 24, -42, 70, 123 },
    { -92, -24, 42, -70, -123 }
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

  // Вычисляем сумму позитивных елементов на главной диагонали
  int sumOfMainDiagonalPositives =  0;

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(j == i) { // Мы на главной диагонали матрицы
              if (M[i][j] > 0) { // Позитивный элемент?
                sumOfMainDiagonalPositives += M[i][j]; // Считаем сумму
              }
            } 
        }
  }

  cout << "Summa positivnuh elementov glavnoi diagonali matrici M ravna: " << sumOfMainDiagonalPositives << endl;
  cout << endl;

  // Умножаем все элементы M на сумму всех позитивных элементов главной диагонали
  for ( int i = 0; i < rows; i++ ) {
    for ( int j = 0; j < columns; j++ ) {
      M[i][j] = M[i][j] * sumOfMainDiagonalPositives;
    }
  }
    
  // Печатаем результат
  cout << "Rezultat ymnojenia vseh elementov matrici M na summy pozitivnuh elementov ee glavnoi diagonali: " << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << M[i][j];
    }

    cout << endl; 
  }
  cout << endl;
  
  cout << endl;
  return 0;
}