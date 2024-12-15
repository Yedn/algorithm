#include <climits>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 51;

int *local = new int[MAX];
int *power = new int[MAX];
int f[MAX][MAX][2];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, c;
    cin >> n >> c;
    memset(f, 66, sizeof(f));
    local[0] = power[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> local[i] >> power[i];
        power[i] += power[i - 1];
    }
    f[c][c][0] = f[c][c][1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j + i - 1 <= n; j++)
        {
            int k = j + i - 1;
            f[j][k][0] = min((f[j + 1][k][0] + (local[j + 1] - local[j]) * (power[n] - (power[k] - power[j]))), (f[j + 1][k][1] + (local[k] - local[j]) * (power[n] - (power[k] - power[j]))));
            f[j][k][1] = min((f[j][k - 1][0] + (local[k] - local[j]) * (power[n] - (power[k - 1] - power[j - 1]))), (f[j][k - 1][1] + (local[k] - local[k - 1]) * (power[n] - (power[k - 1] - power[j - 1]))));
        }
    }
    cout << min(f[1][n][0],f[1][n][1]) << endl;
    return 0;
}