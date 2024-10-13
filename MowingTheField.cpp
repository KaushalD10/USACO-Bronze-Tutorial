#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("mowing.in", "r", stdin);
    int n;
    cin >> n;
    vector<pair<char, int>> steps(n);
    for (auto &[dir, num_steps] : steps)
    {
        cin >> dir >> num_steps;
    }

    pair<int, int> curr{0, 0};

    map<pair<int, int>, int> visits{{curr, 0}};

    int time = 0;
    int max_regrow = INT32_MAX;
    for (const auto &[dir, num_steps] : steps)
    {
        pair<int, int> delta;
        switch (dir)
        {
        case 'N':
            delta = pair<int, int>{0, 1};
            break;
        case 'W':
            delta = pair<int, int>{-1, 0};
            break;
        case 'E':
            delta = pair<int, int>{1, 0};
            break;
        case 'S':
            delta = pair<int, int>{0, -1};
            break;
        }

        for (int i = 0; i < num_steps; i++)
        {
            curr = pair<int, int>{curr.first + delta.first, curr.second + delta.second};
            time++;

            if (visits.count(curr))
            {
                max_regrow = min(max_regrow, time - visits[curr]);
            }

            visits[curr] = time;
        }
    }

    freopen("mowing.out", "w", stdout);
    cout << (max_regrow == INT32_MAX ? -1 : max_regrow) << endl;
}