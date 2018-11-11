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

  // Читаем предложение, введенное пользователем в консоли
  string text;
  cout << "Vvedite predlojenie, razdelite slova probelami: " << endl;
  getline(cin, text);

  // Делим предложение на слова
  vector<string> words = split(text, ' ');
  cout << endl;
  cout << "Slova, v kotoryh net bykv 'в' i 'у': " << endl;

  // Ищем слова в которых нет букв 'в' и 'у'
  int nFound = 0;
  for (int i = 0; i < words.size(); i ++ ) {
    if ((words[i].find("в") == string::npos) && (words[i].find("у") == string::npos) ) {
      cout << words[i] << endl;
      nFound++;
    }
  }

  // Сообщаем, если ничего не нашли
  if (nFound == 0) {
    cout << "   (Ni4ego ne naideno)" << endl;
  }

  return 0;
}