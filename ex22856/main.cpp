#include <iostream>

using namespace std;

int n, target_node;
int cnt = 0;
bool arrive = false;

class node {
public:
	int left_child_node;
	int right_child_node;
};

node arr[100001];

void find_right_node(int top_node);
void tree_traversal(int node);

int main(void) {
	int now, left, right;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> now >> left >> right;
		arr[now].left_child_node = left;
		arr[now].right_child_node = right;
	}
	
	find_right_node(1);
	// 중위 순회
	tree_traversal(1);

	printf("%d", cnt);
}

void find_right_node(int root_node) {
	// 오른쪽 자식 노드가 없다면 가장 오른쪽에 위치한 노드
	if (arr[root_node].right_child_node == -1) {
		target_node = root_node;
		return;
	}
	find_right_node(arr[root_node].right_child_node);
}

void tree_traversal(int node) {
	int left_node = arr[node].left_child_node;
	int right_node = arr[node].right_child_node;

	if (left_node != -1) {
		cnt++;							// parent node -> left child node
		tree_traversal(left_node);	
		if (!arrive) {
			cnt++;						// left child node -> parent node
		}
	}
	if (right_node != -1) {
		cnt++;							// parent node -> right child node
		tree_traversal(right_node);
		if (!arrive) {
			cnt++;						// right child node -> parent node
		}
	}
	if (node == target_node) {
		arrive = true;
		return;
	}
}
