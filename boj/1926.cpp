#include <bits/stdc++.h>
using namespace std;

int maps[505][505];
bool visited[505][505];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> maps[i][j];

	int paint_count = 0, max_paint_size = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (visited[i][j] || !maps[i][j]) continue;
			paint_count++;

			queue<pair<int, int>> Q;
			int area = 0;

			visited[i][j] = true;
			Q.push({i, j});
			while(!Q.empty()) {
				area++;
				pair<int, int> item = Q.front(); Q.pop();

				for (int k=0; k<4; ++k) {
					int nx = dx[k] + item.first;
					int ny = dy[k] + item.second;

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visited[nx][ny] || !maps[nx][ny]) continue;

					visited[nx][ny] = true;
					Q.push({nx, ny});
				}
			}
			max_paint_size = max(max_paint_size, area);
		}
	}
	cout << paint_count << '\n' << max_paint_size << '\n';
}