//更加精简的版本
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int R, C; // R行C列
int ans = -1;

vector<vector<int>> *map = nullptr;
vector<vector<int>> *memory = nullptr; // 记录每个点的最大距离
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
int dfs_cut(int x, int y);
void Print_DPmap();
int main()
{

    cin >> R >> C;
    map = new vector<vector<int>>(R + 1, vector<int>(C + 1, INT_MAX));
    memory = new vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> (*map)[i][j]; // 输入地图
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            // cout << "Search (" << i << "," << j << "):" << endl;
            // vector<vector<int>> step;
            // step.push_back({i, j});
            // ans = max(ans, dfs(i, j, step)); // 深度优先搜索
            ans = max(ans, dfs_cut(i, j));
            if (ans == R * C)
            {
                cout << ans << endl;
                return 0;
            }
            // step.pop_back();
        }
    }
    // Print_DPmap();
    // cout << "Max distance: ";
    cout << ans << endl;
    return 0;
}

int dfs_cut(int x, int y) // 进一步精简的代码
{
    if ((*memory)[x][y])
    {
        return (*memory)[x][y];
    }
    (*memory)[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= R && ny > 0 && ny <= C && (*map)[nx][ny] < (*map)[x][y])
        {
            dfs_cut(nx, ny);
            (*memory)[x][y] = max((*memory)[x][y], 1 + (*memory)[nx][ny]);
        }
    }
    return (*memory)[x][y];
}


void Print_DPmap()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << (*memory)[i][j] << " ";
        }
        cout << endl;
    }
}
