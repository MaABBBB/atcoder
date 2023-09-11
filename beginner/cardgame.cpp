#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  
  sort(a, a+n, greater<int>());
  int a_point = 0, b_point = 0;
  for (int i = 0; i < n; i++) {
    if(i % 2 == 0) a_point += a[i];
    else b_point += a[i];
  }
  cout << a_point - b_point << endl;
  return 0;
}