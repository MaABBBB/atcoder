#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  
  int num = 0;
  while (true) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 != 0) {
        flag = false;
      }
      a[i] /= 2;
    }
    if (flag) num += 1;
    else break;
  }
  cout << num << endl;
  return 0;
}