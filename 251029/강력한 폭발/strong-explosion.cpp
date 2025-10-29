#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[20][20];
vector<pair<int, int>> pos;
int res;

vector<pair<int, int>> bomb[3] =
{
    {{-1, 0}, {-2, 0}, {1, 0}, {2, 0}},
    {{-1, 0}, {0, -1}, {1, 0}, {0, 1}},
    {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}
};

void Recur(int comp, int idx)
{
    if(idx >= pos.size())
    {
        res = (comp > res ? comp : res);
        return;
    }

    int adder, ny, nx;
    for(int i=0; i<3; ++i)
    {
        adder = 0;
        for(int j=0; j<4; ++j)
        {
            ny = pos[idx].first + bomb[i][j].first;
            nx = pos[idx].second + bomb[i][j].second;

            if(0 <= ny && ny < n && 0 <= nx && nx < n && !grid[ny][nx])
            {
                grid[ny][nx] = idx+4;
                ++adder;
            }
        }

        Recur(comp+adder, idx+1);

        for(int j=0; j<4; ++j)
        {
            ny = pos[idx].first + bomb[i][j].first;
            nx = pos[idx].second + bomb[i][j].second;

            if(0 <= ny && ny < n && 0 <= nx && nx < n && grid[ny][nx] == idx+4)
                grid[ny][nx] = 0;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j])
                pos.push_back({i, j});
        }
    }

    // Please write your code here.
    Recur(0, 0);
    cout << (res + pos.size());

    return 0;
}
