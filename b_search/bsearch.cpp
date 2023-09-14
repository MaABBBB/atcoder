#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int bsearch(int key) {
    int left = 0, right = (int)a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) left = mid + 1;
        else right = mid + 1; 
    }
}

//indexが条件を満たすかどうか
bool isOk(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

//key以上の数の最小値を探す
//常にleftはkeyよりも小さいindex、rightは常にkey以上を満たすindex
int mbsearch(int key) {
    int left = -1;
    int right = (int)a.size();//a.size() - 1が条件を満たさない→全ての要素が条件を満たさない時も考える
    
    while (right - left > 1) {
        int mid = left + (right + left) / 2;
        if (isOk(mid, key)) right = mid;
        else left = mid;
    }
    //leftは条件を満たさない最大値、rightは条件を満たす最大値
    return right;
}

