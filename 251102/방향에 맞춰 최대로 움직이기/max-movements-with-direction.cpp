#include <iostream>
#include <vector>
using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;
int res;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void Backtracking(int cnt, int cy, int cx)
{
    int ny, nx;

    for(int i=1; i<n; ++i)
    {
        ny = cy + i * dy[move_dir[cy][cx]-1];
        nx = cx + i * dx[move_dir[cy][cx]-1];

        if(0 <= ny && ny < n && 0 <= nx && nx < n && num[ny][nx] > num[cy][cx])
        {
            res = (cnt+1 > res ? cnt+1 : res);
            Backtracking(cnt+1, ny, nx);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    // Please write your code here.
    Backtracking(0, r-1, c-1);
    cout << res;

    return 0;
}
