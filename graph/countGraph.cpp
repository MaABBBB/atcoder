#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
vector<bool> seen;

//無向グラフの連結成分の個数を求める
//各頂点からｄｆｓを全頂点が訪問済みになるまで行う
void dfs(Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int count = 0;
    for (int v = 0; v < N; v++) {
        if (seen[v]) continue;
        dfs(G, v);
        count++;
    }
    cout << count << endl;
    return 0;
}