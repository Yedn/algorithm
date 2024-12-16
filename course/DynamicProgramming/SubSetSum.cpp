// 子集和数问题

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void SubSetSum(vector<vector<bool>> &dp, vector<int> &w, int M);
void Print_Sol(vector<vector<bool>> &dp, vector<int> &w, int i, int m, int M, vector<int> &step);

void Print_Raw_DP(vector<vector<bool>> &dp, vector<int> &w); // 打印dp数组原始数据
int W, M;
int main()
{
    
    cin >> W >> M;
    vector<int> w(W);
    for (int i = 0; i < W; i++)
        cin >> w[i];
    sort(w.begin(), w.end());
    vector<vector<bool>> dp(W + 1, vector<bool>(M + 1, false));
    for (int i = 0; i <= W; i++)
    {
        dp[i][0] = true;
    }
    SubSetSum(dp, w, M);
    cout << "Print Raw DP: " <<endl;
    Print_Raw_DP(dp, w);
    cout << "Print Solution: " << endl;
    vector<int> step;
    Print_Sol(dp, w, 1, M, M, step);
    return 0;
}

void SubSetSum(vector<vector<bool>> &dp, vector<int> &w, int M)
{
    int n = w.size() - 1;
    if (w[n] <= M)
    {
        dp[n][w[n]] = true;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= M; j++)
        {
            if (j >= w[i])
            {
                dp[i][j] = dp[i + 1][j] || dp[i + 1][j - w[i]];
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
}

void Print_Raw_DP(vector<vector<bool>> &dp,vector<int>&w)
{
    cout << "    ";
    for (int i = 0; i <= M; i++)
    {
        printf("%4d", i);
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < W; i++)
    {
        printf("%4d", w[i]);
        for(int j = 0; j <= M; j++)
        {
            if (dp[i][j])
            {
                printf("%4d", 1);
            }
            else
            {
                printf("%4d", 0);
            }
            cout << " ";
        }
        cout << endl;
    }
    return ;
}

void Print_Sol(vector<vector<bool>> &dp, vector<int> &w, int i, int m, int M, vector<int> &step)
{
    if (w[i] == m)
    {
        for (int i = 0;i<step.size();i++)
        {
            cout << step[i] << " + "; 
        }
        cout << w[i] << " = " << M << endl;
        return ;
    }
    if (dp[i+1][m])
    {
        Print_Sol(dp, w, i + 1, m, M, step);
    }
    if (dp[i+1][m-w[i]])
    {
        step.push_back(w[i]);
        Print_Sol(dp, w, i + 1, m - w[i], M, step);
        step.pop_back();
    }
}