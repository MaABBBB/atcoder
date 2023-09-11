#include <iostream>
using namespace std;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int count = 0;
  for (int i = 0; i < a + 1; i++) {
    for (int j = 0; j < b + 1; j++) {
      int res = x - (500 * i + 100 * j);
      if ((res % 50 == 0 && res > 0 && res / 50 <= c)) count++;
    }
  }
  
  cout << count << endl;
  return 0;
}