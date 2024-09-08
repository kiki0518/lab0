#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int main() {
    int n;
    long long M, x;
    cin >> n >> M >> x;

    vector<int> costs(n + 2);
    vector<long long> positions(n + 2);
    map<long long, int> minCost; 

    positions[0] = 0;
    costs[0] = 0;  
    positions[n+1] = M;
    costs[n+1] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> positions[i];
        minCost[positions[i]] = INT_MAX;
    }

    for (int i = 0; i <= n+1; i++) {
        minCost[positions[i]] = min(minCost[positions[i]], costs[i]);
    }

    vector<long long> dp(n + 2, LLONG_MAX);
    dp[0] = 0;
    minCost[0] = 0;

    for (auto it1 = minCost.begin(); it1 != minCost.end(); it1++) {
        long long pos1 = it1->first;
        if (dp[pos1] == LLONG_MAX) break;

        for (auto it2 = it1; it2 != minCost.end(); it2++) {
            long long pos2 = it2->first;
            if (pos2 - pos1 <= x) {
                dp[pos2] = min(dp[pos2], dp[pos1] + it1->second);
                // cout << "dp["<< pos2 <<"] = "<<dp[pos2]<<endl;
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
