#include <iostream>
using namespace std;

int k, X, Y;

int BinPow(int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res <<= 1;
    }
    return res;
}

void output(int x, int y, int index)
{
    cout << x << " " << y << " " << index << endl;
}

void dfs(int x1, int y1, int x2, int y2, int tx, int ty, int size);
void fillminmap(int x1, int y1, int x2, int y2, int tx, int ty) // 当子地图大小为2*2时，有唯一确定解法
{
    if (tx == x1 && ty == y1) // 在左上角
    {
        // cout << x2 << y2 << 1 << endl;
        cout << x2 << " " << y2 << " " << 1 << endl;
        return;
    }
    if (tx == x1 && ty == y2) // 在右上角
    {
        // cout << x2 << y1 << 3 << endl;
        cout << x2 << " " << y1 << " " << 2 << endl;
        return;
    }
    if (tx == x2 && ty == y1) // 在左下角
    {
        // cout << x1 << y2 << 2 << endl;
        cout << x1 << " " << y2 << " " << 3 << endl;
        return;
    }
    if (tx == x2 && ty == y2) // 在右下角
    {
        // cout << x1 << y1 << 4 << endl;
        cout << x1 << " " << y1 << " " << 4 << endl;
        return;
    }
}

int main()
{
    cin >> k >> X >> Y;
    int size = BinPow(k);
    dfs(1, 1, size, size, X, Y, size);
    return 0;
}

void dfs(int x1, int y1, int x2, int y2, int tx, int ty, int size)
{
    if (size == 2)
    {
        if (tx == x1 && ty == y1)
        {
            output(x2, y2, 1);
        }
        else if (tx == x1 && ty == y2)
        {
            output(x2,y1,2);
        }
        else if (tx == x2 && ty == y1)
        {
            output(x1,y2,3);
        }
        else if (tx == x2 && ty == y2)
        {
            output(x1,y1,4);
        }
        return;
    }
    size >>= 1;
    int mid_x = (x2 - x1 + 1) / 2 + x1 - 1;
    int mid_y = (y2 - y1 + 1) / 2 + y1 - 1;
    if (tx <= mid_x && ty <= mid_y) // 在左上角
    {
        cout << mid_x + 1 << " " << mid_y + 1 << " " << 1 << endl;
        dfs(x1, y1, mid_x, mid_y, tx, ty, size);                       // 处理左上
        dfs(x1, mid_y + 1, mid_x, y2, mid_x, mid_y + 1, size);         // 处理右上
        dfs(mid_x + 1, y1, x2, mid_y, mid_x + 1, mid_y, size);         // 处理左下
        dfs(mid_x + 1, mid_y + 1, x2, y2, mid_x + 1, mid_y + 1, size); // 处理右下
    }
    if (tx > mid_x && ty <= mid_y) // 在左下角
    {
        cout << mid_x << " " << mid_y + 1 << " " << 3 << endl;
        dfs(mid_x+1, y1, x2, mid_y, tx, ty, size);                   // 处理左下角
        dfs(x1, y1, mid_x, mid_y, mid_x, mid_y, size);                 // 处理左上
        dfs(x1, mid_y + 1, mid_x, y2, mid_x, mid_y + 1, size);         // 处理右上
        dfs(mid_x + 1, mid_y + 1, x2, y2, mid_x + 1, mid_y + 1, size); // 处理右下
    }
    if (tx <= mid_x && ty > mid_y) // 在右上角
    {
        cout << mid_x + 1 << " " << mid_y << " " << 2 << endl;
        dfs(x1, mid_y + 1, mid_x, y2, tx, ty, size);                   // 处理右上
        dfs(x1, y1, mid_x, mid_y, mid_x, mid_y, size);                 // 处理左上
        dfs(mid_x + 1, y1, x2, mid_y, mid_x + 1, mid_y, size);         // 处理左下
        dfs(mid_x + 1, mid_y + 1, x2, y2, mid_x + 1, mid_y + 1, size); // 处理右下
    }
    if (tx > mid_x && ty > mid_y) // 在右下角
    {
        cout << mid_x << " " << mid_y << " " << 4 << endl;
        dfs(mid_x + 1, mid_y + 1, x2, y2, tx, ty, size);       // 处理右下
        dfs(x1, y1, mid_x, mid_y, mid_x, mid_y, size);         // 处理左上
        dfs(x1, mid_y + 1, mid_x, y2, mid_x, mid_y + 1, size); // 处理右上
        dfs(mid_x + 1, y1, x2, mid_y, mid_x + 1, mid_y, size); // 处理左下
    }
}