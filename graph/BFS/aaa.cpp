#include <iostream>
using namespace std;
int main(void){
    int n; cin >> n;
    int inc = 0;
    int dec = 0;
    int cur; cin >> cur;
    int c_inc = 0;
    int c_dec = 0;
    for (int i = 0; i < n-1; i++) {
        int x; cin >> x;
        if (cur < x) {
            c_inc++;
            if (c_dec > dec) {
                dec = c_dec;
            }
            c_dec = 0;
        }
        if (cur > x) {
            c_dec++;
            if (c_inc > inc) {
                inc = c_inc;
            }
            c_inc = 0;
        }
        cur = x;
    }
    if (c_inc > inc) inc = c_inc;
    if (c_dec > dec) dec = c_dec;
    cout << dec << " " << inc << endl;
    return 0;
}