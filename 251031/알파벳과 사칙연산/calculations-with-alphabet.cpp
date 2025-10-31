#include <iostream>
#include <stack>
using namespace std;

string expression;
int num['f' - 'a'];
int res = -512;

int Cal()
{
    stack<char> op;
    int op1 = num[expression[0] - 'a'];
    int op2;
    for(int i=1; i<expression.length(); ++i)
    {
        if('a' <= expression[i] && expression[i] <= 'f')
        {
            op2 = num[expression[i] - 'a'];
            if('+' == op.top())
                op1 += op2;
            else if('-' == op.top())
                op1 -= op2;
            else
                op1 *= op2;
        }
        else
            op.push(expression[i]);
    }

    return op1;
}

void Backtracking(int cnt)
{
    if(cnt >= 'f' - 'a')
    {
        int tmp = Cal();
        res = (tmp > res ? tmp : res);
        return;
    }

    for(int i=1; i<=4; ++i)
    {
        num[cnt] = i;
        Backtracking(cnt+1);
    }
}

int main() {
    cin >> expression;

    // Please write your code here.
    Backtracking(0);
    cout << res;

    return 0;
}
