#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> choosed;

void Backtracking(int cnt)
{
    if(cnt >= N)
    {
        for(int i=0; i<N; ++i)
            cout << choosed[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=K; ++i)
    {
        if(cnt < 2 || !(i == choosed[cnt-1] && i == choosed[cnt-2]))
        {
            choosed[cnt] = i;
            Backtracking(cnt+1);
        }
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    choosed.resize(N);
    Backtracking(0);

    return 0;
}
