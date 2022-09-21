#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"

//申请二叉树新结点
BTNode* buyBinaryTreeNewNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
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

//前序遍历字符串构建二叉树
BTNode* createBinaryTree2(char* str, int* index)
{
	//如果遍历到'#',返回空树
	if (str[*index] == '#')
	{
		(*index)++;
		return NULL;
	}
	//先构建根结点
	BTNode* root = buyBinaryTreeNewNode(str[*index]);
	(*index)++;
	//再构建左子树和右子树
	root->left = createBinaryTree2(str, index);
	root->right = createBinaryTree2(str, index);
	return root;
}

//二叉树的销毁
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	//先销毁左子树和右子树
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	//再处理根结点
	free(root);
}

//前序遍历—— 根、左子树、右子树
void preOrder(BTNode* root)
{
	//空树打印#
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	//打印根结点的值
	printf("%c ", root->val);
	//遍历左子树
	preOrder(root->left);
	//遍历右子树
	preOrder(root->right);
}

//中序遍历——左子树、根、右子树
void inOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	inOrder(root->left);
	printf("%c ", root->val);
	inOrder(root->right);
}

//后续遍历——左子树、右子树、根
void postOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%c ", root->val);
}

//层序遍历
void levelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
			//取队头数据，并打印
			BTNode* cur = QueueFront(&q);
			printf("%c ", cur->val);
			//出队头数据
			QueuePop(&q);
			//将队头的左孩子和右孩子入队列
			if (cur->left)
				QueuePush(&q, cur->left);
			if (cur->right)
				QueuePush(&q, cur->right);
		
	}
	QueueDestroy(&q);
}

//二叉树的结点数
int binaryTreeSize(BTNode* root)
{
	//如果是空树，空树的结点数是0
	//二叉树的结点数 = 根结点( 1 )+ 它左子树的结点数和右子树的结点数
	return root == NULL ? 0 : 1 + 
		binaryTreeSize(root->left) + binaryTreeSize(root->right);
}

//二叉树的叶子结点个数
int binaryTreeLeafSize(BTNode* root)
{
	//如果是空树，叶结点数为0
	if (root == NULL)
		return 0;
	//如果这棵树的左子树是空，右子树也是空,这棵树的根结点就是叶子结点
	if (root->left == NULL && root->right == NULL)
		return 1;
	//否则求这棵树的左子树叶子结点数+右子树叶子结点数
	return binaryTreeLeafSize(root->left) + binaryTreeLeafSize(root->right);
}

//求第k层结点个数
int treeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	//如果是空树，结点数为0
	if (root == NULL)
		return 0;
	//如果k = 1，根结点就是这一层的结点
	if (k == 1)
		return 1;
	//否则求左子树的第(k-1)层结点数+右子树的(k-1)层结点数
	return treeKLevel(root->left, k - 1) + treeKLevel(root->right, k - 1);
}

//求二叉树的深度
int treeDepth(BTNode* root)
{
	//空树的深度是0
	if (root == NULL)
		return 0;
	//求出左子树的深度和右子树的深度
	int leftTreeDepth = treeDepth(root->left);
	int rightTreeDepth = treeDepth(root->right);
	//比较两棵子树的深度，返回较大的深度+原树的根深度
	return leftTreeDepth > rightTreeDepth ? leftTreeDepth + 1 : rightTreeDepth + 1;
}

//在二叉树中找值为x的结点
BTNode* binaryTreeFind(BTNode* root, BTDataType x)
{
	//如果是空树，没找到
	if (root == NULL)
		return NULL;
	//找到后返回给 调用该函数的函数
	if (root->val == x)
		return root;
	//如果这棵树的根结点不是，先去左子树找，找到了直接返回
	BTNode* leftTreeFind = binaryTreeFind(root->left, x);
	if (leftTreeFind != NULL)
		return leftTreeFind;
	//再去右子树找，找到了直接返回
	BTNode* rightTreeFind = binaryTreeFind(root->right, x);
	if (rightTreeFind != NULL)
		return rightTreeFind;
	//左右子树都没有找到
	return NULL;
	/*每一次return都是返回给递归调用该函数的上一层*/
}

//判断是否为完全二叉树
bool isCompleteTree(BTNode* root)
{
	if (root == NULL)
		return true;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	BTNode* cur = QueueFront(&q);
	//层序遍历二叉树，直到遍历到NULL结束
	while (cur != NULL)
	{
		//出队头数据
		QueuePop(&q);
		//将下一层的结点入队列
		QueuePush(&q, cur->left);
		QueuePush(&q, cur->right);
		//更新队头数据
		cur = QueueFront(&q);
	}
	//遍历到NULL后，看队列是否还存有二叉树的非空结点
	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q) != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return true;
}