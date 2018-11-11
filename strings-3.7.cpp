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

  // Собираем слово, состоящее из первых букв слов предложения
  string comboWord = "";
  for (int i = 0; i < words.size(); i ++ ) {
    comboWord += words[i][0];
  }

  // Печатаем результат
  cout << "Slovo, polu4ennoe is pervih bykv slov predlojenia: " << comboWord << endl;
  
  return 0;
}