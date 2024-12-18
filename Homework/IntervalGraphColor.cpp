// 区间图着色问题
#include <iostream>
#include <vector>
using namespace std;

vector<int> *s; // 开始时间
vector<int> *e; // 结束时间

void Sort();
int main()
{
    int n;
    cin >> n;
    s = new vector<int>(n); // s是开始时间列表
    e = new vector<int>(n); // e是结束时间列表
    for (int i = 0; i < n; i++)
    {
        cin >> (*s)[i] >> (*e)[i];
    }
    Sort(); // 按照开始时间排序
    int room = 1;
    int current = 0;
    for (int i = 1; i < n; i++)
    {
        if ((*s)[i] < (*e)[current]) //出现冲突，需要新开一间教室
        {
            room++;
        }
        else
        {
            current++; //没有冲突，这个时候按照新活动的结束时间计算
        }
    }
}
