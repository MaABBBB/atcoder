#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
       
       int s_k;
       //cout << "1i : " << i << " s_k : " << s_k << endl;
       cin >> s_k;
       //cout << "2i : " << i << " s_k : " << s_k << endl;
       A[i][s_k-1] = 1;
       //cout << "3i : " << i << " s_k : " << s_k << endl;
    }
  }

  vector<int> p(m);
  for (int i = 0; i < m; i++) cin >> p[i];
  
  //bit search
  int count = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    bool flag = true;
    for (int i = 0; i < m; i++) {
      int light_count = 0;
      for (int j = 0; j < n; j++) {
        if ((bit >> j) & 1) {
          if (A[i][j] == 1) light_count++;
        }
      }
      if (light_count % 2 != p[i]) flag = false;
    }
    if (flag) count++;
  }
  cout << count << endl;
  return 0;
}