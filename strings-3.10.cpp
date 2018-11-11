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

// Функция подсчета вхождения всего списка символов в строку
bool containsSymbols(string source, string *forbiddenSymbols, int numberOfFrbdn) {
  int occurences = 0;

  for ( int i = 0; i < numberOfFrbdn; i++ ) {
    if ( source.find(forbiddenSymbols[i]) != string::npos ) {
      occurences ++;
    }
  }

  return occurences == numberOfFrbdn;
}

int main() {

  // Символы, которых не должно быть
  string forbiddenSymbols[3] = { "п", "р", "о" };

  // Читаем предложение, введенное пользователем в консоли
  string text;
  cout << "Vvedite predlojenie, razdelite slova probelami: " << endl;
  getline(cin, text);

  // Делим предложение на слова
  vector<string> words = split(text, ' ');
  cout << endl;

  // Ищем самое длинное слово, в котором нет запрещенных символов
  string theWord = "";
  int numOfFrbdn = sizeof(forbiddenSymbols) / sizeof(forbiddenSymbols[0]);
  for (int i = 0; i < words.size(); i ++ ) {
    if ( !containsSymbols( words[i], forbiddenSymbols, numOfFrbdn ) && theWord.length() < words[i].length() ) {
      theWord = words[i];
    }
  }

  // Сообщаем, если ничего не нашли
  if (theWord == "") {
    cout << "   (Ni4ego ne naideno)" << endl;
  } else {
    cout << "Samoe dlinnoe slovo bez simvolov 'п', 'р', 'о' " << " : " << theWord << endl;
  }

  return 0;
}