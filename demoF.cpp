#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    long long sum = 0;
    cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
        sum += num;
    }

    for (int i = 0; i < q; i++)
    {
        int k, x;
        cin >> k >> x;
        sum += (x - arr[k - 1]);
        arr[k - 1] = x;
        cout << sum << endl;
    }

    return 0;
}