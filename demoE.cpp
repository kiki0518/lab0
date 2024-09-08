#include <iostream>
#include <vector>
using namespace std;

vector<int> costs;
vector<long long> pos;
long long sum = 0;

int main()
{
    int n;
    long long M, x, minSum = 0;
    cin >> n >> M >> x;

    costs.push_back(0);
    pos.push_back(0);

    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        costs.push_back(cost);
    }

    for (int i = 0; i < n; i++)
    {
        long position;
        cin >> position;
        pos.push_back(position);
    }
    pos.push_back(M);

    // cannot reach NYCU => -1
    // minimum amount

    // brute force
    // if fuel all still cannot get to NYCU
    // then return -1
    long long gas = 0;

    for (int i = 0; i < n + 1; i++)
    {
        if (gas < pos[i + 1] - pos[i])
        {
            gas = x;
            minSum += costs[i];
        }

        gas -= pos[i + 1] - pos[i];
        if (gas < 0)
        {
            cout << -1;
            return 0;
        }
    }

    long long cur = 0;
    gas = x;
    for (int i = 0; i < n + 1; i++)
    {
        double minPrice;
        int minIndex;
        int j;
        if (gas >= (pos[n + 1] - pos[i]))
        {
            break;
        }

        for (j = i + 1; j < n + 1; j++)
        {
            if ((pos[j] - pos[i]) > x)
            {
                break;
            }
            double price = (costs[j] - costs[i]) / (pos[j] - pos[i]);
            if (j == i + 1 || price < minPrice)
            {
                minPrice = price;
                minIndex = j;
            }
        }

        sum += costs[minIndex];
        i = minIndex;
        cur = pos[minIndex];
        gas = x;
    }

    cout << sum;

    return 0;
}