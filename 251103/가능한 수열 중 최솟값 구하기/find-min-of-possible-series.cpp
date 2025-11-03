#include <iostream>
using namespace std;

int n;
int arr[80];

bool IsHaveEqaulSeq(int cnt)
{
    int len = 1;
    int s1, e1, s2, e2;
    bool IsSame = true;
    while(1)
    {
        e1 = cnt - 1;
        s1 = e1 - len + 1;

        e2 = s1 - 1;
        s2 = e2 - len + 1;

        if(s2 < 0)
            break;

        IsSame = true;
        for(int i=0; i<=e1-s1; ++i)
            if(arr[s1 + i] != arr[s2 + i])
            {
                IsSame = false;
                break;
            }
        
        if(IsSame)
            return false;

        ++len;
    }

    return true;
}

bool Backtracking(int cnt)
{
    if(cnt >= n)
    {
        for(int i=0; i<n; ++i)
            cout << arr[i];
        return true;
    }

    for(int i=4; i<=6; ++i)
    {
        arr[cnt] = i;
        if(IsHaveEqaulSeq(cnt+1) && Backtracking(cnt+1))
            return true;
    }

    return false;
}

int main() {
    cin >> n;

    // Please write your code here.
    Backtracking(0);

    return 0;
}
