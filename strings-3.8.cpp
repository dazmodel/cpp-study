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
  cout << "Bydem iskat slova, kotorie nahodiatsa mejdy slovami-granicami intervala poiska." << endl;
  cout << "Naprimer, predlojenie: Y lykomoria dyb zelenii, zlataia tsep na dube tom." << endl;
  cout << "Slovo-na4alo intervala: dyb" << endl;
  cout << "Slovo-konec intervala: na" << endl;
  cout << "Iskomij rezyltat: dub zelenii, zlataia tsep na" << endl;
  cout << endl;
  cout << "Vvedite predlojenie, razdelite slova probelami: " << endl;
  getline(cin, text);

  // Делим предложение на слова
  vector<string> words = split(text, ' ');
  cout << endl;

  // Вводим слово-начало интервала
  cout << "Vvedite slovo-na4alo intervala: " << endl;
  string strBegin;
  getline(cin, strBegin);

  // Вводим слово-конец интервала
  cout << "Vvedite slovo-konec intervala: " << endl;
  string strEnd;
  getline(cin, strEnd);

  cout << endl;

  // Вычисляем границы интервала
  int intBegin = 0;
  int intEnd = 0;

  for (int i = 0; i < words.size(); i ++ ) {
    if ( words[i].compare(strBegin) == 0) {
      intBegin = text.find(strBegin);
    }

    if ( words[i].compare(strEnd) == 0) {
      intEnd = text.find(strEnd);
    }
  }

  // Печатаем результат
  if ( intBegin != intEnd ) {
    cout << "Iskomij interval: " << text.substr(intBegin, text.length() - intBegin - text.substr(intEnd, text.length() - 1).length() + strEnd.length()) << endl;
  } else {
    cout << "V zadannom intervale ni4ego ne naideno!" << endl;
  }

  return 0;
}