#include <bits/stdc++.h>
using namespace std;

// Distance Formula
// D = sqrt( (x1 - x2)^2 + (y1 - y2)^2 ))

double R;

using Point = struct {
  double x;
  double y;
};

using Node = struct {
  int start;
  int end;
  double cost;
};

vector<Node> Graph;
vector<Point> Map;
int Parent[101];

double Distance(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

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

  int N; cin >> N;
  for (int i=0; i<N; ++i) Parent[i] = i;
  for (int i=0; i<N; ++i) {
    Point p; cin >> p.x >> p.y;
    Map.emplace_back(p);
  }

  for (int i=1; i<=N; ++i) {
    for (int j=1; j<=N; ++j) {
      Node node = {i, j, Distance(Map[i-1], Map[j-1])};
      Graph.emplace_back(node);
    }
  }
  
  sort(Graph.begin(), Graph.end(), [](auto p1, auto p2) {
    return p1.cost < p2.cost;
  });
  
  for (auto &p: Graph) {
    if (Find(p.start) != Find(p.end)) {
      Union(p.start, p.end);
      R += p.cost;
    }
  }

  printf("%.2f", R);
  
  return 0;
}
