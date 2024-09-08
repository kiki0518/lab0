#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long M, x;
    cin >> n >> M >> x;

    vector<pair<long long, int> > stations;
    vector<int> costs(n+2);
    vector<long long> positions(n+2);

    costs[0] = 0;
    positions[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    stations.push_back(pair<long long, int>(positions[0], costs[0]));

    for (int i = 1; i <= n; i++) {
        cin >> positions[i];
        stations.push_back(pair<long long, int>(positions[i], costs[i]));
    }
    
    stations.push_back(pair<long long, int>(M, 0));

    sort(stations.begin(), stations.end());

    long long gas = 0;
    long long sum = 0;

    for (int i = 0; i < n + 1; i++)
    {
        if (gas < stations[i + 1].first - stations[i].first)
        {
            gas = x;
            sum += stations[i].second;
        }

        gas -= stations[i + 1].first - stations[i].first;
        if (gas < 0)
        {
            cout << -1;
            return 0;
        }
    }

    gas = x;
    sum = 0;
    for (int i = 0; i < n + 1;)
    {
        double minPrice;
        int minIndex = -1;
        int j;
        if (gas >= (M - stations[i].first))
        {
            break;
        }

        for (j = i + 1; j < n + 1; j++)
        {
            if ((stations[j].first - stations[i].first) > x)
            {
                break;
            }
            
            double price = (double)(stations[j].second - stations[i].second) / (stations[j].first - stations[i].first);
            if (j == i + 1 || price < minPrice)
            {
                minPrice = price;
                minIndex = j;
            }
        }

        sum += stations[minIndex].second;
        i = minIndex;
        // cout << minIndex << " ";
    }
    // cout<<endl;

    cout << sum;
    return 0;
}
