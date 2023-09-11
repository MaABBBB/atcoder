#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int sum = 0;
  for (int i = 1; i < n + 1; i++) {
    int total = 0;
    int cur = i;
    while (cur > 0) {
      total += cur % 10;
      cur /= 10;
    }
    if (total >= a && total <= b) sum += i;
  }
  cout << sum << endl;
  return 0;
}