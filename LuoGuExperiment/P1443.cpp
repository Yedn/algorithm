#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,x,y;
vector<vector<int>> *map;
vector<vector<int>> *ans;
int main()
{
    cin >> n >> m >> x >> y;
    map = new vector<vector<int>>(n,vector<int>(m,0));
    ans = new vector<vector<int>>(n,vector<int>(m,-1));
}