#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

template<typename T>
using v = vector<T>;

int N, M, R;

int main()
{
	STDIO();
	cin >> N >> M;
	v<int> A(N); for(auto &i: A) cin >> i; sort(A.begin(), A.end());
	v<int> B(M); for(auto &i: B) cin >> i; sort(B.begin(), B.end());
	for(auto &item_a : A) if (!binary_search(B.begin(), B.end(), item_a)) R++;
	for(auto &item_b : B) if (!binary_search(A.begin(), A.end(), item_b)) R++;
	cout << R << '\n';
	return 0;
}
