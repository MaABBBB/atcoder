#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int a[8][8];
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        a[x-1][y-1] = 1;
        a[y-1][x-1] = 1;
        //cout << a[x-1][y-1] << " x, y: " << x-1 << " " << y-1 << endl;
    }

    vector<int> p;
    for (int i = 1; i < n; i++) p.push_back(i);

    int ans = 0;
    do {
        bool flag = true;
        vector<int> cur;
        cur.push_back(0);
        for (int i = 0; i < n; i++) {
            cur.push_back(p[i]);
            //cout << "cur[i] : " << cur[i] << endl;
        }
        


        for (int i = 1; i < n; i++) {
            //cout << "cur[i-1] cur[i]: " << cur[i -1] << " " << cur[i] << endl;
            //cout << "a[cur[i-1]][cur[i]] : " << a[cur[i-1]][cur[i]] << endl;
            if (a[cur[i-1]][cur[i]] != 1) flag = false; 
        }
        if (flag) ans++;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}   