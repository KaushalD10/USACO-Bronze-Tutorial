#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Cow
{
    int s, t, c;
};

struct AC
{
    int a, b, p, m;
};

int N, M;
vector<Cow> cows;
vector<AC> acs;
vector<bool> used;

int res = 10000;

bool possible()
{
    for (int i = 0; i < 100; ++i)
    {
        // how much AC can cool for this stall.
        int cooling_offer = 0;
        for (int k = 0; k < M; ++k)
        {
            if (!used[k])
                continue;
            int a = acs[k].a, b = acs[k].b, p = acs[k].p;
            if (a <= i && i <= b)
                cooling_offer += p;
        }
        // how much needed for this stall.
        int cooling_needed = 0;
        for (int k = 0; k < N; ++k)
        {
            int s = cows[k].s, t = cows[k].t, c = cows[k].c;
            if (s <= i && i <= t)
            {
                cooling_needed += c;
                break;
            }
        }
        if (cooling_offer < cooling_needed)
        {
            return false;
        }
    }
    return true;
}

void search(int i)
{
    if (i == M)
    {
        if (possible())
        {
            int cost = 0;
            for (int j = 0; j < M; ++j)
            {
                if (!used[j])
                    continue;
                cost += acs[j].m;
            }
            res = min(res, cost);
        }
    }
    else
    {
        used[i] = true;
        search(i + 1);
        used[i] = false;
        search(i + 1);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        Cow cow;
        cin >> cow.s >> cow.t >> cow.c;
        cows.push_back(cow);
    }
    for (int i = 0; i < M; ++i)
    {
        AC ac;
        cin >> ac.a >> ac.b >> ac.p >> ac.m;
        acs.push_back(ac);
    }
    used.assign(M, false);
    search(0);
    cout << res << "\n";
    return 0;
}
