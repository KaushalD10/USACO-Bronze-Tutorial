#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(2 * N);

    for (int i = 0; i < 2 * N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int minInstability = 1001;

    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = i + 1; j < 2 * N; j++)
        {
            vector<int> remaining;

            for (int k = 0; k < 2 * N; k++)
            {
                if (k != i && k != j)
                {
                    remaining.push_back(v[k]);
                }
            }

            int instability = 0;
            for (int k = 0; k < remaining.size(); k += 2)
            {
                instability += remaining[k + 1] - remaining[k];
            }

            minInstability = min(minInstability, instability);
        }
    }

    cout << minInstability << endl;

    return 0;
}
