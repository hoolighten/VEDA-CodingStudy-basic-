#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int party_space, customer;
int road[501][501];

int main(void) {
	for (int i = 1; i <= party_space; i++) {
		for (int j = 1; j <= party_space; j++) {
			if (i == j)
				road[i][j] = 0;
			else
				road[i][j] = INF;
		}
	}

	cin >> party_space >> customer;

	for (int i = 1; i <= party_space; i++) {
		for (int j = 1; j <= party_space; j++) {
			// i�� ��Ƽ�忡�� j�� ��Ƽ������ ���� �ð�
			cin >> road[i][j];
		}
	}

	// floyd_warshell algorithm
	// party_spot[i] -> party_spot[k] -> party_spot[j]
	for (int k = 1; k <= party_space; k++) {
		for (int i = 1; i <= party_space; i++) {
			for (int j = 1; j <= party_space; j++) {
				road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
			}
		}
	}

	for (int i = 0; i < customer; i++) {
		int start_party_spot, end_party_spot, time;
		cin >> start_party_spot >> end_party_spot >> time;
		// Can't arrive on time
		if (road[start_party_spot][end_party_spot] > time)
			cout << "Stay here\n";
		// Can arrive on time
		else
			cout << "Enjoy other party\n";
	}
}
