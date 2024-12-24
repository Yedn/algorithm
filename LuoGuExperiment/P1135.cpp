#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, A, B;
vector<int> *K;
vector<int> *Visited;
typedef struct Road
{
    int loc;
    int len;
} Road;
void bfs();

int main()
{
    cin >> N >> A >> B;
    K = new vector<int>(N + 1, 0);
    Visited = new vector<int>(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> (*K)[i];
    }
    if (A == B)
    {
        cout << 0 << endl;
        return 0;
    }
    bfs();
    return 0;
}

void bfs()
{
    int Childnode = 1;
    int newChild = 0;
    queue<Road> step;
    step.push(Road{A, 0});
    Visited->at(A) = 1;
    while (!step.empty())
    {
        newChild = 0;
        for (int i = 0; i < Childnode; i++)
        {
            Road tmp = step.front();
            step.pop();
            int cloc = tmp.loc;
            if (cloc == B) // 已经到了
            {
                cout << tmp.len << endl;
                return;
            }
            if (cloc + (*K)[cloc] == B || cloc - (*K)[cloc] == B) // 下一步就是目的地 也是处理 (*K)[nloc] == 0 但是 nloc==B 的情况
            {
                cout << tmp.len + 1 << endl;
                return;
            }
            int nloc = cloc + (*K)[cloc];
            if (nloc <= N && (*K)[nloc] != 0 && !(*Visited)[nloc]) // 不能直接到而且可以往上 (*K)[nloc] != 0 直接就是没得走
            {
                step.push(Road{nloc, tmp.len + 1});
                Visited->at(nloc) = 1;
                newChild++;
            }
            nloc = cloc - (*K)[cloc];
            if (nloc >= 1 && (*K)[nloc] != 0 && !(*Visited)[nloc]) // 不能直接到而且可以往下
            {
                step.push(Road{nloc, tmp.len + 1});
                Visited->at(nloc) = 1;
                newChild++;
            }
        }
        Childnode = newChild;
    }
    cout << -1 << endl;
    return;
}