#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<long long int> S;
    long long int q; cin >> q;
    while (q--) {
        int a; cin >> a;
        //また型で何時間もつまった
        long long int x; cin >> x;
        
        if (a == 1) {
          S.insert(x);
          //cout << "a : " << a << " x : " << x << endl;
        }
        else {
            int k; cin >> k;
            //cout << "a : " << a << " x : " << x << " k : " << k << endl;
            if (a == 2) {
                bool flag = true;
                auto itr = S.upper_bound(x);
                for (int j = 0; j < k; j++) {
                    if (itr == S.begin()) {
                        flag = false;
                        break;
                    }
                    itr--;
                }
                
                if (flag) cout << *itr << endl;
                else cout << -1 << endl;
            }
            else {
                bool flag = true;
                auto itr = S.lower_bound(x);
                if (S.end() == itr) {
                  cout << -1 <<endl;
                  continue;
                }
                for (int j = 0; j < k-1; j++) {
                    itr++;
                    if (itr == S.end()) {
                        flag = false;
                        break;
                    }
                    
                }
                if (flag && itr != S.end()) cout << *itr << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}