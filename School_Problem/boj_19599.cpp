/*
문제 링크 : http://boj.kr/19599

code by Song Kitae(DKSH)
*/


#include <iostream>
#include <vector>
using namespace std;

int b_search(int key, int left, int right)
{
    int cnt = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (key == mid) { break; }
        else if (key < mid) { right = mid - 1; }
        else { left = mid + 1; }
        cnt++;
    }
    return cnt;
}

int t_cnt = 0;
int t_search(int key, int left, int right)
{
    while (left <= right)
    {
        int p1 = left + (right - left) / 3;
        int p2 = right - (right - left) / 3;

        if (key == p1) { return p1; }
        else
        {
            t_cnt++;
            if (key == p2) { return p2; }
            else
            {
                t_cnt++;
                if (key < p1) { right = p1 - 1; }
                else if (key < p2) { left = p1 + 1, right = p2 - 1; }
                else { left = p2 + 1; }
            }
        }
    }
}

int main()
{
    int n, win = 0, lose = 0, draw = 0;
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    vector<int> b_res, t_res;

    for (int i = 0; i < n; i++)
    {
        b_res.push_back(b_search(i, 0, n - 1));
        t_search(i, 0, n - 1);
        t_res.push_back(t_cnt);
        if (b_res[i] < t_res[i]) { lose++; }
        else if (b_res[i] > t_res[i]) { win++; }
        else { draw++; }
        t_cnt = 0;
    }

    cout << lose << '\n' << draw << '\n' << win;

    return 0;
}