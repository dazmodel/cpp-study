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
  const int columns = 5;

  // Входные данные для вычислений
  int Matr[rows][columns] = {
    { 5, -7, 0, 255, 34 },
    { -12, 35, -1, 10, 7 },
    {100, 1, 2, -5, 0}
  };

  // Распечатываем входные данные
  cout << "Vhodnie dannie Matr(" << rows << ", " << columns << "):" << endl;

  for (int i=0; i < rows; i++ ) {
    for (int j=0; j < columns; j++ ) {
        std::cout << " " << Matr[i][j];
    }
    std::cout << std::endl; 
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