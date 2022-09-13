#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "queue.h"
typedef char BTDataType;

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

//通过前序遍历字符串，构建二叉树
BTNode* createBinaryTree2(char* str, int* index);

//二叉树的销毁
void BinaryTreeDestroy(BTNode* root);

//前序遍历
void preOrder(BTNode* root);

//中序遍历
void inOrder(BTNode* root);

//后续遍历
void postOrder(BTNode* root);

//层序遍历（需要队列）
void levelOrder(BTNode* root);

//二叉树结点数量
int binaryTreeSize(BTNode* root);

//二叉树的第k层的结点数
int treeKLevel(BTNode* root, int k);

//二叉树的深度
int treeDepth(BTNode* root);

//判断是否是完全二叉树
bool isCompleteTree(BTNode* root);

