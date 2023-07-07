#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string find_root(unordered_map<string, string> &parent, const string &x)
{
    if (x == parent[x]) return parent[x];
    return parent[x] = find_root(parent, parent[x]);
}

void union_root(unordered_map<string, string> &parent, unordered_map<string, int> &size, string &x, string &y)
{
    x = find_root(parent, x);
    y = find_root(parent, y);

    if (x != y)
    {
        parent[y] = x;
        size[x] += size[y];
    }
}

vector<int> get_size_of_network(const vector<pair<string, string>> &relations)
{
    unordered_map<string, string> parent;
    unordered_map<string, int> size;
    vector<int> net_size;

    for (const auto &relation: relations)
    {
        string x = relation.first;
        string y = relation.second;

        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            size[x] = 1;
        }
        if (parent.find(y) == parent.end())
        {
            parent[y] = y;
            size[y] = 1;
        }

        union_root(parent, size, x, y);
        int networkSize = size[find_root(parent, x)];
        net_size.push_back(networkSize);
    }

    return net_size;
}

int main()
{
    STDIO();
    int T; cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int F; cin >> F;

        vector<pair<string, string>> relations;
        for (int j = 0; j < F; ++j)
        {
            string x, y; cin >> x >> y;
            relations.emplace_back(x, y);
        }
        vector<int> net_size = get_size_of_network(relations);
        for (int size: net_size) cout << size << '\n';
    }

    return 0;
}
