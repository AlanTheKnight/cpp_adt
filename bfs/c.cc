#include <bits/stdc++.h>
using namespace std;


const char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

#define cell pair<int, int>

#define move pair<cell, cell>


// Check that cell is on board
bool onBoard(int x, int y)
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

bool isValid(move m)
{
    return (
        onBoard(m.first.first, m.first.second) &&
        onBoard(m.second.first, m.second.second) &&
        !(m.first.first == m.second.first && m.first.second == m.second.second)
    );
}

int findLetter(char l)
{
    for (int i = 0; i < 8; i++)
    {
        if (letters[i] == l)
            return i;
    }
    return -1;
}


cell getCellFromInput(string s)
{
    cell out;
    out.first = findLetter(s[0]);
    out.second = s[1] - '1';
    return out;
}

// Return string x1y1x2y2
string getCell(move m)
{
    string c;
    c += letters[m.first.first];
    c += to_string(m.first.second + 1);
    c += letters[m.second.first];
    c += to_string(m.second.second + 1);
    return c;
}


int main(int argc, char const *argv[])
{
    // freopen("knight2.in", "r", stdin);
    // freopen("knight2.out", "w", stdout);
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    map<move, int> dist;
    map<move, move> way;

    queue<move> q;

    string s1, e1, s2, e2;
    cin >> s1;
    cin >> e1;
    cin >> s2;
    cin >> e2;

    cell sc1 = getCellFromInput(s1);
    cell sc2 = getCellFromInput(s2);
    cell ec1 = getCellFromInput(e1);
    cell ec2 = getCellFromInput(e2);

    move start = make_pair(sc1, sc2);
    move end = make_pair(ec1, ec2);

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        move c = q.front();
        q.pop();

        move newMove;

        for (int i = 0; i < 8; i++)
        {
            newMove = c;
            newMove.first.first += dx[i];
            newMove.first.second += dy[i];
            if (isValid(newMove) && !dist.count(newMove))
            {
                dist[newMove] = dist[c] + 1;
                way[newMove] = c;
                q.push(newMove);
            }

            newMove = c;
            newMove.second.first += dx[i];
            newMove.second.second += dy[i];
            if (isValid(newMove) && !dist.count(newMove))
            {
                dist[newMove] = dist[c] + 1;
                way[newMove] = c;
                q.push(newMove);
            }
        }
    }

    vector<string> answer;

    move index = end;
    answer.push_back(getCell(end));

    while (way[index] != start)
    {
        answer.push_back(getCell(way[index]));
        index = way[index];
    }

    answer.push_back(getCell(start));

    reverse(answer.begin(), answer.end());

    for (int i = 1; i < answer.size(); i++)
    {
        if (answer[i][0] != answer[i-1][0])
            cout << "1 " << answer[i][0] << answer[i][1] << '\n';
        else
            cout << "2 " << answer[i][2] << answer[i][3] << '\n';
    }

    return 0;
}
