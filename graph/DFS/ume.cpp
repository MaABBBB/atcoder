#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
//再帰関数内でvectorの値を変更したいが元々のvectorを変更したくないときは再帰関数内で＆を使い、元のを渡すときは値渡しをする
void dfs(vector<string> &field, int h, int w) {
  field[h][w] = 'x';
  for (int dir = 0; dir < 4; dir++) {
    int nh = h + dy[dir];
    int nw = w + dx[dir];
    if (nh < 0 || nw < 0 || nh >= 10 || nw >= 10) continue;
    if (field[nh][nw] == 'o') dfs(field, nh, nw);
  }
}

bool check(vector<string> field, int h, int w) {
  dfs(field, h, w);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (field[i][j] == 'o') return false;
    }
  }
  return true;
}

int main () {
  vector<string> field(10);
  for (int h = 0; h < 10; h++) cin >> field[h];
  for (int h = 0; h < 10; h++) {
    for (int w = 0; w < 10; w++) {
      if (field[h][w] == 'x') {
        if (check(field, h, w)) {
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}