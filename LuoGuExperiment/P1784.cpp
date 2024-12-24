#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> map = vector<vector<int>>(10, vector<int>(10, 0));
vector<vector<bool>> rolmark = vector<vector<bool>>(10, vector<bool>(10, false));
vector<vector<bool>> colmark = vector<vector<bool>>(10, vector<bool>(10, false));
vector<vector<bool>> blockmark = vector<vector<bool>>(10, vector<bool>(10, false));
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
bool novacancy();
void dfs(int x, int y);
void PrintMap();
void dfs_2(int x, int y);
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0)
            {
                rolmark[i][map[i][j]] = true;
                colmark[j][map[i][j]] = true;
                int block = (i - 1) / 3*3 + (j - 1) / 3 + 1;
                blockmark[block][map[i][j]] = true;
            }
        }
    }
    dfs_2(1,1);
    // bool flag = true;
    // int i, j;
    // // 找第一个空
    // for (i = 1; i <= 9 && flag; i++)
    // {
    //     for (j = 1; j <= 9 && flag; j++)
    //     {
    //         if (map[i][j] == 0)
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }
    // }
    // // 开始dfs
    // dfs_2(i,j);
    return 0;
}

void PrintMap()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    exit(0); //**** 强制退出 不继续DFS ****//
}

bool check(int x, int y, int num)
{
    // check row
    // check block
    int block_x = (x - 1) / 3 + 1;
    int block_y = (y - 1) / 3 + 1;
    for (int i = block_x * 3 - 2; i <= block_x * 3; i++)
    {
        for (int j = block_y * 3 - 2; j <= block_y * 3; j++)
        {
            if (map[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool novacancy()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (map[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void dfs_2(int x, int y)
{
    if (map[x][y] != 0)
    {
        if (x == 9 && y == 9)
        {
            PrintMap();
            return;
        }
        else if (y == 9)
        {
            dfs_2(x + 1, 1);
        }
        else
        {
            dfs_2(x, y + 1);
        }
    }
    else
    {
        for (int n = 1; n <= 9; n++)
        {
            if (!rolmark[x][n] && !colmark[y][n] && !(blockmark[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][n]))
            {
                map[x][y] = n;
                rolmark[x][n] = colmark[y][n] = blockmark[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][n] = true;
                if (x == 9 && y == 9)
                {
                    PrintMap();
                    return;
                }
                else if (y == 9)
                {
                    dfs_2(x + 1, 1);
                }
                else
                {
                    dfs_2(x, y + 1);
                }
                map[x][y] = 0;
                rolmark[x][n] = colmark[y][n] = blockmark[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][n] = false;
            }
        }
    }
    return ;
}

void dfs(int x, int y)
{
    for (int n = 1; n <= 9; n++)
    {
        if (check(x, y, n))
        {
            map[x][y] = n;
            if (x == 9 && y == 9)
            {
                cout << "Done: " << endl;
                PrintMap();
                return;
            }

            bool flag = true;
            int i, j;
            // 找第一个空
            for (i = 1; i <= 9 && flag; i++)
            {
                for (j = 1; j <= 9 && flag; j++)
                {
                    if (map[i][j] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
            {
                dfs(i, j);
            }
            map[x][y] = 0;
        }
    }
    return;
}
