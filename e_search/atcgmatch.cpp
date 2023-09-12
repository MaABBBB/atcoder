#include <iostream>
#include <string>
using namespace std;
string atcg = "ATCG";

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  int cur_ans = 0;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A' || s[i] == 'T' || s[i] == 'C' || s[i] == 'G') {
      cur_ans++;
    }
    else {
      cur_ans = 0;
    }
    if (cur_ans > ans) ans = cur_ans;
  }
  cout << ans << endl;
  return 0;
}