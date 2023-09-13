#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//もっと簡単にかけた
//fieldをループごとに初期化して入力を受け取り、dfsで訪問済みの島（＝＝１）は０に変えていけばいい

int H, W;
bool seen[50][50];

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

void dfs(vector<vector<int>> &field, int h, int w) {
    seen[h][w] = true;
    for (int dir = 0; dir < 8; dir++) {
        int nh = h + dy[dir];
        int nw = w + dx[dir];
        
        if (nh < 0 || nw < 0 || nh >= H || nw >= W) continue;
        if (field[nh][nw] == 0) continue;
        if (seen[nh][nw]) continue;
        dfs(field, nh, nw);

    }
}

int main() {
    while (true) {
        
        
        cin >> W >> H;
        vector<vector<int>> field(H, vector<int>(W));
        if (H == 0 && W == 0) break;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                int x; cin >> x;
                field[h][w] = x;
            }
        }
        
        memset(seen, 0, sizeof(seen));
        int count = 0;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (seen[h][w]) continue;
                if (field[h][w] == 0) continue;
                dfs(field, h, w);
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}

