// #include <bits/stdc++.h>;
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<vector<int>>> map;
vector<int> u;
vector<int> v;
vector<int> w;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    cin >> N >> M;
    map.resize(N + 1, vector<vector<int>>(N + 1, vector<int>(340, 114514)));
    u.resize(M + 1);
    v.resize(M + 1);
    w.resize(M + 1);
    for (register int i = 1; i <= M; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        for (register int j = w[i];  j<= 260; j++)
        {
            map[u[i]][v[i]][j] = w[i];
            map[v[i]][u[i]][j] = w[i];
        }
    }
    for (register int k = 1; k <= N; k++)
    {
        for (register int i = 0; i <= 260; i++)
        {
            map[k][k][i] = 0;
        }
    }
    for (register int k = 1; k <= N; k++)
    {
        for (register int i =1; i <= N; i++)
        {
            for (register int j = 1; j <= N; j++)
            {
                if (k!=i && i!= j && j!= k)
                {
                    for (register int l = 0; l <= 260; l++)
                    {
                        if (l != 0)
                        {
                            map[i][j][l] = min(map[i][j][l], map[i][j][l-1]);
                        }
                        map[i][j][l] = min (map[i][j][l], map[i][k][l] + map[k][j][l]);
                    }
                }
            }
        }
    }
    int ans = 114514;
    for (register int i = 1; i <= M; i++)
    {
        ans = min(ans,map[1][u[i]][w[i]] + map[v[i]][N][w[i]] + w[i]*2);
        ans = min(ans,map[1][v[i]][w[i]] + map[u[i]][N][w[i]] + w[i]*2);
    }
    cout << ans << endl;
    return 0;
}