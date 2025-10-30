#include <iostream>

using namespace std;

int n, m, c;
int weight[10][10];
int res;

int ChooseRecur(int sy, int sx, int ox, int sum, int ret)
{
    if(sum >= c || sx - ox >= m)
        return ret;

    int tmp1, tmp2 = ret, idx = sx;
    while(idx < n && idx - ox < m)
    {
        if(sum + weight[sy][idx] <= c)
        {
            tmp1 = ChooseRecur(sy, idx+1, ox, sum + weight[sy][idx], ret + (weight[sy][idx] * weight[sy][idx]));
            tmp2 = (tmp1 > tmp2 ? tmp1 : tmp2);
        }
        ++idx;
    }

    return tmp2;
}

int Choosing(int sy, int sx)
{
    int sum=0, idx = sx;
    while(idx < n && idx - sx < m)
    {
        sum += weight[sy][idx];
        ++idx;
    }
    
    if(sum <= c)
    {
        sum = 0;
        idx = sx;
        while(idx < n && idx - sx < m)
        {
            sum += (weight[sy][idx] * weight[sy][idx]);
            ++idx;
        }

        return sum;
    }
    else
        return ChooseRecur(sy, sx, sx, 0, 0);
}

void Backtracking(int sy, int sx, int sum, int cnt)
{
    if(cnt >= 2)
    {
        res = (sum > res ? sum : res);
        return;
    }

    int tmp;
    for(int i=sy; i<n; ++i)
    {
        for(int j=(i != sy ? 0 : sx); j<n; ++j)
        {
            tmp = Choosing(i, j);
            if(j + m < n)
                Backtracking(i, j + m, sum + tmp, cnt + 1);
            else
                Backtracking(i+1, 0, sum + tmp, cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    // Please write your code here.
    Backtracking(0, 0, 0, 0);
    cout << res;

    return 0;
}