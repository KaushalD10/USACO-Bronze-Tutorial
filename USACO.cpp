#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> shell_at_pos(3);
    for (int i = 0; i < 3; i++)
    {
        shell_at_pos[i] = i;
    }

    vector<int> counter(3);
    for (int i = 0; i < n; i++)
    {
        int a, b, g;
        cin >> a >> b >> g;
        a--, b--, g--;

        std::swap(shell_at_pos[a], shell_at_pos[b]);
        counter[shell_at_pos[g]]++;
    }
    int highest = 0;

    for (int i = 0; i < 3; i++)
    {
        if (counter[i] >= highest)
        {
            highest = counter[i];
        }
    }
    cout << highest;

    // cout << max(counter[0], counter[1], counter[2]);
}