#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
vector<double> A[8];
vector<int> towns_x;
vector<int> towns_y;
int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        towns_x.push_back(x);
        towns_y.push_back(y);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            double x = sqrt(pow(towns_x[i] - towns_x[j], 2) + pow(towns_y[i] - towns_y[j], 2));
            //cout << "x, i, j : " << x << " " << i << " " << j << endl;
            //入力する前に[]演算子でvectorにアクセスするとエラーになる
            A[i].push_back(x);
        }
    }
    
    double average = 0;
    int per = 0;
    do {
        per++;
        for (int i = 1; i < n; i++) {
            average += A[p[i-1]][p[i]];
        }
    } while(next_permutation(p, p + n));

    average /= per;
    //fixedを使うと下６桁まで表示してくれる
    cout << fixed;
    cout << average << endl;
    return 0;
}