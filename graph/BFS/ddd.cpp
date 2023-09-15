#include <vector>
#include <iostream>
#include <tuple>
#include <map>
using namespace std;
vector<tuple<int, int, int>> billdings;
unsigned long H, W, N;
unsigned long a, b, c, d;
unsigned long long field[1010][1010];

unsigned long t;
int r() {
  t = (t * a + b) % c;
  return t;
}

void gen() {
  t = 0;
  for (int i = 0; i < N; i++) {
    int x_i = (r() % W);
    int y_i = (r() % H);
    int h_i = (r() % d) + 1;
    tuple<int, int, int> data = make_tuple(x_i, y_i, h_i);
    billdings.push_back(data);
  }
  cout << "billdings num : " << billdings.size() << endl;
}


void make_billdings() {
    for (auto itr : billdings) {
        int x = get<0>(itr), y = get<1>(itr), h = get<2>(itr);
        cout << "x : " << x << " y : " << y << " h : " << h << endl;
        //→
        if (field[y][x] >= h) continue;
        field[y][x] = h;
        for (int i = x+1; i < W; i++) {
            if (i >= W) break;
            if (field[y][i] > field[y][i-1]) break;
            field[y][i] = field[y][i-1] - 1;
            if (field[y][i] == 1 || field[y][i] == 0) break;
            
        }
        //←
        for (int i = x-1; i >= 0; i--) {
            if (i < 0) break;
            if (field[y][i] > field[y][i+1]) break;
            field[y][i] = field[y][i+1] - 1;
            if (field[y][i] == 1 || field[y][i] == 0) break;
            
        }
        //↓
        for (int i = y+1; i < H; i++) {
            if (i >= H) break;
            if (field[i][x] > field[i-1][x]) break;
            field[i][x] = field[i-1][x] - 1;
            if (field[i][x] == 1 || field[i][x] == 0) break;
            
            
        }
        //↑
        for (int i = y-1; i >= 0; i--) {
            if (i < 0) break;
            if (field[i][x] > field[i+1][x]) break;
            //if (field[y][i] == field[i+1][x]) continue;
            field[i][x] = field[i+1][x] - 1;
            if (field[i][x] == 1 || field[i][x] == 0) break;
            
        }
    }
}

int main() {
    cin >> W >> H >> N;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    gen();
    make_billdings();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    //詰まれた石の数をカウント
    map<unsigned long, unsigned long> count;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            count[field[h][w]]++;
        }
    }
    //クエリ結果を出力
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        cout << count[q] << endl;
    }
}