#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> num;
vector<int> player;
int res=0;

void Backtracking(int idx)
{
    if(idx >= n)
    {
        int cnt = 0;
        for(int i=0; i<k; ++i)
            if(player[i] >= m)
                ++cnt;
        res = (cnt > res ? cnt : res);
        return;
    }

    for(int i=0; i<k; ++i)
    {
        player[i] += num[idx];
        Backtracking(idx+1);
        player[i] -= num[idx];
    }
}

int main() {
    cin >> n >> m >> k;

    num.resize(n);
    player.resize(k, 1);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    Backtracking(0);
    cout << res;

    return 0;
}
