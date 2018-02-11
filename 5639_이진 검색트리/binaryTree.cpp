/*

2018 Feb 11, made by Moon

*/
#include <cstdio>
#include <vector>
using namespace std;


struct node {
	int key = 0;
	node* left = NULL;
	node* right = NULL;
};

node* head = new node;


void makeTree(int, node*);
int main() {
	int n;
	while (true) {
		scanf("%d", &n);

		makeTree(n, head);

		if (n > 0 && n < 1000000) {}
		else {
			break;
		}
	}

	return 0;
}

void makeTree(int u, node* root) {
	if (head->key == 0) {
		head->key = u;
		return;
	}
	else {
		if (head->key < u) {
			if (head->left != NULL) {
				makeTree(u, head->left);
			}
			else {
				node* next = new node;
				next->key = u;
				head->left = next;
				return;
			}
		}
		else if (head->key > u) {
			if (head->right != NULL) {
				makeTree(u, head->right);
			}
			else {
				node* next = new node;
				next->key = u;
				head->right = next;
				return;
			}
		}
	}
}
