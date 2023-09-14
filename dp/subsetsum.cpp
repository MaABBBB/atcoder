#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, A;
int a[110];
bool dp[110][10010];
int main() {
    cin >> n >> A;
    memset(dp, 0, sizeof(dp));
    //dp[0][0]は何も選ばず０にするなので常にtrue
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= A; j++) {
            dp[i+1][j] |= dp[i][j];
            if (j >= a[i]) dp[i+1][j] |= dp[i][j - a[i]];
        }
    }

    if (dp[n][A]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}