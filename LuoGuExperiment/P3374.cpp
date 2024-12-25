#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, tree[2000010];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            add(b, c);
        }
        else
        {
            cout << sum(c) - sum(b - 1) << endl;
        }
    }
}

// int n,m;
// int ans;
// int d = 0;
// int input[400010];

// typedef struct Node
// {
//     int l,r;
//     int num;
// }node;
// node tree[2000010];
// void build(int l,int r,int id)
// {
//     d++;
//     tree[id].l = l;
//     tree[id].r = r;
//     if(l == r)
//     {
//         return ;
//     }
//     int mid = ((l+r)>>2);

//     build(l,mid,id<<1);
//     build(mid+1,r,(id<<1)+1);
// }

// int add(int index)
// {
//     if (tree[index].l == tree[index].r)
//     {
//         tree[index].num = input[tree[index].r];
//         return tree[index].num;
//     }
//     tree[index].num = add(index<<1) + add((index<<1)+1);
//     return tree[index].num;
// }

// void _plus(int index,int dis,int k)
// {
//     tree[index].num += k;
//     if(tree[index].l == tree[index].r)
//     {
//         return;
//     }
//     if (dis <= tree[index*2].r)
//     {
//         _plus(index*2,dis,k);
//     }
//     if (dis >= tree[index*2+1].l)
//     {
//         _plus(index*2+1,dis,k);
//     }
//     return ;
// }

// void search(int index,int l,int r)
// {
//     if(tree[index].l >=l && tree[index].r <= r)
//     {
//         ans += tree[index].num;
//         return ;
//     }
//     if (tree[index*2].r >= l)
//     {
//         search(index*2,l,r);
//     }
//     if (tree[index*2+1].l <= r)
//     {
//         search(index*2+1,l,r);
//     }
// }

// int main ()
// {
//     cin >> n >> m;
//     for (int i = 1;i <= n;i++)
//     {
//         cin >> input[i];
//     }
//     build(1,n,1);
//     add(1);
//     for (int i = 1;i <= m;i++)
//     {
//         int a,b,c;
//         cin >> a >> b >> c;
//         if (a == 1)
//         {
//             _plus(1,b,c);
//         }
//         if (a ==2 )
//         {
//             ans = 0;
//             search(1,b,c);
//             cout << ans << endl;
//         }
//     }
//     return 0;
// }
