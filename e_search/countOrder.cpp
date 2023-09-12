#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int P[8], Q[8];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        P[i] = x;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        Q[i] = x;
    }
    vector<int> v;
    for (int i = 1; i < n+1; i++) v.push_back(i);
    int idx = 0, a = -1, b = -1;

    //next_permutationは辞書順で小さい順に順列を取り出してくれる
    do {
        bool flag = true;
        for (int i = 0; i < n; i++) if (P[i] != v[i]) flag = false;
        if(flag) a = idx;

        flag = true;
        for (int i = 0; i < n; i++) if (Q[i] != v[i]) flag = false;
        if (flag) b = idx;

        idx++;
    } while (next_permutation(v.begin(), v.end()));

    cout << abs(a - b) << endl;
    return 0;
}