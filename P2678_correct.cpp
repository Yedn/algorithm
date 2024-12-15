#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long L;
int N, M;
long long mindist = INT_MAX;
long long MaxLimit = INT_MIN;
long long MinLimit = INT_MAX;
void FindMin(vector<long long> temsubdist);
bool FindAns(vector<long long> temsubdist, long long stepdist, int cutCount);
int main()
{
    cin >> L >> N >> M;
    MaxLimit = L;
    vector<long long> step(N + 2, 0);
    vector<long long> tempsubdist(N + 1, 0); // 差分获得刚开始的步距
    step[N + 1] = L;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> step[i];
        tempsubdist[i - 1] = step[i] - step[i - 1];
    }
    tempsubdist[N] = step[N + 1] - step[N]; // 终点到最后一个石头的距离
    FindMin(tempsubdist);
    // cout << "Init MAX:" << MaxLimit << " Init MIN:" << MinLimit << endl;
    while (MaxLimit >= MinLimit)
    {
        // cout << MinLimit << " to " << MaxLimit << endl;
        long long mid = (MaxLimit + MinLimit) / 2;
        // cout << mid;
        if (FindAns(tempsubdist, mid, M) == false)
        {
            // cout << " is not OK" << endl;
            MaxLimit = mid - 1;
        }
        else
        {
            // cout << " is OK" << endl;
            mindist = mid;
            MinLimit = mid + 1;
        }
    }
    cout << mindist << endl;
    return 0;
}

void FindMin(vector<long long> temsubdist)
{
    for (long long i = 0; i < temsubdist.size(); i++)
    {
        if (MinLimit > temsubdist[i])
        {
            MinLimit = temsubdist[i];
        }
    }
}

bool FindAns(vector<long long> temsubdist, long long stepdist, int cutCount)
{
    bool CanPass = true;
    for (int i = 0; i < temsubdist.size();)
    {
        if (temsubdist[i] < stepdist)
        {
            if (i == temsubdist.size() - 1)
            {
                cutCount --;
                break;
            }
            long long tem = temsubdist[i];
            long long j=i+1;
            for (;tem < stepdist && j<temsubdist.size();j++)
            {
                tem += temsubdist[j];
            }
            cutCount -= (j - i - 1);
            i=j;
        }
        else
        {
            i++;
        }
    }
    if (cutCount < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}