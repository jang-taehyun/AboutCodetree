#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s;
int res;

void Backtracking(int cnt)
{
    if(cnt >= n)
    {
        ++res;
        return;
    }

    for(int i=1; i<=4; ++i)
    {
        if(s.size() + i <= n)
        {
            for(int j=0; j<i; ++j)
                s.push(i);
            Backtracking(cnt+i);
            for(int j=0; j<i; ++j)
                s.pop();
        }
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    Backtracking(0);
    cout << res;

    return 0;
}
