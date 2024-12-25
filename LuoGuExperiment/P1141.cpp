#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int len;
vector<vector<int>> map;
vector<vector<int>> path;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
queue<int> anslist;
queue<pair<int, int>> q;
bool inQueue(int x, int y, queue<pair<int, int>> q);
int dfs(int x, int y);
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    cin >> n >> m;

    map = *(new vector<vector<int>>(n, vector<int>(n, 0)));
    path = *(new vector<vector<int>>(n, vector<int>(n, 0)));
    for (int i = 0; i < n; i++)
    {
        string tem;
        cin >> tem;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = tem[j] - '0';
            path[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        len = 0;
        q.push(make_pair(x - 1, y - 1));
        dfs(x - 1, y - 1);
        delete &path;
        path = *(new vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i = 0; i < q.size(); i++)
        {
            q.pop();
        }
        anslist.push(len);
    }
    while (!anslist.empty())
    {
        cout << anslist.front() << endl;
        anslist.pop();
    }
    return 0;
}

bool inQueue(int x, int y, queue<pair<int, int>> q)
{
    for (int i = 0; i < q.size(); i++)
    {
        if (q.front().first == x && q.front().second == y)
        {
            return true;
        }
        q.pop();
    }
    return false;
}

int dfs(int x, int y)
{
    if (q.size() == n * n) // || inQueue(x, y, q)
    {
        return q.size();
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && (map[nx][ny] == !(map[x][y]))&& !path[nx][ny]) // && !inQueue(nx, ny, q)
        {
            q.push(make_pair(nx, ny));
            path[nx][ny] = 1;
            len = max(len,dfs(nx, ny));
            if (len == n * n)
            {
                return len;
            }
            path[nx][ny] = 0;
            q.pop();
        }
    }
}