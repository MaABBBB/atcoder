#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    vector<int> A(n); 
    for (int i = 0; i < n; i++) cin >> A[i];

    bool flag =  false;
    for (int bit = 0; bit < (1 << n); bit++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((bit >> i) & 1) sum += A[i];
        }

        if (sum == v) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}