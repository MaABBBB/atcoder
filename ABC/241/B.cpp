#include <map>
#include <iostream>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int A[N], B[M];
  map<int, int> memMap;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    memMap[x]++;
  }
  for (int i = 0; i < M; i++) {
    int b; cin >> b;
    if (memMap[b] == 0) {
      cout << "No" << endl;
      return 0;
    }
    memMap[b]--;
  }
  
  cout << "Yes" << endl;
  return 0;
}