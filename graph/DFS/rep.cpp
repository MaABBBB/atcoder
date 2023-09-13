#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> G[101010];
int color[101010];



void dfs(int v, int pv = -1, int cur = 0) {
    color[v] = cur;
    for (auto &next_v : G[v]) {
        if (next_v.first == pv) {
            continue;
        }

        if (next_v.second % 2 == 0) dfs(next_v.first, v, cur);
        else dfs(next_v.first, v, 1 - cur);
    }
}

int main() {
    int N; cin >> N;
    
    for (int i = 1; i < N; i++) {
        int u, v, x; cin >> u >> v >> x;
        G[u-1].push_back({ v-1,x });
        G[v-1].push_back({ u-1,x });
       
    }

    dfs(0);

    for (int i = 0; i < N; i++) cout << color[i] << endl;
    return 0;
}
