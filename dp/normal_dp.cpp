#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[101010];
int dp[101010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i], dp[i] + a[i]);
    }

    cout << dp[n] << endl;
    return 0;
}