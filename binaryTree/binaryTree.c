#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"

//����������½��
BTNode* buyBinaryTreeNewNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = x;
	return newNode;
}

//�ִ�Ķ�����
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

//ǰ�����
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

//�������
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

//��������
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

//�������Ľ����
int binaryTreeSize(BTNode* root)
{
	//����ǿ����������Ľ������0
	//�������Ľ���� = �����( 1 )+ ���������Ľ�������������Ľ����
	return root == NULL ? 0 : 1 + 
		binaryTreeSize(root->left) + binaryTreeSize(root->right);
}

//��������Ҷ�ӽ�����
int binaryTreeLeafSize(BTNode* root)
{
	//����ǿ�����Ҷ�����Ϊ0
	if (root == NULL)
		return 0;
	//�����������������ǿգ�������Ҳ�ǿ�,������ĸ�������Ҷ�ӽ��
	if (root->left == NULL && root->right == NULL)
		return 1;
	//�������������������Ҷ�ӽ����+������Ҷ�ӽ����
	return binaryTreeLeafSize(root->left) + binaryTreeLeafSize(root->right);
}

//���k�������
int treeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	//����ǿ����������Ϊ0
	if (root == NULL)
		return 0;
	//���k = 1������������һ��Ľ��
	if (k == 1)
		return 1;
	//�������������ĵ�(k-1)������+��������(k-1)������
	return treeKLevel(root->left, k - 1) + treeKLevel(root->right, k - 1);
}

//������������
int treeDepth(BTNode* root)
{
	//�����������0
	if (root == NULL)
		return 0;
	//�������������Ⱥ������������
	int leftTreeDepth = treeDepth(root->left);
	int rightTreeDepth = treeDepth(root->right);
	//�Ƚ�������������ȣ����ؽϴ�����+ԭ���ĸ����
	return leftTreeDepth > rightTreeDepth ? leftTreeDepth + 1 : rightTreeDepth + 1;
}

//�ڶ���������ֵΪx�Ľ��
BTNode* binaryTreeFind(BTNode* root, BTDataType x)
{
	//����ǿ�����û�ҵ�
	if (root == NULL)
		return NULL;
	//�ҵ��󷵻ظ� ���øú����ĺ���
	if (root->val == x)
		return root;
	//���������ĸ���㲻�ǣ���ȥ�������ң��ҵ���ֱ�ӷ���
	BTNode* leftTreeFind = binaryTreeFind(root->left, x);
	if (leftTreeFind != NULL)
		return leftTreeFind;
	//��ȥ�������ң��ҵ���ֱ�ӷ���
	BTNode* rightTreeFind = binaryTreeFind(root->right, x);
	if (rightTreeFind != NULL)
		return rightTreeFind;
	//����������û���ҵ�
	return NULL;
	/*ÿһ��return���Ƿ��ظ��ݹ���øú�������һ��*/
}
