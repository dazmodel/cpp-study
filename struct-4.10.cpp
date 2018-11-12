#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// Стуктура для хранения предметов
struct discipline {
  string name;
  int mark;
};

// Структура для хранения студентов
struct student {
  int id;
  string name;
  bool playChess;
  discipline disciplines[3];
};

// Печать набора структур
void printStructuresSet(student *students, int n) {
  cout << "Spisok studentov: " << endl;
  cout << endl;
  for ( int i = 0; i < n; i++ ) {
    cout << "     Nomer v jurnale: " << students[i].id << endl;
    cout << "     Imia studenta  : " << students[i].name << endl;
    cout << "     Igraet v shahmatu?  : " << students[i].playChess << endl;
    cout << "     Ocenki po predmetam po rezultatam y4ebnogo goda: " << endl;
    for ( int j = 0; j < 3; j++ ) {
      cout << "          " << students[i].disciplines[j].name << " : " << students[i].disciplines[j].mark << endl;
    }
    cout << endl;
  }
  cout << endl;
}

// Поиск шахматистов
vector<student> findChessmen(student *students, int nStuents) {
  vector<student> result;
  for ( int i = 0; i < nStuents; i++ ) {
    if ( students[i].playChess ) {
      result.push_back(students[i]);
    }
  }
  return result;
}

// Поиск и печать результатов
void printGroups(vector<student> s, int nDisc) {

  cout << "Spisok studentov-shahmatistov, sdav6ih Programmirovanie na 4 i 5: " << endl;
  cout << endl;
  for ( int i = 0; i < s.size(); i++ ) {
    bool match = false;
    for ( int j = 0; j < nDisc; j++ ) {
      if ( s[i].disciplines[j].name.compare("Programmirovanie") == 0 && s[i].disciplines[j].mark >= 4 ) {
        match = true;
        break;
      }
    }

    if ( match ) {
      cout << "     #" << s[i].id << " - " << s[i].name << endl;
    }
  }
  cout << endl;
}

int main() {
  // Массив студентов
  const int numberOfStudents = 5;
  const int numberOfDisciplines = 3;

  student students[] = {
    { 1, "Ivanov", true, { { "Fizika", 4 }, { "Programmirovanie", 4 }, { "Literatura", 5 } } },
    { 2, "Petrov", false, { { "Fizika", 5 }, { "Programmirovanie", 4 }, { "Literatura", 2 } } },
    { 3, "Sidorov", false, { { "Fizika", 4 }, { "Programmirovanie", 5 }, { "Literatura", 3 } } },
    { 4, "Pakin", true, { { "Fizika", 3 }, { "Programmirovanie", 3 }, { "Literatura", 5 } } },
    { 5, "Sobakin", true, { { "Fizika", 5 }, { "Programmirovanie", 5 }, { "Literatura", 5 } } }
  };

  // Печатаем входные данные
  printStructuresSet(students, numberOfStudents);

  // Ищем шахматистов
  vector<student> chessmen = findChessmen(students, numberOfStudents);

  // Печатаем шахматистов, сдавших сессию на 4 и 5
  printGroups(chessmen, numberOfDisciplines);
  
  return 0;
}