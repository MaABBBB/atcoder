#include <iostream>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  //int i = abs(a - b) > min(a, b) / 2 ? min(a, b) : min(a, b) / 2 + 1;

  for (int i = max<int>(a, b); i > 0; i--) {
    if (a % i == 0 && b % i == 0) k--;
    if (!k) {
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}