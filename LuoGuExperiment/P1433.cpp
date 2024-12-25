#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

double ans;
vector<vector<double>> cheese;
vector<bool> haveWalk;
int step;
double cheeseCount;
void dfs(double x, double y, double d);

// unordered_map<vector<double>,double> dp;
double min(double a, double b)
{
    return a < b ? a : b;
}
int main()
{
    cin >> cheeseCount;
    double x, y;
    cheese = *(new vector<vector<double>>(cheeseCount, vector<double>(2, -1)));
    haveWalk = *(new vector<bool>(cheeseCount, false));
    for (double i = 0; i < cheeseCount; i++)
    {
        cin >> x >> y;
        cheese[i][0] = x;
        cheese[i][1] = y;
        // dp.insert({{x, y}, 114514.0F});
    }
    ans = 114514.0F;
    step = 0;
    dfs(0, 0, 0.0F);
    // cout << "Final ans: ";
    printf("%.2f", ans);
    return 0;
}

void dfs(double x, double y, double d)
{
    if (step == cheeseCount)
    {
        ans = min(ans, d);
        // cout << "tempans: " << ans << endl;
        return;
    }
    for (double i = 0; i < cheeseCount; i++)
    {
        if (cheese[i][0] == x && cheese[i][1] == y)
            continue;
        if (!haveWalk[i]) // 没去过的cheese
        {
            // double tem = (d + sqrt((cheese[i][0] - x) * (cheese[i][0] - x) + (cheese[i][1] - y) * (cheese[i][1] - y)));
            double tem = floor((d + sqrt((cheese[i][0] - x) * (cheese[i][0] - x) + (cheese[i][1] - y) * (cheese[i][1] - y))) * 1000) / 1000;
            if(tem < ans)
            {
                haveWalk[i] = true;
                step ++;
                dfs(cheese[i][0], cheese[i][1], tem);
                haveWalk[i] = false;
                step--;
            }
        }
        else
        {
            continue;
        }
    }
    return;
}