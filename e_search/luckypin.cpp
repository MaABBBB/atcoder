#include <iostream>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int count = 0;
  for (int pas1 = 0; pas1 < 10; pas1++) {
    bool flag = false;
    int i = 0;
    for (i; i < n-2; i++) {
      
      if (s[i] - '0' == pas1) {
        flag = true;
        break;
      }
    }
    //cout <<"i's index: " << i << " pas1 : " << pas1 << " flag : " << flag << endl;
    if (!flag) continue;
    flag = false;
    
    for (int pas2 = 0; pas2 < 10; pas2++) {
      int j = i+1;
      //cout <<"before j's index : " << j << endl;
      for (j; j < n-1; j++) {
        
        if (s[j] - '0' == pas2) {
          flag = true;
          break;
        }
      }
      //cout <<"j's index: " << j << " pas2 : "<< pas2 << " flag : " << flag << endl;
      if (!flag) continue;
      flag = false;
      
      for (int pas3 = 0; pas3 < 10; pas3++) {
        int k = j+1;
        for (k; k < n; k++) {
          if (s[k] - '0' == pas3) {
            flag = true;
            break;
          }
        }
        if (flag) count++;
        flag = false;
        //cout <<"k's index: " << k << " pas3 : " << pas3 << " flag : " << flag << endl;
      }
    }
  }
  cout << count << endl;
  return 0;
}