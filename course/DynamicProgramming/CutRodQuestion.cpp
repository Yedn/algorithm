//钢条切割问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int len;

int max(int a, int b)
{
    return a > b ? a : b;
}

int cut_rod_dp_2(vector<int> &p, int len, vector<int> &dp)//自底向上的动态规划
{
    for (int i = 1; i <= len; i++)
    {
        int price = p[i];
        for (int j = 1; j < i; j++)
        {
            price = max(price, dp[i - j] + p[j]);
        }
        dp[i] = price;
    }
    return dp[len];
}

int cut_rod_dp(vector<int> &p, int len, vector<int> &dp)//带备忘录的递归
{
    if (dp[len] != -1)
    {
        return dp[len]; //已经算过
    }

    int price = 0;
    if (len != 0)
    {
        price = -1;
        for (int i = 1; i <= len; i++)
        {
            price = max(price, cut_rod_dp(p, len - i, dp) + p[i]);
        }
        dp[len] = price;
    }
    return price;
    
}

int cut_rod(vector<int> &p, int len)//分治方法
{
    if (len == 0)
    {
        return 0;
    }
    int max_price = -1;
    for (int i=1;i<= len;i++)
    {
        max_price = max(max_price, cut_rod(p, len - i) + p[i]);
    }
    return max_price;
}

int main ()
{
    cin >> n >> len;
    vector<int> p(n+1);
    vector<int> dp(n+1,-1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    // cut_rod(p, len);
    // cout << cut_rod(p, len) << endl;
    cout << cut_rod_dp(p, len, dp) << endl;
    return 0;
}

