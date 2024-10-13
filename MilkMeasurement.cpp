#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Log
{
    int day, cow, change;
};

int main()
{

    int n;
    int g;
    cin >> n >> g;

    vector<Log> log(n);
    std::map<int, int> cows;
    for (Log &l : log)
    {
        cin >> l.day >> l.cow >> l.change;
        cows[l.cow] = g;
    }
    std::sort(log.begin(), log.end(),
              [](const Log &l1, const Log &l2)
              { return l1.day < l2.day; });

    std::map<int, int> milk_prod{{g, n}};

    int changeAmt = 0;
    for (Log l : log)
    {
        int milk_amt = cows[l.cow];
        bool was_top = milk_amt == milk_prod.rbegin()->first;
        int prev_count = milk_prod[milk_amt];
        milk_prod[milk_amt]--;
        if (milk_prod[milk_amt] == 0)
        {
            milk_prod.erase(milk_amt);
        }

        milk_amt += l.change;
        cows[l.cow] = milk_amt;
        milk_prod[milk_amt]++;

        bool is_top = milk_amt == milk_prod.rbegin()->first;
        int curr_count = milk_prod[milk_amt];
        if (was_top)
        {
            if (is_top && curr_count == prev_count)
            {
                continue;
            }

            changeAmt++;
        }
        else if (is_top)
        {

            changeAmt++;
        }
    }

    cout << changeAmt << endl;
}