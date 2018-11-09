#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  // Задаем размеры матрицы
  const int rows = 5;
  const int columns = 4;

  // Входные данные для вычислений
  int C[rows][columns] = {
    { 5, -7, 0, 255 },
    { -12, 35, -1, 10 },
    { 100, 1, 2, -5 },
    { 34, 7, 0, 80 },
    { 92, 24, -42, 70 }
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie C(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << C[i][j];
    }

    cout << endl; 
  }
  cout << endl;

  // Задаем индексы строчек, в которых будем менятьзначения местами (индекс начинается с 0)
  const int sourceIndex = 0; // 1я
  const int destIndex = 1; // 2я 

  // Меняем значения местами
  int tmpEl;

  for(int i = 0; i < columns; i++) {
    tmpEl = C[destIndex][i];
    C[destIndex][i] = C[sourceIndex][i];
    C[sourceIndex][i] = tmpEl;

  }
    
  //Печатаем результат
  cout << "Matrica C(" << rows << ", " << columns << ") posle zameny mestami elementov ";
  cout << sourceIndex + 1 << " i " << destIndex + 1 << " strok: " << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << C[i][j];
    }

    cout << endl; 
  }
  
  cout << endl;
  return 0;
}