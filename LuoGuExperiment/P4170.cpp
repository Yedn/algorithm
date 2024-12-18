#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string target;
int n;
int min(int a, int b)
{
    return ((a < b) ? a : b);
}
void dp_paint(vector<vector<int>> dp, string target);
int main()
{
    cin >> target;
    n = target.size();
    vector<vector<int>> dp(n, vector<int>(n, n));
    dp_paint(dp, target);
    return 0;
}

void dp_paint(vector<vector<int>> dp, string target)
{
    // for (int i=0;i<n;i++)
    for (int i = n-1; i >=0; i--) //一定要从后面往前数 不然会出错 <- 算了[0,1] [0,2]但是[1,2]还没算
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (target[i] == target[j])
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = n;
                for (int k = i; k < j; k++)
                {
                    // cout << "dp[" << i << "][" << j << "]= " << dp[i][j] << " dp[" << i << "][" << k << "] + dp[" << k + 1 << "][" << j << "]= " << dp[i][k] << "+" << dp[k + 1][j] << endl;
                    dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j]));
                }
            }
            // cout << "i= " << i << " ,j= " << j << " ,dp[i][j]= " << dp[i][j] << endl;
        }
    }
    cout << dp[0][n - 1] << endl;
    return;
}