#include <iostream>
using namespace std;

int n;
int arr[80];

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
        if(cnt%2 && cnt > 1)
        {
            if(arr[cnt-1] != i && arr[cnt-2] != i)
            {
                arr[cnt] = i;
                if(Backtracking(cnt+1))
                    return true;
            }
        }
        else
        {
            if(arr[cnt-1] != i)
            {
                arr[cnt] = i;
                if(Backtracking(cnt+1))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    // Please write your code here.
    Backtracking(0);

    return 0;
}
