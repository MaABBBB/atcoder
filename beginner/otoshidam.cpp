#include <iostream>
using namespace std;

int main() {
  int n, y;
  cin >> n >> y;
  bool flag = false;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      int rest_n = n - i - j;
      int rest_y = y - 10000 * i - 5000 * j;
      if (rest_y / 1000 == rest_n) {
        flag = true;
        cout << i << ' ' << j << ' ' << rest_n << endl;
        break;
      }
    }
    if (flag) break;
  }
  if (!(flag)) cout <<"-1 -1 -1" << endl;
  return 0;
}