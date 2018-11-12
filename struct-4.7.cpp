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
  discipline disciplines[3];
};

// Печать набора структур
void printStructuresSet(student *students, int n) {
  cout << "Spisok studentov: " << endl;
  cout << endl;
  for ( int i = 0; i < n; i++ ) {
    cout << "     Nomer v jurnale: " << students[i].id << endl;
    cout << "     Imia studenta  : " << students[i].name << endl;
    cout << "     Ocenki po predmetam po rezultatam y4ebnogo goda: " << endl;
    for ( int j = 0; j < 3; j++ ) {
      cout << "          " << students[i].disciplines[j].name << " : " << students[i].disciplines[j].mark << endl;
    }
    cout << endl;
  }
  cout << endl;
}

// Поиск студента по номеру в журнале
student findStudent(student *students, int numberInJournal, int nStuents) {
  for ( int i = 0; i < nStuents; i++ ) {
    if (students[i].id == numberInJournal) {
      return students[i];
    }
  }
}

// Поиск и печать результатов
void printGroups(student s, int nDisc, int bestMark) {
  cout << "Y studenta #" << s.id << " - " << s.name << " nailu46ie ocenki na konec goda po takim predmetam: " << endl;
  cout << endl;
  for ( int i = 0; i < nDisc; i++ ) {
    if ( s.disciplines[i].mark == bestMark ) {
      cout << "     " << s.disciplines[i].name << " : " << s.disciplines[i].mark << endl;
    }
  }
  cout << endl;
}

int main() {
  // Массив студентов
  const int numberOfStudents = 5;
  const int numberOfDisciplines = 3;

  student students[] = {
    { 1, "Ivanov", { { "Fizika", 3 }, { "Programmirovanie", 4 }, { "Literatura", 5 } } },
    { 2, "Petrov", { { "Fizika", 5 }, { "Programmirovanie", 4 }, { "Literatura", 2 } } },
    { 3, "Sidorov", { { "Fizika", 4 }, { "Programmirovanie", 5 }, { "Literatura", 3 } } },
    { 4, "Pakin", { { "Fizika", 3 }, { "Programmirovanie", 3 }, { "Literatura", 5 } } },
    { 5, "Sobakin", { { "Fizika", 5 }, { "Programmirovanie", 5 }, { "Literatura", 5 } } }
  };

  // Печатаем входные данные
  printStructuresSet(students, numberOfStudents);

  cout << "Vvedite nomer studenta v jurnale 4tobu uznat, po kakomy predmety y nego naily46aia ocenka po rezultatam goda: " << endl;
  cout << "(Nomer mojet bit on 1 do 5)" << endl;
  int studentToSearch;
  cin >> studentToSearch;

  if ( ( studentToSearch <= 0 ) || (studentToSearch > 5) ) {
    cout << "Nomer vveden neverno, smotri podskazky vishe!" << endl;
    return 0;
  }

  student currentStudent = findStudent(students, studentToSearch, numberOfStudents);

  // Будем искать предмет с максимальной оценкой
  discipline byMark;

  for ( int i = 0; i < numberOfDisciplines; i++ ) {
    if (currentStudent.disciplines[i].mark > byMark.mark ) {
      byMark = currentStudent.disciplines[i];
    }
  }

  printGroups(currentStudent, numberOfDisciplines, byMark.mark);
  
  return 0;
}