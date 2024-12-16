//最长子序列问题

#include <iostream>
#include <string>
#include <vector>
using namespace std;



void LCS(string X, string Y);
void Print_Raw_Path(vector<vector<string>> path, string X, string Y);
void Print_LCS(vector<vector<string>> path, vector<char> *LCS, string X, string Y, int i, int j) ;
int main()
{
    string X, Y;
    cin >> X >> Y;
    LCS(X, Y);
    return 0;
}

void LCS(string X, string Y)
{
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    vector<vector<string>> path(m+1, vector<string>(n+1, ""));

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (X[i] == Y[j])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
                path[i][j] = "↖";
            }
            else if (dp[i][j+1] >= dp[i+1][j])//X的LCS比较长
            {
                dp[i+1][j+1] = dp[i][j+1];
                path[i][j] = "↑";
            }
            else
            {
                dp[i+1][j+1] = dp[i+1][j];
                path[i][j] = "←";
            }
        }
    }
    cout << "Raw Path: " << endl;
    Print_Raw_Path(path, X, Y);
    vector<char> *LCS = new vector<char>();
    Print_LCS(path, LCS, X, Y, m-1, n-1);
    cout << "LCS: ";
    for (int i = 0;i < (*LCS).size();i++)
    {
        cout << (*LCS)[i];
    }
    cout << endl;
}

void Print_Raw_Path(vector<vector<string>> path, string X, string Y)
{
    cout << "  ";
    for (int i = 0;i < path.size();i++)
    {
        cout << Y[i] << " ";
    }
    cout << endl;
    for (int i =0;i<path.size();i++)
    {
        cout << X[i] << " ";
        for (int j = 0;j < path[0].size();j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    return ;
}

void Print_LCS(vector<vector<string>> path, vector<char> *LCS,string X, string Y,int i,int j)
{

    if (i == -1 || j == -1)
    {
        return ;
    }
    if (path[i][j] == "↖")
    {
        Print_LCS(path, LCS,X, Y, i-1, j-1);
        (*LCS).push_back(X[i]);
    }
    else if (path[i][j] == "↑")
    {
        Print_LCS(path, LCS,X, Y, i-1, j);
    }
    else
    {
        Print_LCS(path, LCS,X, Y, i, j-1);
    }

}
