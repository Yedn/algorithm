#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
#define maxn 2000005

int n, m;
char S[maxn];
int rnk[maxn], sa[maxn], tp[maxn], tax[maxn];

void RadixSort();
int ReadStr(char *p);
bool cmp(const int &a, const int &b);

int main()
{
    n = ReadStr(S);
    for (int i = 1; i <= n; ++i)
    {
        rnk[i] = S[i];
        tp[i] = i;
    }
    m = 10000;
    RadixSort();
    for (int len = 1, p = 0; p < n; len <<= 1, m = p)
    {
        p = 0;
        for (int i = 1; i <= len; ++i)
            tp[++p] = n - len + i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > len)
                tp[++p] = sa[i] - len;
        RadixSort();
        swap(tp, rnk);
        rnk[sa[1]] = p = 1;
        for (int i = 2; i <= n; ++i)
        {
            rnk[sa[i]] = ((tp[sa[i - 1]] == tp[sa[i]]) && (tp[sa[i - 1] + len] == tp[sa[i] + len])) ? p : ++p;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", sa[i]);
    }
    return 0;
}

int ReadStr(char *p)
{
    auto beg = p;
    do
        *(++p) = getchar();
    while (((*p >= 'a') && (*p <= 'z')) || ((*p >= '0') && (*p <= '9')) || ((*p >= 'A') && (*p <= 'Z')));
    *p = 0;
    return p - beg - 1;
}

void RadixSort()
{
    for (int i = 0; i <= m; ++i)
        tax[i] = 0;
    for (int i = 1; i <= n; ++i)
        ++tax[rnk[i]];
    for (int i = 1; i <= m; ++i)
        tax[i] += tax[i - 1];
    for (int i = n; i; --i)
        sa[tax[rnk[tp[i]]]--] = tp[i];
}
