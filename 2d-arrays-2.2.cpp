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
      cout << " " << Matr[i][j];
    }

    cout << endl; 
  }
  cout << endl;
  // Заполняем массивы парных и непарных елементов
  vector<int> M1; // Непарные
  vector<int> M2; // Парные

  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            int current = Matr[i][j];

            if(current % 2 == 0) { // Парное, делится на 2 без остатка
              M2.push_back(current); 
            } else { // В противном случае не парное
              M1.push_back(current);
            }
        }
    }
    
  //Печатаем результат
  cout << "Parnie, detatsa na 2 bez ostatka: ";
  printVector(M2);

  cout << endl;

  cout << "Neparnie:";
  printVector(M1);

  cout << endl;
  return 0;
}