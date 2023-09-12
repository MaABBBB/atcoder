#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> C(m);
    vector<vector<int>> A(m);
    for (int i = 0; i < m; i++) {
        cin >> C[i];
        A[i].resize(C[i]);
        for (int j = 0; j < C[i]; j++) cin >> A[i][j];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << m); bit++) {
        set<int> st;
        for (int i = 0; i < m; i++) {
            if ((bit >> i) & 1) {
                for (int j = 0; j < C[i]; j++) {
                    st.insert(A[i][j]);
                }
            }
        }

        if (st.size() == n) ans++;
    }

    cout << ans << endl;
    return 0;
}