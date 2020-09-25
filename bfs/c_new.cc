#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool OnBoard(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
 
int getOne(int i, int j, int k, int l)
{
    return i * 1000 + j * 100 + k * 10 + l;
}
 
int getOne(vector<int> nums)
{
    return nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
}
 
vector<int> getFour(int num)
{
    vector<int> ans(4);
    ans[0] = num / 1000 % 10;
    ans[1] = num / 100 % 10;
    ans[2] = num / 10 % 10;
    ans[3] = num / 1 % 10;
    return ans;
}
 
map<int, int> m;
map<int, int> way;
queue<int> q;
 
int dx[8] = { 1, 2,  1,  2, -1, -2, -1, -2 };
int dy[8] = { 2, 1, -2, -1,  2,  1, -2, -1 };
 
void f(int curNum, int curKnight)
{
    vector<int> coord = getFour(curNum);
    for (int i = 0; i < 8; ++i)
    {
        vector<int> newCoord = coord;
        newCoord[curKnight] += dx[i];
        newCoord[curKnight + 1] += dy[i];
        int newNum = getOne(newCoord);
 
        if (m.find(newNum) != m.end() && m[newNum] > m[curNum] + 1)
        {
            m[newNum] = m[curNum] + 1;
            way[newNum] = curNum;
            q.push(newNum);
        }
    }
}

 
int main()
{

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                for (int l = 0; l < 8; ++l)
                {
                    if (i * 10 + j != k * 10 + l && 
                        OnBoard(i, j) && OnBoard(k, l))
                    {
                        m[getOne(i, j, k, l)] = 1e9;
                    }
                }
            }
        }
    }
 
    char c1, c2;
    cin >> c1 >> c2;
    int startX1 = c1 - 'a', startY1 = c2 - '1';
    cin >> c1 >> c2;
    int startX2 = c1 - 'a', startY2 = c2 - '1';
 
    cin >> c1 >> c2;
    int finishX1 = c1 - 'a', finishY1 = c2 - '1';
    cin >> c1 >> c2;
    int finishX2 = c1 - 'a', finishY2 = c2 - '1';
 
    int start = getOne(startX1, startY1, startX2, startY2);
    int finish = getOne(finishX1, finishY1, finishX2, finishY2);
    m[start] = 0;
 
    q.push(start);
    while (!q.empty())
    {
        int curNum = q.front();
        q.pop();
    
        f(curNum, 0);
        f(curNum, 2);
    }
 
    vector<int> ans;
    int cur = finish;
    while (cur != start)
    {
        ans.emplace_back(cur);
        cur = way[cur];
    }
    ans.emplace_back(start);
    reverse(ans.begin(), ans.end());
 
    for (int i = 0; i < ans.size() - 1; ++i)
    {
        if (ans[i] / 100 != ans[i + 1] / 100)
        {
            cout << "1 " << char(ans[i + 1] / 1000 % 10 + 'a') << char(ans[i + 1] / 100 % 10 + '1');
        }
        else
        {
            cout << "2 " << char(ans[i + 1] / 10 % 10 + 'a') << char(ans[i + 1] / 1 % 10 + '1');
        }
        cout << endl;
    }
}
