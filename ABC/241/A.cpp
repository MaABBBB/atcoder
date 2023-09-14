#include <iostream>
using namespace std;
int main() {
  int a[10];
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  int cur = 0;
  cur = a[cur];
  cur = a[cur];
  cur = a[cur];
  cout << cur << endl;
  return 0;
}