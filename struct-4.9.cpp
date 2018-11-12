#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// Структура для хранения результатов сессии студента
struct result {
  string name;
  string sex;
  int score;
};

// Структура для группировки студентов по полу
struct sexGroup {
  string sex;
  vector<result> results;
};

// Функция нахождения группы по полу
int getGroupIndex(vector<sexGroup> &groups, string sex) {
  int groupIndex = -1;
  for ( int i = 0; i < groups.size(); i++ ) {
    if (groups[i].sex == sex) {
      groupIndex = i;
      break;
    }
  }

  return groupIndex;
}

// Печать набора структур
void printSet(result *results, int n) {
  cout << "Spisok rezultatov sessii: " << endl;
  cout << endl;
  for ( int i = 0; i < n; i++ ) {
    cout << "     Imia: " << results[i].name << endl;
    cout << "     Pol: " << results[i].sex << endl;
    cout << "     Ball: " << results[i].score << endl;
    cout << endl;
  }
  cout << endl;
}

// Поиск и печать результата
void printGroups(vector<sexGroup> &groups) {
  int bestIndex = 0;
  double bestGroupAvg = 0;
  for ( int i = 0; i < groups.size(); i++ ) {
    int groupSum = 0;
    for ( int j = 0; j < groups[i].results.size(); j++ ) {
      groupSum += groups[i].results[j].score;
    }
    double groupAvg = groupSum / groups[i].results.size();

    if ( groupAvg > bestGroupAvg ) {
      bestGroupAvg = groupAvg;
      bestIndex = i;
    }
  }

  cout << "Lu4shaia uspevaiemost v gruppe y : " << groups[bestIndex].sex << endl;
}

int main() {
  // Массив студентов
  const int numberOfResults = 20;

  result results[] = {
    { "Ivanov", "male", 34 },
    { "Petrov", "male", 42 },
    { "Sidorov", "male", 56 },
    { "Pakin", "male", 12 },
    { "Sobakin", "male", 10 },
    { "Beliaiev", "male", 88 },
    { "Bragin", "male", 17 },
    { "Palagin", "male", 21 },
    { "Rosomahin", "male", 16 },
    { "Kukunin", "male", 10 },
    { "Ivanova", "female", 43 },
    { "Petrova", "female", 24 },
    { "Sidorova", "female", 65 },
    { "Pakina", "female", 21 },
    { "Sobakina", "female", 90 },
    { "Beliaieva", "female", 98 },
    { "Bragina", "female", 71 },
    { "Palagina", "female", 12 },
    { "Rosomahina", "female", 61 },
    { "Kukunina", "female", 76 }
  };

  // Печатаем входные данные
  printSet(results, numberOfResults);

  // Будем группировать по полу студента
  vector<sexGroup> bySex;
  
  for ( int i = 0; i < numberOfResults; i++ ) {
    int indexOfSexGroup = getGroupIndex(bySex, results[i].sex);

    if ( indexOfSexGroup == -1 ) { // Новый пол, добавляем группу
      sexGroup newSexGroup;
      newSexGroup.sex = results[i].sex;
      newSexGroup.results.push_back(results[i]);

      bySex.push_back(newSexGroup);
    } else { // Существующий группа по полу, добавляем результат туда, сортируем
      if (bySex[indexOfSexGroup].results[0].score > results[i].score) {
        bySex[indexOfSexGroup].results.push_back(results[i]);
      } else {
        bySex[indexOfSexGroup].results.insert(bySex[indexOfSexGroup].results.begin(), results[i]);
      }
    }
  }

  // Вычисляем и печатаем результат
  printGroups(bySex);
  
  return 0;
}