//解けなかった
//時間かかりすぎたので１５分で解けなかったら答えと解説を見る
#include <vector>
#include <iostream>
using namespace std;
vector<int> honests[15];
vector<int> liars[15];


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y; cin >> x >> y;
            if (y == 0) liars[i].push_back(x-1);
            else honests[i].push_back(x-1);
        }
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool flag = true;
        //honestの数
        int cnt = 0;
        for (int j = 0; j < 15; j++) {
            //ここでｊ番目の人が正しいとして分岐する
            if((bit >> j) & 1) {
                cnt++;
                //j番目の人の発言が正しいかの確認
                for (auto &honest : honests[j]) {
                    if (!((bit >> honest) & 1)) flag = false; 
                }
                for (auto &liar : liars[j]) {
                    if ((bit >> liar) & 1) flag = false;
                }
            }
        }
        //全ての人の発言が正しい場合のみflag = trueなのでansを更新する
        if (flag) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return  0;
}
