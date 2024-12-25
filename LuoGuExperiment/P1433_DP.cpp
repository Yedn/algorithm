#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
double ans;
vector<double> x(20, 0);
vector<double> y(20, 0);
vector<vector<double>> dp(18, vector<double>(34000, 114514.0f));
vector<vector<double>> dis(20, vector<double>(20, 0));

double min(double a, double b)
{
    return a < b ? a : b;
}
double distance(int i, int j);
int main()
{
    cin >> n;
    // x = *(new vector<double>(20));
    // y = *(new vector<double>(20));
    // dp = *(new vector<vector<double>>(18, vector<double>(34000, 127)));
    // dis = *(new vector<vector<double>>(20, vector<double>(20, 0)));
    x[0] = y[0] = 0;
    ans = dp[0][0];

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) // 初始化dis
    {
        for (int j = i + 1; j <= n; j++)
        {
            dis[i][j] = distance(i, j);
            dis[j][i] = dis[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][(1 << (i - 1))] = dis[0][i]; //(0,0)直接到(x[i],y[i])
    }

    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((k & (1 << (i - 1))) == 0)
            {
                continue;
            }
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if ((k & (1 << (j - 1))) == 0)
                {
                    continue;
                }
                dp[i][k] = min(dp[i][k], (dp[j][(k - (1 << (i - 1)))] + dis[i][j]));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }
    printf("%.2f", ans);
    return 0;
}
double distance(int i, int j)
{
    return sqrt(((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])));
}