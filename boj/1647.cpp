#include <bits/stdc++.h>
using namespace std;

// 기초 MST를 짜고, 거기서 제일 큰 비용의 간선 제거

int R;

using Point = struct {
  int start;
  int end;
  int cost;
};

vector<Point> Graph;
vector<int> Cost;
int Parent[101010];

int Find(int x) {
  if (Parent[x] != x) return Parent[x] = Find(Parent[x]);
  return x;
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x != y) Parent[y] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M; cin >> N >> M;
  for (int i=1; i<=N; ++i) Parent[i] = i;
  
  for (int i=0; i<M; ++i) {
    Point p; cin >> p.start >> p.end >> p.cost;
    Graph.emplace_back(p);
  }
  
  sort(Graph.begin(), Graph.end(), [](auto p1, auto p2) {
    return p1.cost < p2.cost;
  });
  
  for (auto &p: Graph) {
    if (Find(p.start) != Find(p.end)) {
      Union(p.start, p.end);
      Cost.emplace_back(p.cost);
    }
  }

  cout << accumulate(Cost.begin(), Cost.end() - 1, 0) << '\n';
  
  return 0;
}
