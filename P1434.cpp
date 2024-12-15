#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int R, C;
vector<vector<int>> *map;
vector<vector<int>> *dp;
int maxstep = 0;

int max (int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    cin >> R >> C;
    map = new vector<vector<int>>(R + 1, vector<int>(C + 1, INT_MAX)); // 把整个地图外面围一个INT_MAX高度，方便后期处理
    dp = new vector<vector<int>>(R + 1, vector<int>(C + 1, -1));       // dp数组，记录到达每个点所需的最小步数
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> (*map)[i][j];
        }
    }
}

void dfs(queue<vector<int>> step, int lastheight, int last_x, int last_y, int x, int y)
{
    int height = (*map)[x][y];
    if ((*map)[x][y + 1] > height && (*map)[x + 1][y] > height && (*map)[x - 1][y] > height && (*map)[x][y - 1] > height)
    {
        if ((*dp)[x][y] == -1 || (*dp)[x][y] < step.size())
        {
            (*dp)[x][y] = step.size();
        }
        // 没有路可走，说明已经到了终点
        if (maxstep < step.size())
        {
            maxstep = step.size();
        }
        return;
    }

    if ((*map)[x][y + 1] < height) // 可以往下走
    {
        if ((*dp)[x][y + 1] == -1) //下一格没走过往下探索
        {
            step.push({x, y + 1});
            dfs(step, (*map)[x][y], x, y, x, y + 1);
            step.pop();
        }
        else //已经有下一格的最长路
        {
            if (maxstep < step.size() + (*dp)[x][y + 1])
            {
                maxstep = step.size() + (*dp)[x][y + 1];
            }
            (*dp)[x][y] = max((*dp)[x][y], step.size() + (*dp)[x][y + 1]);

        }
    }
}