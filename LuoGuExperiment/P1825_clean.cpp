#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
vector<vector<char>> *Map; // 原始地图
vector<int> startloc;
vector<vector<bool>> *visited;
vector<vector<int>> *transLocList_2 = new vector<vector<int>>(52, vector<int>(2, -1)); // 记录所有传送门 <- 一个简易Hash

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

typedef struct Node
{
    int x, y;
    int step;
} Node;
void PrintRawMap();
void InputMap(vector<vector<char>> &Map);
void bfs();
void PrintQueue(queue<Node> step); // 测试用
int main()
{
    cin >> N >> M;
    Map = new vector<vector<char>>(N + 1, vector<char>(M + 1));
    visited = new vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
    InputMap(*Map);
    // PrintRawMap();
    bfs();
    return 0;
}

void InputMap(vector<vector<char>> &Map)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] >= 'A' && Map[i][j] <= 'Z')
            {

                if ((*transLocList_2)[(Map[i][j] - 'A') * 2][0] == -1 && (*transLocList_2)[(Map[i][j] - 'A') * 2][1] == -1)
                {
                    (*transLocList_2)[(Map[i][j] - 'A') * 2] = {i, j};
                }
                else
                {
                    (*transLocList_2)[(Map[i][j] - 'A') * 2 + 1] = {i, j};
                }
            }
            if (Map[i][j] == '@')
            {
                startloc = vector<int>{i, j};
            }
        }
    }
}
void PrintRawMap()
{
    cout << "Raw Map:" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << (*Map)[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Doors: " << endl;

    for (int i = 0; i < 52; i += 2)
    {
        if ((*transLocList_2)[i][0] != -1)
        {
            cout << "(" << (*transLocList_2)[i][0] << "," << (*transLocList_2)[i][1] << ") to (" << (*transLocList_2)[i + 1][0] << "," << (*transLocList_2)[i + 1][1] << ")" << endl;
        }
    }
    cout << "Start from : " << "(" << startloc[0] << "," << startloc[1] << ")" << endl;
}

void PrintQueue(queue<Node> step)
{
    for (int i = 0; i < step.size(); i++)
    {
        Node cur = step.front();
        step.pop();
        cout << "(" << cur.x << "," << cur.y << ") :" << cur.step << " ";
        if (i != step.size() - 1 && step.size() != 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void bfs()
{
    int childNode = 1;
    int newchild = 0;
    queue<Node> step;
    step.push(Node{startloc[0], startloc[1], 0});
    // (*visited)[startloc[0]][startloc[1]] = 1;
    while (!step.empty())
    {
        newchild = 0;
        // PrintQueue(step);
        for (int c = 0; c < childNode; c++)
        {
            Node cur = step.front();
            step.pop();
            if ((*Map)[cur.x][cur.y] == '=')
            {
                cout << cur.step << endl;
                return;
            }
            else if ((*Map)[cur.x][cur.y] >= 'A' && (*Map)[cur.x][cur.y] <= 'Z') // 传送门
            {
                vector<int> nloc = (*transLocList_2)[((*Map)[cur.x][cur.y] - 'A') * 2];
                vector<int> cloc = {cur.x, cur.y};
                if (nloc == cloc)
                {
                    nloc = (*transLocList_2)[((*Map)[cur.x][cur.y] - 'A') * 2 + 1];
                }
                cur.x = nloc[0];
                cur.y = nloc[1];
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && (*Map)[nx][ny] != '#' && !(*visited)[nx][ny])
                {
                    step.push({nx, ny, (cur.step + 1)});
                    (*visited)[nx][ny] = true;
                    newchild++;
                }
            }
        }
        childNode = newchild;
    }
    return;
}