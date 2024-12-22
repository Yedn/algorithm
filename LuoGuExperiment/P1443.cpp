#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, x, y;
vector<vector<int>> *ans;
int min(int a, int b)
{
    return a < b ? a : b;
}

vector<int> dx = {1, -1, 2, -2, 1, -1, 2, -2};
vector<int> dy = {2, -2, 1, -1, -2, 2, -1, 1};
void dfs(int i, int j, int step); // i,j为坐标，step为步数
void bfs(int i, int j);
void PrintAns();
int main()
{
    cin >> n >> m >> x >> y;
    ans = new vector<vector<int>>(n, vector<int>(m, -1));
    (*ans)[x-1][y-1] = 0;
    // dfs(x-1,y-1,0); // dfs会TLE
    bfs(x - 1, y - 1);
    PrintAns();
    return 0;
}

void dfs(int i, int j, int step)
{
    if (i < 0 || i >= n || j < 0 || j >= m) // 超出范围
    {
        return;
    }
    (*ans)[i][j] = min(step, (*ans)[i][j]);
    for (int k = 0; k < 8; k++)
    {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
        {
            continue;
        }
        else if ((*ans)[xx][yy] > step)
        {
            dfs(xx, yy, step + 1);
        }
    }
}
void bfs(int i, int j)
{
    queue<vector<int>> steps;
    steps.push({i, j});
    int stepslen = 1; //记录上一步里面有多少个节点
    while (!steps.empty())
    {
        int templen=0;
        while (stepslen--)
        {
            vector<int> step = steps.front();
            steps.pop();
            int x = step[0], y = step[1];
            for (int k = 0; k < 8; k++)
            {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                {
                    continue;
                }
                if ((*ans)[xx][yy] == -1) //只有没走过的才要push 因为BFS一定是最优解
                {
                    (*ans)[xx][yy] = (*ans)[x][y] + 1;
                    steps.push({xx, yy});
                    templen++;
                }
            }
        }
        stepslen = templen;
    }
    return ;
}
void PrintAns()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if ((*ans)[i][j] == INT_MAX)
            // {
            //     (*ans)[i][j] = -1;
            // }
            printf("%-4d ", (*ans)[i][j]);
        }
        cout << endl;
    }
}