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
  const int rows = 3;
  const int columns = 4;

  // Входные данные для вычислений
  int P[rows][columns] = {
    { 5, -7, 0, 255 },
    { -12, 35, -1, 10 },
    {100, 1, 2, -5}
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie P(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
      cout << " " << P[i][j];
    }
    
    cout << std::endl; 
  }

  // Заполняем массивы позитивных и негативных елементов
  // ноль игнорируется
  vector<int> PN;
  vector<int> PP;

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            int current = P[i][j];

            if(current > 0) {
              PP.push_back(current);
            }

            if(current < 0) {
              PN.push_back(current);
            }
        }
    }

  //Печатаем результат
  cout << "Otricatelnie elementu PN: ";
  printVector(PN);

  cout << endl;

  cout << "Polojitelnue elementu PP:";
  printVector(PP);

  return 0;
}