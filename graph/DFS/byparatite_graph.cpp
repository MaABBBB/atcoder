//二分グラフかどうかの判定
//任意の頂点を白または黒としたときに、隣り合った頂点が黒または白であるようなグラフ
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

//二分グラフ判定
vector<int> color;

bool dfs(const Graph &G, int v, int cur = 0) {
    //ここで色をつける
    color[v] = cur;
    for (auto next_v : G[v]) {
        //隣接頂点が色がすでに色が決まっていて、現在の頂点と同じ色ならfalse
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false;
            continue;
        }
        //ここで色を反転させて次の頂点に色を付けに行く
        if (!dfs(G, next_v, 1 - cur)) return false;
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; v++) {
        if (color[v] != -1) continue;
        if (!dfs(G, v)) is_bipartite = false;
   }
   if (is_bipartite) cout << "Yes" << endl;
   else cout << "No" << endl;
}
