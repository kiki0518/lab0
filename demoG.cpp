#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> segment_tree(200005);
vector<int> a(200005);
int n;

void build(int l, int r, int v = 0)
{
    if (l == r)
    {
        segment_tree[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * v + 1);
    build(m + 1, r, 2 * v + 2);
    segment_tree[v] = max(segment_tree[2 * v + 1], segment_tree[2 * v + 2]);
}

void update(int node, int start, int end, int index, int val)
{
    if (start == end)
    {
        a[index] = val;
        segment_tree[node];
    }
    else
    {
        int m = (start + end) / 2;
        int l = 2 * node + 1;
        int r = 2 * node + 2;
        if (index >= start && index <= m)
        {
            update(l, start, m, index, val);
        }
        else
        {
            update(r, m, end, index, val);
        }
        segment_tree[node] = max(segment_tree[l], segment_tree[r]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
    {
        return 0;
    }
    else if (start == end)
    {
        return segment_tree[node];
    }
    else
    {
        int m = (start + end) / 2;
        int l = 2 * node + 1;
        int r = 2 * node + 2;
        int max_left = query(l, start, m, l, r);
        int max_right = query(r, m + 1, end, l, r);
        return max(max_left, max_right);
    }
}

int main()
{
    int q;
    long long sum = 0;
    cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        double r = sqrt(num);
        int x = r;
        a[i] = (r == x) ? num : -1;
    }
    build(0, n - 1, 0);

    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, v;
            cin >> x >> v;
            update(0, 0, n - 1, x, v);
            a[x - 1] = v;
        }
        else
        {
            int l, r, max_sq = -1;
            cin >> l >> r;
            max_sq = query(0, 0, n - 1, l, r);
            cout << max_sq << endl;
        }
    }

    return 0;
}