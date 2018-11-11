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

  // Задаем искомую аббревиатуру
  string searchTerm = "США";

  // Читаем предложение, введенное пользователем в консоли
  string text;
  cout << "Vvedite predlojenie, razdelite slova probelami: " << endl;
  getline(cin, text);

  // Делим предложение на слова
  vector<string> words = split(text, ' ');
  cout << endl;

  int numberOfTermOccurences = 0; 
  for (int i = 0; i < words.size(); i ++ ) {
    if ( words[i].compare(searchTerm) == 0) {
      numberOfTermOccurences++;
    }
  }

  // Печатаем результат
  if ( numberOfTermOccurences != 0 ) {
    cout << "Abbreviatura " << searchTerm << " vstrechaetsa v prilojenii " << numberOfTermOccurences << " raz(a)." << endl;
  } else {
    cout << "Abbreviatura " << searchTerm << " v predlojenii ne vstrechaetsa!" << endl;
  }

  return 0;
}