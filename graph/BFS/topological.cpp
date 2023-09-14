//topological sortは各頂点を辺の向きに沿うように一列に並べること
//DAG（サイクルの無い有向グラフ）＜＝＞トポロジカルソート可能
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using Graph = vector<vector<int>>;
using namespace std;


//方法　出次数：頂点ｖを始点とする辺のこと
//    　シンク：出次数が０の頂点
//      出次数が０の頂点をグラフから外して配列の一番後ろにおく。これの繰り返し。
int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    //各頂点の出次数
    vector<int> deg(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        //逆向きにする
        G[b].push_back(a);
        deg[a]++;
    }

    queue<int> que;
    //出次数０の頂点をキューにいれる
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) que.push(i);
    }

    vector<int> order;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        order.push_back(v);
        for (auto nv : G[v]) {
            --deg[nv];

            if (deg[nv] == 0) que.push(nv);
        }
    }

    reverse(order.begin(), order.end());
    for (auto v : order) cout << v << endl;
    return 0;
}