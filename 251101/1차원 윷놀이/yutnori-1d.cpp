#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> num;
vector<int> player;
int res=0;

void Backtracking(int idx, int score)
{
    if(idx >= n)
    {
        res = (score > res ? score : res);
        return;
    }

    for(int i=0; i<k; ++i)
    {
        if(player[i] < m)
        {
            player[i] += num[idx];
            if(player[i] >= m)
                Backtracking(idx+1, score+1);
            else
                Backtracking(idx+1, score);
            player[i] -= num[idx];
        }
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
    Backtracking(0, 0);
    cout << res;

    return 0;
}
