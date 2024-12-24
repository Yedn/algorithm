#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
int N, M;
vector<vector<char>> *Map;                                                    // 原始地图
unordered_map<int *, int *> *transportList = new unordered_map<int *, int *>; // 记录所有传送节点对
vector<int> startloc;
vector<vector<int>> *visited;

vector<vector<int>> *transLocList_2 = new vector<vector<int>>(52, vector<int>(2, -1));

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
    visited = new vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    InputMap(*Map);
    // PrintRawMap();
    bfs();
    return 0;
}

void InputMap(vector<vector<char>> &Map)
{
    unordered_map<char, int *> tem_transportList = *(new unordered_map<char, int *>());
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] >= 'A' && Map[i][j] <= 'Z')
            {

                if ((*transLocList_2)[Map[i][j] - 'A'][0] == -1)
                {
                    (*transLocList_2)[Map[i][j] - 'A'] = {i, j};
                }
                else
                {
                    (*transLocList_2)[Map[i][j] - 'A' + 1] = {i, j};
                }

                // int *tem_loc = new int[2];
                // tem_loc[0] = i;
                // tem_loc[1] = j;
                // if (tem_transportList.find(Map[i][j]) == tem_transportList.end())
                // {
                //     tem_transportList[Map[i][j]] = tem_loc; // 第一次出现这个字母，那么就记录下这个坐标
                // }
                // else // 不是第一次，形成坐标对
                // {
                //     int *tem_transport = new int[2];
                //     tem_transport[0] = tem_transportList[Map[i][j]][0];
                //     tem_transport[1] = tem_transportList[Map[i][j]][1];

                //     (*transportList)[tem_transport] = tem_loc;
                //     (*transportList)[tem_loc] = tem_transport;

                //     tem_transportList.erase(Map[i][j]);
                // }
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

    // for (auto i : *transportList)
    // {
    //     cout << "(" << i.first[0] << "," << i.first[1] << ") to " << "(" << i.second[0] << "," << i.second[1] << ")" << endl;
    // }
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
    step.push({startloc[0], startloc[1], 0});
    (*visited)[startloc[0]][startloc[1]] = 1;
    while (!step.empty())
    {
        // PrintQueue(step);
        for (int c = 0; c < childNode; c++)
        {
            Node cur = step.front();
            step.pop();
            if ((*Map)[cur.x][cur.y] == '=')
            {
                cout << "Use steps: ";
                cout << cur.step << endl;
                return;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && (*visited)[nx][ny] == 0)
                {
                    if ((*Map)[nx][ny] == '#') // 走不了
                    {
                        continue;
                    }
                    else if ((*Map)[nx][ny] == '.') // 走得通 是普通路
                    {
                        step.push({nx, ny, cur.step + 1});
                        (*visited)[nx][ny] = 1;
                        newchild++;
                    }
                    else if ((*Map)[nx][ny] >= 'A' && (*Map)[nx][ny] <= 'Z') // 传送门
                    {
                        (*visited)[nx][ny] = 1;
                        // cout << "Transport from : " << "(" << nx << "," << ny << ") ";
                        vector<int> nloc = (*transLocList_2)[(*Map)[nx][ny] - 'A'];
                        vector<int> cloc = {nx, ny};
                        if (nloc == cloc)
                        {
                            nloc = (*transLocList_2)[(*Map)[nx][ny]-'A' + 1];
                        }
                        // cout << "to (" << nloc[0] << "," << nloc[1] << ") " << endl;
                        if ((*visited)[nloc[0]][nloc[1]] == 0)
                        {
                            step.push({nloc[0], nloc[1], cur.step + 1});
                            (*visited)[nloc[0]][nloc[1]] = 1;
                            newchild++;
                        }
                        // int *tem_loc = new int[2];
                        // tem_loc[0] = nx;
                        // tem_loc[1] = ny;
                        // cout << "Transport from : " << "(" << nx << "," << ny << ") " ;
                        // auto to = (*transportList)[tem_loc];
                        // if (to)//存在以tem_loc为key的传送门
                        // {
                        //     nx = to[0];
                        //     ny = to[1];
                        // }
                        // else
                        // {
                        //     cout << "Have ERROR" << endl;
                        // }
                        // cout << "to (" << nx << "," << ny << ") " << endl;
                        // if ((*visited)[nx][ny] == 0)
                        // {
                        //     step.push({nx, ny, cur.step + 1});
                        //     (*visited)[nx][ny] = 1;
                        //     newchild++;
                        // }
                    }
                    else if ((*Map)[nx][ny] == '=') // 障碍物
                    {
                        cout << cur.step + 1 << endl;
                        return;
                    }
                }
            }
        }
        childNode = newchild;
        newchild = 0;
    }
    return;
}