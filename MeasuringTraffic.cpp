#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<string> ramp_type(N);
    vector<pair<int, int>> sensor_range(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> ramp_type[i] >> sensor_range[i].first >> sensor_range[i].second;
    }

    int min_before = 0, max_before = 1000;
    int min_after = 0, max_after = 1000;

    for (int i = N - 1; i >= 0; --i)
    {
        if (ramp_type[i] == "on")
        {
            min_before -= sensor_range[i].second;
            max_before -= sensor_range[i].first;
        }
        else if (ramp_type[i] == "off")
        {
            min_before += sensor_range[i].first;
            max_before += sensor_range[i].second;
        }
        else
        {
            min_before = max(min_before, sensor_range[i].first);
            max_before = min(max_before, sensor_range[i].second);
        }
    }

    min_before = max(0, min_before);
    max_before = max(0, max_before);

    // Process for the flow after mile N (from mile 1 forwards to mile N)
    for (int i = 0; i < N; ++i)
    {
        if (ramp_type[i] == "on")
        {
            min_after += sensor_range[i].first;
            max_after += sensor_range[i].second;
        }
        else if (ramp_type[i] == "off")
        {
            min_after -= sensor_range[i].second;
            max_after -= sensor_range[i].first;
        }
        else
        {
            min_after = max(min_after, sensor_range[i].first);
            max_after = min(max_after, sensor_range[i].second);
        }
    }

    cout << min_before << " " << max_before << endl;
    cout << min_after << " " << max_after << endl;

    return 0;
}
