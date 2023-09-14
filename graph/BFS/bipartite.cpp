#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool is_biparitite = true;
    vector<int> dist(N, -1);
    queue<int> que;
    //連結グラフでない場合を想定して各頂点からグラフを塗る
    //連結グラフなら一つの頂点だけで二分グラフかどうかの判別可能
    for (int v = 0; v < N; v++) {
        if (dist[v] != -1) continue;
        dist[v] = 0, que.push(v);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (int nv : G[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
                else {
                    //bfsの場合各層ごとに塗分けていけば二分グラフになる。もし同じ層の中で辺存在するならば二分グラフではない
                    if (dist[v] == dist[nv]) is_biparitite = false;
                }
            }
        }
    }
    if (is_biparitite) cout << "Yes" << endl;
    else cout << "No" << endl;
}
