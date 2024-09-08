#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n;
    long long M, x;
    cin >> n >> M >> x;

    vector<int> costs(n + 2);
    vector<long long> positions(n + 2);

    costs[0] = 0;
    positions[0] = 0;
    positions[n+1] = M;
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> positions[i];
    }

    vector<long long> dp(n + 2, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < n + 2; i++) {
        if (dp[i] == LLONG_MAX) break;
        for (int j = i + 1; j < n + 2; j++) {
            // if ((j==i+1 || positions[j-1] != positions[j]) && positions[j-1] - positions[j] <= x) {
            if (positions[j] - positions[i] <= x) {
                dp[j] = min(dp[j], dp[i] + costs[i]);
                // cout << "dp["<< j <<"] = "<<dp[j]<<endl;

            } else {
                break;
            }
        }
    }
    
    // for (int i = 0; i < n + 2; i++) {
    //     cout << "dp["<< i <<"] = "<<dp[i]<<endl;
    // }

    if (dp[n + 1] == LLONG_MAX) {
        cout << -1;
    } else {
        cout << dp[n + 1];
    }

    return 0;
}
