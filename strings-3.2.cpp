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

  // Задаем количество студентов в группе
  const int numberOfStudents = 5;

  // Читаем список студентов, введенный пользователем в консоли
  string listOfStudents[numberOfStudents];
  cout << "Vvedite vedomost poseshenia zaniatia, razdelite familiy i status probelom, " << endl;
  cout << "Primer: Ivanov n" << endl;
  cout << "Status mojet but sledyiyshim:" << endl;
  cout << "     n - student otsutstvuiet na zaniatii;" << endl;
  cout << "     c - student opozdal;" << endl;
  cout << "     . - student prisutstvuiet na zaniatii;" << endl;
  cout << endl;
  cout << "Vvedite vedomost: " << endl;

  for (int i = 0; i < numberOfStudents; i++ ) {
    string tmp;
    getline(cin, tmp);
    listOfStudents[i] = tmp;
  }
  cout << endl;

  string studentStatus;

  cout << "Spisok studentov s kakim statusom hotite polu4it? " << endl;
  cout << "Status mojet but sledyiyshim:" << endl;
  cout << "     n - student otsutstvuiet na zaniatii;" << endl;
  cout << "     c - student opozdal;" << endl;
  cout << "     . - student prisutstvuiet na zaniatii;" << endl;
  cout << endl;
  cout << "Vvedite status: " << endl;

  cin >> studentStatus;
  cout << endl;

  cout << "Rezultat poiska: " << endl;

  // Считаем и печатаем результат
  int foundN = 0;
  char* s = &studentStatus[0];
  for (int i = 0; i < numberOfStudents; i ++ ) {
    // Разделяем запись о студенте на фамилию и статус
    // результат: фамилия - studentRec[0], статус - studentRec[1]
    vector<string> studentRec = split(listOfStudents[i], ' ');

    // Искомый статус?
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