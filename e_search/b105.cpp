#include <iostream>
using namespace std;

int solved(int n) {
  int total = 1;
  for (int i = 1; i < n/2 + 1; i++) {
    if (n % i == 0) total++;
  }
  return total;
}

int main() {
  int n;
  cin >> n;
  if (n < 105) {
    cout << 0 << endl;
    return 0;
  }
  else {
    int total = 1;
    for (int i = 107; i < n+1; i += 2) {
        if (solved(i) == 8) total++;
    }
    cout << total << endl;
    return 0;
  }
}