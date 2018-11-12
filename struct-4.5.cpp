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
  const int numberOfStudentsInGroup = 5;

  // Обе группы ниже упорядочены по убыванию среднего балла
  // Группа А
  student groupA[] = {
    { "Ivanov", 56 },
    { "Petrov", 42 },
    { "Sidorov", 34 },
    { "Pakin", 12 },
    { "Sobakin", 10 }
  };

  // Группа Б
  student groupB[] = {
    { "Beliaiev", 21 },
    { "Bragin", 17 },
    { "Palagin", 16 },
    { "Rosomahin", 12 },
    { "Kukunin", 10 }
  };

  // Печатаем входные данные
  cout << "Gryppa A: " << endl;
  cout << endl;
  vector<student> vRes;
  vRes.assign(groupA, groupA + numberOfStudentsInGroup);
  printSet(vRes);

  cout << endl;

  cout << "Gryppa B: " << endl;
  cout << endl;
  vRes.assign(groupB, groupB + numberOfStudentsInGroup);
  printSet(vRes);

  // Контейнер для будущего слияния групп
  student *mergedGroups = new student[numberOfStudentsInGroup * 2];

  int i = 0;
  int j = 0;
  int k = 0;

  while ( i < numberOfStudentsInGroup || j < numberOfStudentsInGroup ) {
    student v;
    if ( i < numberOfStudentsInGroup && j < numberOfStudentsInGroup ) {
        v = ( groupA[i].avgMark > groupB[j].avgMark ) ? groupA[i++] : groupB[j++];
    } else
    {
        v = ( numberOfStudentsInGroup == i ) ? groupB[j++] : groupA[i++];
    }

    mergedGroups[k++] = v;
  }
  
  // Печатаем результат
  cout << "Spisok ob6ei gryppu: " << endl;
  cout << endl;
  vRes.assign(mergedGroups, mergedGroups + numberOfStudentsInGroup * 2);
  printSet(vRes);
  
  return 0;
}