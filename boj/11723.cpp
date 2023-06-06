#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

class Set
{
private:
    vector<pair<int, bool>> s;
public:
    void init()
    {
        s.reserve(20);
        for (int i = 1; i <= 20; ++i) s.emplace_back(i, false);
    }

    void add(int x)
    {
        s[x - 1].second = true;
    }

    void remove(int x)
    {
        s[x - 1].second = false;
    }

    int check(int x)
    {
        return s[x - 1].second ? 1 : 0;
    }

    void toggle(int x)
    {
        if (s[x - 1].second) remove(x);
        else add(x);
    }

    void all()
    {
        for (int i = 1; i <= 20; ++i) add(i);
    }

    void empty()
    {
        for (int i = 1; i <= 20; ++i) remove(i);
    }
};

int main()
{
    STDIO();
    Set app;
    app.init();

    int T;
    cin >> T;
    while (T--)
    {
        string st;
        cin >> st;
        if (st == "add")
        {
            int x; cin >> x;
            app.add(x);
        }
        else if (st == "remove")
        {
            int x; cin >> x;
            app.remove(x);
        }
        else if (st == "check")
        {
            int x; cin >> x;
            cout << app.check(x) << '\n';
        }
        else if (st == "toggle")
        {
            int x; cin >> x;
            app.toggle(x);
        }
        if (st == "all") app.all();
        if (st == "empty") app.empty();
    }

    return 0;
}