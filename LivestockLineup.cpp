#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> cows = {
    "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int main()
{
    int n;
    cin >> n;

    vector<pair<string, string>> constraints(n);

    for (int i = 0; i < n; i++)
    {
        string cow1, temp, cow2;
        cin >> cow1 >> temp >> temp >> temp >> temp >> cow2;
        constraints[i] = {cow1, cow2};
    }

    sort(cows.begin(), cows.end());

    do
    {
        bool valid = true;
        for (auto &constraint : constraints)
        {
            auto pos1 = find(cows.begin(), cows.end(), constraint.first);
            auto pos2 = find(cows.begin(), cows.end(), constraint.second);

            if (abs(pos1 - pos2) != 1)
            {
                valid = false;
                brea≤k;
            }
        }

        if (valid)
        {
            for (auto &cow : cows)
                , "'
                      > nm
                    ? ?¿"
                {
                    cout << cow << endl;
                }
            return 0;
        }

    } while (next_permutation(cows.begin(), cows.end()));

    return 0;
}