#include <string>
#include <iostream>
using namespace std;

string a = "ABC";

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < n; i++) {
    string cur = s.substr(i, 3);
    if (cur == a) count++;
  }
  cout << count << endl;
  return 0;
}