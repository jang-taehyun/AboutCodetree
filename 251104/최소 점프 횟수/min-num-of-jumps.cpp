#include <iostream>

using namespace std;

int n;
int num[10];
int res = 100;

void Backtracking(int cur, int cnt)
{
    if(cur >= n-1)
    {
        res = (cnt < res ? cnt : res);
        return;
    }

    for(int i=1; i<=num[cur]; ++i)
        Backtracking(cur+i, cnt+1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    Backtracking(0, 0);
    cout << (res < 100 ? res : -1);

    return 0;
}
