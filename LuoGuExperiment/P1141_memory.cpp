#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int len;
vector<vector<bool>> map;
vector<vector<int>> path;
vector<int> *ans;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
void dfs_memory(int x, int y, int canwalk, int count);
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    cin >> n >> m;
    ans = new vector<int>(m, 0);
    map = *(new vector<vector<bool>>(n, vector<bool>(n, 0)));
    path = *(new vector<vector<int>>(n, vector<int>(n, -1)));
    for (int i = 0; i < n; i++)
    {
        string tem;
        cin >> tem;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = (tem[j] - '0');
        }
    }
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (path[x-1][y-1] == -1)
        {
            dfs_memory(x - 1, y - 1, map[x-1][y-1], i);
        }
        else
        {
            (*ans)[i] = (*ans)[path[x - 1][y - 1]];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << (*ans)[i] << endl;
    }
    return 0;
}
void dfs_memory(int x, int y, int canwalk, int count)
{
    if (x < 0 || x >= n || y < 0 || y >= n || path[x][y] != -1 || map[x][y] != canwalk)
    {
        return ;
    }
    path[x][y] = count;
    (*ans)[count]++;
    canwalk = !canwalk;
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && map[nx][ny] == canwalk && ny < n )// 
        {
            dfs_memory(nx, ny, canwalk, count);
        }
    }
    return ;
}