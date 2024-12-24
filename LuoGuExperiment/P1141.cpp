#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<vector<int>> map;
int dfs(int x, int y);

int main()
{
    cin >> n >> m;
    map = *(new vector<vector<int>> (n,vector<int>(n,0)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        dfs(x-1,y-1);
    }
}