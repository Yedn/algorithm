//编辑距离问题

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string X,Y;

void EditDistance(string X, string Y);
int FindMinIndex(vector<int> &tem);

int main()
{
    cin >> X >> Y;
    EditDistance(X, Y);
}

void EditDistance(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    vector<vector<char>> path(m,vector<char>(n, ' '));
    for (int i =0;i <m;i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0;j < n;j++)
    {
        dp[0][j] = j;
    }
    int cost;
    for (int i = 1;i <= m;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if(X[i-1] == Y[j-1])
            {
                cost = 0;
            }
            else
            {
                cost = 1;
            }
            vector<int> tem = {dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost};
            int index = FindMinIndex(tem);
            if (index == 0)
            {
                dp[i][j] = dp[i-1][j]+1;
                path[i - 1][j - 1] = '↑';
            }
            else if (index == 1)
            {
                dp[i][j] = dp[i][j-1]+1;
                path[i - 1][j - 1] = '←';
            }
            else
            {
                dp[i][j] = dp[i-1][j-1]+cost;
                path[i - 1][j - 1] = '↖';
            }
        }
    }


}

int FindMinIndex(vector<int> &tem)
{
    int min = tem[0];
    int index = 0;
    for (int i = 1;i < tem.size();i++)
    {
        if (tem[i] < min)
        {
            min = tem[i];
            index = i;
        }
    }
    return index;
}