#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> lines;      // first : b, second : a
vector<pair<int, int>> choosed;
vector<int> origin;
vector<int> comp;
int res = 16;

void Backtracking(int cnt)
{
    if(cnt >= m)
    {
        int idx, tmp;
        bool flag = true;

        for(int i=0; i<n; ++i)
            comp[i] = i;
        for(int i=0; i<choosed.size(); ++i)
        {
            idx = choosed[i].second;
            tmp = comp[idx];
            comp[idx] = comp[idx+1];
            comp[idx+1] = tmp;
        }

        for(int i=0; i<n; ++i)
            if(comp[i] != origin[i])
            {
                flag = false;
                break;
            }
        
        if(flag)
            res = (choosed.size() < res ? choosed.size() : res);

        return;
    }

    choosed.push_back(lines[cnt]);
    Backtracking(cnt+1);
    choosed.pop_back();
    Backtracking(cnt+1);
}

int main() {
    int idx, tmp;

    cin >> n >> m;

    origin.resize(n);
    comp.resize(n);
    lines.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> lines[i].second >> lines[i].first;
        --lines[i].second;
    }

    // Please write your code here.
    sort(lines.begin(), lines.end());

    for(int i=0; i<n; ++i)
        origin[i] = i;
    for(int i=0; i<m; ++i)
    {
        idx = lines[i].second;
        tmp = origin[idx];
        origin[idx] = origin[idx+1];
        origin[idx+1] = tmp;
    }

    Backtracking(0);
    cout << res;

    return 0;
}
