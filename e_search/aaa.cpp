#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
;
int H, W;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


void dfs(vector<string> &field, int h, int w, char color) {
    field[h][w] = '.';
    for (int dir = 0; dir < 4; dir++) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];
        if (nh < 0 || nw < 0 || nh >= H || nw >= W) continue; 
        if (field[nh][nw] != color) continue;
        dfs(field, nh, nw, color);
    }
}

int main(void){
    cin >> H >> W;
    vector<string> field(H);
    for (int h = 0; h < H; h++) cin >> field[h];
    
    //cout << (field[0][0] == 'R') << endl;
    
    map<char, int> colorMap;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (field[h][w] != '.') {
                colorMap[field[h][w]]++;
                dfs(field, h, w, field[h][w]);
                //エラーにひっかかりすぎ、変数の値がどうなってるのかをもっと追う
                //cout << field[h][w] << endl;
                //cout << colorMap[field[h][w]] << endl;
            }
        }
    }
    
    
    cout << colorMap['R'] << " " << colorMap['G'] << " " << colorMap['B'] << endl;
    return 0;
}