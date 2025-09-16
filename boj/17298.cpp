#include <bits/stdc++.h>
using namespace std;

int N, A[1010101], R[1010101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> N;
  for (int i=1; i<=N; ++i) cin >> A[i];
  
  stack<int> S;
  for (int i=N; i>=1; --i) {
    while (!S.empty() && S.top() <= A[i]) S.pop();
    R[i] = S.empty() ? -1 : S.top();
    S.push(A[i]);
  }

  for (int i=1; i<=N; ++i) cout << R[i] << " ";
  return 0;
}
