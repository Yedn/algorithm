#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
vector<ll> *a;
ll average;
ll ans;
void greedy();
ll abs(int a, int b)
{
    return a > b ? a - b : b - a;
}
// ll MinIndex(ll l, ll r, ll target);
// bool CheckDirection(ll start);
void greedy_2();
int main()
{
    cin >> n;
    a = new vector<ll>(n);
    ans = 0;
    average = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> (*a)[i];
        average += (*a)[i];
    }
    average /= n;
    greedy_2();
    return 0;
}

void greedy_2()
{
    vector<ll> c(n);
    c[0] = 0;
    for (int i = 1; i < n; i++)
    {
        c[i] = c[i - 1] + (*a)[i - 1] - average;
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++)
    {
        ans += abs(c[i] - c[(n - 1) / 2]);
    }
    cout << ans << endl;
    return ;
}

// void greedy()
// {
//     ll index = MinIndex(0,n,average);
//     while (index < n)
//     {
//         // index = MinIndex(0,index,average-1);
//         (*a)[index]--;
//         if (index == n - 1)
//         {
//             cout << "form: " << index << " : " << (*a)[index] + 1 << " give to " << index - 1 << " : " << (*a)[index - 1] << endl;
//             (*a)[index - 1]++;
//         }
//         else if (index == 0)
//         {
//             cout << "form: " << index << " : " << (*a)[index] + 1 << " give to " << index + 1 << " : " << (*a)[index + 1] << endl;
//             (*a)[index + 1]++;
//         }
//         else
//         {
//             bool direction = CheckDirection(index);
//             if ((((*a)[index] - (*a)[index - 1]) >= ((*a)[index] - (*a)[index + 1])) && !direction) //
//             {
//                 cout << "form: " << index << " : " << (*a)[index] + 1 << " give to " << index - 1 << " : " << (*a)[index - 1] << endl;
//                 (*a)[index - 1]++;
//             }
//             else
//             {
//                 cout << "form: " << index << " : " << (*a)[index] + 1 << " give to " << index + 1 << " : " << (*a)[index + 1] << endl;
//                 (*a)[index + 1]++;
//             }
//         }

//         ans++;
//         index = MinIndex(0,n,average);
//     }
//     cout << ans << endl;
//     return;
// }