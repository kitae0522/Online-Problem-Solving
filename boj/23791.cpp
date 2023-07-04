#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> find_kth_food(int k, const vector<int>& a_list, const vector<int>& b_list) {
    int start = 0;
    int end = a_list.size() - 1;
    pair<int, int> result;

    while (start <= end) {
        int mid = (start + end) / 2;
        int count = mid + 1;  // mid까지의 개수

        if (count == k) {
            result = make_pair(1, a_list[mid]);  // 한식 음식
            break;
        } else if (count < k) {
            // 한식을 더 선택해야 함
            start = mid + 1;
        } else {
            // 한식을 덜 선택해야 함
            result = make_pair(2, b_list[mid]);  // 양식 음식
            end = mid - 1;
        }
    }

    if (result.first == 0) {
        // k가 전체 음식 개수보다 큰 경우
        if (k <= a_list.size()) {
            result = make_pair(1, a_list.back());  // 모든 한식을 선택한 경우
        } else {
            result = make_pair(2, b_list.back());  // 모든 양식을 선택한 경우
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;  // 음식의 수

    vector<int> a_list(n);  // 한식의 맛
    for (int i = 0; i < n; i++) {
        cin >> a_list[i];
    }

    vector<int> b_list(n);  // 양식의 맛
    for (int i = 0; i < n; i++) {
        cin >> b_list[i];
    }

    int q;
    cin >> q;  // 질의의 개수

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    // 정렬
    sort(a_list.begin(), a_list.end());
    sort(b_list.begin(), b_list.end());

    // 질의 처리
    for (const auto& query : queries) {
        int i = query[0];
        int j = query[1];
        int k = query[2];

        pair<int, int> result = find_kth_food(k, vector<int>(a_list.begin(), a_list.begin() + i), vector<int>(b_list.begin(), b_list.begin() + j));
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
