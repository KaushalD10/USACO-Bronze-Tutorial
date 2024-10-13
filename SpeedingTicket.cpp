#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int LEN = 100;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> limit(LEN, 0);
    vector<int> bessie(LEN, 0);

    int start = 0;
    for (int i = 0; i < N; i++)
    {
        int length, speed;
        cin >> length >> speed;
        for (int j = start; j < start + length; j++)
        {
            limit[j] = speed;
        }
        start += length;
    }

    start = 0;
    for (int i = 0; i < M; i++)
    {
        int length, speed;
        cin >> length >> speed;
        for (int j = start; j < start + length; j++)
        {
            bessie[j] = speed;
        }
        start += length;
    }

    int worst = 0;
    for (int i = 0; i < LEN; i++)
    {
        worst = max(worst, bessie[i] - limit[i]);
    }
    cout << worst << endl;

    return 0;
}
