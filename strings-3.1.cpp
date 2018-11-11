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

  // Ищем самое длинное слово и его индекс
  string longestWord = words[0];
  int longestWordIndex = 0;

  for (int i = 1; i < words.size(); i ++ ) {
    if (words[i].length() > longestWord.length()) {
      longestWord = words[i];
      longestWordIndex = i;
    }
  }

  // Печатаем результат
  cout << "Samoe dlinnoe slovo v predlojenii: " << longestWord << endl;
  cout << "Ego index (na4inaets s 0): " << longestWordIndex << endl;

  return 0;
}