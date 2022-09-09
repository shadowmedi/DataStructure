#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"

//申请二叉树新结点
BTNode* buyBinaryTreeNewNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = x;
	return newNode;
}

//手搓的二叉树
BTNode* createBinaryTree1()
{
	BTNode* node1 = buyBinaryTreeNewNode(1);
	assert(node1);
	BTNode* node2 = buyBinaryTreeNewNode(2);
	assert(node2);
	BTNode* node3 = buyBinaryTreeNewNode(3);
	assert(node3);
	BTNode* node4 = buyBinaryTreeNewNode(4);
	assert(node4);
	BTNode* node5 = buyBinaryTreeNewNode(5);
	assert(node5);
	BTNode* node6 = buyBinaryTreeNewNode(6);
	assert(node6);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

//前序遍历
void preOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}

//中序遍历
void inOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	inOrder(root->left);
	printf("%d ", root->val);
	inOrder(root->right);
}

//后续遍历
void postOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->val);
}

