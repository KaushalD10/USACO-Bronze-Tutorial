#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int minimum = min(min(a, b), min(c, d));
    int maximum = max(max(a, b), max(c, d));

    cout << maximum - minimum;

    return 0;
}