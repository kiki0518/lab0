#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    // find median in unsorted array

    // Sol 1
    // just sort it and access arr[n/2 + n%2]
    sort(nums.begin(), nums.end());
    cout << nums[(n / 2 + n % 2) - 1];

    return 0;
}