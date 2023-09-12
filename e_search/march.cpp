#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int v[5] = {0};
char march[] = {'M', 'A', 'R', 'C', 'H'};
map<char, long long int> m;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        m[s[0]]++;
    }
    
    /*for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {
            cout << "s[0] " << s[0] << "march[j] " << march[j] << endl;
            if (s[0] == march[j]) v[j]++;
        }
    }
    for (auto &vec : v) cout << vec << endl;*/
    long long int ans = 0;
    /*
    for (int bit = 0; bit < (1 << 5); bit++) {
        int cnt = 0;
        vector<int> a;
        for (int i = 0; i < 5; i++) {
            if (bit >> i & 1) {
                cnt++;
                a.push_back(v[i]);
            }
        }
        if (cnt == 3) {
            ans += a[0] * a[1] * a[2];
        }
    }*/
    //間違えた理由がわからん
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j +1; k < 5; k++) {
                ans += v[i] * v[j] * v[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}