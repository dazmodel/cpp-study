#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  // Задаем размеры матрицы
  const int rows = 3;
  const int columns = 5;

  // Входные данные для вычислений
  int Q[rows][columns] = {
    { 5, -7, 0, 255, 34 },
    { -12, 35, -1, 10, 7 },
    {100, 1, 2, -5, 0}
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie Q(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << Q[i][j];
    }

    cout << endl; 
  }
  cout << endl;

  // Задаем индексы строчек, в которых будем менятьзначения местами (индекс начинается с 0)
  const int sourceIndex = 0; // 1я
  const int destIndex = 2; // 3я 

  // Меняем значения местами
  int tmpEl;

  for(int i = 0; i < columns; i++) {
    tmpEl = Q[destIndex][i];
    Q[destIndex][i] = Q[sourceIndex][i];
    Q[sourceIndex][i] = tmpEl;

  }
    
  //Печатаем результат
  cout << "Matrica Q(" << rows << ", " << columns << ") posle zameny mestami elementov ";
  cout << sourceIndex + 1 << " i " << destIndex + 1 << " strok: " << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << Q[i][j];
    }

    cout << endl; 
  }
  

  cout << endl;
  return 0;
}