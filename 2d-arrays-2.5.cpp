#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  
  // Задаем размеры матрицы
  const int rows = 5;
  const int columns = 5;

  // Входные данные для вычислений
  int P[rows][columns] = {
    { 5, -7, 0, 255, 34 },
    { -12, 35, -1, 10, 7 },
    { 100, 1, 2, -5, 0 },
    { 290, -57, 90, 3, 11 },
    { 22, -33, 44, -55, 66 }
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
  
  // В какой строчке матрицы будем искать?
  int rowToSearch = 3;

  // Полагаем что максимальный элемент - первый в строке
  int maxEl = P[rowToSearch][0];
  // Соответственно его индекс равен 0
  int maxElIndex = 0;

  // Ищем максимальный элемент в строке и его индекс
  for(int i = 1; i < columns; i++) {
    if(P[rowToSearch][i] > maxEl) {
      maxEl = P[rowToSearch][i];
      maxElIndex = i;
    }
  }
    
  //Печатаем результат
  cout << "Maksimalniy element v " << rowToSearch << " stroke P raven " << maxEl << endl;
  cout << "Ego index raven " << maxElIndex;
  
  cout << endl;
  return 0;
}