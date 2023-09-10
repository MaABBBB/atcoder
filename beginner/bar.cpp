#include <iostream>
using namespace std;

void prr(int x, char name) {
  cout << name << ":";
  int i = 1;
  while (i <= x) {
    cout << "]";
    i += 1;
  }
  cout << "\n";
}

int main() {
  int a, b;
  cin >> a >> b;
  prr(a, 'A');
  prr(b, 'B');
  return 0;
}