#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M, s, t; cin >> N >> M >> s >> t;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        //もし無向グラフなら下のものを追加
        //G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int nv : G[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    if (dist[t] != -1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}