#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	Graph() : N(0) {}
	Graph(int n) : N(n) {
		adj.resize(N + 1);
		visit.resize(N + 1);
	}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sort_list() {
		for (int i = 0; i < N; ++i) {
			sort(adj[i].begin(), adj[i].end());
		}
	}

	void dfs() {
		fill(visit.begin(), visit.end(), false);
		dfs(1);
	}

	int return_components() {
		int res = 0;
		fill(visit.begin(), visit.end(), false);
		for (int i = 1; i <= N; ++i) {
			if (!visit[i]) {
				dfs(i);
				res++;
			}
		}
		return res;
	}

private:
	int N;
	vector<vector<int>> adj;
	vector<bool> visit;

	void dfs(int curr) {
		visit[curr] = true;
		for (auto& n : adj[curr]) {
			if (!visit[n]) {
				dfs(n);
			}
		}
	}
};

int main()
{
	int N, M;
	vector<int> V;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	Graph G(N);

	while (M--) {
		int target, victim;
		cin >> target >> victim;
		G.add_edge(target, victim);
	}

	G.sort_list();
	cout << G.return_components() << '\n';
	
	return 0;
}