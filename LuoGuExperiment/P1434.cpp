#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int R, C;
vector<vector<int>> *map;
vector<vector<int>> *dp;
queue<string> checkstep; // 保存每个可能路径
int maxstep = 0;

int max(int a, int b)
{
    return a > b ? a : b;
}

void StepToString(queue<vector<int>> step);
void dfs(queue<vector<int>> step, int lastheight, int last_x, int last_y, int x, int y);
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
    queue<vector<int>> step;
    dfs(step,0, 0, 0, 1, 1);
    cout << maxstep << endl;
    return 0;
}

void StepToString(queue<vector<int>> step)
{
    for (int i = 0; i < step.size(); i++)
    {
        string s = "[" + to_string(step.front()[0]) + "," + to_string(step.front()[1]) + "]";
        if (i != step.size() - 1)
        {
            s += "->";
        }
        checkstep.push(s);
    }
}

void PrintAllStep()
{
    for (int i = 0; i < checkstep.size(); i++)
    {
        cout << checkstep.front() << endl;
        checkstep.pop();
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
        StepToString(step); // 记录路径
        return;
    }

    if ((*map)[x][y + 1] < height && !(last_x == x && last_y == y + 1)) // 可以往下走而且刚才不是从下面来的
    {
        if ((*dp)[x][y + 1] == -1) // 下一格没走过往下探索
        {
            step.push({x, y + 1});
            dfs(step, (*map)[x][y], x, y, x, y + 1);
            step.pop();
        }
        else // 已经有下一格的最长路
        {
            if (maxstep < step.size() + (*dp)[x][y + 1])
            {
                maxstep = step.size() + (*dp)[x][y + 1];
            }
            (*dp)[x][y] = max((*dp)[x][y], step.size() + (*dp)[x][y + 1]);
        }
    }

    if ((*map)[x][y - 1] < height && !(last_x == x && last_y == y - 1))
    {
        if ((*dp)[x][y - 1] == -1) // 下一格没走过往下探索
        {
            step.push({x, y - 1});
            dfs(step, (*map)[x][y], x, y, x, y - 1);
            step.pop();
        }
        else // 已经有下一格的最长路
        {
            if (maxstep < step.size() + (*dp)[x][y - 1])
            {
                maxstep = step.size() + (*dp)[x][y - 1];
            }
            (*dp)[x][y] = max((*dp)[x][y], step.size() + (*dp)[x][y - 1]);
        }
    }

    if ((*map)[x + 1][y] < height && !(last_x == x + 1 && last_y == y))
    {
        if ((*dp)[x + 1][y] == -1) // 下一格没走过往下探索
        {
            step.push({x + 1, y});
            dfs(step, (*map)[x][y], x, y, x + 1, y);
            step.pop();
        }
        else // 已经有下一格的最长路
        {
            if (maxstep < step.size() + (*dp)[x + 1][y])
            {
                maxstep = step.size() + (*dp)[x + 1][y];
            }
            (*dp)[x][y] = max((*dp)[x][y], step.size() + (*dp)[x + 1][y]);
        }
    }

    if ((*map)[x - 1][y] < height && !(last_x == x - 1 && last_y == y))
    {
        if ((*dp)[x - 1][y] == -1) // 下一格没走过往下探索
        {
            step.push({x - 1, y});
            dfs(step, (*map)[x][y], x, y, x - 1, y);
            step.pop();
        }
        else // 已经有下一格的最长路
        {
            if (maxstep < step.size() + (*dp)[x - 1][y])
            {
                maxstep = step.size() + (*dp)[x - 1][y];
            }
            (*dp)[x][y] = max((*dp)[x][y], step.size() + (*dp)[x - 1][y]);
        }
    }
}