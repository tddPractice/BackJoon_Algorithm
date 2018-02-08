/*

2018 Feb 08, made by Moon

*/
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node {
	char key = NULL;
	bool visited = false;
	struct node* left = NULL;
	struct node* right = NULL;
};

void insertNode(char c[]);
void preOrder(node*);
void inOrder(node*);
void postOrder(node*);


node* head = new node;

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	int firstInsert = 1;
	while (n--) {
		char c[3];
		node* n = new node;
		scanf("%c %c %c", &c[0], &c[1], &c[2]);
		getchar();

		if (firstInsert) {
			node* left = new node;
			node* right = new node;

			head->key = c[0];
			if (c[1] != '.') {
				left->key = c[1];
				head->left = left;
			}
			else {
				head->left = NULL;
			}

			if (c[2] != '.') {
				right->key = c[2];
				head->right = right;
			}
			else {
				head->right = NULL;
			}

			firstInsert--;
		}
		else {
			insertNode(c);
		}
	}

	node* pre = head;
	preOrder(pre);
	printf("\n");

	node* in = head;
	inOrder(in);
	printf("\n");
	
	node* post = head;
	postOrder(post);
	printf("\n");

	return 0;
}

void insertNode(char c[]) {
	queue<node*> q;
	node* left = new node;
	node* right = new node;

	if (c[1] != '.') {
		left->key = c[1];
	}
	else {
		left = NULL;
	}

	if (c[2] != '.') {
		right->key = c[2];
	}
	else {
		right = NULL;
	}

	q.push(head);

	while (!q.empty()) {
		node* tail = q.front();
		q.pop();

		if (tail->key == c[0]) {
			tail->left = left;
			tail->right = right;
			break;
		}
		else {
			if (tail->left != NULL) {
				q.push(tail->left);
			}
			if (tail->right != NULL) {
				q.push(tail->right);
			}
		}
	}
}

void preOrder(node* pre) {
	pre->visited = true;
	printf("%c", pre->key);

	if (pre->left != NULL) {
		preOrder(pre->left);
	}
	if (pre->right != NULL) {
		preOrder(pre->right);
	}
}

void inOrder(node* in) {
	if (in->left != NULL) {
		inOrder(in->left);
	}
	in->visited = true;
	printf("%c", in->key);

	if (in->right != NULL) {
		inOrder(in->right);
	}
}

void postOrder(node* post) {
	if (post->left != NULL) {
		postOrder(post->left);
	}
	if (post->right != NULL) {
		postOrder(post->right);
	}
	post->visited = true;
	printf("%c", post->key);
}
