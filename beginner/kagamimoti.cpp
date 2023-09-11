#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> mochis;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int mochi;
    cin >> mochi;
    mochis.push_back(mochi);
  }
  
  sort(mochis.rbegin(), mochis.rend());
  int k_count = 1;
  vector<int>::iterator itr = mochis.begin();
  int p_mochi = *itr;
  itr++;
  for (itr; itr != mochis.end(); itr++) {
    if(*itr < p_mochi) {
      k_count++;
      p_mochi = *itr;
    }
  }
  cout << k_count << endl;
  return 0;
}