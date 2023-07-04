#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int bfs(vector<vector<char>>& grid, int x, int y) {
    int count = 0;
    queue<Point> q;
    q.push({x, y});
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    visited[x][y] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        count++;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny] && grid[nx][ny] == 'O') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return count;
}

bool checkChocolate(vector<vector<char>>& grid, vector<int>& numbers) {
    int numCount = 0;
    vector<int> counts(9, 0);

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'O') {
                int count = bfs(grid, i, j);
                counts[count]++;
            }
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (counts[i] > 0)
            numCount++;
        if (numCount > numbers.size() || (numCount <= numbers.size() && counts[i] != numbers[numCount - 1]))
            return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<vector<char>> grid(3, vector<char>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> grid[i][j];
            }
        }

        int n;
        cin >> n;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        bool isValid = checkChocolate(grid, numbers);
        if (isValid)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
