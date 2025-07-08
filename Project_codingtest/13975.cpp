// 백준, 13975번, 파일합치기3

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
			int sz; cin >> sz; // 파일 크기
			pq.push(sz);
		}

		long long total = 0; // 총 합치기 비용
		while (k>1) {
			long long sz1 = pq.top(); pq.pop(); // 작은 순서대로 pop
			long long sz2 = pq.top(); pq.pop(); // 작은 순서대로 pop
			pq.push(sz1 + sz2);
			total += (sz1 + sz2);

			k -= 1;  // 남는 파일 개수
		}
		cout << total << '\n';
	}
}