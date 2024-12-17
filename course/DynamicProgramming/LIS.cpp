//最大递增子序列

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
void LIS(vector<int> &input) ;
int main()
{
    cin >> len;
    vector<int> input(len,0);
    for (int i = 0; i < len; i++)
    {
        cin >> input[i];
    }
    LIS(input);
    return 0;
}

void LIS(vector<int> &input)
{
    vector<int> dp(len,1);
    vector<int> index(len,-1);
    int maxindex = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[i] > input[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if (dp[i] > dp[maxindex])
                {
                    maxindex = i;
                }
                index[i] = j;
            }
        }
    }

    for (int i = dp[maxindex];i>0;i--)
    {
        cout << input[maxindex] << " ";
        maxindex = index[maxindex];
    }
}
