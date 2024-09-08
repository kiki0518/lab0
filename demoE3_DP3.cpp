#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

bool compareStations(const pair<long long, int>& a, const pair<long long, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int n;
    long long M, x;
    cin >> n >> M >> x;

    vector<pair<long long, int> > stations;
    vector<int> costs(n + 2);
    vector<long long> positions(n + 2);

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

    sort(stations.begin(), stations.end(), compareStations);

    vector<long long> dp(n + 2, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < n + 2; i++) {
        if (dp[i] == LLONG_MAX) break;
        for (int j = i + 1; j < n + 2; j++) {
            if ((j==i+1 || stations[j-1].first != stations[j].first) && stations[j].first - stations[i].first <= x) {
                dp[j] = min(dp[j], dp[i] + stations[i].second);
            } else {
                break;
            }
        }
    }

    if (dp[n + 1] == LLONG_MAX) {
        cout << -1;
    } else {
        cout << dp[n + 1];
    }

    return 0;
}
