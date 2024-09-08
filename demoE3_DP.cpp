#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
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
    
    vector<long long> dp(n+2, LLONG_MAX);
    for(int i = n+1; i >= 0; i--) {

        if(stations[n+1].first - stations[i].first <= x) {
            dp[i] = stations[i].second;
        } else {
            for(int j = i+1; j < n+1; j++) {
                if(stations[j].first - stations[i].first <= x) {
                    dp[i] = min(dp[i], stations[i].second + dp[j]);
                }
            }
        }
    }

    cout << dp[0];
    return 0;
}
