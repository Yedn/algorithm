#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n ;
string word[30];
int mm[30][30];
int fre[30];//频度
char fristword;
int ans = -1;
int currentmax = 0;

void dfs(int p);
int findmm(int x, int y);
int max(int a, int b)
{
    return a > b ? a : b;
}
int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> word[i];
    }
    cin >> fristword;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mm[i][j] = findmm(i, j);
        }
    }
    for (int i =1 ;i<=n;i++)
    {
        if (word[i][0] == fristword)
        {
            fre[i]++;
            currentmax = word[i].length();
            dfs(i);
            fre[i]=0;
        }
    }
    cout << ans << endl;
    return 0;
}

int findmm(int x, int y)
{
    bool pp = true;
    int ky = 0;
    for (int k = word[x].length()-1;k>=0;k--)
    {
        for (int kx = k;kx<word[x].length();kx++)
        {
            if (word[x][kx] != word[y][ky++])
            {
                pp = false;
                break;
            }
        }
        if (pp == true)
        {
            return word[x].length() - k;
        }
        ky = 0;
        pp = true;
    }
    return 0;
}

void dfs(int p)
{
    bool jx = false;
    for (int j =1 ;j<=n;j++)
    {
        if (fre[j]>=2)
        {
            continue;
        }
        if (mm[p][j] == 0)
        {
            continue;
        }
        if (mm[p][j] == word[p].length() || mm[p][j] == word[j].length())
        {
            continue;
        }
        currentmax += word[j].length() - mm[p][j];
        fre[j]++;
        dfs(j);
        fre[j]--;
        currentmax -= word[j].length() - mm[p][j];
    }
    if (jx == false)
    {
        ans = max(ans, currentmax);
    }
    return ;
}