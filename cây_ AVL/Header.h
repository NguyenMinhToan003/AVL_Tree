#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	int height;
	Node* left;
	Node* right;

};
typedef Node* tree;
int findMax(int a,int b);
int findHeight(tree avl);
tree createNode(int x);
void duyet_LeftRightNode(tree avl);
void duyet_LeftNodeRight(tree avl);
void duyet_NodeLeftRight(tree avl);
tree rotate_left(tree& avl);
tree rotate_right(tree& avl);
tree seachNode(tree avl,int x);
tree insertNode(tree& avl,int x);
int getBalanceFactor(tree avl);
tree minValue(tree avl);
tree deleteNode(tree& avl,int x);
