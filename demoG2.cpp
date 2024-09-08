#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> segment_tree(900005);
vector<int> a(900005);
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
        segment_tree[node] = val;
    }
    else
    {
        int m = (start + end) / 2;
        int l = 2 * node + 1;
        int r = 2 * node + 2;
        if (index <= m)
        {
            update(l, start, m, index, val);
        }
        else
        {
            update(r, m + 1, end, index, val);
        }
        segment_tree[node] = max(segment_tree[l], segment_tree[r]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
    {
        return -1;
    }
    if (l <= start && end <= r)
    {
        return segment_tree[node];
    }
    int m = (start + end) / 2;
    int max_left = query(2 * node + 1, start, m, l, r);
    int max_right = query(2 * node + 2, m + 1, end, l, r);
    return max(max_left, max_right);
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        double r = sqrt(num);
        int x = r;
        a[i] = (r == x) ? num : -1;
    }
    build(0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, v;
            cin >> x >> v;
            double r = sqrt(v);
            int temp = r;
            v = (r == temp) ? v : -1;
            update(0, 0, n - 1, x - 1, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int max_sq = query(0, 0, n - 1, l - 1, r - 1);
            cout << max_sq << endl;
        }
    }

    return 0;
}
