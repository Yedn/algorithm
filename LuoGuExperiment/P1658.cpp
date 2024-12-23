#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int X,N;
int main(){
    cin >> X >> N;
    vector<int> coins(N);
    for (int i=0;i<N;i++){
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end());
    if (coins[0] != 1 || X < coins[0])
    {
        cout << "-1" << endl;
        return 0;
    }
    int counts = 0;
    int sum =0;
    while (sum < X)
    {
        int i;
        for (i=N-1;i>=0;i--)
        {
            if (coins[i] <= sum +1)
            {
                break;
            }
        }
        counts++;
        sum += coins[i];
    }
    cout << counts << endl;
    return 0;
}

