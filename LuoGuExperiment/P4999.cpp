#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1e9 + 7;

vector<ll> digital;
ll dp[100][500][2];
int T, l, r;

ll digital_dp(ll tar);
ll dfs(int pos, int sum, bool flag);
int main()
{
    cin >> T;
    vector<vector<ll>> read(T, vector<ll>(2));
    int x = 0;
    while (x < T)
    {
        cin >> read[x][0] >> read[x][1];
        x++;
    }
    x = 0;
    while (x < T)
    {
        cout << (digital_dp(read[x][1]) - digital_dp(read[x][0] - 1) + MOD) % MOD << endl;
        x++;
    }
    return 0;
}

ll digital_dp(ll tar)
{
    digital.clear(); // digital存每个位
    do
    {
        digital.push_back(tar % 10);
        tar /= 10;
    } while (tar);
    memset(dp, 0, sizeof(dp));
    return dfs(digital.size(), 0, 1); // 从最高位开始算 即为 abcde的a开始
}

ll dfs(int pos, int sum, bool flag)
{
    if (pos == 0) // 算到第零位了
    {
        return sum % MOD;
    }
    if (dp[pos][sum][flag] != 0) // 算过
    {
        return dp[pos][sum][flag];
    }
    ll res = 0; // 做累加
    int max = flag ? digital[pos - 1] : 9;//如果这时候是有限制的话，最多只能数到digital[pos-1] 例如abcde在pos = 6的时候，最多只能数到a
    for (int i = 0; i <= max; i++)
    {
        res = (res + dfs(pos - 1, sum + i, flag && (i == max))%MOD) % MOD; 
        //flag && (i == max)是判断是否继续有限制 如果本身有限制而且刚好数到了最大值，比如abcde 在pos = 6的时候，如果数到小于a，那么b的位置可以取1到9，但是如果数到a，则b的位置最多到b
    }

    return (dp[pos][sum][flag] = (res) % MOD);
}