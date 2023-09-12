#include <iostream>
#include <climits>
using namespace std;
//解きなおししたほうがいい問題、複雑なものを起点として全探索してる
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int mini = max<int>(x, y);
  long long ans = LLONG_MAX;
  for (int i = 0; i < 2 * mini+1; i += 2) {
    int x_res = x - i / 2 >= 0 ? x - i / 2 : 0;
    int y_res = y - i / 2 >= 0 ? y - i / 2 : 0;
    long long cur_ans = x_res * a + y_res * b + c * i;
    if (ans > cur_ans) ans = cur_ans;
  }
  cout << ans << endl;
  return 0;
}