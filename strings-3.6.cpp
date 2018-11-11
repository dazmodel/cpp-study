#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <sstream>
using namespace std;

int main() {

  // Задаем количество студентов в списке
  const int numberOfStudents = 10;

  // Читаем список студентов, введенных пользователем в консоли
  string listOfStudents[numberOfStudents];
  cout << "Vvedite spisok stydentov:" << endl;

  for (int i = 0; i < numberOfStudents; i++ ) {
    string tmp;
    getline(cin, tmp);
    listOfStudents[i] = tmp;
  }
  cout << endl;

  cout << "Spisok studentov, otsortirovannyi po alfavity: " << endl;

  // Сортируем введенный список и печатаем в консоль
  vector<string> sortedStudents;
  sortedStudents.assign(listOfStudents, listOfStudents + numberOfStudents); 
  sort(sortedStudents.begin(), sortedStudents.end());
  copy(sortedStudents.begin(), sortedStudents.end(), ostream_iterator<string>(cout, "\n"));

  return 0;
}