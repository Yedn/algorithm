#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int k;
void input(vector<int> &a, vector<int> &backup); //输入流
void checkinput(vector<int> a);
long makenum(vector<int> a);

void greedy(vector<int> a, vector<int> backup, int k); //贪心删数
int main()
{
    vector<int> a;
    vector<int> backup;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    //     backup[i]=a[i];
    // }
    input(a, backup);
    cin >> k;
    greedy(a, backup, k);
    // bool haszero = false;
    // for (int i = 0;i<k;i++)
    // {
    //     if (a[i+1] == 0)
    //     {
    //         a[i] = -1;
    //         k--;
    //         haszero = true;
    //     }
    // }
    // if (haszero)//提前清除了前导0
    // {
    // }
    // sort(backup.begin(), backup.end(),[](int a, int b){return a>b;});
    // // checkinput(backup);
    // // cout << "cut: ";
    // for (int i = 0; i < k; i++)
    // {
    //     // cout << a[backup[i]];
    //     a[find(a.begin(),a.end(),backup[i]) - a.begin()] = -1;
    // }
    // // cout << endl;
    // long ans = makenum(a);
    // cout << ans << endl;
    return 0;
}

void greedy(vector<int> a, vector<int> backup, int k)
{
    int rest = a.size() - k;
    int t = 0;
    int flag=0;
    int minp;
    for (int i = 0; i < rest; i++)
    {   
        minp = t;
        for (int j = t; j < k+t; j++)
        {
            if (a[j] < a[minp])
            {
                minp = j;
            }
        }
        if (a[minp])
        {
            flag = 1;
        }
        if (flag)
        {
            cout << a[minp];
        }
        k -= minp-t;
        t = minp+1;
    }
    if (!flag)
    {
        cout << 0;
    }
    return ;
}

long makenum(vector<int> a)
{
    long ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != -1)
        {
            ans = ans * 10 + a[i];
        }
    }
    return ans;
}

void checkinput(vector<int> a)
{
    cout << "input: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void input(vector<int> &a, vector<int> &backup)
{
    
    bool flag = true;
    while (flag)
    {
        char singleinput = getchar();
        if ('0' <= singleinput && singleinput <= '9')
        {
            a.push_back(singleinput - '0');
            backup.push_back(singleinput - '0');
        }
        else if (singleinput == '\n')
        {
            flag = false;
            return;
        }
    }
}