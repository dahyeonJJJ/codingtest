// ����, 13975��, ������ġ��3

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int k; cin >> k;

		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int j = 0; j < k; j++) {
			int sz; cin >> sz; // ���� ũ��
			pq.push(sz);
		}

		long long total = 0; // �� ��ġ�� ���
		while (k>1) {
			long long sz1 = pq.top(); pq.pop(); // ���� ������� pop
			long long sz2 = pq.top(); pq.pop(); // ���� ������� pop
			pq.push(sz1 + sz2);
			total += (sz1 + sz2);

			k -= 1;  // ���� ���� ����
		}
		cout << total << '\n';
	}
}