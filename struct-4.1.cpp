#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// Структура для хранения студентов
struct student {
  string name;
  string zodiak;
};

// Структура для группировки студентов по знаку зодиака
struct zodiakGroup {
  string zodiak;
  vector<student> students;
};

// Функция нахождения группы по имени зодиака
int zodiakGroupIndex(vector<zodiakGroup> &groups, string zodiakGroupName) {
  int zodiakGroupIndex = -1;
  for ( int i = 0; i < groups.size(); i++ ) {
    if (groups[i].zodiak == zodiakGroupName) {
      zodiakGroupIndex = i;
      break;
    }
  }

  return zodiakGroupIndex;
}

// Печать набора структур
void printStructuresSet(student *students, int n) {
  cout << "Spisok studentov: " << endl;
  cout << endl;
  for ( int i = 0; i < n; i++ ) {
    cout << "     Name: " << students[i].name << endl;
    cout << "     Zodiak: " << students[i].zodiak << endl;
    cout << endl;
  }
  cout << endl;
}

// Печать сгруппированных значений
void printGroups(vector<zodiakGroup> &groups) {
  cout << "Gruppirovka stydentov po znaky zodiaka: " << endl;
  cout << endl;
  for ( int i = 0; i < groups.size(); i++ ) {
    cout << groups[i].zodiak << ":" << endl;
    for ( int j = 0; j < groups[i].students.size(); j++ ) {
      cout << "     " << groups[i].students[j].name << endl;
    }
    cout << endl;
  }
}

int main() {
  // Массив студентов
  const int numberOfStudents = 10;

  student students[] = {
    { "Ivanov", "Ruby" },
    { "Petrov", "Strelec" },
    { "Sidorov", "Telec" },
    { "Pakin", "Vesy" },
    { "Sobakin", "Deva" },
    { "Beliaiev", "Ruby" },
    { "Bragin", "Rak" },
    { "Palagin", "Strelec" },
    { "Rosomahin", "Lev" },
    { "Kukunin", "Ruby" }
  };

  // Печатаем входные данные
  printStructuresSet(students, numberOfStudents);

  // Будем группировать по знаку зодиака
  vector<zodiakGroup> byZodiak;
  
  for ( int i = 0; i < numberOfStudents; i++ ) {
    int indexOfZodiakGroup = zodiakGroupIndex(byZodiak, students[i].zodiak);

    if ( indexOfZodiakGroup == -1 ) { // Новый зодиак, добавляем группу
      zodiakGroup newZodiakGroup;
      newZodiakGroup.zodiak = students[i].zodiak;
      newZodiakGroup.students.push_back(students[i]);

      byZodiak.push_back(newZodiakGroup);
    } else { // Существующая группа по зодиаку, добавляем студента туда
      byZodiak[indexOfZodiakGroup].students.push_back(students[i]);
    }
  }

  printGroups(byZodiak);
  
  return 0;
}