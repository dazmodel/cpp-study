#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// Структура для хранения иформации о студенте
struct student {
  string name;
  double avgMark;
};

// Печать набора структур
void printSet(vector<student> &results) {
  for ( int i = 0; i < results.size(); i++ ) {
    cout << "     Imia: " << results[i].name << endl;
    cout << "     Srednii ball: " << results[i].avgMark << endl;
    cout << endl;
  }
  cout << endl;
}

int main() {
  // Размер массива студентов
  const int numberOfMath = 5;
  const int numberOfInf = 8;

  student didMath[] = {
    { "Ivanov", 56 },
    { "Petrov", 42 },
    { "Sidorov", 34 },
    { "Pakin", 12 },
    { "Sobakin", 10 }
  };

  student didInf[] = {
    { "Beliaiev", 21 },
    { "Pakin", 12 },
    { "Bragin", 17 },
    { "Petrov", 24 },
    { "Palagin", 16 },
    { "Rosomahin", 12 },
    { "Sobakin", 30 },
    { "Kukunin", 10 }
  };

  vector<student> vRes;

  // Печатаем входные данные
  cout << "Studenty-y4astniki olimpiady po Matematike: " << endl;
  cout << endl;
  
  vRes.assign(didMath, didMath + numberOfMath);
  printSet(vRes);

  cout << endl;

  cout << "Studenty-y4astniki olimpiady po Informatike: " << endl;
  cout << endl;
  vRes.assign(didInf, didInf + numberOfInf);
  printSet(vRes);

  // Контейнер для будущего слияния групп
  vector<student> bothOlimp;

  for ( int i = 0; i < numberOfMath; i++ ) {
    for ( int j = 0; j < numberOfInf; j++ ) {
      if (didMath[i].name.compare(didInf[j].name) == 0) {
        bothOlimp.push_back(didMath[i]);
      }
    }
  }
  
  // Печатаем результат
  cout << "Studenty-y4astniki obeih olimpiad: " << endl;
  for ( int i = 0; i < bothOlimp.size(); i++ ) {
    cout << "     Imia: " << bothOlimp[i].name << endl;
    cout << endl;
  }
  
  return 0;
}