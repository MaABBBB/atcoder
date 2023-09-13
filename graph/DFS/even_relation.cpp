#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
using Graph = vector<pair<int, int>>;
vector<int> color;
Graph dist;
Graph G[101010];

void dfs(int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        if (color[next_v.first] != -1) {
            continue;
        }

        if (next_v.second % 2 == 0) dfs(next_v.first, cur);
        else dfs(next_v.first, 1 - cur);
    }
}

int main() {
    int N; cin >> N;
    //dist.assign(N, vector<int>(N, 0));
    color.assign(N, -1);
    for (int i = 1; i < N; i++) {
        int u, v, x; cin >> u >> v >> x;
        G[u-1].push_back({ v-1,x });
        G[v-1].push_back({ u-1,x });
        //dist[u-1][v-1] = x;
    }

    dfs(0);

    for (int i = 0; i < N; i++) cout << color[i] << endl;
    return 0;
}
