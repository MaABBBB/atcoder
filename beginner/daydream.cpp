#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string T[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
  
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  for (int i = 0; i < 4; i++) reverse(T[i].begin(), T[i].end());

  bool can = true;
  for (int i = 0; i < s.size();) {
    bool can2 = false;
    for (int j = 0; j < 4; j++) {
        string d = T[j];
        if(s.substr(i, d.size()) == d) {
            can2 = true;
            i += d.size();
            break;
        }
    }

    if(!can2) {
        can = false;
        break;
    }
  }
  if (can) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}