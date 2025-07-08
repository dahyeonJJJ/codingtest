// ����, 2206��, �� �μ��� �̵��ϱ�

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	int n, m;
	cin >> n >> m;  // n: ��, m: ĭ
	vector<vector<int>> graph(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = s[j] - '0';
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	// visited[y][x][broken]: 3���� ���� Ȱ��, (x,y)�� broken(0 �Ǵ� 1) ���·� �湮�ߴ°�
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	queue<tuple<int, int, int, int>> q;  // x, y, broken, dist


	// BFS Ȱ�� (�ִܰŸ�)
	q.push({ 0, 0, 0, 1 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		auto [x, y, broken, dist] = q.front();
		q.pop();

		// ù��°�� ������ ��, dist ���
		if (x == m - 1 && y == n - 1) {
			cout << dist << "\n";
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				// ���� �ƴϰ� ���� �湮���� �ʾ��� ���
				if (graph[ny][nx] == 0 && !visited[ny][nx][broken]) {
					visited[ny][nx][broken] = true;
					q.push({ nx, ny, broken, dist + 1 });
				}
				// ���̰�, ���� ���� �μ� ���� ���� ���
				else if (graph[ny][nx] == 1 && broken == 0 && !visited[ny][nx][1]) {
					visited[ny][nx][1] = true;
					q.push({ nx, ny, 1, dist + 1 });
				}
			}
		}
	}

	cout << -1 << "\n";
	return 0;
}
