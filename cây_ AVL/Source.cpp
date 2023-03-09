#include"Header.h"
int findMax(int a, int b) {
	return a > b ? a : b;
}
int findHeight(tree avl) {
	if (avl == NULL)return 0;
	return avl->height;
}
tree createNode(int x) {
	tree p = new Node();
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return p;
}
void duyet_LeftRightNode(tree avl) {
	if (avl != NULL) {
		duyet_LeftRightNode(avl->left);
		duyet_LeftRightNode(avl->right);
		cout << avl->data<<"\t";
	}
}
		
void duyet_LeftNodeRight(tree avl) {
	if (avl != NULL) {
		duyet_LeftNodeRight(avl->left);
		cout << avl->data << "\t";
		duyet_LeftNodeRight(avl->right);
	}
}
void duyet_NodeLeftRight(tree avl) {
	if (avl != NULL) {
		cout << avl->data << "\t";
		duyet_NodeLeftRight(avl->left);
		duyet_NodeLeftRight(avl->right);
	}
}
tree rotate_left(tree& avl) {
	tree p = avl->left;
	tree q = p->right;
	//xoay
	p->left = avl;
	avl->right = q;
	avl->height = findMax(findHeight(avl->left), findHeight(avl->right));
	p->height = findMax(findHeight(p->left), findHeight(p->right));
	return p;
}
tree rotate_right(tree& avl) {
	tree p = avl->left;
	tree q = p->right;
	//xoay
	p->right = avl;
	avl->left = q;
	avl->height = findMax(findHeight(avl->left), findHeight(avl->right));
	p->height = findMax(findHeight(p->left), findHeight(p->right));
	return p;
}
tree seachNode(tree avl, int x) {
	if (avl->data == x)return avl;
	else if (avl->data > x) seachNode(avl->left, x);
	else if (avl->data < x)seachNode(avl->right, x);
	else return NULL;
}
tree insertNode(tree& avl, int x) {
	int balance = getBalanceFactor(avl);
	if (avl == NULL) avl = createNode(x);
	if (avl->data > x)avl->left = insertNode(avl->left, x);
	else if (avl->data < x)avl->right = insertNode(avl->right, x);
	else  return avl;
	avl->height = findMax(findHeight(avl->left), findHeight(avl->right));
	if (balance > 1 && x < avl->left->data) {
		rotate_right(avl);
	}
	if (balance<-1 && x>avl->right->data) {
		rotate_left(avl);
	}
	if (balance > 1 && x > avl->left->data)
	{
		avl->left = rotate_left(avl->left);
		return rotate_right(avl);
	}
	if (balance < -1 && x < avl->right->data) {
		avl->right = rotate_right(avl->right);
		return rotate_left(avl);
	}
	return avl;
}
int getBalanceFactor(tree avl) {
	if (avl == NULL)return 0;
	return findHeight(avl->left) - findHeight(avl->right);
}
tree minValue(tree avl) {
	tree current = avl;
	while (current != NULL) {
		current = current->left;
	}
	return current;
}
tree deleteNode(tree& avl, int x) {
	int balance = getBalanceFactor(avl);
	if (avl == NULL) return avl;
	if (avl->data > x) deleteNode(avl->left, x);
	else if (avl->data < x) deleteNode(avl->right, x);
	else {
		if (avl->left == NULL || avl->right == NULL) {
			tree temp = avl->left ? avl->left : avl->right;
			if (temp == NULL) {
				temp = avl;
				avl = NULL;
			}
			else {
				avl = temp;

			}
		}
		else {
			tree temp = minValue(avl->right);
			avl->data = temp->data;
			avl->right = deleteNode(avl->right, temp->data);
		}
	}
	if (avl == NULL) return avl;
	avl->height = findMax(findHeight(avl->left), findHeight(avl->right));
	if (balance > 1 && getBalanceFactor(avl->left)>=0) {
		return rotate_right(avl);
	}
	if (balance > 1 && getBalanceFactor(avl->left) < 0) {
		avl->left = rotate_left(avl->left);
		return rotate_right(avl);
	}
	if (balance < -1 && getBalanceFactor(avl->right) <= 0) {
		return rotate_left(avl);
	}
	if (balance < -1 && getBalanceFactor(avl->right) < 0) {
		avl->right = rotate_right(avl->right);
		return rotate_left(avl);
	}

	return avl;
}