#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// Структура для хранения результатов соревнований
struct result {
  string name;
  string group;
  int score;
};

// Печать набора структур
void printSet(vector<result> &results) {
  for ( int i = 0; i < results.size(); i++ ) {
    cout << "     Imia: " << results[i].name << endl;
    cout << "     Gruppa: " << results[i].group << endl;
    cout << "     Rezultat: " << results[i].score << endl;
    cout << endl;
  }
  cout << endl;
}

int main() {
  // Массив студентов
  const int numberOfResults = 20;

  result results[] = {
    { "Ivanov", "A", 34 },
    { "Petrov", "C", 42 },
    { "Sidorov", "B", 56 },
    { "Pakin", "B", 12 },
    { "Sobakin", "B", 10 },
    { "Beliaiev", "C", 88 },
    { "Bragin", "A", 17 },
    { "Palagin", "A", 21 },
    { "Rosomahin", "B", 16 },
    { "Kukunin", "C", 10 },
    { "Ivanova", "A", 43 },
    { "Petrova", "A", 24 },
    { "Sidorova", "C", 65 },
    { "Pakina", "C", 21 },
    { "Sobakina", "B", 90 },
    { "Beliaieva", "C", 98 },
    { "Bragina", "B", 71 },
    { "Palagina", "B", 12 },
    { "Rosomahina", "C", 61 },
    { "Kukunina", "A", 76 }
  };

  // Печатаем входные данные
  cout << "Spisok rezultatov: " << endl;
  cout << endl;
  vector<result> vRes;
  vRes.assign(results, results + numberOfResults);
  printSet(vRes);

  // Формируем команду лучших
  vector<result> theTeam;
  
  // Размер команды лучших
  int theTeamSize = 7;
  
  result temp;
  bool exit = false;
  // Сортировка набора результатов пузырьком
  while (!exit) { // пока массив не отсортирован
    exit = true;

    for ( int i = 0; i < numberOfResults - 1; i++ ) { // внутренний цикл
      //сортировка пузырьком по возрастанию - знак >
      //сортировка пузырьком по убыванию - знак <
      if (results[i].score < results[i + 1].score) { // сравниваем два соседних элемента
      
        // выполняем перестановку элементов массива
        temp = results[i];
        results[i] = results[i + 1];
        results[i + 1] = temp;
        exit = false; // на очередной итерации была произведена перестановка элементов
      }
    }
  }

  for ( int i = 0; i < theTeamSize; i++ ) {
    theTeam.push_back(results[i]);
  }

  // Печатаем состав супер команды
  cout << "Spisok y4astnikov SUPER komandu: " << endl;
  cout << endl;
  printSet(theTeam);
  
  return 0;
}