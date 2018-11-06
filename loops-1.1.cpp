#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;

double calculateZ(double x) {
  return abs(x) + pow(x,3);
} 

double calculateY(double x) {
  return calculateZ(x) * ((pow(sin(2+x), 2)/(2 + x)));
}

int main() {
  

  int xmin = 1, xmax = 4; 
  double hx = 0.5;
  cout << "Vhodnie dannue:" << endl;
  cout << "        x=> [1,4]" << endl;
  cout << "        Hx = 0.5 " << endl;
  cout << endl;

  cout << "Rezultat: " << endl;
  double currentX = xmin;
  int iterationsCount = 0;
  while(currentX <= xmax) {
    cout << "        Pri X=" << currentX << ", Y=" << calculateY(currentX) << endl;
    currentX+=hx;
    iterationsCount++;
  }

  cout << endl;
  cout << "Gotovo! Koli4estvo proidennux iteracii: " << iterationsCount << endl;

  return 0;
}