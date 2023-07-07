#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

namespace Trie
{
    struct Node
    {
        map<char, Node *> _next;

        Node() {}

        ~Node() { for (auto &i: _next) delete i.second; }

        Node *insert(char x)
        {
            if (!find(x)) _next[x] = new Node();
            return _next[x];
        }

        Node *next(char x) { return _next.count(x) ? _next[x] : nullptr; }

        bool find(char x) { return _next.count(x) != 0; }

        bool end() { return _next.count(0); }
    } *root = new Node();

    int words = 0;

    bool insert(const string &word)
    {
        bool prefix_exist = false;
        Node *cursor = root;
        for (char i : word)
        {
            cursor = cursor->insert(i);
            if (cursor->end()) prefix_exist = true;
        }
        if (!cursor->end())
        {
            cursor->insert(0);
            ++words;
            if (cursor->_next.size() > 1) prefix_exist = true;
        }
        return prefix_exist;
    }

    bool find(const string &str)
    {
        Node *cursor = root;
        for (char i : str)
        {
            if (!cursor->find(i)) return false;
            cursor = cursor->next(i);
        }
        return cursor->end();
    }

    void clear()
    {
        delete root;
        root = new Node();
        words = 0;
    }
}

int main()
{
    STDIO();

    int T; cin >> T;
    while (T--)
    {
        int N; cin >> N;
        bool ans = false;
        for (int i = 1; i <= N; ++i)
        {
            string st; cin >> st;
            ans |= Trie::insert(st);
        }
        cout << (ans ? "NO" : "YES") << '\n';
        Trie::clear();
    }

    return 0;
}