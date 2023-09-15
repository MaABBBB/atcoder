#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, c_f, c_b;
vector<int> result;
int INF = 1<<29;

int trip(vector<char> s, int p[]) {
    int mini = 0;
    int trip[N+1];
    trip[0] = N-1;
    for (int i = 0; i < N-1; i++) trip[i+1] = p[i];
    trip[N] = N-1;
    int curP = N-1;
    for (int i = 0; i<N+1; i++) cout << trip[i];
    cout << endl;
    for (int i = 1; i < N+1; i++) {
        
        if (s[trip[i]] == 's') {
            if (trip[i] > curP) {
                mini += c_f;
            }
            else {
                mini += c_b;
            }
            result.push_back(trip[i]+1);
        }
        else {
            return INF;
        }
        
        for (int j = trip[i]+1; j < N; j++) {
            if (s[j] == 's') s[j] = 'd';
            else s[j] = 's';
        }
        for (auto itr : s) cout << itr << " ";
        cout << endl;
        curP = trip[i];
    }
    return mini;
}


int main(void){
    cin >> N;
    cin >> c_f >> c_b;
    string s; cin >> s;
    vector<char> n_s;
    for (int i = 0; i < N; i++) {
        n_s.push_back(s[i]);
    }
    
    int p[N-1];
    for (int i = 0; i < N-1; i++) p[i] = i;
    int mini_cost = INF;
    
    vector<int> ans;
    do {
        result.push_back(N);
        int c_mini = trip(n_s, p);
        cout << "result : ";
        for (auto itr : result) cout << itr << " ";
        cout << endl;       
        
        if (c_mini < mini_cost) {
            mini_cost = c_mini;
            cout << "result : ";
            for (auto itr : result) cout << itr << " ";
            cout << endl;
            ans.clear();
            for (auto itr : result) ans.push_back(itr);
        }
        else {
            result.clear();
        }
    } while (next_permutation(p, p+N-1));
    ans.push_back(N);
    ans.resize(N+1);
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << ans[N] << endl;
    return 0;
}