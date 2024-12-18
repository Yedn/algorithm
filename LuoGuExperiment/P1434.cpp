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
int dfs(int x, int y, vector<vector<int>> &step);
int dfs_2(int x, int y);
int dfs_cut(int x, int y);
void Print_DPmap();
int main()
{

    cin >> R >> C;
    map = new vector<vector<int>>(R + 2, vector<int>(C + 2, 114514));
    memory = new vector<vector<int>>(R + 2, vector<int>(C + 2, -1));
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

int dfs(int x, int y, vector<vector<int>> &step)
{
    // cout << "Now in: (" << x << "," << y << ")" << endl;
    if ((*map)[x][y] < (*map)[x - 1][y] && (*map)[x][y] < (*map)[x + 1][y] && (*map)[x][y] < (*map)[x][y - 1] && (*map)[x][y] < (*map)[x][y + 1]) // 没有可走的路
    {
        // return 1;
        // return step.size();
        // cout << "No way to go" << endl;
        (*memory)[x][y] = 1;
        return (*memory)[x][y];
    }
    vector<vector<int>> *temstep = new vector<vector<int>>;
    if ((*map)[x][y] >= (*map)[x - 1][y] && x - 1 >= 1)
    {
        if ((*memory)[x - 1][y] != -1)
        {
            // cout << "(" << x - 1 << "," << y << ") is visited" << endl;
            (*memory)[x][y] = max((*memory)[x][y], step.size() + (*memory)[x - 1][y]);
        }
        else
        {
            // cout << "(" << x - 1 << "," << y << ") is not visited" << endl;
            // step.push_back({x - 1, y});

            (*temstep).push_back({x - 1, y});
            (*memory)[x][y] = max((*memory)[x][y], step.size() + dfs(x - 1, y, *temstep));
            (*temstep).pop_back();
            // step.pop_back();
        }
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }

    if ((*map)[x][y] >= (*map)[x + 1][y] && x + 1 <= R)
    {

        if ((*memory)[x + 1][y] != -1)
        {
            // cout << "(" << x + 1 << "," << y << ") is visited" << endl;
            (*memory)[x][y] = max((*memory)[x][y], step.size() + (*memory)[x + 1][y]);
        }
        else
        {
            // cout << "(" << x + 1 << "," << y << ") is not visited" << endl;
            // step.push_back({x + 1, y});
            (*temstep).push_back({x + 1, y});
            (*memory)[x][y] = max((*memory)[x][y], step.size() + dfs(x + 1, y, *temstep));
            (*temstep).pop_back();
            // step.pop_back();
        }
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }

    if ((*map)[x][y] >= (*map)[x][y - 1] && y - 1 >= 1)
    {

        if ((*memory)[x][y - 1] != -1)
        {
            // cout << "(" << x << "," << y - 1 << ") is visited" << endl;
            (*memory)[x][y] = max((*memory)[x][y], step.size() + (*memory)[x][y - 1]);
        }
        else
        {
            // cout << "(" << x << "," << y - 1 << ") is not visited" << endl;
            // step.push_back({x, y - 1});
            (*temstep).push_back({x, y - 1});
            (*memory)[x][y] = max((*memory)[x][y], step.size() + dfs(x, y - 1, *temstep));
            (*temstep).pop_back();
            // step.pop_back();
        }
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }

    if ((*map)[x][y] >= (*map)[x][y + 1] && y + 1 <= C)
    {

        if ((*memory)[x][y + 1] != -1)
        {
            // cout << "(" << x << "," << y + 1 << ") is visited" << endl;
            (*memory)[x][y] = max((*memory)[x][y], step.size() + (*memory)[x][y + 1]);
        }
        else
        {
            // cout << "(" << x << "," << y + 1 << ") is not visited" << endl;
            // step.push_back({x, y + 1});
            (*temstep).push_back({x, y + 1});
            (*memory)[x][y] = max((*memory)[x][y], step.size() + dfs(x, y + 1, *temstep));
            (*temstep).pop_back();
            // step.pop_back();
        }
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }
    delete temstep;
    return (*memory)[x][y];
}

int dfs_cut(int x, int y)//进一步精简的代码
{
    if ((*memory)[x][y] != -1)
    {
        return (*memory)[x][y];
    }
    (*memory)[x][y] = 1;
     for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && (*map)[nx][ny] <= (*map)[x][y])
        {
            dfs_cut(nx, ny);
            (*memory)[x][y] = max((*memory)[x][y], 1 + (*memory)[nx][ny]);
        }
    }
    return (*memory)[x][y];
}

int dfs_2(int x, int y) // 用int记录步数, flag记录是否有最大值
{
    // cout << "Now in: (" << x << "," << y << ")" << endl;
    if ((*memory)[x][y] != -1)
    {
        return (*memory)[x][y];
    }
    if ((*map)[x][y] < (*map)[x - 1][y] && (*map)[x][y] < (*map)[x + 1][y] && (*map)[x][y] < (*map)[x][y - 1] && (*map)[x][y] < (*map)[x][y + 1]) // 没有可走的路
    {
        (*memory)[x][y] = 1;
        return (*memory)[x][y];
    }
    if ((*map)[x][y] >= (*map)[x - 1][y])
    {
            // cout << "(" << x - 1 << "," << y << ") is not visited" << endl;
        (*memory)[x][y] = max((*memory)[x][y], 1 + dfs_2(x - 1, y));
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }

    if ((*map)[x][y] >= (*map)[x + 1][y])
    {
            // cout << "(" << x + 1 << "," << y << ") is not visited" << endl;
        (*memory)[x][y] = max((*memory)[x][y], 1 + dfs_2(x + 1, y));
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }

    if ((*map)[x][y] >= (*map)[x][y - 1])
    {
            // cout << "(" << x << "," << y - 1 << ") is not visited" << endl;
        (*memory)[x][y] = max((*memory)[x][y], 1 + dfs_2(x, y - 1));
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }

    if ((*map)[x][y] >= (*map)[x][y + 1])
    {
        // cout << "(" << x << "," << y + 1 << ") is not visited" << endl;
        (*memory)[x][y] = max((*memory)[x][y], 1 + dfs_2(x, y + 1));
        // cout << "Update (" << x << "," << y << ") to " << (*memory)[x][y] << endl;
    }
    return (*memory)[x][y];
}

void Print_DPmap()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cout << (*memory)[i][j] << " ";
        }
        cout << endl;
    }
}
