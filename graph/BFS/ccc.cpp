#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int INF = 1<<29;
using Graph = vector<vector<int>>;
int path[7][7];
int N;
vector<int> res;

int dfs(string s, bool seen[], int v, int total) {
    seen[v] = true;
    for (int i = 0; i < N; i++) {
        if (s[i] != 's') continue;
        if ()
    }
}

int main() {
    cin >> N;
    int c_f, c_b; cin >> c_f >> c_b;
    //コストを保存
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i < j) path[i][j] = c_f;
            if (i > j) path[i][j] = c_b;
        }
    }
    string s; cin >> s;
    Graph G(N);
    //N-1からいける安全なiを保存
    for (int i = 0; i < N-1; i++) {
        if (s[i] == 's') G[N-1].push_back(i);
    }

    int mini = INF;
    vector<int> ans;
    bool seen[N];
    memset(seen, 0, sizeof(seen));
    for (auto nv : G[N-1]) {
        //dfsで最小値を取得
        int c_min = dfs(s, seen, nv, 0);
        if (c_min < mini) {
            mini = c_min;
            ans.clear();
            for (auto x : res) ans.push_back(x);          
        }
        res.clear();
        memset(seen, 0, sizeof(seen));
    }

    cout << N;
    for (auto x : ans) cout << " " << x;
    cout << " " << N;
    return 0;
}