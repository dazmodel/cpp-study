#include <cmath>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// Структура для хранения результатов соревнований
struct result {
  string name;
  string sex;
  int score;
};

// Структура для группировки студентов по знаку зодиака
struct sexGroup {
  string sex;
  vector<result> results;
};

// Функция нахождения группы по имени зодиака
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
  cout << "Spisok rezultatov: " << endl;
  cout << endl;
  for ( int i = 0; i < n; i++ ) {
    cout << "     Imia: " << results[i].name << endl;
    cout << "     Pol: " << results[i].sex << endl;
    cout << "     Rezultat: " << results[i].score << endl;
    cout << endl;
  }
  cout << endl;
}

// Печать сгруппированных значений
void printGroups(vector<sexGroup> &groups) {
  cout << "5 ly46ih rezultatov sorevnovanii. Gruppirovka y4astnikov po poly: " << endl;
  cout << endl;
  for ( int i = 0; i < groups.size(); i++ ) {
    cout << groups[i].sex << ": " << endl;
    for ( int j = 0; j < 5; j++ ) {
      cout << "     " << groups[i].results[j].name << " : " << groups[i].results[j].score << endl;
    }
    cout << endl;
  }
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

  // Будем группировать по полу участника
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

  printGroups(bySex);
  
  return 0;
}