#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef int BTDataType;

typedef struct binaryTreeNode
{
	struct binaryTreeNode* left;//指向左孩子结点
	struct binaryTreeNode* right;//指向右孩子结点
	BTDataType val;
}BTNode;

//申请二叉树的新结点
BTNode* buyBinaryTreeNewNode(BTDataType x);

//手搓的用来理解的二叉树
BTNode* createBinaryTree1();

//前序遍历
void preOrder(BTNode* root);

//中序遍历
void inOrder(BTNode* root);

//后续遍历
void postOrder(BTNode* root);

//二叉树结点数量
int binaryTreeSize(BTNode* root);

//二叉树的第k层的结点数
int treeKLevel(BTNode* root, int k);

//二叉树的深度
int treeDepth(BTNode* root);

