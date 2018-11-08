#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << "  " << v[i];
  }
  cout << endl;
}

int main() {
  
  // Задаем размеры матрицы
  const int rows = 5;
  const int columns = 5;

  // Входные данные для вычислений
  int X[rows][columns] = {
    { 5, -7, 0, 255, 34 },
    { -12, 35, -1, 10, 7 },
    { 100, 1, 2, -5, 0 },
    { 290, -57, 90, 3, 11 },
    { 22, -33, 44, -55, 66 }
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie X(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << X[i][j];
    }

    cout << endl; 
  }
  cout << endl;
  
  // Мы находимся на главной диагонали матрицы
  // если номер солбца равен номеру строки матрицы.
  // Исходя из этого, полагаем, что максимыльный элемент
  // это X[0][0]. Сравним его с остальными элементамии
  // главной диагонали, чтобы найти максимум
  int maxGD = X[0][0];

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(i == j) { // Мы на главной диагонали матрицы
              if (X[i][j] > maxGD) { // Текущий элемент больше, принимаем его как максимальный
                maxGD = X[i][j]; 
              }
            } 
        }
    }
    
  //Печатаем результат
  cout << "Maksimalnii element glavnoi diagonali X raven: " << maxGD;
  
  cout << endl;
  return 0;
}