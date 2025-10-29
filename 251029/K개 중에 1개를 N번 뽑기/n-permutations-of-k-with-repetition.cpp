#include <iostream>
#include <deque>
using namespace std;

int K, N;
deque<int> d;

void Recur(int cnt)
{
    if(cnt >= N)
    {
        int len = d.size();
        for(int i=0; i<len; ++i)
        {
            cout << d.front() << ' ';
            d.push_back(d.front());
            d.pop_front();
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=K; ++i)
    {
        d.push_back(i);
        Recur(cnt+1);
        d.pop_back();
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    Recur(0);

    return 0;
}
