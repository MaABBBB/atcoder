#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
//seenで各頂点を訪れたかどうかを保存
vector<bool> seen;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto next_v: G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int n, m; cin >> n >> m;
    Graph G(n);
    //グラフの作成
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    //ここでs→tのパスが存在するかを調べるにはdfs(G, s)としてseen[v]がtrueになってるかを確認する
}