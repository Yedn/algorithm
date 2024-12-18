//硬币找零问题

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;
    // int count =0;
    // for (int i = 0; i < n; i++)
    // {
    //     int number = amount / coins[i]; //计算当前硬币可以换的次数
    //     amount -= number * coins[i]; //剩下多少钱，即使这个面额没法换也不影响，因为number为0
    //     count += number;
    // }
    // cout << count << endl;
}