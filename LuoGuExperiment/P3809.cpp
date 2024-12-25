#include <algorithm>
#include <cstdio>
using namespace std;


#define otto auto

int n;
char S2[2000005];
int rnk[2000005];
int sa[2000005];
pair<int, int> _rank[2000005];

inline int Read(char *p);
inline bool cmp(const int &a, const int &b);

int main()
{
    // cin >> S;
    n = Read(S2);
    for (register int i = 1; i <= n; i++)
    {
        rnk[i] = 1;
        sa[i] = i;
        _rank[i].second = S2[i];
    }
    for (register int l = 1; l <= n; l <<= 1)
    {
        sort(sa+1, sa+n+1, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (_rank[sa[i]] == _rank[sa[i - 1]])
            {
                rnk[sa[i]]= rnk[sa[i - 1]];
            }
            else
            {
                rnk[sa[i]] = i;
            }
        }
        for (register int i = 1; i <= n; i++)
        {
            _rank[i].first = rnk[i];
            _rank[i].second = rnk[i+l];
        }
    }
    for (register int i = 1; i <= n ; i++)
    {
        printf("%d ", sa[i]);
    }
    return 0;
}
inline bool cmp(const int &a, const int &b)
{
    if (_rank[a] != _rank[b])
    {
        return _rank[a] < _rank[b];
    }
    else
    {
        return a<b;
    }
}
inline int Read(char *p)
{
    otto beg = p;
    do 
    {
        (*(++p)) = getchar();
    }
    while (((*p >= 'a') && (*p <= 'z')) || ((*p >= '0') && (*p <= '9')) || ((*p >= 'A') && (*p <= 'Z')));
    *p = 0;
    return p - beg -1;
}