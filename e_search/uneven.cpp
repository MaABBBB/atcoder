#include <iostream>
using namespace std;

bool solved(int n) {
  int total = 0;
  while (n > 0) {
    n /= 10;
    total++;
  }
  if(total % 2 == 0) return false;
  else return true;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i < n+1; i++) {
    if (solved(i)) ans++; 
  }
  cout << ans << endl;
  return 0;
}

void othersolved() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n+1; i++) {
        if (i >= 1 && i <= 9) ans++;
        if (i >= 100 && i <= 999) ans++;
        if (i >= 10000 && i <= 99999) ans++;
    }
    cout << ans << endl;
}