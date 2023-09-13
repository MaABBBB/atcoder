#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

using Graph = vector<vector<int>>;
//gridの場合文字列として入力を受け取る
vector<string> field;
//４方向への移動
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int H, W;
bool seen[510][510];

void dfs(int h, int w) {
    seen[h][w] = true;

    for (int dir = 0; dir < 4; dir++) {
        int nh = h + dy[dir];
        int nw = w + dx[dir];
        //壁や場外の時は次に行く
        if (nw < 0 || nh < 0 || nw >= W || nh >= H) continue;
        if (field[nh][nw] == '#') continue;

        dfs(nh, nw);
    }
}

int main() {
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; h++) cin >> field[h];

    //ｓとｇのマスを特定する
    int sh, sw, gh, gw;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (field[h][w] == 's') sh = h, sw = w;
            if (field[h][w] == 'g') gh = h, gw = w;
        }
    }
    memset(seen, 0, sizeof(seen));
    dfs(sh, sw);
    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}