#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> field;
int N;

bool check(string s) {
  int cnt = 0;
  for (int i = 0; i < 6; i++) {
    if (s[i] == '#') cnt++;
    if (cnt == 4) return true;
  }
  return false;
}


int main() {
  cin >> N;
  field.resize(N);
  for (int i = 0; i < N; i++) cin >> field[i];
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      string under, right, r_u, l_u;
      if (i+5 < N) {
        for (int h = 0; h < 6; h++) under += field[i+h][j];
      }
      if (j+5 < N) {
        for (int w = 0; w < 6; w++) right += field[i][j+w];
      }
      if (i+5 < N && j+5 < N) {
        for (int dir = 0; dir < 6; dir++) r_u += field[i+dir][j+dir];
      }
      if (i+5 < N && j-5 >= 0) {
        for (int dir = 0; dir < 6; dir++) l_u += field[i+dir][j-dir];
      }
      
      if (check(right) || check(under) || check(r_u) || check(l_u)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;
  return 0;
}