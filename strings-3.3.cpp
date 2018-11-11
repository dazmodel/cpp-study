#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <sstream>
using namespace std;

// Разделяем строку на части по заданному разделителю
vector<string> split(const string& s, char delimiter) {
  vector<string> tokens;
  string token;

  istringstream tokenStream(s);

  while (getline(tokenStream, token, delimiter))
  {
    tokens.push_back(token);
  }

  return tokens;
}

int main() {

  // Задаем количество студентов в ведомости
  const int numberOfStudents = 5;

  // Читаем ведомость студентов, введенную пользователем в консоли
  string listOfStudents[numberOfStudents];
  cout << "Vvedite vedomost ekzamena po fizike, razdelite familiy i ocenky probelom, " << endl;
  cout << "Primer: Ivanov 5" << endl;
  cout << "Ocenki mogut but v intervale ot 1 do 5." << endl;
  cout << endl;
  cout << "Vvedite vedomost: " << endl;

  for (int i = 0; i < numberOfStudents; i++ ) {
    string tmp;
    getline(cin, tmp);
    listOfStudents[i] = tmp;
  }
  cout << endl;

  string studentStatus;

  cout << "Spisok studentov s kakoj ocenkoj hotite polu4it? " << endl;
  cout << "Vvedite ocenky: " << endl;

  cin >> studentStatus;
  cout << endl;

  cout << "Rezultat poiska: " << endl;

  // Считаем и печатаем результат
  int foundN = 0;
  char* s = &studentStatus[0];
  for (int i = 0; i < numberOfStudents; i ++ ) {
    // Разделяем запись о студенте на фамилию и оценку
    // результат: фамилия - studentRec[0], оценка - studentRec[1]
    vector<string> studentRec = split(listOfStudents[i], ' ');

    // Искомая оценка?
    if (studentRec[1].compare(studentStatus) == 0) {
      cout << "   #" << i + 1 <<  ": " << listOfStudents[i] << endl; // Печатаем
      foundN++;
    }
  }

  // Сообщаем, если ничего не нашли
  if (foundN == 0) {
    cout << "   (Ni4ego ne naideno)" << endl;
  }

  return 0;
}