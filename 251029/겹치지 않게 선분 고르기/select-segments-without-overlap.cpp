#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;
vector<pair<int, int>> choosed;
int res;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if(p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

void Backtracking(int cnt, int s)
{
    if(cnt >= n)
    {
        res = n;
        return;
    }

    bool flag;
    for(int i=s; i<n; ++i)
    {
        flag = true;
        for(int j=0; j<choosed.size(); ++j)
        {
            if((choosed[j].first <= lines[i].first && lines[i].first <= choosed[j].second)
                || (choosed[j].first <= lines[i].second && lines[i].second <= choosed[j].second))
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            choosed.push_back(lines[i]);
            Backtracking(cnt+1, s+1);
            choosed.pop_back();
        }
    }

    res = (cnt > res ? cnt : res);
}

int main() {
    cin >> n;

    lines.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    // Please write your code here.
    sort(lines.begin(), lines.end(), comp);
    Backtracking(0, 0);
    cout << res;
    return 0;
}
