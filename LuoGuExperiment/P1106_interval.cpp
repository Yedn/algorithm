// 用单调区间的做法做删数问题

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string rawinput;
    int k;
    cin >> rawinput >> k;
    vector<int> input;
    for (int i = 0; i < rawinput.size(); i++)
    {
        input.push_back(rawinput[i] - '0');
    }
    input.push_back(0);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < input.size()-1; j++)
        {
            if (input[j] > input[j + 1])
            {
                input.erase(input.begin() + j);
                break;
            }
        }
    }
    // cout << "raw OK:" << endl;
    // for (int i = 0; i < input.size() && input[i]!=-1; i++)
    // {
    //     cout << input[i];
    // }
    // cout << endl;
    while (input[0]==0 && input.size()>1)
    {
        input.erase(input.begin());
    }
    int i=0;
    //这里用do-while处理最后一个0和本身就只剩下0的情况 <-一定至少output一个数
    do 
    {
        cout << input[i];
        i++;
    }
    while (i<input.size()-1);
    return 0;
}