#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<bool> step;
int MaxEdge; // 路径中的最大边权
int PathPower;
stack<int> path;
int MinTime;
void dfs();
inline int min(int a, int b)
{
    return a < b ? a : b;
}
void PrintStackToCheckPath(stack<int> path, int NeedTime);
int main()
{
    MinTime = 114514;
    cin >> N >> M;
    map = *(new vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
    step = *(new vector<bool>(N + 1, false));
    for (register int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y] = z;
        map[y][x] = map[x][y];
    }
    PathPower = 0;
    path.push(1);
    step[1] = true;
    MaxEdge = 0;
    dfs();
    cout << MinTime << endl;
    return 0;
}
void dfs()
{
    if (path.top() == N)
    {
        // PrintStackToCheckPath(path, PathPower + MaxEdge);
        // cout << "Max Edge: " << MaxEdge << endl;
        MinTime = min(MinTime, PathPower + MaxEdge);
        return;
    }
    if (path.size() == N)
    {
        return;
    }
    int from = path.top();
    for (register int to = 1; to <= N; to++)
    {
        if (map[from][to] && step[to] == false) //&& PathPower + map[from][to] + MaxEdge < MinTime
        {
            if (PathPower + map[from][to] + MaxEdge >= MinTime)
            {
                continue;
            }
            int PreMaxEdge = MaxEdge;
            if (map[from][to] > MaxEdge)
            {
                MaxEdge = map[from][to];
            }

            path.push(to);
            PathPower += map[from][to];
            step[to] = true;
            dfs();
            step[to] = false;
            path.pop();
            MaxEdge = PreMaxEdge;
            PathPower -= map[from][to];
        }
    }
    return;
}

void PrintStackToCheckPath(stack<int> path, int NeedTime)
{
    while (!path.empty())
    {
        cout << path.top();
        if (path.size() != 1)
        {
            cout << " -> ";
        }
        path.pop();
    }
    cout << " NeedTime: " << NeedTime;
    cout << endl;
}