#include <iostream>
#include <cmath>
using namespace std;

int solved(long long num) {
  int total = 0;
  while (num > 0) {
    num /= 10;
    total++;
  }
  return total;
}

int main() {
  long long n;
  cin >> n;
  int n_s = sqrt(n);
  int min = 10;
  for (int i = 1; i < n_s+1; i++) {
    if(n % i == 0) {
      long long res = n / i;
      int cur_i = solved(i);
      int cur_res = solved(res);
      int cur_min = max<int>(cur_i, cur_res);
      if (min > cur_min) min = cur_min;
    }
  }
  
  cout << min << endl;
  return 0;
}